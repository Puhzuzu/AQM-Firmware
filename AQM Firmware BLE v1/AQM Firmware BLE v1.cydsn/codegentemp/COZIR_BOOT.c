/*******************************************************************************
* File Name: COZIR_BOOT.c
* Version 2.0
*
* Description:
*  This file provides the source code to the API for the bootloader
*  communication support in the SCB Component.
*
* Note:
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "COZIR_BOOT.h"


#if defined(CYDEV_BOOTLOADER_IO_COMP) && (COZIR_BTLDR_COMM_MODE_ENABLED)

/*******************************************************************************
* Function Name: COZIR_CyBtldrCommStart
********************************************************************************
*
* Summary:
*  Calls the CyBtldrCommStart function of the bootloader communication
*  component for the selected mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void COZIR_CyBtldrCommStart(void)
{
    #if(COZIR_SCB_MODE_UNCONFIG_CONST_CFG)
        if(COZIR_SCB_MODE_I2C_RUNTM_CFG)
        {
            COZIR_I2CCyBtldrCommStart();
        }
        else if(COZIR_SCB_MODE_SPI_RUNTM_CFG)
        {
            COZIR_SpiCyBtldrCommStart();
        }
        else if(COZIR_SCB_MODE_UART_RUNTM_CFG)
        {
            COZIR_UartCyBtldrCommStart();
        }
        else if(COZIR_SCB_MODE_EZI2C_RUNTM_CFG)
        {
             COZIR_EzI2CCyBtldrCommStart();
        }
        else
        {
            /* Unknown mode */
        }
    #elif(COZIR_SCB_MODE_I2C_CONST_CFG)
        COZIR_I2CCyBtldrCommStart();

    #elif(COZIR_SCB_MODE_SPI_CONST_CFG)
        COZIR_SpiCyBtldrCommStart();

    #elif(COZIR_SCB_MODE_UART_CONST_CFG)
        COZIR_UartCyBtldrCommStart();

    #elif(COZIR_SCB_MODE_EZI2C_CONST_CFG)
        COZIR_EzI2CCyBtldrCommStart();

    #else
        /* Unknown mode */

    #endif /* (COZIR_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: COZIR_CyBtldrCommStop
