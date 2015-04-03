/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "main.h"

/**************************Variable Declarations*****************************/
/*'deviceConnected' flag is used by application to know whether a Central device  
* has been connected. This is updated in BLE event callback */
uint8 deviceConnected = FALSE;	

/*'startNotification' flag is set when the central device writes to CCC (Client 
* Characteristic Configuration) of the CapSense proximity characteristic to 
*enable notifications */
uint8 startNotification = FALSE;		

/* 'connectionHandle' is handle to store BLE connection parameters */
CYBLE_CONN_HANDLE_T  				connectionHandle;	

/* 'restartAdvertisement' flag provided the present state of power mode in firmware */
uint8 restartAdvertisement = FALSE;

/* This flag is used to let application update the CCCD value for correct read 
* operation by connected Central device */
uint8 updateNotificationCCCAttribute = FALSE;

/* This flag is used to let application send a L2CAP connection update request
* to Central device */
static uint8 isConnectionUpdateRequested = TRUE;

/* Connection Parameter update values. This values are used by the BLE component
* to update the connector parameter, including connection interval, to desired 
* value */
static CYBLE_GAP_CONN_UPDATE_PARAM_T ConnectionParam =
{
    CONN_PARAM_UPDATE_MIN_CONN_INTERVAL,  		      
    CONN_PARAM_UPDATE_MAX_CONN_INTERVAL,		       
    CONN_PARAM_UPDATE_SLAVE_LATENCY,			    
    CONN_PARAM_UPDATE_SUPRV_TIMEOUT 			         	
};

/* Status flag for the Stack Busy state. This flag is used to notify the application 
* whether there is stack buffer free to push more data or not */
uint8 busyStatus = CYBLE_STACK_STATE_FREE;

extern float dataArray[];
//extern uint8 eeprom_read_index;

/****************************************************************************/
//BLE STACK HANDLING
void CustomEventHandler(uint32 event, void *eventParam)
{
    CYBLE_GATTS_WRITE_REQ_PARAM_T *wrReqParam;
	
    switch(event)
	{
        /**********************************************************
        *                       General Events
        ***********************************************************/
		case CYBLE_EVT_STACK_ON:
			/* This event is received when component is Started */
			
			/* Set restartAdvertisement flag to allow calling Advertisement 
			* API from main function */
			restartAdvertisement = TRUE;
			
			break;
		
		case CYBLE_EVT_TIMEOUT:
			/* Event Handling for Timeout  */
			
			break;
		
        /**********************************************************
        *                       GAP Events
        ***********************************************************/
				
        case CYBLE_EVT_GAPP_ADVERTISEMENT_START_STOP:
			
			if(CyBle_GetState() == CYBLE_STATE_DISCONNECTED)
			{
				/* Set restartAdvertisement flag to allow calling Advertisement 
				* API from main function */
				restartAdvertisement = TRUE;
			}
			break;
			
		case CYBLE_EVT_GAP_DEVICE_CONNECTED:		
			/* This event is received when device is connected over GAP layer */

			break;
			
        case CYBLE_EVT_GAP_DEVICE_DISCONNECTED:		
			/* This event is received when device is disconnected */
			
			/* Set restartAdvertisement flag to allow calling Advertisement 
			* API from main function */
			restartAdvertisement = TRUE;

            break;

        /**********************************************************
        *                       GATT Events
        ***********************************************************/
        case CYBLE_EVT_GATT_CONNECT_IND:
			/* This event is received when device is connected over GATT level */
			
			/* Update attribute handle on GATT Connection*/
            connectionHandle = *(CYBLE_CONN_HANDLE_T *)eventParam;	
			
			/* This flag is used in application to check connection status */
			deviceConnected = TRUE;	
	
            break;
			
        case CYBLE_EVT_GATT_DISCONNECT_IND:	
			/*This event is received when device is disconnected. 
			* Update connection flag accordingly */
			deviceConnected = FALSE;
			
			/* Reset notification flag to prevent further notifications
			 * being sent to Central device after next connection. */
			startNotification = FALSE;
			
			/* Reset the CCCD value to disable notifications */
			updateNotificationCCCAttribute = TRUE;
			UpdateNotificationCCCD();
			
			/* Reset the isConnectionUpdateRequested flag to allow sending
			* connection parameter update request in next connection */
			isConnectionUpdateRequested = TRUE;
			break;    
			
			
        case CYBLE_EVT_GATTS_WRITE_REQ:				
			/*When this event is triggered, the peripheral has received 
			* a write command on the custom characteristic */
			
			/* Extract the write value from the event parameter */
            wrReqParam = (CYBLE_GATTS_WRITE_REQ_PARAM_T *) eventParam;
			/* Check if the returned handle is matching to Random Data Client custom configuration*/
            if(CYBLE_AIR_QUALITY_DATA_AIR_QUALITY_DATA_CLIENT_CHARACTERISTIC_CONFIGURATION_DESC_HANDLE == wrReqParam->handleValPair.attrHandle)
            {
                /* Set flag so that application can start sending notifications.*/
				startNotification = wrReqParam->handleValPair.value.val[CYBLE_AIR_QUALITY_DATA_AIR_QUALITY_DATA_CLIENT_CHARACTERISTIC_CONFIGURATION_DESC_INDEX];
				
				/* Set flag to allow CCCD to be updated for next read operation */
				updateNotificationCCCAttribute = TRUE;
			}
			/* Send the response to the write command received. */
			CyBle_GattsWriteRsp(connectionHandle);			
            break;			
		
		case CYBLE_EVT_L2CAP_CONN_PARAM_UPDATE_RSP:
				/* If L2CAP connection parameter update response received, reset application flag */
            	isConnectionUpdateRequested = FALSE;
            break;
		
		case CYBLE_EVT_STACK_BUSY_STATUS:
			/* This event is generated when the internal stack buffer is full and no more
			* data can be accepted or the stack has buffer available and can accept data.
			* This event is used by application to prevent pushing lot of data to stack. */
			
			/* Extract the present stack status */
            busyStatus = * (uint8*)eventParam;
            break;
			
        default:
                        
            break;
	} /* switch(event)*/
}

