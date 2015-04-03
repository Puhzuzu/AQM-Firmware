/*******************************************************************************
* File Name: COZIR.c
* Version 2.0
*
* Description:
*  This file provides the source code to the API for the SCB Component.
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
*    Run Time Configuration Vars
***************************************/

/* Stores internal component configuration for Unconfigured mode */
#if(COZIR_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    uint8 COZIR_scbMode = COZIR_SCB_MODE_UNCONFIG;
    uint8 COZIR_scbEnableWake;
    uint8 COZIR_scbEnableIntr;

    /* I2C configuration variables */
    uint8 COZIR_mode;
    uint8 COZIR_acceptAddr;

    /* SPI/UART configuration variables */
    volatile uint8 * COZIR_rxBuffer;
    uint8  COZIR_rxDataBits;
    uint32 COZIR_rxBufferSize;

    volatile uint8 * COZIR_txBuffer;
    uint8  COZIR_txDataBits;
    uint32 COZIR_txBufferSize;

    /* EZI2C configuration variables */
    uint8 COZIR_numberOfAddr;
    uint8 COZIR_subAddrSize;
#endif /* (COZIR_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Common SCB Vars
***************************************/

uint8 COZIR_initVar = 0u;

#if !defined (CY_REMOVE_COZIR_CUSTOM_INTR_HANDLER)
    cyisraddress COZIR_customIntrHandler = NULL;
#endif /* !defined (CY_REMOVE_COZIR_CUSTOM_INTR_HANDLER) */


/***************************************
*    Private Function Prototypes
***************************************/

static void COZIR_ScbEnableIntr(void);
static void COZIR_ScbModeStop(void);


/*******************************************************************************
* Function Name: COZIR_Init
********************************************************************************
*
* Summary:
*  Initializes the SCB component to operate in one of the selected
*  configurations: I2C, SPI, UART or EZI2C.
*  When the configuration is set to "Unconfigured SCB", this function does
*  not do any initialization. Use mode-specific initialization APIs instead:
*  SCB_I2CInit, SCB_SpiInit, SCB_UartInit or SCB_EzI2CInit.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void COZIR_Init(void)
{
#if(COZIR_SCB_MODE_UNCONFIG_CONST_CFG)
    if(COZIR_SCB_MODE_UNCONFIG_RUNTM_CFG)
    {
        COZIR_initVar = 0u;
    }
    else
    {
        /* Initialization was done before this function call */
    }

#elif(COZIR_SCB_MODE_I2C_CONST_CFG)
    COZIR_I2CInit();

#elif(COZIR_SCB_MODE_SPI_CONST_CFG)
    COZIR_SpiInit();

#elif(COZIR_SCB_MODE_UART_CONST_CFG)
    COZIR_UartInit();

#elif(COZIR_SCB_MODE_EZI2C_CONST_CFG)
    COZIR_EzI2CInit();

#endif /* (COZIR_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: COZIR_Enable
********************************************************************************
*
* Summary:
*  Enables the SCB component operation.
*  The SCB configuration should be not changed when the component is enabled.
*  Any configuration changes should be made after disabling the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void COZIR_Enable(void)
{
#if(COZIR_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Enable SCB block, only if it is already configured */
    if(!COZIR_SCB_MODE_UNCONFIG_RUNTM_CFG)
    {
        COZIR_CTRL_REG |= COZIR_CTRL_ENABLED;

        COZIR_ScbEnableIntr();
    }
#else
    COZIR_CTRL_REG |= COZIR_CTRL_ENABLED;

    COZIR_ScbEnableIntr();
#endif /* (COZIR_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: COZIR_Start
********************************************************************************
*
* Summary:
*  Invokes SCB_Init() and SCB_Enable().
*  After this function call, the component is enabled and ready for operation.
*  When configuration is set to "Unconfigured SCB", the component must first be
*  initialized to operate in one of the following configurations: I2C, SPI, UART
*  or EZ I2C. Otherwise this function does not enable the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  COZIR_initVar - used to check initial configuration, modified
*  on first function call.
*
*******************************************************************************/
void COZIR_Start(void)
{
    if(0u == COZIR_initVar)
    {
        COZIR_Init();
        COZIR_initVar = 1u; /* Component was initialized */
    }

    COZIR_Enable();
}


/*******************************************************************************
* Function Name: COZIR_Stop
********************************************************************************
*
* Summary:
*  Disables the SCB component and its interrupt.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void COZIR_Stop(void)
{
#if(COZIR_SCB_IRQ_INTERNAL)
    COZIR_DisableInt();
#endif /* (COZIR_SCB_IRQ_INTERNAL) */

    COZIR_CTRL_REG &= (uint32) ~COZIR_CTRL_ENABLED;  /* Disable scb IP */

#if(COZIR_SCB_IRQ_INTERNAL)
    COZIR_ClearPendingInt();
#endif /* (COZIR_SCB_IRQ_INTERNAL) */

    COZIR_ScbModeStop(); /* Calls scbMode specific Stop function */
}


