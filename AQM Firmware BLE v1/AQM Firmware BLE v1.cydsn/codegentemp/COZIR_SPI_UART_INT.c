/*******************************************************************************
* File Name: COZIR_SPI_UART_INT.c
* Version 2.0
*
* Description:
*  This file provides the source code to the Interrupt Service Routine for
*  the SCB Component in SPI and UART modes.
*
* Note:
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "COZIR_PVT.h"
#include "COZIR_SPI_UART_PVT.h"


/*******************************************************************************
* Function Name: COZIR_SPI_UART_ISR
********************************************************************************
*
* Summary:
*  Handles the Interrupt Service Routine for the SCB SPI or UART modes.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
CY_ISR(COZIR_SPI_UART_ISR)
{
#if(COZIR_INTERNAL_RX_SW_BUFFER_CONST)
    uint32 locHead;
    uint32 dataRx;
#endif /* (COZIR_INTERNAL_RX_SW_BUFFER_CONST) */

#if(COZIR_INTERNAL_TX_SW_BUFFER_CONST)
    uint32 locTail;
#endif /* (COZIR_INTERNAL_TX_SW_BUFFER_CONST) */

    if(NULL != COZIR_customIntrHandler)
    {
        COZIR_customIntrHandler();
    }

    #if(COZIR_CHECK_SPI_WAKE_ENABLE)
    {
        /* Clear SPI wakeup source */
        COZIR_ClearSpiExtClkInterruptSource(COZIR_INTR_SPI_EC_WAKE_UP);
    }
    #endif

    #if(COZIR_CHECK_RX_SW_BUFFER)
    {
        if(COZIR_CHECK_INTR_RX_MASKED(COZIR_INTR_RX_NOT_EMPTY))
        {
            while(0u != COZIR_GET_RX_FIFO_ENTRIES)
            {
                /* Get data from RX FIFO */
                dataRx = COZIR_RX_FIFO_RD_REG;

                /* Move local head index */
                locHead = (COZIR_rxBufferHead + 1u);

                /* Adjust local head index */
                if(COZIR_RX_BUFFER_SIZE == locHead)
                {
                    locHead = 0u;
                }

                if(locHead == COZIR_rxBufferTail)
                {
                    /* Overflow: through away new data */
                    COZIR_rxBufferOverflow = (uint8) COZIR_INTR_RX_OVERFLOW;
                }
                else
                {
                    /* Store received data */
                    COZIR_PutWordInRxBuffer(locHead, dataRx);

                    /* Move head index */
                    COZIR_rxBufferHead = locHead;
                }
            }

            COZIR_ClearRxInterruptSource(COZIR_INTR_RX_NOT_EMPTY);
        }
    }
    #endif


    #if(COZIR_CHECK_TX_SW_BUFFER)
    {
        if(COZIR_CHECK_INTR_TX_MASKED(COZIR_INTR_TX_NOT_FULL))
        {
            /* Put data into TX FIFO */
            while(COZIR_SPI_UART_FIFO_SIZE != COZIR_GET_TX_FIFO_ENTRIES)
            {
                /* Check for room in TX software buffer */
                if(COZIR_txBufferHead != COZIR_txBufferTail)
                {
                    /* Move local tail index */
                    locTail = (COZIR_txBufferTail + 1u);

                    /* Adjust local tail index */
                    if(COZIR_TX_BUFFER_SIZE == locTail)
                    {
                        locTail = 0u;
                    }

                    /* Put data into TX FIFO */
                    COZIR_TX_FIFO_WR_REG = COZIR_GetWordFromTxBuffer(locTail);

                    /* Move tail index */
                    COZIR_txBufferTail = locTail;
                }
                else
                {
                    /* TX software buffer is empty: complete transfer */
                    COZIR_DISABLE_INTR_TX(COZIR_INTR_TX_NOT_FULL);
                    break;
                }
            }

            COZIR_ClearTxInterruptSource(COZIR_INTR_TX_NOT_FULL);
        }
    }
    #endif
}


/* [] END OF FILE */
