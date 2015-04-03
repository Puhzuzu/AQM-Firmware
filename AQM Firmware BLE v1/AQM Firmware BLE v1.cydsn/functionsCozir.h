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
#if !defined(FUNCTIONS_COZIR_H)
#define FUNCTIONS_COZIR_H
	
	//#define CO2_IS_ENABLED		(1u)
	
	//cozir command values
	#define FILTER_WR_CMD			0x41u //A Cmd - userconfig
	#define FILTER_RD_CMD			0x61u //a Cmd - info
	#define OUTPUT_WR_CMD			0x4Du //M Cmd - userconfig
	#define USER_PARA_WR_CMD		0x50u //P Cmd - userconfig
	#define USER_PARA_RD_CMD		0x70u //p Cmd - info
	#define FIRMWARE_RD_CMD			0x59u //Y Cmd - info
	#define CONFIG_BEHAV_INFO_CMD	0x59u //* Cmd - info
	#define CO2_TO_PPM_RD_CMD		0x59u //. Cmd - info
	#define WRITE_MODE_CMD			0x4Bu //K Cmd - userconfig - switch btwn OP modes
		
	//OP MODES
	#define COMMAND_MODE		0x30u // Mode '0' - no measurements are taken
	#define STREAM_MODE			0x31u // Mode '1' - measurements reported twice per second
	#define POLLING_MODE		0x32u // Mode '2' - measurements cycle in background, reports only when requested(H,L,Q,T,Z).
	
	//Calibration CMDs
	
	
	// POLLING CMDs (humid/light/temp (H/T/L)?)
	#define RD_CO2_PPM_CMD				0x5Au // Z Cmd - latest CO2 in ppm
	#define ALL_MEASUREMENTS_RD_CMD		0x51u // Q Cmd - latest measurement fields defined by 'M' cmd.		
	
	
	
	// all CMDs should end in '\r\n'
	#define CR_END_CHAR				0x0Du // '\r' or 'CR'
	#define LF_END_CHAR				0x0Au // '\n' or 'LF'	

	#define SPACE_CHAR				0x20u // ' ' or Space, 32u
	#define ZERO_CHAR				0x30u // '0' or zero, 48u
	//cozir err responses
	#define UNKNOWN_CMD			0x3Fu // '?' - returned by cozir in response to an unknown cmd
	#define RESPONSE_MIN_SIZE		3u

	
	//Output mask values for setting output (maximum of 5 outputs)
//	#define OUTPUT_MASK_LIGHT			8192u
//	#define OUTPUT_MASK_LIGHT			4096
//	#define OUTPUT_MASK_LIGHT			2048
//	#define OUTPUT_MASK_LIGHT			1024
//	#define OUTPUT_MASK_LIGHT			512
//	#define OUTPUT_MASK_LIGHT			256
//	#define OUTPUT_MASK_LIGHT			128	
//	#define OUTPUT_MASK_LIGHT			64
//	#define OUTPUT_MASK_LIGHT			32u	
//	#define OUTPUT_MASK_LIGHT			16u
//	#define OUTPUT_MASK_LIGHT			8u	
	#define OUTPUT_MASK_CO2_FILT		0x34u // '4' or 52u
	#define OUTPUT_MASK_CO2_NO_FILT		0x32u // '2' or 50u

	
	//function Prototypes
	uint8 Cozir_WriteMode(uint8, uint8 *);
	uint8 ReadCO2(uint8 *,uint8 *);
	uint16 ReadCO2_2(uint8 *,uint8 *);
	
#endif 

/* [] END OF FILE */
