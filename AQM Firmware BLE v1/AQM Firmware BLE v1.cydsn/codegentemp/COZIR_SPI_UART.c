/*******************************************************************************
* File Name: COZIR_SPI_UART.c
* Version 2.0
*
* Description:
*  This file provides the source code to the API for the SCB Component in
*  SPI and UART modes.
*
* Note:
*
*******************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "COZIR_PVT.h"
#include "COZIR_SPI_UART_PVT.h"

/***************************************
*        SPI/UART Private Vars
***************************************/

#if(COZIR_INTERNAL_RX_SW_BUFFER_CONST)
    volatile uint32 COZIR_rxBufferHead;
    volatile uint32 COZIR_rxBufferTail;
    volatile uint8  COZIR_rxBufferOverflow;
#endif /* (COZIR_INTERNAL_RX_SW_BUFFER_CONST) */

#if(COZIR_INTERNAL_TX_SW_BUFFER_CONST)
    volatile uint32 COZIR_txBufferHead;
    volatile uint32 COZIR_txBufferTail;
#endif /* (COZIR_INTERNAL_TX_SW_BUFFER_CONST) */

#if(COZIR_INTERNAL_RX_SW_BUFFER)
    /* Add one element to the buffer to receive full packet. One byte in receive buffer is always empty */
    volatile uint8 COZIR_rxBufferInternal[COZIR_RX_BUFFER_SIZE];
#endif /* (COZIR_INTERNAL_RX_SW_BUFFER) */

#if(COZIR_INTERNAL_TX_SW_BUFFER)
    volatile uint8 COZIR_txBufferInternal[COZIR_TX_BUFFER_SIZE];
#endif /* (COZIR_INTERNAL_TX_SW_BUFFER) */


#if(COZIR_RX_DIRECTION)

    /*******************************************************************************
    * Function Name: COZIR_SpiUartReadRxData
    ********************************************************************************
    *
    * Summary:
    *  Retrieves the next data element from the receive buffer.
    *   - RX software buffer is disabled: Returns data element retrieved from
    *     RX FIFO. Undefined data will be returned if the RX FIFO is empty.
    *   - RX software buffer is enabled: Returns data element from the software
    *     receive buffer. Zero value is returned if the software receive buffer
    *     is empty.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  Next data element from the receive buffer.
    *
    * Global Variables:
    *  Look into COZIR_SpiInit for description.
    *
    *******************************************************************************/
    uint32 COZIR_SpiUartReadRxData(void)
    {
        uint32 rxData = 0u;

        #if(COZIR_INTERNAL_RX_SW_BUFFER_CONST)
            uint32 locTail;
        #endif /* (COZIR_INTERNAL_RX_SW_BUFFER_CONST) */

        #if(COZIR_CHECK_RX_SW_BUFFER)
        {
            if(COZIR_rxBufferHead != COZIR_rxBufferTail)
            {
                /* There is data in RX software buffer */

                /* Calculate index to read from */
                locTail = (COZIR_rxBufferTail + 1u);

                if(COZIR_RX_BUFFER_SIZE == locTail)
                {
                    locTail = 0u;
                }

                /* Get data from RX software buffer */
                rxData = COZIR_GetWordFromRxBuffer(locTail);

                /* Change index in the buffer */
                COZIR_rxBufferTail = locTail;
            }
        }
        #else
        {
            rxData = COZIR_RX_FIFO_RD_REG; /* Read data from RX FIFO */
        }
        #endif

        return(rxData);
    }


    /*******************************************************************************
    * Function Name: COZIR_SpiUartGetRxBufferSize
    ********************************************************************************
    *
    * Summary:
    *  Returns the number of received data elements in the receive buffer.
    *   - RX software buffer disabled: returns the number of used entries in
    *     RX FIFO.
    *   - RX software buffer enabled: returns the number of elements which were
    *     placed in the receive buffer. This does not include the hardware RX FIFO.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  Number of received data elements
    *
    *******************************************************************************/
    uint32 COZIR_SpiUartGetRxBufferSize(void)
    {
        uint32 size;
        #if(COZIR_INTERNAL_RX_SW_BUFFER_CONST)
            uint32 locHead;
        #endif /* (COZIR_INTERNAL_RX_SW_BUFFER_CONST) */

        #if(COZIR_CHECK_RX_SW_BUFFER)
        {
            locHead = COZIR_rxBufferHead;

            if(locHead >= COZIR_rxBufferTail)
            {
                size = (locHead - COZIR_rxBufferTail);
            }
            else
            {
                size = (locHead + (COZIR_RX_BUFFER_SIZE - COZIR_rxBufferTail));
            }
        }
        #else
        {
            size = COZIR_GET_RX_FIFO_ENTRIES;
        }
        #endif

        return(size);
    }


    /*******************************************************************************
    * Function Name: COZIR_SpiUartClearRxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Clears the receive buffer and RX FIFO.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void COZIR_SpiUartClearRxBuffer(void)
    {
        #if(COZIR_INTERNAL_RX_SW_BUFFER_CONST)
            uint32 intSourceMask;
        #endif /* (COZIR_INTERNAL_RX_SW_BUFFER_CONST) */

        #if(COZIR_CHECK_RX_SW_BUFFER)
        {
            intSourceMask = COZIR_SpiUartDisableIntRx();

            COZIR_CLEAR_RX_FIFO;

            /* Flush RX software buffer */
            COZIR_rxBufferHead     = COZIR_rxBufferTail;
            COZIR_rxBufferOverflow = 0u;

            /* End RX transfer */
            COZIR_ClearRxInterruptSource(COZIR_INTR_RX_ALL);

            COZIR_SpiUartEnableIntRx(intSourceMask);
        }
        #else
        {
            COZIR_CLEAR_RX_FIFO;
        }
        #endif
    }