/*******************************************************************************
* Function Name: COZIR_SetRxFifoLevel
********************************************************************************
*
* Summary:
*  Sets level in the RX FIFO to generate a RX level interrupt.
*  When the RX FIFO has more entries than the RX FIFO level an RX level
*  interrupt request is generated.
*
* Parameters:
*  level: Level in the RX FIFO to generate RX level interrupt.
*         The range of valid level values is between 0 and RX FIFO depth - 1.
*
* Return:
*  None
*
*******************************************************************************/
void COZIR_SetRxFifoLevel(uint32 level)
{
    uint32 rxFifoCtrl;

    rxFifoCtrl = COZIR_RX_FIFO_CTRL_REG;

    rxFifoCtrl &= ((uint32) ~COZIR_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK); /* Clear level mask bits */
    rxFifoCtrl |= ((uint32) (COZIR_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK & level));

    COZIR_RX_FIFO_CTRL_REG = rxFifoCtrl;
}


/*******************************************************************************
* Function Name: COZIR_SetTxFifoLevel
********************************************************************************
*
* Summary:
*  Sets level in the TX FIFO to generate a TX level interrupt.
*  When the TX FIFO has more entries than the TX FIFO level an TX level
*  interrupt request is generated.
*
* Parameters:
*  level: Level in the TX FIFO to generate TX level interrupt.
*         The range of valid level values is between 0 and TX FIFO depth - 1.
*
* Return:
*  None
*
*******************************************************************************/
void COZIR_SetTxFifoLevel(uint32 level)
{
    uint32 txFifoCtrl;

    txFifoCtrl = COZIR_TX_FIFO_CTRL_REG;

    txFifoCtrl &= ((uint32) ~COZIR_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK); /* Clear level mask bits */
    txFifoCtrl |= ((uint32) (COZIR_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK & level));

    COZIR_TX_FIFO_CTRL_REG = txFifoCtrl;
}


/*******************************************************************************
* Function Name: COZIR_SetCustomInterruptHandler
********************************************************************************
*
* Summary:
*  Registers a function to be called by the internal interrupt handler.
*  First the function that is registered is called, then the internal interrupt
*  handler performs any operation such as software buffer management functions
*  before the interrupt returns.  It is the user's responsibility not to break
*  the software buffer operations. Only one custom handler is supported, which
*  is the function provided by the most recent call.
*  At the initialization time no custom handler is registered.
*
* Parameters:
*  func: Pointer to the function to register.
*        The value NULL indicates to remove the current custom interrupt
*        handler.
*
* Return:
*  None
*
*******************************************************************************/
void COZIR_SetCustomInterruptHandler(cyisraddress func)
{
#if !defined (CY_REMOVE_COZIR_CUSTOM_INTR_HANDLER)
    COZIR_customIntrHandler = func; /* Register interrupt handler */
#else
    if(NULL != func)
    {
        /* Suppress compiler warning */
    }
#endif /* !defined (CY_REMOVE_COZIR_CUSTOM_INTR_HANDLER) */
}


