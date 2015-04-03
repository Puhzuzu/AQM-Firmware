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
#if !defined(SI_7020_H)
#define SI_7020_H
	
	//TEMP/HUMID
	
	#define TH_SLAVE_ADDR			(0x40u)//i2c slave addr for temp/humid
	
	//register addresses
	#define TH_REG_ADDR_TEMP		(0xE3u)
	#define TH_REG_ADDR_HUMID		(0xE5u)
	#define TH_REG_ADDR_CTRL_WR		(0xE6u)
	#define TH_REG_ADDR_CTRL_RD		(0xE7u)
	#define TH_REG_ADDR_RESET		(0xFEu)	
	
	//function Prototypes
	float MeasureHumidity(void);
	float MeasureTemperature(void);
	
#endif 

/* [] END OF FILE */
