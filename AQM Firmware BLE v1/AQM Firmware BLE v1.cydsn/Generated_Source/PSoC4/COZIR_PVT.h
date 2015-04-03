/*******************************************************************************
* File Name: .h
* Version 2.0
*
* Description:
*  This private file provides constants and parameter values for the
*  SCB Component.
*  Please do not use this file or its content in your project.
*
* Note:
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_PVT_COZIR_H)
#define CY_SCB_PVT_COZIR_H

#include "COZIR.h"


/***************************************
*     Private Function Prototypes
***************************************/

/* APIs to service INTR_I2C_EC register */
#define COZIR_SetI2CExtClkInterruptMode(interruptMask) COZIR_WRITE_INTR_I2C_EC_MASK(interruptMask)
#define COZIR_ClearI2CExtClkInterruptSource(interruptMask) COZIR_CLEAR_INTR_I2C_EC(interruptMask)
#define COZIR_GetI2CExtClkInterruptSource()                (COZIR_INTR_I2C_EC_REG)
#define COZIR_GetI2CExtClkInterruptMode()                  (COZIR_INTR_I2C_EC_MASK_REG)
#define COZIR_GetI2CExtClkInterruptSourceMasked()          (COZIR_INTR_I2C_EC_MASKED_REG)

#if (!COZIR_CY_SCBIP_V1)
    /* APIs to service INTR_SPI_EC register */
    #define COZIR_SetSpiExtClkInterruptMode(interruptMask) \
                                                                COZIR_WRITE_INTR_SPI_EC_MASK(interruptMask)
    #define COZIR_ClearSpiExtClkInterruptSource(interruptMask) \
                                                                COZIR_CLEAR_INTR_SPI_EC(interruptMask)
    #define COZIR_GetExtSpiClkInterruptSource()                 (COZIR_INTR_SPI_EC_REG)
    #define COZIR_GetExtSpiClkInterruptMode()                   (COZIR_INTR_SPI_EC_MASK_REG)
    #define COZIR_GetExtSpiClkInterruptSourceMasked()           (COZIR_INTR_SPI_EC_MASKED_REG)
#endif /* (!COZIR_CY_SCBIP_V1) */

#if(COZIR_SCB_MODE_UNCONFIG_CONST_CFG)
    extern void COZIR_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask);
#endif /* (COZIR_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Vars with External Linkage
***************************************/

#if !defined (CY_REMOVE_COZIR_CUSTOM_INTR_HANDLER)
    extern cyisraddress COZIR_customIntrHandler;
#endif /* !defined (CY_REMOVE_COZIR_CUSTOM_INTR_HANDLER) */

extern COZIR_BACKUP_STRUCT COZIR_backup;

#if(COZIR_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    extern uint8 COZIR_scbMode;
    extern uint8 COZIR_scbEnableWake;
    extern uint8 COZIR_scbEnableIntr;

    /* I2C configuration variables */
    extern uint8 COZIR_mode;
    extern uint8 COZIR_acceptAddr;

    /* SPI/UART configuration variables */
    extern volatile uint8 * COZIR_rxBuffer;
    extern uint8   COZIR_rxDataBits;
    extern uint32  COZIR_rxBufferSize;

    extern volatile uint8 * COZIR_txBuffer;
    extern uint8   COZIR_txDataBits;
    extern uint32  COZIR_txBufferSize;

    /* EZI2C configuration variables */
    extern uint8 COZIR_numberOfAddr;
    extern uint8 COZIR_subAddrSize;
#endif /* (COZIR_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*        Conditional Macro
****************************************/

#if(COZIR_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Defines run time operation mode */
    #define COZIR_SCB_MODE_I2C_RUNTM_CFG     (COZIR_SCB_MODE_I2C      == COZIR_scbMode)
    #define COZIR_SCB_MODE_SPI_RUNTM_CFG     (COZIR_SCB_MODE_SPI      == COZIR_scbMode)
    #define COZIR_SCB_MODE_UART_RUNTM_CFG    (COZIR_SCB_MODE_UART     == COZIR_scbMode)
    #define COZIR_SCB_MODE_EZI2C_RUNTM_CFG   (COZIR_SCB_MODE_EZI2C    == COZIR_scbMode)
    #define COZIR_SCB_MODE_UNCONFIG_RUNTM_CFG \
                                                        (COZIR_SCB_MODE_UNCONFIG == COZIR_scbMode)

    /* Defines wakeup enable */
    #define COZIR_SCB_WAKE_ENABLE_CHECK       (0u != COZIR_scbEnableWake)
#endif /* (COZIR_SCB_MODE_UNCONFIG_CONST_CFG) */

/* Defines maximum number of SCB pins */
#if (!COZIR_CY_SCBIP_V1)
    #define COZIR_SCB_PINS_NUMBER    (7u)
#else
    #define COZIR_SCB_PINS_NUMBER    (2u)
#endif /* (!COZIR_CY_SCBIP_V1) */

#endif /* (CY_SCB_PVT_COZIR_H) */


/* [] END OF FILE */