/*******************************************************************************
* Function Name: COZIR_ScbModeEnableIntr
********************************************************************************
*
* Summary:
*  Enables an interrupt for a specific mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
static void COZIR_ScbEnableIntr(void)
{
#if(COZIR_SCB_IRQ_INTERNAL)
    #if(COZIR_SCB_MODE_UNCONFIG_CONST_CFG)
        /* Enable interrupt in NVIC */
        if(0u != COZIR_scbEnableIntr)
        {
            COZIR_EnableInt();
        }
    #else
        COZIR_EnableInt();

    #endif /* (COZIR_SCB_MODE_UNCONFIG_CONST_CFG) */
#endif /* (COZIR_SCB_IRQ_INTERNAL) */
}


/*******************************************************************************
* Function Name: COZIR_ScbModeStop
********************************************************************************
*
* Summary:
*  Calls the Stop function for a specific operation mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
static void COZIR_ScbModeStop(void)
{
#if(COZIR_SCB_MODE_UNCONFIG_CONST_CFG)
    if(COZIR_SCB_MODE_I2C_RUNTM_CFG)
    {
        COZIR_I2CStop();
    }
    else if (COZIR_SCB_MODE_EZI2C_RUNTM_CFG)
    {
        COZIR_EzI2CStop();
    }
#if (!COZIR_CY_SCBIP_V1)
    else if (COZIR_SCB_MODE_UART_RUNTM_CFG)
    {
        COZIR_UartStop();
    }
#endif /* (!COZIR_CY_SCBIP_V1) */
    else
    {
        /* Do nothing for other modes */
    }
#elif(COZIR_SCB_MODE_I2C_CONST_CFG)
    COZIR_I2CStop();

#elif(COZIR_SCB_MODE_EZI2C_CONST_CFG)
    COZIR_EzI2CStop();

#elif(COZIR_SCB_MODE_UART_CONST_CFG)
    COZIR_UartStop();

#endif /* (COZIR_SCB_MODE_UNCONFIG_CONST_CFG) */
}


