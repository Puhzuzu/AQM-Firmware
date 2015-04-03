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
 * ========================================
*/
#if !defined(MAIN_LOOP_H)
#define MAIN_LOOP_H

	/* ---Defines ----- */
	//flag on/off states
	#define ON_FLAG					1u
	#define OFF_FLAG				0u
	
	//Data Array Index Values
	#define SP_DATA_INDEX				0u
	#define LP_DATA_INDEX				1u
	#define TEMPERATURE_DATA_INDEX		2u
	#define HUMIDITY_DATA_INDEX			3u
	#define CO2_DATA_INDEX				4u

	//States for switch-case in mainloop.c
	#define IDLE_STATE					1u
	#define READ_DUST_STATE 			2u
	#define READ_TH_STATE				3u
	#define COZIR_STANDBY_STATE			4u
	#define COZIR_POLLING_STATE			10u
	#define READ_CO2_STATE				11u
	#define SAVE_DATA_STATE				12u
	#define MAX_STATE_VALUE				(SAVE_DATA_STATE+1u)//define marking the end of the range of state values
	
	//Read Modes (now only used in LoadNextState function in myfunctions.c)
	#define STANDBY_MODE 				1u		
	#define SINGLE_MODE					2u
	#define CONTINUOUS_MODE 			3u
	#define PERIODIC_MODE 				4u
	//test modes
	#define COZIR_STANDBY_MODE			5u
	#define TH_MODE						6u
	#define READ_CO2_MODE				7u
	#define READ_DUST_MODE				8u
	#define ENDOFRANGE_MODE	 			(READ_DUST_MODE+1)//end of defined read modes range	
	
	
	/* Function Prototypes */
	void HandleDataCollection(void);
#endif 

/* [] END OF FILE */
