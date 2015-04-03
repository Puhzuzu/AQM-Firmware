/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 
 * Overview: CO2 Measurement Code
 
 * ========================================
*/

#include "main.h"

#ifdef FUNCTIONS_COZIR_H
	
	const char *strEnd = "\r\n";

	uint8 ReadCO2(uint8 *array,uint8 *size)
	{
		COZIR_SpiUartClearRxBuffer();
		
		COZIR_UartPutChar(RD_CO2_PPM_CMD);
		COZIR_UartPutString(strEnd);
		
		while(COZIR_SpiUartGetRxBufferSize()<RESPONSE_MIN_SIZE)
		{}
		uint8 index = 0u;
		uint8 j;
		for(j=0u;j<75u;++j)
		{
			uint8 val = COZIR_UartGetChar();
			switch(val)
			{
				case 0u:
				{
					if(COZIR_SpiUartGetRxBufferSize()<1u)
					{
						CyDelay(50u);
					}
				}
				break;
				
				case CR_END_CHAR:
				{
					#ifdef XBEE_IS_ENABLED
						XBee_PutChar(READ_CO2_STATE);
						XBee_PutChar(READ_CO2_STATE);
						uint8 w;
						for(w=0u;w<index;++w)
						{
							XBee_PutChar(*(array+w));
						}
					#endif
					
					*(size) = index;
					return IDLE_STATE;
				}
				break;
				
				case UNKNOWN_CMD:
				{
					*(size) = 0u;
					
					#ifdef XBEE_IS_ENABLED
						XBee_PutChar(READ_CO2_STATE);
						XBee_PutChar(READ_CO2_STATE);
						XBee_PutChar(UNKNOWN_CMD);
					#endif
				
					return IDLE_STATE;	
				}
				break;

				default:
				{
					if((val < 58u)&&(val > 47u))// IF w/in '0' to '9' ASCII digit range
					{
						*(array+index) = val-48u; //add code to subtract '0' from each value before storing
						index += 1u;
					}
				}
			}//end of switch-case
		}// end of FOR loop (j)
		return IDLE_STATE;
	}

	uint16 ReadCO2_2(uint8 *array,uint8 *state)
	{
		COZIR_SpiUartClearRxBuffer();

		COZIR_UartPutChar(RD_CO2_PPM_CMD);
		COZIR_UartPutString(strEnd);
		while(COZIR_SpiUartGetRxBufferSize()<RESPONSE_MIN_SIZE)
		{}
		uint8 index = 0u;
		uint8 j;
		for(j=0u;j<50u;++j)
		{
			uint8 val = COZIR_UartGetChar();
			switch(val)
			{
				case 0u:
				{
					if(COZIR_SpiUartGetRxBufferSize()<1u)
					{
						CyDelay(100u);
					}
				}
				break;
				
				case CR_END_CHAR:
				{
					*(state) = IDLE_STATE;
					return ConvertDigitsToU16(array,index);
				}
				break;
				
				case UNKNOWN_CMD:
				{
					//XBee_PutChar(val); // test
					*(state) = IDLE_STATE;
					return 0u;
				}
				break;

				default:
				{
					if((val < 58u)&&(val > 47u))// IF w/in '0' to '9' ASCII digit range
					{
						*(array+index) = val-48u; //add code to subtract '0' from each value before storing
	//					XBee_PutChar(val-48u); //test
						index += 1u;
					}
				}		
			}//end of switch-case
		}// end of FOR loop (j)
		return 0u;
	}

	//Base function for sending cmds to COZIR
	uint8 Cozir_WriteMode(uint8 mode, uint8 *response)
	{
		const char *strMode = "K ";

		
		//GREEN_Write(ON_LED);
		COZIR_SpiUartClearRxBuffer();
		
		COZIR_UartPutString(strMode);
		COZIR_UartPutChar(mode);
		COZIR_UartPutString(strEnd);

		while(COZIR_SpiUartGetRxBufferSize()<RESPONSE_MIN_SIZE)
		{}
		
		uint8 last= 0u;
		uint8 j;
		for(j=0u;j<50u;++j)
		{
			uint8 val = COZIR_UartGetChar();
			switch(val)
			{
				case 0u:
				{
					CyDelay(50);
				}
				break;
				
				case CR_END_CHAR: // '\r' ASCII char
				{
					#ifdef XBEE_IS_ENABLED
						if(last == mode)
						{
							XBee_PutChar(COZIR_STANDBY_STATE);
							XBee_PutChar(COZIR_STANDBY_STATE);
							XBee_PutChar(last);
						}
					#endif
					*(response) = last;
					return IDLE_STATE;
					
					//break;
				}
				break;
				
				case UNKNOWN_CMD:
				{
					#ifdef XBEE_IS_ENABLED

						XBee_PutChar(COZIR_STANDBY_STATE);
						XBee_PutChar(COZIR_STANDBY_STATE);
						XBee_PutChar(UNKNOWN_CMD);
						
					#endif
					
					*(response) = val; 
					return IDLE_STATE;
					//break;
				}
				break;

				default:
				{
					last = val;
				}
			}//end of switch-case
		}// end of FOR loop (j)
		return IDLE_STATE;
	}


#endif

/* [] END OF FILE */
