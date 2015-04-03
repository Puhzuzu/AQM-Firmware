/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 * Overview: Temperature and Humidity Measurement Code
 * ========================================
*/


#include "main.h"

#ifdef SI_7020_H
float MeasureTemperature(void)
{
	 /*Values for read temp*/
	I2C_1_I2CMasterClearStatus();
    I2C_1_I2CMasterClearWriteBuf();
    I2C_1_I2CMasterClearReadBuf();
    uint8 LSB = 0;
    uint8 MSB = 0;
    float T_Code = 0;
    float temperature = 0;
	
	 /*I2C Commands for capturing temp*/
//    uint8 Slave_Addr = 0x40;//for temp
    uint8 Write_Buffer[1] = {0};
    uint8 Measure_Cmd = 0xE3;//for temp
	
    Write_Buffer[0] = Measure_Cmd;
	
	 /*Buffer for reading temp values*/
    uint8 Read_Buf[2] = {0,0};//temp
	 /*Read and write values*/


    uint32 error = I2C_1_I2CMasterWriteBuf(TH_SLAVE_ADDR, Write_Buffer, 1, I2C_1_I2C_MODE_NO_STOP);

	while(0u==(I2C_1_I2CMasterStatus()&I2C_1_I2C_MSTR_ERR_LB_NAK))
	{
		//Add code to break loop if unsucessful
	}
	
	uint32 error2 = I2C_1_I2CMasterReadBuf(TH_SLAVE_ADDR, Read_Buf, 2, I2C_1_I2C_MODE_REPEAT_START);
	while(0u ==(I2C_1_I2CMasterStatus() & I2C_1_I2C_MSTAT_RD_CMPLT))
	{
		//Add code to break loop if unsucessful
	}
	
	LSB = Read_Buf[1];
    MSB = Read_Buf[0];//temp
    T_Code = MSB*256 + LSB;//LSB = Read_Buf[1]; MSB = Read_Buf[0];
    temperature = (((175.72*T_Code)/65536)-46.85);
	
	return temperature;
}

float MeasureHumidity(void)
{
    I2C_1_I2CMasterClearStatus();
	I2C_1_I2CMasterClearWriteBuf();
    I2C_1_I2CMasterClearReadBuf(); 
    
    /*Values for read humidity*/
    uint8 LSB = 0u;
    uint8 MSB = 0u;
    float RH_Code = 0;
    float humidity = 0;
	
	 /*I2C Commands for capturing humidity*/
//    uint8 Slave_Addr = 0x40;//for humid

    uint8 Write_Buffer[1] = {0};
    uint8 Measure_Cmd = 0xE5;//for humid

    Write_Buffer[0] = Measure_Cmd;
	
	 /*Buffer for reading humidity values*/
    uint8 Read_Buf[2] = {0,0};

    uint32 error = I2C_1_I2CMasterWriteBuf(TH_SLAVE_ADDR, Write_Buffer, 1, I2C_1_I2C_MODE_NO_STOP);
	while(0u==(I2C_1_I2CMasterStatus()&I2C_1_I2C_MSTR_ERR_LB_NAK))
	{
		//Add code to break loop if unsucessful
	}

    uint32 error2 = I2C_1_I2CMasterReadBuf(TH_SLAVE_ADDR, Read_Buf, 2, I2C_1_I2C_MODE_REPEAT_START);//temp
	while(0u ==(I2C_1_I2CMasterStatus() & I2C_1_I2C_MSTAT_RD_CMPLT))
	{
		//Add code to break loop if unsucessful
	}
	
	LSB = Read_Buf[1];
    MSB = Read_Buf[0];
    RH_Code = MSB*256 + LSB;
    humidity = (((125*RH_Code)/65536)-6);

	return humidity;
}
#endif
/* [] END OF FILE */
