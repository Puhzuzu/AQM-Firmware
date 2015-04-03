/*******************************************************************************
* File Name: CounterLP1_PM.c
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

#include "CounterLP1.h"

static CounterLP1_BACKUP_STRUCT CounterLP1_backup;


/*******************************************************************************
* Function Name: CounterLP1_SaveConfig
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
void CounterLP1_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: CounterLP1_Sleep
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
void CounterLP1_Sleep(void)
{
    if(0u != (CounterLP1_BLOCK_CONTROL_REG & CounterLP1_MASK))
    {
        CounterLP1_backup.enableState = 1u;
    }
    else
    {
        CounterLP1_backup.enableState = 0u;
    }

    CounterLP1_Stop();
    CounterLP1_SaveConfig();
}


/*******************************************************************************
* Function Name: CounterLP1_RestoreConfig
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
void CounterLP1_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: CounterLP1_Wakeup
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
void CounterLP1_Wakeup(void)
{
    CounterLP1_RestoreConfig();

    if(0u != CounterLP1_backup.enableState)
    {
        CounterLP1_Enable();
    }
}


/* [] END OF FILE */
