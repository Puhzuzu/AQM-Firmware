/*******************************************************************************
* File Name: CounterSP2_PM.c
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

#include "CounterSP2.h"

static CounterSP2_BACKUP_STRUCT CounterSP2_backup;


/*******************************************************************************
* Function Name: CounterSP2_SaveConfig
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
void CounterSP2_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: CounterSP2_Sleep
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
void CounterSP2_Sleep(void)
{
    if(0u != (CounterSP2_BLOCK_CONTROL_REG & CounterSP2_MASK))
    {
        CounterSP2_backup.enableState = 1u;
    }
    else
    {
        CounterSP2_backup.enableState = 0u;
    }

    CounterSP2_Stop();
    CounterSP2_SaveConfig();
}


/*******************************************************************************
* Function Name: CounterSP2_RestoreConfig
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
void CounterSP2_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: CounterSP2_Wakeup
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
void CounterSP2_Wakeup(void)
{
    CounterSP2_RestoreConfig();

    if(0u != CounterSP2_backup.enableState)
    {
        CounterSP2_Enable();
    }
}


/* [] END OF FILE */