********************************************************************************
*
* Summary:
*  Calls the CyBtldrCommStop function of the bootloader communication
*  component for the selected mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void COZIR_CyBtldrCommStop(void)
{
    #if(COZIR_SCB_MODE_UNCONFIG_CONST_CFG)
        if(COZIR_SCB_MODE_I2C_RUNTM_CFG)
        {
            COZIR_I2CCyBtldrCommStop();
        }
        else if(COZIR_SCB_MODE_SPI_RUNTM_CFG)
        {
            COZIR_SpiCyBtldrCommStop();
        }
        else if(COZIR_SCB_MODE_UART_RUNTM_CFG)
        {
            COZIR_UartCyBtldrCommStop();
        }
        else if(COZIR_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            COZIR_EzI2CCyBtldrCommStop();
        }
        else
        {
            /* Unknown mode */
        }
    #elif(COZIR_SCB_MODE_I2C_CONST_CFG)
        COZIR_I2CCyBtldrCommStop();

    #elif(COZIR_SCB_MODE_SPI_CONST_CFG)
        COZIR_SpiCyBtldrCommStop();

    #elif(COZIR_SCB_MODE_UART_CONST_CFG)
        COZIR_UartCyBtldrCommStop();

    #elif(COZIR_SCB_MODE_EZI2C_CONST_CFG)
        COZIR_EzI2CCyBtldrCommStop();

    #else
        /* Unknown mode */

    #endif /* (COZIR_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: COZIR_CyBtldrCommReset
********************************************************************************
*
* Summary:
*  Calls the CyBtldrCommReset function of the bootloader communication
*  component for the selected mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void COZIR_CyBtldrCommReset(void)
{
    #if(COZIR_SCB_MODE_UNCONFIG_CONST_CFG)
        if(COZIR_SCB_MODE_I2C_RUNTM_CFG)
        {
            COZIR_I2CCyBtldrCommReset();
        }
        else if(COZIR_SCB_MODE_SPI_RUNTM_CFG)
        {
            COZIR_SpiCyBtldrCommReset();
        }
        else if(COZIR_SCB_MODE_UART_RUNTM_CFG)
        {
            COZIR_UartCyBtldrCommReset();
        }
        else if(COZIR_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            COZIR_EzI2CCyBtldrCommReset();
        }
        else
        {
            /* Unknown mode */
        }
    #elif(COZIR_SCB_MODE_I2C_CONST_CFG)
        COZIR_I2CCyBtldrCommReset();

    #elif(COZIR_SCB_MODE_SPI_CONST_CFG)
        COZIR_SpiCyBtldrCommReset();

    #elif(COZIR_SCB_MODE_UART_CONST_CFG)
        COZIR_UartCyBtldrCommReset();

    #elif(COZIR_SCB_MODE_EZI2C_CONST_CFG)
        COZIR_EzI2CCyBtldrCommReset();

    #else
        /* Unknown mode */

    #endif /* (COZIR_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: COZIR_CyBtldrCommRead
********************************************************************************
*
* Summary:
*  Calls the CyBtldrCommRead function of the bootloader communication
*  component for the selected mode.
*
* Parameters:
*  pData:    Pointer to storage for the block of data to be read from the
*            bootloader host
*  size:     Number of bytes to be read.
*  count:    Pointer to the variable to write the number of bytes actually
*            read.
*  timeOut:  Number of units in 10 ms to wait before returning because of a
*            timeout.
*
* Return:
*  Returns CYRET_SUCCESS if no problem was encountered or returns the value
*  that best describes the problem.
*
*******************************************************************************/
cystatus COZIR_CyBtldrCommRead(uint8 pData[], uint16 size, uint16 * count, uint8 timeOut)
{
    cystatus status;

    #if(COZIR_SCB_MODE_UNCONFIG_CONST_CFG)
        if(COZIR_SCB_MODE_I2C_RUNTM_CFG)
        {
            status = COZIR_I2CCyBtldrCommRead(pData, size, count, timeOut);
        }
        else if(COZIR_SCB_MODE_SPI_RUNTM_CFG)
        {
            status = COZIR_SpiCyBtldrCommRead(pData, size, count, timeOut);
        }
        else if(COZIR_SCB_MODE_UART_RUNTM_CFG)
        {
            status = COZIR_UartCyBtldrCommRead(pData, size, count, timeOut);
        }
        else if(COZIR_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            status = COZIR_EzI2CCyBtldrCommRead(pData, size, count, timeOut);
        }
        else
        {
            status = CYRET_INVALID_STATE; /* Unknown mode: return status */
        }

    #elif(COZIR_SCB_MODE_I2C_CONST_CFG)
        status = COZIR_I2CCyBtldrCommRead(pData, size, count, timeOut);

    #elif(COZIR_SCB_MODE_SPI_CONST_CFG)
        status = COZIR_SpiCyBtldrCommRead(pData, size, count, timeOut);

    #elif(COZIR_SCB_MODE_UART_CONST_CFG)
        status = COZIR_UartCyBtldrCommRead(pData, size, count, timeOut);

    #elif(COZIR_SCB_MODE_EZI2C_CONST_CFG)
        status = COZIR_EzI2CCyBtldrCommRead(pData, size, count, timeOut);

    #else
        status = CYRET_INVALID_STATE; /* Unknown mode: return status */

    #endif /* (COZIR_SCB_MODE_UNCONFIG_CONST_CFG) */

    return(status);
}


/*******************************************************************************
* Function Name: COZIR_CyBtldrCommWrite
********************************************************************************
*
* Summary:
*  Calls the CyBtldrCommWrite  function of the bootloader communication
*  component for the selected mode.
*
* Parameters:
*  pData:    Pointer to the block of data to be written to the bootloader host.
*  size:     Number of bytes to be written.
*  count:    Pointer to the variable to write the number of bytes actually
*            written.
*  timeOut:  Number of units in 10 ms to wait before returning because of a
*            timeout.
*
* Return:
*  Returns CYRET_SUCCESS if no problem was encountered or returns the value
*  that best describes the problem.
*
*******************************************************************************/
cystatus COZIR_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut)
{
    cystatus status;

    #if(COZIR_SCB_MODE_UNCONFIG_CONST_CFG)
        if(COZIR_SCB_MODE_I2C_RUNTM_CFG)
        {
            status = COZIR_I2CCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else if(COZIR_SCB_MODE_SPI_RUNTM_CFG)
        {
            status = COZIR_SpiCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else if(COZIR_SCB_MODE_UART_RUNTM_CFG)
        {
            status = COZIR_UartCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else if(COZIR_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            status = COZIR_EzI2CCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else
        {
            status = CYRET_INVALID_STATE; /* Unknown mode */
        }
    #elif(COZIR_SCB_MODE_I2C_CONST_CFG)
        status = COZIR_I2CCyBtldrCommWrite(pData, size, count, timeOut);

    #elif(COZIR_SCB_MODE_SPI_CONST_CFG)
        status = COZIR_SpiCyBtldrCommWrite(pData, size, count, timeOut);

    #elif(COZIR_SCB_MODE_UART_CONST_CFG)
        status = COZIR_UartCyBtldrCommWrite(pData, size, count, timeOut);

    #elif(COZIR_SCB_MODE_EZI2C_CONST_CFG)
        status = COZIR_EzI2CCyBtldrCommWrite(pData, size, count, timeOut);

    #else
        status = CYRET_INVALID_STATE; /* Unknown mode */

    #endif /* (COZIR_SCB_MODE_UNCONFIG_CONST_CFG) */

    return(status);
}

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (COZIR_BTLDR_COMM_MODE_ENABLED) */


/* [] END OF FILE */
