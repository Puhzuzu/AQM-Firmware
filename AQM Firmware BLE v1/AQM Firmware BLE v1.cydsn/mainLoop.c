/* ========================================
 *
 * by Keith Soneda
 * UC Davis - EEC136AB - Firmware for Air Quality Monitor - PSOC 4 BLE revision - March 2015
 * Overview: Data Collection Cycle for Dust, Temperature, Humidity, and CO2
 * ========================================
*/
#include "main.h"

float dataArray[5];//stores most recent cycle worth of float values

extern uint32 SPdata;//stores low pulse time for small particle dust
extern uint32 LPdata;//stores low pulse time for large particle dust

#ifdef MAIN_LOOP_H
static uint32 wait= 1u;
//Function for performing regular data measurements cycle and storing the data in EEPROM
void HandleDataCollection(void)
{
	//State Machine flags 
	static uint8 currentState = IDLE_STATE;
	static uint8 nextState = CONTINUOUS_MODE;//(Set in XBEE ISR) 
	static uint8 currentReadMode = CONTINUOUS_MODE;
	
	static uint32 dataBuf[3] = {1u, 1u, 1u};
	static uint32 *dataPtr = dataBuf;
	

	if(FALSE == (--wait))//provides some delay between measurement cycles
	{
		BLUE_Write(~BLUE_Read());
		wait = 6553500;
		switch (currentState)
		{
			case IDLE_STATE:
			{
				if(nextState != STANDBY_MODE)
				{
					currentState = LoadNextState(nextState,&currentReadMode);
				}
			}
			//break;
			
			#ifdef AMPHENOL_DUST_H
			case READ_DUST_STATE:
			{
				//#ifdef BASEBOARD_IS_ENABLED
				GREEN_Write(~GREEN_Read());	
				//#endif
				
//				uint32 dustOutput[2];
//				uint32 *dustPtr = dustOutput;
//				DustSamplingCycle(dustPtr);
				DustSamplingCycle();
				
				//Conversion for DUST (LPO to PPM)
				float POLY_X3_SP = 0.0006;
				float POLY_X2_SP = -0.0348;
				float POLY_X1_SP = 0.605;
				float POLY_X0_SP = 0.2614;

				float POLY_X2_LP = -0.0177;
				float POLY_X1_LP = 1.0182;			
				float lpoSP = ((float)SPdata)/((float)SAMPLING_WINDOW_COUNT/100);
				float lpoLP = ((float)LPdata)/((float)SAMPLING_WINDOW_COUNT/100);
//				float lpoSP = ((float)dustOutput[0])/((float)SAMPLING_WINDOW_COUNT/100);
//				float lpoLP = ((float)dustOutput[1])/((float)SAMPLING_WINDOW_COUNT/100);
				
				dataArray[SP_DATA_INDEX] = (lpoSP*lpoSP*lpoSP*POLY_X3_SP)+(lpoSP*lpoSP*POLY_X2_SP)+(lpoSP*POLY_X1_SP)+(POLY_X0_SP);
				//write_to_eeprom(dataArray[SP_DATA_INDEX]);
				//dataArray[SP_DATA_INDEX] = 1;
				dataArray[LP_DATA_INDEX] = (lpoLP*lpoLP*POLY_X2_LP)+(lpoLP*POLY_X1_LP);
				//write_to_eeprom(dataArray[LP_DATA_INDEX]);
				currentState = READ_TH_STATE;	
			}
			//break;		
			#endif
		
			#ifdef SI_7020_H
			case READ_TH_STATE: //--> IDLE or SLEEP
			{
				//#ifdef BASEBOARD_IS_ENABLED
				BLUE_Write(~BLUE_Read());
				//#endif
				dataArray[TEMPERATURE_DATA_INDEX] = MeasureTemperature();
				dataArray[HUMIDITY_DATA_INDEX] = MeasureHumidity();
				currentState = READ_CO2_STATE;
			}
			//break;
			#endif
			
			#ifdef FUNCTIONS_COZIR_H			

			case READ_CO2_STATE:
			{			
				Status_LED_Write(~Status_LED_Read());
				
				//Set Cozir CO2 sensor to active mode before reading
				uint8 response = 0u;
				Cozir_WriteMode(POLLING_MODE,&response);
				if(response != POLLING_MODE)
				{	
					Cozir_WriteMode(POLLING_MODE,&response);				
				}

				uint8 digits[5] = {0u,0u,0u,0u,0u};//holds returned CO2 PPM measurement in digit form
				uint8 *digitsPtr = digits;
				uint8 size;
				
				//returns CO2 PPM measurement in digit form
				ReadCO2(digitsPtr,&size);
				
				//Convert individual digits of the CO2 PPM measurement into a single uint32 value
				uint32 convertedVal = ConvertDigitsToU16(digitsPtr,size);
				
				//store in global array
				dataArray[CO2_DATA_INDEX] = (float)convertedVal;
				
				BLUE_Write(LED_OFF);
				GREEN_Write(LED_OFF);
				Status_LED_Write(LED_OFF);
				
				currentState = IDLE_STATE;
			}
			//break;
			#if 0
			case COZIR_STANDBY_STATE:
			{				
				uint8 mode = 0u;
				currentState = Cozir_WriteMode(COMMAND_MODE,&mode);
				if(mode != COMMAND_MODE)
				{
					Cozir_WriteMode(COMMAND_MODE,&mode);
					if(mode != COMMAND_MODE)
					{
						#ifdef XBEE_IS_ENABLED
						XBee_PutChar(mode);//test
						#endif
					}
				}
			}
			//break;
			#endif
			#endif		

			default:
			{
				//default handling code(add erro handling code)
				if(currentState >= (MAX_STATE_VALUE))
				{
					currentState = IDLE_STATE;
				}
			}
		}//end of switch-case
	}//if(FALSE == (--wait))
}
#endif

/* [] END OF FILE */