#endif /* (COZIR_RX_DIRECTION) */


#if(COZIR_TX_DIRECTION)

    /*******************************************************************************
    * Function Name: COZIR_SpiUartWriteTxData
    ********************************************************************************
    *
    * Summary:
    *  Places a data entry into the transmit buffer to be sent at the next available
    *  bus time.
    *  This function is blocking and waits until there is space available to put the
    *  requested data in the transmit buffer.
    *
    * Parameters:
    *  txDataByte: the data to be transmitted.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void COZIR_SpiUartWriteTxData(uint32 txData)
    {
        #if(COZIR_INTERNAL_TX_SW_BUFFER_CONST)
            uint32 locHead;
            uint32 intSourceMask;
        #endif /* (COZIR_INTERNAL_TX_SW_BUFFER_CONST) */

        #if(COZIR_CHECK_TX_SW_BUFFER)
        {
            /* Head index to put data */
            locHead = (COZIR_txBufferHead + 1u);

            /* Adjust TX software buffer index */
            if(COZIR_TX_BUFFER_SIZE == locHead)
            {
                locHead = 0u;
            }

            while(locHead == COZIR_txBufferTail)
            {
                /* Wait for space in TX software buffer */
            }

            /* TX software buffer has at least one room */

            if((COZIR_txBufferHead == COZIR_txBufferTail) &&
               (COZIR_SPI_UART_FIFO_SIZE != COZIR_GET_TX_FIFO_ENTRIES))
            {
                /* TX software buffer is empty: put data directly in TX FIFO */
                COZIR_TX_FIFO_WR_REG = txData;
            }
            /* Put data in TX software buffer */
            else
            {
                /* Clear old status of INTR_TX_NOT_FULL. It sets at the end of transfer when TX FIFO is empty. */
                COZIR_ClearTxInterruptSource(COZIR_INTR_TX_NOT_FULL);

                COZIR_PutWordInTxBuffer(locHead, txData);

                COZIR_txBufferHead = locHead;

                /* Enable interrupt to transmit */
                intSourceMask  = COZIR_INTR_TX_NOT_FULL;
                intSourceMask |= COZIR_GetTxInterruptMode();
                COZIR_SpiUartEnableIntTx(intSourceMask);
            }
        }
        #else
        {
            while(COZIR_SPI_UART_FIFO_SIZE == COZIR_GET_TX_FIFO_ENTRIES)
            {
                /* Block while TX FIFO is FULL */
            }

            COZIR_TX_FIFO_WR_REG = txData;
        }
        #endif
    }


    /*******************************************************************************
    * Function Name: COZIR_SpiUartPutArray
    ********************************************************************************
    *
    * Summary:
    *  Places an array of data into the transmit buffer to be sent.
    *  This function is blocking and waits until there is a space available to put
    *  all the requested data in the transmit buffer. The array size can be greater
    *  than transmit buffer size.
    *
    * Parameters:
    *  wrBuf:  pointer to an array with data to be placed in transmit buffer.
    *  count:  number of data elements to be placed in the transmit buffer.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void COZIR_SpiUartPutArray(const uint8 wrBuf[], uint32 count)
    {
        uint32 i;

        for(i=0u; i < count; i++)
        {
            COZIR_SpiUartWriteTxData((uint32) wrBuf[i]);
        }
    }


    /*******************************************************************************
    * Function Name: COZIR_SpiUartGetTxBufferSize
    ********************************************************************************
    *
    * Summary:
    * Returns the number of elements currently in the transmit buffer.
    *  - TX software buffer is disabled: returns the number of used entries in
    *    TX FIFO.
    *  - TX software buffer is enabled: returns the number of elements currently
    *    used in the transmit buffer. This number does not include used entries in
    *    the TX FIFO. The transmit buffer size is zero until the TX FIFO is
    *    not full.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  Number of data elements ready to transmit.
    *
    *******************************************************************************/
    uint32 COZIR_SpiUartGetTxBufferSize(void)
    {
        uint32 size;
        #if(COZIR_INTERNAL_TX_SW_BUFFER_CONST)
            uint32 locTail;
        #endif /* (COZIR_INTERNAL_TX_SW_BUFFER_CONST) */

        #if(COZIR_CHECK_TX_SW_BUFFER)
        {
            /* Get current Tail index */
            locTail = COZIR_txBufferTail;

            if(COZIR_txBufferHead >= locTail)
            {
                size = (COZIR_txBufferHead - locTail);
            }
            else
            {
                size = (COZIR_txBufferHead + (COZIR_TX_BUFFER_SIZE - locTail));
            }
        }
        #else
        {
            size = COZIR_GET_TX_FIFO_ENTRIES;
        }
        #endif

        return(size);
    }


    /*******************************************************************************
    * Function Name: COZIR_SpiUartClearTxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Clears the transmit buffer and TX FIFO.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void COZIR_SpiUartClearTxBuffer(void)
    {
        #if(COZIR_INTERNAL_TX_SW_BUFFER_CONST)
            uint32 intSourceMask;
        #endif /* (COZIR_INTERNAL_TX_SW_BUFFER_CONST) */

        #if(COZIR_CHECK_TX_SW_BUFFER)
        {
            intSourceMask = COZIR_SpiUartDisableIntTx();

            COZIR_CLEAR_TX_FIFO;

            /* Flush TX software buffer */
            COZIR_txBufferHead = COZIR_txBufferTail;

            /* End TX transfer if it is in progress */
            intSourceMask &= (uint32) ~COZIR_INTR_TX_NOT_FULL;

            COZIR_SpiUartEnableIntTx(intSourceMask);
        }
        #else
        {
            COZIR_CLEAR_TX_FIFO;
        }
        #endif
    }

