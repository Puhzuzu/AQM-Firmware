/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * by Keith Soneda
 * UC Davis - EEC136AB - Firmware for Air Quality Monitor - PSOC 4 BLE revision - March 2015
 * Overview: Main FOR loop. Reads data from
 * 			 array of sensors at a regular interval when a BLE connection has not been established. 
 * 			 When a connected device enables notifications, past data will be sent to the connected device over notifications.
 * Changes: This version lacks EEPROM. So I altered it to just send the last read cycle's data on loop.
 * ========================================
*/

#include "main.h"

/*'deviceConnected' flag is used by application to know whether a Central device  
* has been connected. This is updated in BLE event callback */
extern uint8 deviceConnected;

/*'startNotification' flag is set when the central device writes to CCC (Client  
* Characteristic Configuration) of the Random Data characteristic to 
* enable notifications */
extern uint8 startNotification;		

/* 'restartAdvertisement' flag is used to restart advertisement */
extern uint8 restartAdvertisement;
 
//data holding array
extern float dataArray[];

int main()
{
    /* Enable global interrupt mask */
	CyGlobalIntEnable;
	/* This function will initialize the system resources such as BLE*/
    InitializeDevice();
	
	
    for(;;)
    {
        //#ifdef BASEBOARD_IS_ENABLED
		Status_LED_Write(LED_OFF);
		GREEN_Write(LED_OFF);
		BLUE_Write(LED_OFF);
		//#endif
		/*Process Event callback to handle BLE events. The events generated and 
		* used for this application are inside the 'CustomEventHandler' routine*/
		CyBle_ProcessEvents();
		
		#ifdef BLE_BASEBOARD_IS_ENABLED
		/* Function to handle LED status depending on BLE state */
        /* Not necessary but useful to determine the state that the device is in. */
		
		HandleStatusLED();
		
		#endif
		
		
		/* Handle random data and CCCD value update only if BLE device is connected */
		if(TRUE == deviceConnected) 
		{
			/* After the connection, send new connection parameter to the Client device 
			* to run the BLE communication on desired interval. This affects the data rate 
			* and power consumption. High connection interval will have lower data rate but 
			* lower power consumption. Low connection interval will have higher data rate at
			* expense of higher power. This function is called only once per connection. */
			UpdateConnectionParam();
			
			/* When the Client Characteristic Configuration descriptor (CCCD) is written
			* by Central device for enabling/disabling notifications, then the same
			* descriptor value has to be explicitly updated in application so that
			* it reflects the correct value when the descriptor is read */
			UpdateNotificationCCCD();			
			
			 /* Send random data when notifications are enabled */
			if(startNotification)
			{
				/*Loops through numbers and dynamically changes the random data values when notifications are enabled. */
				/*Check for random data change and report to BLE central device*/
					//HandleRandomData(startNotification);
				


				/* FUNCTION TO HANDLE READ CYCLE */
				NotifyLastCycleData();
			}
	
        }//if(TRUE == deviceConnected) 
        
		else
		{	
			HandleDataCollection();	
		}
  
        if(restartAdvertisement)
	    {
			/* Reset 'restartAdvertisement' flag*/
			restartAdvertisement = FALSE;
			
			/* Start Advertisement and enter Discoverable mode*/
			CyBle_GappStartAdvertisement(CYBLE_ADVERTISING_FAST);	
	    }
		
        #ifdef ENABLE_LOW_POWER_MODE
		/* Put system to Deep sleep, including BLESS, and wakeup on interrupt. 
		* The source of the interrupt can be either BLESS Link Layer in case of 
		* BLE advertisement and connection or by User Button press during BLE 
		* disconnection */
		HandleLowPowerMode();
	    #endif		
     }//for(;;)
}//int main()

/* ---Initialization Function---- */
void InitializeDevice(void)
{	
	/* Start ISRs */
	#ifdef XBEE_IS_ENABLED
	ISR_Xbee_StartEx(XBEE_ISR);
	
	//Initialize Components
	XBee_Start();
	XBee_ClearRxBuffer();
	XBee_ClearTxBuffer();
	#endif

	#ifdef SI_7020_H
	I2C_1_Start();
	#endif
	
	#ifdef FUNCTIONS_COZIR_H		
	COZIR_Start();
	COZIR_SpiUartClearRxBuffer();
	COZIR_SpiUartClearTxBuffer();

	//Write COZIR to standby mode
//	uint8 response = 0u;
//	Cozir_WriteMode(COMMAND_MODE,&response);
//	if(response != COMMAND_MODE)
//	{	
//		Cozir_WriteMode(COMMAND_MODE,&response);	
//	}
	#endif

	/* Start BLE component and register the CustomEventHandler function. This 
	* function exposes the events from BLE component for application use */
	CyBle_Start(CustomEventHandler);					

#ifdef BLE_BASEBOARD_IS_ENABLED
	/* Set drive mode of the status LED pin to Strong*/
	Status_LED_SetDriveMode(Status_LED_DM_STRONG);	
	
   /* Start the Button ISR to allow wakeup from sleep */
	isr_button_StartEx(MyISR);
	
	Status_LED_Write(LED_ON);
	GREEN_Write(LED_ON);
	BLUE_Write(LED_ON);
	CyDelay(1000u);
#endif
}

//Sends last read cycle's data over notifications in order of: 
//Small Particle Dust, Large Particle dust, Temperature, Humidity, and CO2
//Sends repeatedly when connected BLE device has enabled notifications.
void NotifyLastCycleData(void)
{
	/* Static variable used as counter for reading the new value */
	static uint16 delayCounter = TRUE;
			
	/* Static variable to store last value */
	static uint8 lastValue = FALSE;
	
	//stores index into data array.
	static uint8 currentIndex = 0;

	
	/* Check if Counter has reached its counting value */
	if(FALSE == (--delayCounter))			
	{
		/* Set 'Counter' to the RAND_COUNTER_VALUE. This counter prevents sending 
		   of large number of Random data to BLE Central device */
		delayCounter = 65535;
        
		uint8 value;
		if(lastValue != (uint8)dataArray[currentIndex])
		{

		    value = (uint8) dataArray[currentIndex];
			
			/* Send the data to BLE central device by notifications*/
		    SendDataOverNotification(&value);
		
		    /* Update present random value */
		    lastValue = (uint8)dataArray[currentIndex];
	
		}
		currentIndex+=1;//increment index
		if(currentIndex>4)//if end of data array has been reached, reset index
		{
			currentIndex = 0;
		}
	}
}//void NotifyLastCycleData(void)

/* [] END OF FILE */
