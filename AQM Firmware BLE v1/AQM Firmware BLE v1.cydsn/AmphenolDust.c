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
 * Overview: Read Cycle for sampling dust levels.
 * ========================================
*/

#include "main.h"

uint32 SPdata=0;//stores Low pulse time for Small Particle Dust
uint32 LPdata=0;//stores low pulse time for large particle dust

#ifdef AMPHENOL_DUST_H


//function for accumulating low pulse time during read cycle. (non ISR method)
//This function starts a blocking 30 second window in which the "Low pulse time"
//is measured from the two PWM Dust Sensor inputs.
//uint8 DustSamplingCycle(uint32 *array)
uint8 DustSamplingCycle(void)
{
/*----------- START: Start DustSamplingCycle() Code --------------*/	
	//Start Variables
	SPdata = 0u;
	LPdata = 0u;
	uint32 currentCount = 0u;//for sampling window

	//Reset Counters
	CounterLP1_WriteCounter(currentCount);
	CounterLP2_WriteCounter(currentCount);	
	
	/* Start Components */
	Clock_Counter_Start();
	CounterLP1_Start();
	CounterLP2_Start();
	CounterSP1_Start();	
	CounterSP2_Start();
	
	
	CounterLP1_TriggerCommand((CounterLP1_MASK|CounterLP2_MASK),CounterLP1_CMD_STOP);
	CounterLP2_WriteCounter(0u);
	CounterLP1_WriteCounter(0u);
	
	while(CounterLP1_ReadCounter()>0u){
		//RED_Write(~RED_Read());
		//CyDelay(150);
	}
	
	//Clear Both capture buffers so if line is LOW during first loop, the residual captures are not large values.
	CounterLP1_TriggerCommand((CounterLP1_MASK|CounterLP2_MASK),CounterLP1_CMD_CAPTURE);
	CounterLP1_TriggerCommand((CounterLP1_MASK|CounterLP2_MASK),CounterLP1_CMD_CAPTURE);
	CounterLP1_TriggerCommand((CounterLP1_MASK|CounterLP2_MASK),CounterLP1_CMD_RELOAD);
	CounterLP1_TriggerCommand((CounterLP1_MASK|CounterLP2_MASK),CounterLP1_CMD_START);
	
	uint8 spFlag = ON_FLAG;
	uint8 lpFlag = ON_FLAG;

	uint32 lastLP;//1
/*----------- END: Start DustSamplingCycle() Code --------------*/	
		
/*----------- START: Loop DustSamplingCycle() Code --------------*/
	//while(currentCount<SAMPLING_WINDOW_COUNT)
	while(currentCount<(SAMPLING_WINDOW_COUNT/2))//sampling duration reduced for testing
	{	
		//SP handling
		if(Pin_SP_Read()==OFF_FLAG)
		{
			if(spFlag)
			{
				spFlag = OFF_FLAG;
			}
		}
		else
		{
			if(spFlag==OFF_FLAG)//rising edge
			{
				SPdata += CounterSP1_ReadCapture()+(CounterSP2_ReadCapture()<<16u);
				spFlag = ON_FLAG;
			}
		}
		
		//LP handling & window handling
		if(Pin_LP_Read()==OFF_FLAG)
		{
			if(lpFlag)
			{
				lpFlag = OFF_FLAG;//set flag to signal that rising edge has not yet occured					
			}

		}
		else
		{
			if(lpFlag==OFF_FLAG)
			{
				lpFlag = ON_FLAG;
				LPdata += (CounterLP1_ReadCapture()-CounterLP1_ReadCaptureBuf()) + ((CounterLP2_ReadCapture()-CounterLP2_ReadCaptureBuf())*65500u);//<-- 2) Lowered rate of >100% values still occurs sometimes. Loses some accuracy.
			}

		}
		//Check current count to see if 30 second window has expired.
		currentCount = CounterLP1_ReadCounter()+(CounterLP2_ReadCounter()<<16u);
		
	}//end of while loop

	// code for handing error values
	if(SPdata > SAMPLING_WINDOW_COUNT)
	{
		//error code
		SPdata = 360000000u;
	}
	if(LPdata > SAMPLING_WINDOW_COUNT)
	{
		//error code
		LPdata = 360000000u;
	}
	
	// code for handing error values
	if(SPdata==0u)
	{
		SPdata = 1u;
	}
	if(LPdata == 0u)
	{
		LPdata = 1u;
	}		
/*----------- END: Loop DustSamplingCycle() Code --------------*/	

	
/*----------- START: Stop DustSamplingCycle() Code --------------*/	
	//Stop Variables

	/* Stop Clocks */
	CounterLP1_TriggerCommand((CounterLP1_MASK|CounterLP2_MASK),CounterLP1_CMD_STOP);
	
	CounterLP1_WriteCounter(1u);
	CounterLP2_WriteCounter(1u);
	//Clear Both capture buffers so if line is LOW during first loop, the residual captures are not large values.
	CounterLP1_TriggerCommand((CounterLP1_MASK|CounterLP2_MASK),CounterLP1_CMD_CAPTURE);
	CounterLP1_TriggerCommand((CounterLP1_MASK|CounterLP2_MASK),CounterLP1_CMD_CAPTURE);
	
	Clock_Counter_Stop();	
	
	//Stop Components
	CounterLP1_Stop();
	CounterLP2_Stop();	
	CounterSP1_Stop();
	CounterSP2_Stop();	
	
	
	//Store/return Values
	//*(array) = SPdata;
	// *(array+1u) = LPdata;
	
	#ifdef XBEE_IS_ENABLED
		XBee_PutChar(3u);
		XBee_PutChar(SPdata);
		XBee_PutChar(SPdata/255u);
		XBee_PutChar(SPdata/65535u);
		XBee_PutChar(SPdata/16777216u);
		
		XBee_PutChar(LPdata);
		XBee_PutChar(LPdata/255u);
		XBee_PutChar(LPdata/65535u);
		XBee_PutChar(LPdata/16777216u);
//			XBee_PutChar(LPdata>>BYTE1_SHIFT);
//			XBee_PutChar(LPdata>>BYTE2_SHIFT);
//			XBee_PutChar(LPdata>>BYTE3_SHIFT);
	#endif

	return IDLE_STATE;
/*----------- END: Stop DustSamplingCycle() Code --------------*/	
}

#endif

/* [] END OF FILE */
