/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 * by Keith Soneda
 * UC Davis - EEC136AB - Firmware for Air Quality Monitor - PSOC 4 BLE revision - March 2015
 * ========================================
*/
#if !defined(AMPHENOL_DUST_H)
#define AMPHENOL_DUST_H
	
	//DEFINES
	//Dust Sensor
	#define SAMPLING_WINDOW_SEC			30u //30 seconds
	#define CLOCK_FREQ_COUNTER			12000000u//12mhz
	#define SAMPLING_WINDOW_COUNT		(SAMPLING_WINDOW_SEC*CLOCK_FREQ_COUNTER)
	#define SAMPLING_WINDOW_UPPER16		(SAMPLING_WINDOW_COUNT>>BYTE2_SHIFT)

	//function Prototypes
	//uint8 DustSamplingCycle(uint32 *);
	uint8 DustSamplingCycle(void);

	
#endif 

/* [] END OF FILE */
