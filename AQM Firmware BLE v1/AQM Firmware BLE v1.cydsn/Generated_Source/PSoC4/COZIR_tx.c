/*******************************************************************************
* File Name: COZIR_tx.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "COZIR_tx.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        COZIR_tx_PC =   (COZIR_tx_PC & \
                                (uint32)(~(uint32)(COZIR_tx_DRIVE_MODE_IND_MASK << (COZIR_tx_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (COZIR_tx_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: COZIR_tx_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void COZIR_tx_Write(uint8 value) 
{
    uint8 drVal = (uint8)(COZIR_tx_DR & (uint8)(~COZIR_tx_MASK));
    drVal = (drVal | ((uint8)(value << COZIR_tx_SHIFT) & COZIR_tx_MASK));
    COZIR_tx_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: COZIR_tx_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  COZIR_tx_DM_STRONG     Strong Drive 
*  COZIR_tx_DM_OD_HI      Open Drain, Drives High 
*  COZIR_tx_DM_OD_LO      Open Drain, Drives Low 
*  COZIR_tx_DM_RES_UP     Resistive Pull Up 
*  COZIR_tx_DM_RES_DWN    Resistive Pull Down 
*  COZIR_tx_DM_RES_UPDWN  Resistive Pull Up/Down 
*  COZIR_tx_DM_DIG_HIZ    High Impedance Digital 
*  COZIR_tx_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void COZIR_tx_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(COZIR_tx__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: COZIR_tx_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro COZIR_tx_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 COZIR_tx_Read(void) 
{
    return (uint8)((COZIR_tx_PS & COZIR_tx_MASK) >> COZIR_tx_SHIFT);
}


/*******************************************************************************
* Function Name: COZIR_tx_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 COZIR_tx_ReadDataReg(void) 
{
    return (uint8)((COZIR_tx_DR & COZIR_tx_MASK) >> COZIR_tx_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(COZIR_tx_INTSTAT) 

    /*******************************************************************************
    * Function Name: COZIR_tx_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 COZIR_tx_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(COZIR_tx_INTSTAT & COZIR_tx_MASK);
		COZIR_tx_INTSTAT = maskedStatus;
        return maskedStatus >> COZIR_tx_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
