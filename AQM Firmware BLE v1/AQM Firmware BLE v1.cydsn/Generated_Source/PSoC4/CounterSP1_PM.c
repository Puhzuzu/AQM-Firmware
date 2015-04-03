/*******************************************************************************
* File Name: CounterSP1_PM.c
* Version 2.0
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "CounterSP1.h"

static CounterSP1_BACKUP_STRUCT CounterSP1_backup;


/*******************************************************************************
* Function Name: CounterSP1_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void CounterSP1_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: CounterSP1_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void CounterSP1_Sleep(void)
{
    if(0u != (CounterSP1_BLOCK_CONTROL_REG & CounterSP1_MASK))
    {
        CounterSP1_backup.enableState = 1u;
    }
    else
    {
        CounterSP1_backup.enableState = 0u;
    }

    CounterSP1_Stop();
    CounterSP1_SaveConfig();
}


/*******************************************************************************
* Function Name: CounterSP1_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void CounterSP1_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: CounterSP1_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void CounterSP1_Wakeup(void)
{
    CounterSP1_RestoreConfig();

    if(0u != CounterSP1_backup.enableState)
    {
        CounterSP1_Enable();
    }
}


/* [] END OF FILE */