#if(COZIR_SCB_MODE_UNCONFIG_CONST_CFG)
    /*******************************************************************************
    * Function Name: COZIR_SetPins
    ********************************************************************************
    *
    * Summary:
    *  Sets the pins settings accordingly to the selected operation mode.
    *  Only available in the Unconfigured operation mode. The mode specific
    *  initialization function calls it.
    *  Pins configuration is set by PSoC Creator when a specific mode of operation
    *  is selected in design time.
    *
    * Parameters:
    *  mode:      Mode of SCB operation.
    *  subMode:   Sub-mode of SCB operation. It is only required for SPI and UART
    *             modes.
    *  uartEnableMask: enables TX or RX direction and RTS and CTS signals.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void COZIR_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask)
    {
        uint32 hsiomSel [COZIR_SCB_PINS_NUMBER];
        uint32 pinsDm   [COZIR_SCB_PINS_NUMBER];

    #if (!COZIR_CY_SCBIP_V1)
        uint32 pinsInBuf = 0u;
    #endif /* (!COZIR_CY_SCBIP_V1) */

        uint32 i;

        /* Set default HSIOM to GPIO and Drive Mode to Analog Hi-Z */
        for(i = 0u; i < COZIR_SCB_PINS_NUMBER; i++)
        {
            hsiomSel[i]  = COZIR_HSIOM_DEF_SEL;
            pinsDm[i]    = COZIR_PIN_DM_ALG_HIZ;
        }

        if((COZIR_SCB_MODE_I2C   == mode) ||
           (COZIR_SCB_MODE_EZI2C == mode))
        {
            hsiomSel[COZIR_MOSI_SCL_RX_PIN_INDEX] = COZIR_HSIOM_I2C_SEL;
            hsiomSel[COZIR_MISO_SDA_TX_PIN_INDEX] = COZIR_HSIOM_I2C_SEL;

            pinsDm[COZIR_MOSI_SCL_RX_PIN_INDEX] = COZIR_PIN_DM_OD_LO;
            pinsDm[COZIR_MISO_SDA_TX_PIN_INDEX] = COZIR_PIN_DM_OD_LO;
        }
    #if (!COZIR_CY_SCBIP_V1)
        else if(COZIR_SCB_MODE_SPI == mode)
        {
            hsiomSel[COZIR_MOSI_SCL_RX_PIN_INDEX] = COZIR_HSIOM_SPI_SEL;
            hsiomSel[COZIR_MISO_SDA_TX_PIN_INDEX] = COZIR_HSIOM_SPI_SEL;
            hsiomSel[COZIR_SCLK_PIN_INDEX]        = COZIR_HSIOM_SPI_SEL;

            if(COZIR_SPI_SLAVE == subMode)
            {
                /* Slave */
                pinsDm[COZIR_MOSI_SCL_RX_PIN_INDEX] = COZIR_PIN_DM_DIG_HIZ;
                pinsDm[COZIR_MISO_SDA_TX_PIN_INDEX] = COZIR_PIN_DM_STRONG;
                pinsDm[COZIR_SCLK_PIN_INDEX]        = COZIR_PIN_DM_DIG_HIZ;

            #if(COZIR_SS0_PIN)
                /* Only SS0 is valid choice for Slave */
                hsiomSel[COZIR_SS0_PIN_INDEX] = COZIR_HSIOM_SPI_SEL;
                pinsDm  [COZIR_SS0_PIN_INDEX] = COZIR_PIN_DM_DIG_HIZ;
            #endif /* (COZIR_SS1_PIN) */

            #if(COZIR_MISO_SDA_TX_PIN)
                /* Disable input buffer */
                 pinsInBuf |= COZIR_MISO_SDA_TX_PIN_MASK;
            #endif /* (COZIR_MISO_SDA_TX_PIN_PIN) */
            }
            else /* (Master) */
            {
                pinsDm[COZIR_MOSI_SCL_RX_PIN_INDEX] = COZIR_PIN_DM_STRONG;
                pinsDm[COZIR_MISO_SDA_TX_PIN_INDEX] = COZIR_PIN_DM_DIG_HIZ;
                pinsDm[COZIR_SCLK_PIN_INDEX]        = COZIR_PIN_DM_STRONG;

            #if(COZIR_SS0_PIN)
                hsiomSel [COZIR_SS0_PIN_INDEX] = COZIR_HSIOM_SPI_SEL;
                pinsDm   [COZIR_SS0_PIN_INDEX] = COZIR_PIN_DM_STRONG;
                pinsInBuf                                |= COZIR_SS0_PIN_MASK;
            #endif /* (COZIR_SS0_PIN) */

            #if(COZIR_SS1_PIN)
                hsiomSel [COZIR_SS1_PIN_INDEX] = COZIR_HSIOM_SPI_SEL;
                pinsDm   [COZIR_SS1_PIN_INDEX] = COZIR_PIN_DM_STRONG;
                pinsInBuf                                |= COZIR_SS1_PIN_MASK;
            #endif /* (COZIR_SS1_PIN) */

            #if(COZIR_SS2_PIN)
                hsiomSel [COZIR_SS2_PIN_INDEX] = COZIR_HSIOM_SPI_SEL;
                pinsDm   [COZIR_SS2_PIN_INDEX] = COZIR_PIN_DM_STRONG;
                pinsInBuf                                |= COZIR_SS2_PIN_MASK;
            #endif /* (COZIR_SS2_PIN) */

            #if(COZIR_SS3_PIN)
                hsiomSel [COZIR_SS3_PIN_INDEX] = COZIR_HSIOM_SPI_SEL;
                pinsDm   [COZIR_SS3_PIN_INDEX] = COZIR_PIN_DM_STRONG;
                pinsInBuf                                |= COZIR_SS3_PIN_MASK;
            #endif /* (COZIR_SS2_PIN) */

                /* Disable input buffers */
            #if(COZIR_MOSI_SCL_RX_PIN)
                pinsInBuf |= COZIR_MOSI_SCL_RX_PIN_MASK;
            #endif /* (COZIR_MOSI_SCL_RX_PIN) */

             #if(COZIR_MOSI_SCL_RX_WAKE_PIN)
                pinsInBuf |= COZIR_MOSI_SCL_RX_WAKE_PIN_MASK;
            #endif /* (COZIR_MOSI_SCL_RX_WAKE_PIN) */

            #if(COZIR_SCLK_PIN)
                pinsInBuf |= COZIR_SCLK_PIN_MASK;
            #endif /* (COZIR_SCLK_PIN) */
            }
        }
        else /* UART */
        {
            if(COZIR_UART_MODE_SMARTCARD == subMode)
            {
                /* SmartCard */
                hsiomSel[COZIR_MISO_SDA_TX_PIN_INDEX] = COZIR_HSIOM_UART_SEL;
                pinsDm  [COZIR_MISO_SDA_TX_PIN_INDEX] = COZIR_PIN_DM_OD_LO;
            }
            else /* Standard or IrDA */
            {
                if(0u != (COZIR_UART_RX_PIN_ENABLE & uartEnableMask))
                {
                    hsiomSel[COZIR_MOSI_SCL_RX_PIN_INDEX] = COZIR_HSIOM_UART_SEL;
                    pinsDm  [COZIR_MOSI_SCL_RX_PIN_INDEX] = COZIR_PIN_DM_DIG_HIZ;
                }

                if(0u != (COZIR_UART_TX_PIN_ENABLE & uartEnableMask))
                {
                    hsiomSel[COZIR_MISO_SDA_TX_PIN_INDEX] = COZIR_HSIOM_UART_SEL;
                    pinsDm  [COZIR_MISO_SDA_TX_PIN_INDEX] = COZIR_PIN_DM_STRONG;

                #if(COZIR_MISO_SDA_TX_PIN)
                     pinsInBuf |= COZIR_MISO_SDA_TX_PIN_MASK;
                #endif /* (COZIR_MISO_SDA_TX_PIN_PIN) */
                }

            #if !(COZIR_CY_SCBIP_V0 || COZIR_CY_SCBIP_V1)
                if(COZIR_UART_MODE_STD == subMode)
                {
                    if(0u != (COZIR_UART_CTS_PIN_ENABLE & uartEnableMask))
                    {
                        /* CTS input is multiplexed with SCLK */
                        hsiomSel[COZIR_SCLK_PIN_INDEX] = COZIR_HSIOM_UART_SEL;
                        pinsDm  [COZIR_SCLK_PIN_INDEX] = COZIR_PIN_DM_DIG_HIZ;
                    }

                    if(0u != (COZIR_UART_RTS_PIN_ENABLE & uartEnableMask))
                    {
                        /* RTS output is multiplexed with SS0 */
                        hsiomSel[COZIR_SS0_PIN_INDEX] = COZIR_HSIOM_UART_SEL;
                        pinsDm  [COZIR_SS0_PIN_INDEX] = COZIR_PIN_DM_STRONG;

                    #if(COZIR_SS0_PIN)
                        /* Disable input buffer */
                        pinsInBuf |= COZIR_SS0_PIN_MASK;
                    #endif /* (COZIR_SS0_PIN) */
                    }
                }
            #endif /* !(COZIR_CY_SCBIP_V0 || COZIR_CY_SCBIP_V1) */
            }
        }
    #endif /* (!COZIR_CY_SCBIP_V1) */

    /* Configure pins: set HSIOM, DM and InputBufEnable */
    /* Note: the DR register settings do not effect the pin output if HSIOM is other than GPIO */

    #if(COZIR_MOSI_SCL_RX_PIN)
        COZIR_SET_HSIOM_SEL(COZIR_MOSI_SCL_RX_HSIOM_REG,
                                       COZIR_MOSI_SCL_RX_HSIOM_MASK,
                                       COZIR_MOSI_SCL_RX_HSIOM_POS,
                                       hsiomSel[COZIR_MOSI_SCL_RX_PIN_INDEX]);

        COZIR_spi_mosi_i2c_sda_uart_rx_SetDriveMode((uint8) pinsDm[COZIR_MOSI_SCL_RX_PIN_INDEX]);

    #if (!COZIR_CY_SCBIP_V1)
        COZIR_SET_INP_DIS(COZIR_spi_mosi_i2c_sda_uart_rx_INP_DIS,
                                     COZIR_spi_mosi_i2c_sda_uart_rx_MASK,
                                     (0u != (pinsInBuf & COZIR_MOSI_SCL_RX_PIN_MASK)));
    #endif /* (!COZIR_CY_SCBIP_V1) */
    #endif /* (COZIR_MOSI_SCL_RX_PIN) */

    #if(COZIR_MOSI_SCL_RX_WAKE_PIN)
        COZIR_SET_HSIOM_SEL(COZIR_MOSI_SCL_RX_WAKE_HSIOM_REG,
                                       COZIR_MOSI_SCL_RX_WAKE_HSIOM_MASK,
                                       COZIR_MOSI_SCL_RX_WAKE_HSIOM_POS,
                                       hsiomSel[COZIR_MOSI_SCL_RX_WAKE_PIN_INDEX]);

        COZIR_spi_mosi_i2c_sda_uart_rx_wake_SetDriveMode((uint8)
                                                               pinsDm[COZIR_MOSI_SCL_RX_WAKE_PIN_INDEX]);

        COZIR_SET_INP_DIS(COZIR_spi_mosi_i2c_sda_uart_rx_wake_INP_DIS,
                                     COZIR_spi_mosi_i2c_sda_uart_rx_wake_MASK,
                                     (0u != (pinsInBuf & COZIR_MOSI_SCL_RX_WAKE_PIN_MASK)));

         /* Set interrupt on falling edge */
        COZIR_SET_INCFG_TYPE(COZIR_MOSI_SCL_RX_WAKE_INTCFG_REG,
                                        COZIR_MOSI_SCL_RX_WAKE_INTCFG_TYPE_MASK,
                                        COZIR_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS,
                                        COZIR_INTCFG_TYPE_FALLING_EDGE);
    #endif /* (COZIR_MOSI_SCL_RX_WAKE_PIN) */

    #if(COZIR_MISO_SDA_TX_PIN)
        COZIR_SET_HSIOM_SEL(COZIR_MISO_SDA_TX_HSIOM_REG,
                                       COZIR_MISO_SDA_TX_HSIOM_MASK,
                                       COZIR_MISO_SDA_TX_HSIOM_POS,
                                       hsiomSel[COZIR_MISO_SDA_TX_PIN_INDEX]);

        COZIR_spi_miso_i2c_scl_uart_tx_SetDriveMode((uint8) pinsDm[COZIR_MISO_SDA_TX_PIN_INDEX]);

    #if (!COZIR_CY_SCBIP_V1)
        COZIR_SET_INP_DIS(COZIR_spi_miso_i2c_scl_uart_tx_INP_DIS,
                                     COZIR_spi_miso_i2c_scl_uart_tx_MASK,
                                    (0u != (pinsInBuf & COZIR_MISO_SDA_TX_PIN_MASK)));
    #endif /* (!COZIR_CY_SCBIP_V1) */
    #endif /* (COZIR_MOSI_SCL_RX_PIN) */

    #if(COZIR_SCLK_PIN)
        COZIR_SET_HSIOM_SEL(COZIR_SCLK_HSIOM_REG, COZIR_SCLK_HSIOM_MASK,
                                       COZIR_SCLK_HSIOM_POS, hsiomSel[COZIR_SCLK_PIN_INDEX]);

        COZIR_spi_sclk_uart_cts_SetDriveMode((uint8) pinsDm[COZIR_SCLK_PIN_INDEX]);

        COZIR_SET_INP_DIS(COZIR_spi_sclk_uart_cts_INP_DIS,
                                     COZIR_spi_sclk_uart_cts_MASK,
                                     (0u != (pinsInBuf & COZIR_SCLK_PIN_MASK)));
    #endif /* (COZIR_SCLK_PIN) */

    #if(COZIR_SS0_PIN)
        COZIR_SET_HSIOM_SEL(COZIR_SS0_HSIOM_REG, COZIR_SS0_HSIOM_MASK,
                                       COZIR_SS0_HSIOM_POS, hsiomSel[COZIR_SS0_PIN_INDEX]);

        COZIR_spi_ss0_uart_rts_SetDriveMode((uint8) pinsDm[COZIR_SS0_PIN_INDEX]);

        COZIR_SET_INP_DIS(COZIR_spi_ss0_uart_rts_INP_DIS,
                                     COZIR_spi_ss0_uart_rts_MASK,
                                     (0u != (pinsInBuf & COZIR_SS0_PIN_MASK)));
    #endif /* (COZIR_SS1_PIN) */

    #if(COZIR_SS1_PIN)
        COZIR_SET_HSIOM_SEL(COZIR_SS1_HSIOM_REG, COZIR_SS1_HSIOM_MASK,
                                       COZIR_SS1_HSIOM_POS, hsiomSel[COZIR_SS1_PIN_INDEX]);

        COZIR_spi_ss1_SetDriveMode((uint8) pinsDm[COZIR_SS1_PIN_INDEX]);

        COZIR_SET_INP_DIS(COZIR_spi_ss1_INP_DIS,
                                     COZIR_spi_ss1_MASK,
                                     (0u != (pinsInBuf & COZIR_SS1_PIN_MASK)));
    #endif /* (COZIR_SS1_PIN) */

    #if(COZIR_SS2_PIN)
        COZIR_SET_HSIOM_SEL(COZIR_SS2_HSIOM_REG, COZIR_SS2_HSIOM_MASK,
                                       COZIR_SS2_HSIOM_POS, hsiomSel[COZIR_SS2_PIN_INDEX]);

        COZIR_spi_ss2_SetDriveMode((uint8) pinsDm[COZIR_SS2_PIN_INDEX]);

        COZIR_SET_INP_DIS(COZIR_spi_ss2_INP_DIS,
                                     COZIR_spi_ss2_MASK,
                                     (0u != (pinsInBuf & COZIR_SS2_PIN_MASK)));
    #endif /* (COZIR_SS2_PIN) */

    #if(COZIR_SS3_PIN)
        COZIR_SET_HSIOM_SEL(COZIR_SS3_HSIOM_REG,  COZIR_SS3_HSIOM_MASK,
                                       COZIR_SS3_HSIOM_POS, hsiomSel[COZIR_SS3_PIN_INDEX]);

        COZIR_spi_ss3_SetDriveMode((uint8) pinsDm[COZIR_SS3_PIN_INDEX]);

        COZIR_SET_INP_DIS(COZIR_spi_ss3_INP_DIS,
                                     COZIR_spi_ss3_MASK,
                                     (0u != (pinsInBuf & COZIR_SS3_PIN_MASK)));
    #endif /* (COZIR_SS3_PIN) */
    }

