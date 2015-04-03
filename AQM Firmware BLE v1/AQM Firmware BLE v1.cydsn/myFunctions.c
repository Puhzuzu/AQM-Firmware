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
 * Overview: Random Functions
 * ========================================
*/
#include "main.h"

#ifdef MY_FUNCTIONS_H
//Function for loading next state in mainLoop.c code 
	//(largely pointless now if you remove the IDLE_STATE case from that code hardcode the return state)
uint8 LoadNextState(uint8 nextState, uint8 *readMode)
{
	switch(nextState)
	{
		case STANDBY_MODE:
		{
			*(readMode) = STANDBY_MODE;
			return IDLE_STATE;
		}
		break;
		
		case PERIODIC_MODE:// repeating, with sleep
		{
			*(readMode) = PERIODIC_MODE;
			return READ_DUST_STATE;
		}
		break;
		
		case CONTINUOUS_MODE://repeating
		{
			*(readMode) = CONTINUOUS_MODE;
			return READ_DUST_STATE;
		}
		break;
	
	#ifdef FUNCTIONS_COZIR_H
		case COZIR_STANDBY_MODE:
		{
			nextState = STANDBY_MODE;//test
			return COZIR_STANDBY_STATE;
		}
		break;
	
		case READ_CO2_MODE:
		{
			nextState = STANDBY_MODE;//test
			return READ_CO2_STATE;
		}
		break;
	#endif	
		
	#ifdef SI_7020_H
		case TH_MODE:
		{
			nextState = STANDBY_MODE;//test
			return READ_TH_STATE;
		}
		break;
	#endif
		
		default:
		{
			//add error handling code
			if(nextState >= ENDOFRANGE_MODE)
			{
			}
			return IDLE_STATE;
		}
	}//end of switch-case for nextState	
}

// overview: 	turns array of base 10 digits and stores in base 2 (uint16)
// details:		input array format - most significant (index 0) to least significant (index size-1);
//				Does not check array.
// inputs: 		digits - pointer to array of digits, size - number of digits to process
// outputs:		uint16 number
// errors: 		doesnt check for Overflow, or non integer characters.
uint16 ConvertDigitsToU16(uint8 *digits,uint8 size)
{
	uint16 number,value = 0u;
	uint8 i,j;
	for(i=0u;i<size;++i)
	{
		value = *(digits+i);// Start of '0' (48u) to '9' (57u) range.
		for(j=1u;j<(size-i);++j) //shift digit to correct position in base 10
		{
			value*=10u;
		}

		number+=value;
		//}
	}
	return number;
}

#endif

/* [] END OF FILE */
