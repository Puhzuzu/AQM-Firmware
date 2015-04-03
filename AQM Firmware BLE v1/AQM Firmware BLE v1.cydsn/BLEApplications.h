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
#if !defined(BLEAPPLICATIONS_H)
#define BLEAPPLICATIONS_H

    
/*************************Pre-processor directives****************************/
/* 'ENABLE_LOW_POWER_MODE' pre-processor directive enables the low power mode 
* handling in the firmware, ensuring low power consumption during project usage.
* To disable, comment the following #define. 
* If disabled, prevent usage of the project with coin cell */
//#define ENABLE_LOW_POWER_MODE

//#define BLE_BASEBOARD_IS_ENABLED //uncomment if not using BLE baseboard	

/* 'RAND_ENABLED' pre-processor directive enables RAND functionality 
* in the firmware. To disable RANDOM, comment the following #define as well 
* as disable the CapSense component from the TopDesign */
//#define RAND_ENABLED
    
void CustomEventHandler(uint32 event, void * eventParam);
void SendDataOverNotification(uint8 *);
void UpdateNotificationCCCD(void);
void UpdateConnectionParam(void); 
void HandleStatusLED(void);



/* Data length of RANDOM data sent over notification */
#define RAND_NOTIFICATION_DATA_LEN		1
#define READ_DATA_LEN					4		

/* Shifts used for different notification characteristics */
#define SHIFT_NTF_1			0u
#define SHIFT_NTF_2			1u
#define SHIFT_NTF_3			2u

/* Bit mask for notification bit in CCCD (Client Characteristic 
* Configuration Descriptor) written by Client device. */
#define NTF_BIT_MASK	                0x01
#define NTF_BIT_MASK_1						(NTF_BIT_MASK<<SHIFT_NTF_1)
#define NTF_BIT_MASK_2						(NTF_BIT_MASK<<SHIFT_NTF_2)

/* Client Characteristic Configuration descriptor data length. This is defined
* as per BLE spec. */
#define CCC_DATA_LEN						2

/* Connection Update Parameter values to modify connection interval. These values
* are sent as part of CyBle_L2capLeConnectionParamUpdateRequest() which requests
* Client to update the existing Connection Interval to new value. Increasing 
* connection interval will reduce data rate but will also reduce power consumption.
* These numbers will influence power consumption */

/* Minimum connection interval = CONN_PARAM_UPDATE_MIN_CONN_INTERVAL * 1.25 ms*/
#define CONN_PARAM_UPDATE_MIN_CONN_INTERVAL	50        	
/* Maximum connection interval = CONN_PARAM_UPDATE_MAX_CONN_INTERVAL * 1.25 ms */
#define CONN_PARAM_UPDATE_MAX_CONN_INTERVAL	60        	
/* Slave latency = Number of connection events */
#define CONN_PARAM_UPDATE_SLAVE_LATENCY		0          
/* Supervision timeout = CONN_PARAM_UPDATE_SUPRV_TIMEOUT * 10*/
#define CONN_PARAM_UPDATE_SUPRV_TIMEOUT		200      

/* LED Blink rate values for different stages of BLE connection */
#ifdef ENABLE_LOW_POWER_MODE
#define	LED_ADV_BLINK_PERIOD_ON			5
#define LED_ADV_BLINK_PERIOD_OFF		20
#else
#define	LED_ADV_BLINK_PERIOD_ON			10000
#define LED_ADV_BLINK_PERIOD_OFF		15000
#endif

/* Macros for LED ON and OFF values */
#define LED_ON							0x00
#define LED_OFF							0x01
/****************************************************************************/

#endif

/* [] END OF FILE */