#endif /* (COZIR_SCB_MODE_UNCONFIG_CONST_CFG) */


#if (COZIR_CY_SCBIP_V0 || COZIR_CY_SCBIP_V1)
    /*******************************************************************************
    * Function Name: COZIR_I2CSlaveNackGeneration
    ********************************************************************************
    *
    * Summary:
    *  Sets command to generate NACK to the address or data.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void COZIR_I2CSlaveNackGeneration(void)
    {
        /* Check for EC_AM toggle condition: EC_AM and clock stretching for address are enabled */
        if ((0u != (COZIR_CTRL_REG & COZIR_CTRL_EC_AM_MODE)) &&
            (0u == (COZIR_I2C_CTRL_REG & COZIR_I2C_CTRL_S_NOT_READY_ADDR_NACK)))
        {
            /* Toggle EC_AM before NACK generation */
            COZIR_CTRL_REG &= ~COZIR_CTRL_EC_AM_MODE;
            COZIR_CTRL_REG |=  COZIR_CTRL_EC_AM_MODE;
        }

        COZIR_I2C_SLAVE_CMD_REG = COZIR_I2C_SLAVE_CMD_S_NACK;
    }
#endif /* (COZIR_CY_SCBIP_V0 || COZIR_CY_SCBIP_V1) */


/* [] END OF FILE */