#endif /* (COZIR_TX_DIRECTION) */


/*******************************************************************************
* Function Name: COZIR_SpiUartDisableIntRx
********************************************************************************
*
* Summary:
*  Disables the RX interrupt sources.
*
* Parameters:
*  None
*
* Return:
*  Returns the RX interrupt sources enabled before the function call.
*
*******************************************************************************/
uint32 COZIR_SpiUartDisableIntRx(void)
{
    uint32 intSource;

    intSource = COZIR_GetRxInterruptMode();

    COZIR_SetRxInterruptMode(COZIR_NO_INTR_SOURCES);

    return(intSource);
}


/*******************************************************************************
* Function Name: COZIR_SpiUartDisableIntTx
********************************************************************************
*
* Summary:
*  Disables TX interrupt sources.
*
* Parameters:
*  None
*
* Return:
*  Returns TX interrupt sources enabled before function call.
*
*******************************************************************************/
uint32 COZIR_SpiUartDisableIntTx(void)
{
    uint32 intSourceMask;

    intSourceMask = COZIR_GetTxInterruptMode();

    COZIR_SetTxInterruptMode(COZIR_NO_INTR_SOURCES);

    return(intSourceMask);
}


#if(COZIR_SCB_MODE_UNCONFIG_CONST_CFG)
    /*******************************************************************************
    * Function Name: COZIR_PutWordInRxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Stores a byte/word into the RX buffer.
    *  Only available in the Unconfigured operation mode.
    *
    * Parameters:
    *  index:      index to store data byte/word in the RX buffer.
    *  rxDataByte: byte/word to store.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void COZIR_PutWordInRxBuffer(uint32 idx, uint32 rxDataByte)
    {
        /* Put data in buffer */
        if(COZIR_ONE_BYTE_WIDTH == COZIR_rxDataBits)
        {
            COZIR_rxBuffer[idx] = ((uint8) rxDataByte);
        }
        else
        {
            COZIR_rxBuffer[(uint32)(idx << 1u)]      = LO8(LO16(rxDataByte));
            COZIR_rxBuffer[(uint32)(idx << 1u) + 1u] = HI8(LO16(rxDataByte));
        }
    }


    /*******************************************************************************
    * Function Name: COZIR_GetWordFromRxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Reads byte/word from RX buffer.
    *  Only available in the Unconfigured operation mode.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  Returns byte/word read from RX buffer.
    *
    *******************************************************************************/
    uint32 COZIR_GetWordFromRxBuffer(uint32 idx)
    {
        uint32 value;

        if(COZIR_ONE_BYTE_WIDTH == COZIR_rxDataBits)
        {
            value = COZIR_rxBuffer[idx];
        }
        else
        {
            value  = (uint32) COZIR_rxBuffer[(uint32)(idx << 1u)];
            value |= (uint32) ((uint32)COZIR_rxBuffer[(uint32)(idx << 1u) + 1u] << 8u);
        }

        return(value);
    }


    /*******************************************************************************
    * Function Name: COZIR_PutWordInTxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Stores byte/word into the TX buffer.
    *  Only available in the Unconfigured operation mode.
    *
    * Parameters:
    *  idx:        index to store data byte/word in the TX buffer.
    *  txDataByte: byte/word to store.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void COZIR_PutWordInTxBuffer(uint32 idx, uint32 txDataByte)
    {
        /* Put data in buffer */
        if(COZIR_ONE_BYTE_WIDTH == COZIR_txDataBits)
        {
            COZIR_txBuffer[idx] = ((uint8) txDataByte);
        }
        else
        {
            COZIR_txBuffer[(uint32)(idx << 1u)]      = LO8(LO16(txDataByte));
            COZIR_txBuffer[(uint32)(idx << 1u) + 1u] = HI8(LO16(txDataByte));
        }
    }


    /*******************************************************************************
    * Function Name: COZIR_GetWordFromTxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Reads byte/word from the TX buffer.
    *  Only available in the Unconfigured operation mode.
    *
    * Parameters:
    *  idx: index to get data byte/word from the TX buffer.
    *
    * Return:
    *  Returns byte/word read from the TX buffer.
    *
    *******************************************************************************/
    uint32 COZIR_GetWordFromTxBuffer(uint32 idx)
    {
        uint32 value;

        if(COZIR_ONE_BYTE_WIDTH == COZIR_txDataBits)
        {
            value = (uint32) COZIR_txBuffer[idx];
        }
        else
        {
            value  = (uint32) COZIR_txBuffer[(uint32)(idx << 1u)];
            value |= (uint32) ((uint32) COZIR_txBuffer[(uint32)(idx << 1u) + 1u] << 8u);
        }

        return(value);
    }

#endif /* (COZIR_SCB_MODE_UNCONFIG_CONST_CFG) */


/* [] END OF FILE */
