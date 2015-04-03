/*******************************************************************************
* File Name: COZIR_SPI_UART_PVT.h
* Version 2.0
*
* Description:
*  This private file provides constants and parameter values for the
*  SCB Component in SPI and UART modes.
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

#if !defined(CY_SCB_SPI_UART_PVT_COZIR_H)
#define CY_SCB_SPI_UART_PVT_COZIR_H

#include "COZIR_SPI_UART.h"


/***************************************
*     Internal Global Vars
***************************************/

#if(COZIR_INTERNAL_RX_SW_BUFFER_CONST)
    extern volatile uint32  COZIR_rxBufferHead;
    extern volatile uint32  COZIR_rxBufferTail;
    extern volatile uint8   COZIR_rxBufferOverflow;
#endif /* (COZIR_INTERNAL_RX_SW_BUFFER_CONST) */

#if(COZIR_INTERNAL_TX_SW_BUFFER_CONST)
    extern volatile uint32  COZIR_txBufferHead;
    extern volatile uint32  COZIR_txBufferTail;
#endif /* (COZIR_INTERNAL_TX_SW_BUFFER_CONST) */

#if(COZIR_INTERNAL_RX_SW_BUFFER)
    extern volatile uint8 COZIR_rxBufferInternal[COZIR_RX_BUFFER_SIZE];
#endif /* (COZIR_INTERNAL_RX_SW_BUFFER) */

#if(COZIR_INTERNAL_TX_SW_BUFFER)
    extern volatile uint8 COZIR_txBufferInternal[COZIR_TX_BUFFER_SIZE];
#endif /* (COZIR_INTERNAL_TX_SW_BUFFER) */


/***************************************
*     Private Function Prototypes
***************************************/

#if(COZIR_SCB_MODE_SPI_CONST_CFG)
    void COZIR_SpiInit(void);
#endif /* (COZIR_SCB_MODE_SPI_CONST_CFG) */

#if(COZIR_SPI_WAKE_ENABLE_CONST)
    void COZIR_SpiSaveConfig(void);
    void COZIR_SpiRestoreConfig(void);
#endif /* (COZIR_SPI_WAKE_ENABLE_CONST) */

#if(COZIR_SCB_MODE_UART_CONST_CFG)
    void COZIR_UartInit(void);
#endif /* (COZIR_SCB_MODE_UART_CONST_CFG) */

#if(COZIR_UART_WAKE_ENABLE_CONST)
    void COZIR_UartSaveConfig(void);
    void COZIR_UartRestoreConfig(void);
    #define COZIR_UartStop() \
        do{                             \
            COZIR_UART_RX_CTRL_REG &= ~COZIR_UART_RX_CTRL_SKIP_START; \
        }while(0)
#else
        #define COZIR_UartStop() do{ /* Does nothing */ }while(0)

#endif /* (COZIR_UART_WAKE_ENABLE_CONST) */

/* Interrupt processing */
#define COZIR_SpiUartEnableIntRx(intSourceMask)  COZIR_SetRxInterruptMode(intSourceMask)
#define COZIR_SpiUartEnableIntTx(intSourceMask)  COZIR_SetTxInterruptMode(intSourceMask)
uint32  COZIR_SpiUartDisableIntRx(void);
uint32  COZIR_SpiUartDisableIntTx(void);


/***************************************
*         UART API Constants
***************************************/

/* UART RX and TX position to be used in COZIR_SetPins() */
#define COZIR_UART_RX_PIN_ENABLE    (COZIR_UART_RX)
#define COZIR_UART_TX_PIN_ENABLE    (COZIR_UART_TX)

/* UART RTS and CTS position to be used in  COZIR_SetPins() */
#define COZIR_UART_RTS_PIN_ENABLE    (0x10u)
#define COZIR_UART_CTS_PIN_ENABLE    (0x20u)

#endif /* (CY_SCB_SPI_UART_PVT_COZIR_H) */


/* [] END OF FILE */
