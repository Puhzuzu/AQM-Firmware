/*******************************************************************************
* File Name: COZIR_PM.c
* Version 2.0
*
* Description:
*  This file provides the source code to the Power Management support for
*  the SCB Component.
*
* Note:
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "COZIR.h"
#include "COZIR_PVT.h"

#if(COZIR_SCB_MODE_I2C_INC)
    #include "COZIR_I2C_PVT.h"
#endif /* (COZIR_SCB_MODE_I2C_INC) */

#if(COZIR_SCB_MODE_EZI2C_INC)
    #include "COZIR_EZI2C_PVT.h"
#endif /* (COZIR_SCB_MODE_EZI2C_INC) */

#if(COZIR_SCB_MODE_SPI_INC || COZIR_SCB_MODE_UART_INC)
    #include "COZIR_SPI_UART_PVT.h"
#endif /* (COZIR_SCB_MODE_SPI_INC || COZIR_SCB_MODE_UART_INC) */


/***************************************
*   Backup Structure declaration
***************************************/

#if(COZIR_SCB_MODE_UNCONFIG_CONST_CFG || \
   (COZIR_SCB_MODE_I2C_CONST_CFG   && (!COZIR_I2C_WAKE_ENABLE_CONST))   || \
   (COZIR_SCB_MODE_EZI2C_CONST_CFG && (!COZIR_EZI2C_WAKE_ENABLE_CONST)) || \
   (COZIR_SCB_MODE_SPI_CONST_CFG   && (!COZIR_SPI_WAKE_ENABLE_CONST))   || \
   (COZIR_SCB_MODE_UART_CONST_CFG  && (!COZIR_UART_WAKE_ENABLE_CONST)))

    COZIR_BACKUP_STRUCT COZIR_backup =
    {
        0u, /* enableState */
    };
#endif


/*******************************************************************************
* Function Name: COZIR_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component to enter Deep Sleep.
*  The "Enable wakeup from Sleep Mode" selection has an influence on
*  this function implementation.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void COZIR_Sleep(void)
{
#if(COZIR_SCB_MODE_UNCONFIG_CONST_CFG)

    if(COZIR_SCB_WAKE_ENABLE_CHECK)
    {
        if(COZIR_SCB_MODE_I2C_RUNTM_CFG)
        {
            COZIR_I2CSaveConfig();
        }
        else if(COZIR_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            COZIR_EzI2CSaveConfig();
        }
    #if(!COZIR_CY_SCBIP_V1)
        else if(COZIR_SCB_MODE_SPI_RUNTM_CFG)
        {
            COZIR_SpiSaveConfig();
        }
        else if(COZIR_SCB_MODE_UART_RUNTM_CFG)
        {
            COZIR_UartSaveConfig();
        }
    #endif /* (!COZIR_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        COZIR_backup.enableState = (uint8) COZIR_GET_CTRL_ENABLED;

        if(0u != COZIR_backup.enableState)
        {
            COZIR_Stop();
        }
    }

#else

    #if (COZIR_SCB_MODE_I2C_CONST_CFG && COZIR_I2C_WAKE_ENABLE_CONST)
        COZIR_I2CSaveConfig();

    #elif (COZIR_SCB_MODE_EZI2C_CONST_CFG && COZIR_EZI2C_WAKE_ENABLE_CONST)
        COZIR_EzI2CSaveConfig();

    #elif (COZIR_SCB_MODE_SPI_CONST_CFG && COZIR_SPI_WAKE_ENABLE_CONST)
        COZIR_SpiSaveConfig();

    #elif (COZIR_SCB_MODE_UART_CONST_CFG && COZIR_UART_WAKE_ENABLE_CONST)
        COZIR_UartSaveConfig();

    #else

        COZIR_backup.enableState = (uint8) COZIR_GET_CTRL_ENABLED;

        if(0u != COZIR_backup.enableState)
        {
            COZIR_Stop();
        }

    #endif /* defined (COZIR_SCB_MODE_I2C_CONST_CFG) && (COZIR_I2C_WAKE_ENABLE_CONST) */

#endif /* (COZIR_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: COZIR_Wakeup
********************************************************************************
*
* Summary:
*  Prepares the component for the Active mode operation after exiting
*  Deep Sleep. The "Enable wakeup from Sleep Mode" option has an influence
*  on this function implementation.
*  This function should not be called after exiting Sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void COZIR_Wakeup(void)
{
#if(COZIR_SCB_MODE_UNCONFIG_CONST_CFG)

    if(COZIR_SCB_WAKE_ENABLE_CHECK)
    {
        if(COZIR_SCB_MODE_I2C_RUNTM_CFG)
        {
            COZIR_I2CRestoreConfig();
        }
        else if(COZIR_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            COZIR_EzI2CRestoreConfig();
        }
    #if(!COZIR_CY_SCBIP_V1)
        else if(COZIR_SCB_MODE_SPI_RUNTM_CFG)
        {
            COZIR_SpiRestoreConfig();
        }
        else if(COZIR_SCB_MODE_UART_RUNTM_CFG)
        {
            COZIR_UartRestoreConfig();
        }
    #endif /* (!COZIR_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        if(0u != COZIR_backup.enableState)
        {
            COZIR_Enable();
        }
    }

#else

    #if (COZIR_SCB_MODE_I2C_CONST_CFG  && COZIR_I2C_WAKE_ENABLE_CONST)
        COZIR_I2CRestoreConfig();

    #elif (COZIR_SCB_MODE_EZI2C_CONST_CFG && COZIR_EZI2C_WAKE_ENABLE_CONST)
        COZIR_EzI2CRestoreConfig();

    #elif (COZIR_SCB_MODE_SPI_CONST_CFG && COZIR_SPI_WAKE_ENABLE_CONST)
        COZIR_SpiRestoreConfig();

    #elif (COZIR_SCB_MODE_UART_CONST_CFG && COZIR_UART_WAKE_ENABLE_CONST)
        COZIR_UartRestoreConfig();

    #else

        if(0u != COZIR_backup.enableState)
        {
            COZIR_Enable();
        }

    #endif /* (COZIR_I2C_WAKE_ENABLE_CONST) */

#endif /* (COZIR_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/* [] END OF FILE */
