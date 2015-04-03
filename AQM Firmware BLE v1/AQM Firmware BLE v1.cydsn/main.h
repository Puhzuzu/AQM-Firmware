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
#if !defined(MAIN_H)
#define MAIN_H
    
#include <project.h>
#include "BLEApplications.h"
#include "HandleLowPower.h"
#include "Si7020.h"
#include "myFunctions.h"
#include "functionsCozir.h"
#include "AmphenolDust.h"	
#include "mainLoop.h"

//#define BASEBOARD_IS_ENABLED

void InitializeDevice(void);
void NotifyLastCycleData(void);
void CustomEventHandler(uint32 event, void * eventParam);

/****************************************************************************/

/***************************Macro Definitions*******************************/
#define TRUE								1
#define FALSE								0
#define ZERO								0
    
/* Random Data value ranges from 0-255*/
#define MAX_RAND_VALUE						0xFF

/* Counter value for reading random data. This counter prevents pushing 
* large number of Random data to connected BLE Client. Modify
* this counter to change the rate of notification of Random data*/
#define DELAY_COUNTER_VALUE					5
#define LOOP_MAX_VALUE						3

#endif
/* [] END OF FILE */