//Updates notification data and reports new data to BLE for sending over notifications
//Input: uint8 array
void SendDataOverNotification(uint8 *randValue)
{
	/* 'notificationHandle' is handle to store notification data parameters */
	CYBLE_GATTS_HANDLE_VALUE_NTF_T		notificationHandle; 
	
	/* If stack is not busy, then send the notification */
	if(busyStatus == CYBLE_STACK_STATE_FREE)
	{
		/* Update Notification handle with random data*/
		notificationHandle.attrHandle = CYBLE_AIR_QUALITY_DATA_AIR_QUALITY_DATA_CHAR_HANDLE;				
		notificationHandle.value.val = randValue;
		notificationHandle.value.len = RAND_NOTIFICATION_DATA_LEN;
		
		/* Report data to BLE component for sending data by notifications*/
		CyBle_GattsNotification(connectionHandle,&notificationHandle);
	}
}

//Communicates the connection parameters to connected device after connection has been established.
void UpdateConnectionParam(void)
{
	/* If device is connected and Update connection parameter not updated yet,
	* then send the Connection Parameter Update request to Client. */
    if(deviceConnected && isConnectionUpdateRequested)
	{
		/* Reset the flag to indicate that connection Update request has been sent */
		isConnectionUpdateRequested = FALSE;
		
		/* Send Connection Update request with set Parameter */
		CyBle_L2capLeConnectionParamUpdateRequest(connectionHandle.bdHandle, &ConnectionParam);
	}
}

//Updates BLE component with new notification status
void UpdateNotificationCCCD(void)
{
	/* Local variable to store the current CCCD value */
	uint8 CCCDvalue[2];
	
	/* Handle value to update the CCCD */
	CYBLE_GATT_HANDLE_VALUE_PAIR_T	 notificationCCCDhandle;
	
	/* Update notification attribute only when there has been change */
	if(updateNotificationCCCAttribute)
	{	

		updateNotificationCCCAttribute=FALSE;
		
		/* Write the present notification status to the local variable */
		CCCDvalue[0] = startNotification;
		CCCDvalue[1] = 0x00;
		
		/* Update CCCD handle with notification status data*/
		notificationCCCDhandle.attrHandle = CYBLE_AIR_QUALITY_DATA_AIR_QUALITY_DATA_CLIENT_CHARACTERISTIC_CONFIGURATION_DESC_HANDLE;
		notificationCCCDhandle.value.val = CCCDvalue;
		notificationCCCDhandle.value.len = CCC_DATA_LEN;
		
		/* Report data to BLE component for sending data when read by Central device */
		CyBle_GattsWriteAttributeValue(&notificationCCCDhandle, ZERO, &connectionHandle, CYBLE_GATT_DB_LOCALLY_INITIATED);		
	}
}//void UpdateNotificationCCCD(void)

/* [] END OF FILE */
