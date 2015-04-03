/*******************************************************************************
* File Name: COZIR_BOOT.h
* Version 2.0
*
* Description:
*  This file provides constants and parameter values for the bootloader
*  communication interface of SCB component.
*
* Note:
*
********************************************************************************
* Copyright 2014, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_BOOT_COZIR_H)
#define CY_SCB_BOOT_COZIR_H

#include "COZIR_PVT.h"

#if (COZIR_SCB_MODE_I2C_INC)
    #include "COZIR_I2C.h"
#endif /* (COZIR_SCB_MODE_I2C_INC) */

#if (COZIR_SCB_MODE_EZI2C_INC)
    #include "COZIR_EZI2C.h"
#endif /* (COZIR_SCB_MODE_EZI2C_INC) */

#if (COZIR_SCB_MODE_SPI_INC || COZIR_SCB_MODE_UART_INC)
    #include "COZIR_SPI_UART.h"
#endif /* (COZIR_SCB_MODE_SPI_INC || COZIR_SCB_MODE_UART_INC) */


/***************************************
*        Function Prototypes
***************************************/

/* Bootloader communication interface enable */
#define COZIR_BTLDR_COMM_ENABLED ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_COZIR) || \
                                             (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))

#if (COZIR_SCB_MODE_I2C_INC)

    #define COZIR_I2C_BTLDR_COMM_ENABLED     (COZIR_BTLDR_COMM_ENABLED && \
                                                            (COZIR_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             COZIR_I2C_SLAVE_CONST))

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (COZIR_I2C_BTLDR_COMM_ENABLED)
    /* Bootloader physical layer functions */
    void COZIR_I2CCyBtldrCommStart(void);
    void COZIR_I2CCyBtldrCommStop (void);
    void COZIR_I2CCyBtldrCommReset(void);
    cystatus COZIR_I2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus COZIR_I2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Size of Read/Write buffers for I2C bootloader  */
    #define COZIR_I2C_BTLDR_SIZEOF_READ_BUFFER   (64u)
    #define COZIR_I2C_BTLDR_SIZEOF_WRITE_BUFFER  (64u)
    #define COZIR_I2C_MIN_UINT16(a, b)           ( ((uint16)(a) < (uint16) (b)) ? \
                                                                    ((uint32) (a)) : ((uint32) (b)) )
    #define COZIR_WAIT_1_MS                      (1u)
#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (COZIR_I2C_BTLDR_COMM_ENABLED) */

#endif /* (COZIR_SCB_MODE_I2C_INC) */


#if (COZIR_SCB_MODE_EZI2C_INC)

    /* Provide EMPTY bootloader communication functions. EZI2C is NOT supported yet */
    #define COZIR_EZI2C_BTLDR_COMM_ENABLED   (COZIR_BTLDR_COMM_ENABLED && \
                                                         COZIR_SCB_MODE_UNCONFIG_CONST_CFG)

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (COZIR_EZI2C_BTLDR_COMM_ENABLED)
    /* Bootloader physical layer functions */
    void COZIR_EzI2CCyBtldrCommStart(void);
    void COZIR_EzI2CCyBtldrCommStop (void);
    void COZIR_EzI2CCyBtldrCommReset(void);
    cystatus COZIR_EzI2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus COZIR_EzI2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (COZIR_EZI2C_BTLDR_COMM_ENABLED) */

#endif /* (COZIR_SCB_MODE_EZI2C_INC) */

#if (COZIR_SCB_MODE_SPI_INC || COZIR_SCB_MODE_UART_INC)
    /* Provide EMPTY bootloader communication functions. SPI and UART is NOT supported yet */
    #define COZIR_SPI_BTLDR_COMM_ENABLED     (COZIR_BTLDR_COMM_ENABLED && \
                                                        COZIR_SCB_MODE_UNCONFIG_CONST_CFG)

    #define COZIR_UART_BTLDR_COMM_ENABLED    (COZIR_BTLDR_COMM_ENABLED && \
                                                        COZIR_SCB_MODE_UNCONFIG_CONST_CFG)

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (COZIR_SPI_BTLDR_COMM_ENABLED)
    /* SPI Bootloader physical layer functions */
    void COZIR_SpiCyBtldrCommStart(void);
    void COZIR_SpiCyBtldrCommStop (void);
    void COZIR_SpiCyBtldrCommReset(void);
    cystatus COZIR_SpiCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus COZIR_SpiCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (COZIR_SPI_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (COZIR_UART_BTLDR_COMM_ENABLED)
    /* UART Bootloader physical layer functions */
    void COZIR_UartCyBtldrCommStart(void);
    void COZIR_UartCyBtldrCommStop (void);
    void COZIR_UartCyBtldrCommReset(void);
    cystatus COZIR_UartCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus COZIR_UartCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (COZIR_UART_BTLDR_COMM_ENABLED) */

#endif /* (COZIR_SCB_MODE_SPI_INC || COZIR_SCB_MODE_UART_INC) */

#if !defined (COZIR_I2C_BTLDR_COMM_ENABLED)
    #define COZIR_I2C_BTLDR_COMM_ENABLED     (0u)
#endif /* (COZIR_I2C_BTLDR_COMM_ENABLED) */

#if !defined (COZIR_EZI2C_BTLDR_COMM_ENABLED)
    #define COZIR_EZI2C_BTLDR_COMM_ENABLED   (0u)
#endif /* (COZIR_EZI2C_BTLDR_COMM_ENABLED) */

#if !defined (COZIR_SPI_BTLDR_COMM_ENABLED)
    #define COZIR_SPI_BTLDR_COMM_ENABLED     (0u)
#endif /* (COZIR_SPI_BTLDR_COMM_ENABLED) */

#if !defined (COZIR_UART_BTLDR_COMM_ENABLED)
    #define COZIR_UART_BTLDR_COMM_ENABLED    (0u)
#endif /* (COZIR_UART_BTLDR_COMM_ENABLED) */

/* Bootloader enabled condition for each mode */
#define COZIR_BTLDR_COMM_MODE_ENABLED    (COZIR_I2C_BTLDR_COMM_ENABLED   || \
                                                     COZIR_EZI2C_BTLDR_COMM_ENABLED || \
                                                     COZIR_SPI_BTLDR_COMM_ENABLED   || \
                                                     COZIR_UART_BTLDR_COMM_ENABLED)

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (COZIR_BTLDR_COMM_ENABLED)
    #if (COZIR_BTLDR_COMM_MODE_ENABLED)
        /* Bootloader physical layer functions */
        void COZIR_CyBtldrCommStart(void);
        void COZIR_CyBtldrCommStop (void);
        void COZIR_CyBtldrCommReset(void);
        cystatus COZIR_CyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
        cystatus COZIR_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    #endif /* (COZIR_BTLDR_COMM_MODE_ENABLED) */

    #if (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_COZIR)
        #define CyBtldrCommStart    COZIR_CyBtldrCommStart
        #define CyBtldrCommStop     COZIR_CyBtldrCommStop
        #define CyBtldrCommReset    COZIR_CyBtldrCommReset
        #define CyBtldrCommWrite    COZIR_CyBtldrCommWrite
        #define CyBtldrCommRead     COZIR_CyBtldrCommRead
    #endif /* (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_COZIR) */
#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (COZIR_BTLDR_COMM_ENABLED) */

#endif /* (CY_SCB_BOOT_COZIR_H) */

/* [] END OF FILE */
