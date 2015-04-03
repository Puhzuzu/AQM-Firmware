/*******************************************************************************
* File Name: COZIR_PINS.h
* Version 2.0
*
* Description:
*  This file provides constants and parameter values for the pin components
*  buried into SCB Component.
*
* Note:
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_PINS_COZIR_H)
#define CY_SCB_PINS_COZIR_H

#include "cydevice_trm.h"
#include "cyfitter.h"
#include "cytypes.h"


/***************************************
*   Conditional Compilation Parameters
****************************************/

/* Unconfigured pins */
#define COZIR_REMOVE_MOSI_SCL_RX_WAKE_PIN    (1u)
#define COZIR_REMOVE_MOSI_SCL_RX_PIN         (1u)
#define COZIR_REMOVE_MISO_SDA_TX_PIN         (1u)
#define COZIR_REMOVE_SCLK_PIN                (1u)
#define COZIR_REMOVE_SS0_PIN                 (1u)
#define COZIR_REMOVE_SS1_PIN                 (1u)
#define COZIR_REMOVE_SS2_PIN                 (1u)
#define COZIR_REMOVE_SS3_PIN                 (1u)

/* Mode defined pins */
#define COZIR_REMOVE_I2C_PINS                (1u)
#define COZIR_REMOVE_SPI_MASTER_PINS         (1u)
#define COZIR_REMOVE_SPI_SLAVE_PINS          (1u)
#define COZIR_REMOVE_SPI_MASTER_SS0_PIN      (1u)
#define COZIR_REMOVE_SPI_MASTER_SS1_PIN      (1u)
#define COZIR_REMOVE_SPI_MASTER_SS2_PIN      (1u)
#define COZIR_REMOVE_SPI_MASTER_SS3_PIN      (1u)
#define COZIR_REMOVE_UART_TX_PIN             (0u)
#define COZIR_REMOVE_UART_RX_TX_PIN          (1u)
#define COZIR_REMOVE_UART_RX_PIN             (0u)
#define COZIR_REMOVE_UART_RX_WAKE_PIN        (1u)
#define COZIR_REMOVE_UART_RTS_PIN            (1u)
#define COZIR_REMOVE_UART_CTS_PIN            (1u)

/* Unconfigured pins */
#define COZIR_MOSI_SCL_RX_WAKE_PIN   (0u == COZIR_REMOVE_MOSI_SCL_RX_WAKE_PIN)
#define COZIR_MOSI_SCL_RX_PIN        (0u == COZIR_REMOVE_MOSI_SCL_RX_PIN)
#define COZIR_MISO_SDA_TX_PIN        (0u == COZIR_REMOVE_MISO_SDA_TX_PIN)
#define COZIR_SCLK_PIN               (0u == COZIR_REMOVE_SCLK_PIN)
#define COZIR_SS0_PIN                (0u == COZIR_REMOVE_SS0_PIN)
#define COZIR_SS1_PIN                (0u == COZIR_REMOVE_SS1_PIN)
#define COZIR_SS2_PIN                (0u == COZIR_REMOVE_SS2_PIN)
#define COZIR_SS3_PIN                (0u == COZIR_REMOVE_SS3_PIN)

/* Mode defined pins */
#define COZIR_I2C_PINS               (0u == COZIR_REMOVE_I2C_PINS)
#define COZIR_SPI_MASTER_PINS        (0u == COZIR_REMOVE_SPI_MASTER_PINS)
#define COZIR_SPI_SLAVE_PINS         (0u == COZIR_REMOVE_SPI_SLAVE_PINS)
#define COZIR_SPI_MASTER_SS0_PIN     (0u == COZIR_REMOVE_SPI_MASTER_SS0_PIN)
#define COZIR_SPI_MASTER_SS1_PIN     (0u == COZIR_REMOVE_SPI_MASTER_SS1_PIN)
#define COZIR_SPI_MASTER_SS2_PIN     (0u == COZIR_REMOVE_SPI_MASTER_SS2_PIN)
#define COZIR_SPI_MASTER_SS3_PIN     (0u == COZIR_REMOVE_SPI_MASTER_SS3_PIN)
#define COZIR_UART_TX_PIN            (0u == COZIR_REMOVE_UART_TX_PIN)
#define COZIR_UART_RX_TX_PIN         (0u == COZIR_REMOVE_UART_RX_TX_PIN)
#define COZIR_UART_RX_PIN            (0u == COZIR_REMOVE_UART_RX_PIN)
#define COZIR_UART_RX_WAKE_PIN       (0u == COZIR_REMOVE_UART_RX_WAKE_PIN)
#define COZIR_UART_RTS_PIN           (0u == COZIR_REMOVE_UART_RTS_PIN)
#define COZIR_UART_CTS_PIN           (0u == COZIR_REMOVE_UART_CTS_PIN)


/***************************************
*             Includes
****************************************/

#if(COZIR_MOSI_SCL_RX_WAKE_PIN)
    #include "COZIR_spi_mosi_i2c_sda_uart_rx_wake.h"
#endif /* (COZIR_MOSI_SCL_RX_WAKE_PIN) */

#if(COZIR_MOSI_SCL_RX_PIN)
    #include "COZIR_spi_mosi_i2c_sda_uart_rx.h"
#endif /* (COZIR_MOSI_SCL_RX_PIN) */

#if(COZIR_MISO_SDA_TX_PIN)
    #include "COZIR_spi_miso_i2c_scl_uart_tx.h"
#endif /* (COZIR_MISO_SDA_TX_PIN_PIN) */

#if(COZIR_SCLK_PIN)
    #include "COZIR_spi_sclk_uart_cts.h"
#endif /* (COZIR_SCLK_PIN) */

#if(COZIR_SS0_PIN)
    #include "COZIR_spi_ss0_uart_rts.h"
#endif /* (COZIR_SS1_PIN) */

#if(COZIR_SS1_PIN)
    #include "COZIR_spi_ss1.h"
#endif /* (COZIR_SS1_PIN) */

#if(COZIR_SS2_PIN)
    #include "COZIR_spi_ss2.h"
#endif /* (COZIR_SS2_PIN) */

#if(COZIR_SS3_PIN)
    #include "COZIR_spi_ss3.h"
#endif /* (COZIR_SS3_PIN) */

#if(COZIR_I2C_PINS)
    #include "COZIR_scl.h"
    #include "COZIR_sda.h"
#endif /* (COZIR_I2C_PINS) */

#if(COZIR_SPI_MASTER_PINS)
    #include "COZIR_sclk_m.h"
    #include "COZIR_mosi_m.h"
    #include "COZIR_miso_m.h"
#endif /* (COZIR_SPI_MASTER_PINS) */

#if(COZIR_SPI_SLAVE_PINS)
    #include "COZIR_sclk_s.h"
    #include "COZIR_mosi_s.h"
    #include "COZIR_miso_s.h"
    #include "COZIR_ss_s.h"
#endif /* (COZIR_SPI_SLAVE_PINS) */

#if(COZIR_SPI_MASTER_SS0_PIN)
    #include "COZIR_ss0_m.h"
#endif /* (COZIR_SPI_MASTER_SS0_PIN) */

#if(COZIR_SPI_MASTER_SS1_PIN)
    #include "COZIR_ss1_m.h"
#endif /* (COZIR_SPI_MASTER_SS1_PIN) */

#if(COZIR_SPI_MASTER_SS2_PIN)
    #include "COZIR_ss2_m.h"
#endif /* (COZIR_SPI_MASTER_SS2_PIN) */

#if(COZIR_SPI_MASTER_SS3_PIN)
    #include "COZIR_ss3_m.h"
#endif /* (COZIR_SPI_MASTER_SS3_PIN) */

#if(COZIR_UART_TX_PIN)
    #include "COZIR_tx.h"
#endif /* (COZIR_UART_TX_PIN) */

#if(COZIR_UART_RX_TX_PIN)
    #include "COZIR_rx_tx.h"
#endif /* (COZIR_UART_RX_TX_PIN) */

#if(COZIR_UART_RX_PIN)
    #include "COZIR_rx.h"
#endif /* (COZIR_UART_RX_PIN) */

#if(COZIR_UART_RX_WAKE_PIN)
    #include "COZIR_rx_wake.h"
#endif /* (COZIR_UART_RX_WAKE_PIN) */

#if(COZIR_UART_RTS_PIN)
    #include "COZIR_rts.h"
#endif /* (COZIR_UART_RTS_PIN) */

#if(COZIR_UART_CTS_PIN)
    #include "COZIR_cts.h"
#endif /* (COZIR_UART_CTS_PIN) */


/***************************************
*              Registers
***************************************/

#if(COZIR_MOSI_SCL_RX_WAKE_PIN)
    #define COZIR_MOSI_SCL_RX_WAKE_HSIOM_REG  \
                                                (*(reg32 *) COZIR_spi_mosi_i2c_sda_uart_rx_wake__0__HSIOM)
    #define COZIR_MOSI_SCL_RX_WAKE_HSIOM_PTR  \
                                                ( (reg32 *) COZIR_spi_mosi_i2c_sda_uart_rx_wake__0__HSIOM)
    #define COZIR_MOSI_SCL_RX_WAKE_HSIOM_MASK \
                                                (COZIR_spi_mosi_i2c_sda_uart_rx_wake__0__HSIOM_MASK)
    #define COZIR_MOSI_SCL_RX_WAKE_HSIOM_POS  \
                                                (COZIR_spi_mosi_i2c_sda_uart_rx_wake__0__HSIOM_SHIFT)

    #define COZIR_MOSI_SCL_RX_WAKE_INTCFG_REG    (*(reg32 *) \
                                                              COZIR_spi_mosi_i2c_sda_uart_rx_wake__0__INTCFG)
    #define COZIR_MOSI_SCL_RX_WAKE_INTCFG_PTR    ( (reg32 *) \
                                                              COZIR_spi_mosi_i2c_sda_uart_rx_wake__0__INTCFG)

    #define COZIR_INTCFG_TYPE_MASK                  (0x03u)
    #define COZIR_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS  (COZIR_spi_mosi_i2c_sda_uart_rx_wake__SHIFT)
    #define COZIR_MOSI_SCL_RX_WAKE_INTCFG_TYPE_MASK ((uint32)                                           \
                                                                    ((uint32) COZIR_INTCFG_TYPE_MASK << \
                                                                    COZIR_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS))
#endif /* (COZIR_MOSI_SCL_RX_WAKE_PIN) */

#if(COZIR_MOSI_SCL_RX_PIN)
    #define COZIR_MOSI_SCL_RX_HSIOM_REG      (*(reg32 *) COZIR_spi_mosi_i2c_sda_uart_rx__0__HSIOM)
    #define COZIR_MOSI_SCL_RX_HSIOM_PTR      ( (reg32 *) COZIR_spi_mosi_i2c_sda_uart_rx__0__HSIOM)
    #define COZIR_MOSI_SCL_RX_HSIOM_MASK     (COZIR_spi_mosi_i2c_sda_uart_rx__0__HSIOM_MASK)
    #define COZIR_MOSI_SCL_RX_HSIOM_POS      (COZIR_spi_mosi_i2c_sda_uart_rx__0__HSIOM_SHIFT)
#endif /* (COZIR_MOSI_SCL_RX_PIN) */

#if(COZIR_MISO_SDA_TX_PIN)
    #define COZIR_MISO_SDA_TX_HSIOM_REG      (*(reg32 *) COZIR_spi_miso_i2c_scl_uart_tx__0__HSIOM)
    #define COZIR_MISO_SDA_TX_HSIOM_PTR      ( (reg32 *) COZIR_spi_miso_i2c_scl_uart_tx__0__HSIOM)
    #define COZIR_MISO_SDA_TX_HSIOM_MASK     (COZIR_spi_miso_i2c_scl_uart_tx__0__HSIOM_MASK)
    #define COZIR_MISO_SDA_TX_HSIOM_POS      (COZIR_spi_miso_i2c_scl_uart_tx__0__HSIOM_SHIFT)
#endif /* (COZIR_MISO_SDA_TX_PIN_PIN) */

#if(COZIR_SCLK_PIN)
    #define COZIR_SCLK_HSIOM_REG     (*(reg32 *) COZIR_spi_sclk_uart_cts__0__HSIOM)
    #define COZIR_SCLK_HSIOM_PTR     ( (reg32 *) COZIR_spi_sclk_uart_cts__0__HSIOM)
    #define COZIR_SCLK_HSIOM_MASK    (COZIR_spi_sclk_uart_cts__0__HSIOM_MASK)
    #define COZIR_SCLK_HSIOM_POS     (COZIR_spi_sclk_uart_cts__0__HSIOM_SHIFT)
#endif /* (COZIR_SCLK_PIN) */

#if(COZIR_SS0_PIN)
    #define COZIR_SS0_HSIOM_REG      (*(reg32 *) COZIR_spi_ss0_uart_rts__0__HSIOM)
    #define COZIR_SS0_HSIOM_PTR      ( (reg32 *) COZIR_spi_ss0_uart_rts__0__HSIOM)
    #define COZIR_SS0_HSIOM_MASK     (COZIR_spi_ss0_uart_rts__0__HSIOM_MASK)
    #define COZIR_SS0_HSIOM_POS      (COZIR_spi_ss0_uart_rts__0__HSIOM_SHIFT)
#endif /* (COZIR_SS1_PIN) */

#if(COZIR_SS1_PIN)
    #define COZIR_SS1_HSIOM_REG      (*(reg32 *) COZIR_spi_ss1__0__HSIOM)
    #define COZIR_SS1_HSIOM_PTR      ( (reg32 *) COZIR_spi_ss1__0__HSIOM)
    #define COZIR_SS1_HSIOM_MASK     (COZIR_spi_ss1__0__HSIOM_MASK)
    #define COZIR_SS1_HSIOM_POS      (COZIR_spi_ss1__0__HSIOM_SHIFT)
#endif /* (COZIR_SS1_PIN) */

#if(COZIR_SS2_PIN)
    #define COZIR_SS2_HSIOM_REG     (*(reg32 *) COZIR_spi_ss2__0__HSIOM)
    #define COZIR_SS2_HSIOM_PTR     ( (reg32 *) COZIR_spi_ss2__0__HSIOM)
    #define COZIR_SS2_HSIOM_MASK    (COZIR_spi_ss2__0__HSIOM_MASK)
    #define COZIR_SS2_HSIOM_POS     (COZIR_spi_ss2__0__HSIOM_SHIFT)
#endif /* (COZIR_SS2_PIN) */

#if(COZIR_SS3_PIN)
    #define COZIR_SS3_HSIOM_REG     (*(reg32 *) COZIR_spi_ss3__0__HSIOM)
    #define COZIR_SS3_HSIOM_PTR     ( (reg32 *) COZIR_spi_ss3__0__HSIOM)
    #define COZIR_SS3_HSIOM_MASK    (COZIR_spi_ss3__0__HSIOM_MASK)
    #define COZIR_SS3_HSIOM_POS     (COZIR_spi_ss3__0__HSIOM_SHIFT)
#endif /* (COZIR_SS3_PIN) */

#if(COZIR_I2C_PINS)
    #define COZIR_SCL_HSIOM_REG     (*(reg32 *) COZIR_scl__0__HSIOM)
    #define COZIR_SCL_HSIOM_PTR     ( (reg32 *) COZIR_scl__0__HSIOM)
    #define COZIR_SCL_HSIOM_MASK    (COZIR_scl__0__HSIOM_MASK)
    #define COZIR_SCL_HSIOM_POS     (COZIR_scl__0__HSIOM_SHIFT)

    #define COZIR_SDA_HSIOM_REG     (*(reg32 *) COZIR_sda__0__HSIOM)
    #define COZIR_SDA_HSIOM_PTR     ( (reg32 *) COZIR_sda__0__HSIOM)
    #define COZIR_SDA_HSIOM_MASK    (COZIR_sda__0__HSIOM_MASK)
    #define COZIR_SDA_HSIOM_POS     (COZIR_sda__0__HSIOM_SHIFT)
#endif /* (COZIR_I2C_PINS) */


/***************************************
*        Registers Constants
***************************************/

/* Pins constants */
#define COZIR_HSIOM_DEF_SEL      (0x00u)
#define COZIR_HSIOM_GPIO_SEL     (0x00u)
#define COZIR_HSIOM_UART_SEL     (0x09u)
#define COZIR_HSIOM_I2C_SEL      (0x0Eu)
#define COZIR_HSIOM_SPI_SEL      (0x0Fu)

#define COZIR_MOSI_SCL_RX_PIN_INDEX      (0u) /* RX pins without interrupt */
#define COZIR_MOSI_SCL_RX_WAKE_PIN_INDEX (0u) /* RX pin with interrupt     */
#define COZIR_MISO_SDA_TX_PIN_INDEX      (1u)
#define COZIR_SCLK_PIN_INDEX             (2u)
#define COZIR_SS0_PIN_INDEX              (3u)
#define COZIR_SS1_PIN_INDEX              (4u)
#define COZIR_SS2_PIN_INDEX              (5u)
#define COZIR_SS3_PIN_INDEX              (6u)

#define COZIR_MOSI_SCL_RX_PIN_MASK      ((uint32) 0x01u << COZIR_MOSI_SCL_RX_PIN_INDEX)
#define COZIR_MOSI_SCL_RX_WAKE_PIN_MASK ((uint32) 0x01u << COZIR_MOSI_SCL_RX_WAKE_PIN_INDEX)
#define COZIR_MISO_SDA_TX_PIN_MASK      ((uint32) 0x01u << COZIR_MISO_SDA_TX_PIN_INDEX)
#define COZIR_SCLK_PIN_MASK             ((uint32) 0x01u << COZIR_SCLK_PIN_INDEX)
#define COZIR_SS0_PIN_MASK              ((uint32) 0x01u << COZIR_SS0_PIN_INDEX)
#define COZIR_SS1_PIN_MASK              ((uint32) 0x01u << COZIR_SS1_PIN_INDEX)
#define COZIR_SS2_PIN_MASK              ((uint32) 0x01u << COZIR_SS2_PIN_INDEX)
#define COZIR_SS3_PIN_MASK              ((uint32) 0x01u << COZIR_SS3_PIN_INDEX)

#define COZIR_INTCFG_TYPE_FALLING_EDGE   (0x02u)

/* Pin DM defines */
#define COZIR_PIN_DM_ALG_HIZ  (0u)
#define COZIR_PIN_DM_DIG_HIZ  (1u)
#define COZIR_PIN_DM_OD_LO    (4u)
#define COZIR_PIN_DM_STRONG   (6u)


/***************************************
*          Macro Definitions
***************************************/

/* Set bits-mask in register */
#define COZIR_SET_REGISTER_BITS(reg, mask, pos, mode) \
                    do                                           \
                    {                                            \
                        (reg) = (((reg) & ((uint32) ~(uint32) (mask))) | ((uint32) ((uint32) (mode) << (pos)))); \
                    }while(0)

/* Set bit in the register */
#define COZIR_SET_REGISTER_BIT(reg, mask, val) \
                    ((val) ? ((reg) |= (mask)) : ((reg) &= ((uint32) ~((uint32) (mask)))))

#define COZIR_SET_HSIOM_SEL(reg, mask, pos, sel) COZIR_SET_REGISTER_BITS(reg, mask, pos, sel)
#define COZIR_SET_INCFG_TYPE(reg, mask, pos, intType) \
                                                        COZIR_SET_REGISTER_BITS(reg, mask, pos, intType)
#define COZIR_SET_INP_DIS(reg, mask, val) COZIR_SET_REGISTER_BIT(reg, mask, val)

/* COZIR_SET_I2C_SCL_DR(val) - Sets I2C SCL DR register.
*  COZIR_SET_I2C_SCL_HSIOM_SEL(sel) - Sets I2C SCL HSIOM settings.
*/
/* SCB I2C: scl signal */
#if(COZIR_I2C_PINS)
    #define COZIR_SET_I2C_SCL_DR(val) COZIR_scl_Write(val)

    #define COZIR_SET_I2C_SCL_HSIOM_SEL(sel) \
                          COZIR_SET_HSIOM_SEL(COZIR_SCL_HSIOM_REG,  \
                                                         COZIR_SCL_HSIOM_MASK, \
                                                         COZIR_SCL_HSIOM_POS,  \
                                                         (sel))
    #define COZIR_WAIT_SCL_SET_HIGH  (0u == COZIR_scl_Read())

/* Unconfigured SCB: scl signal */
#elif(COZIR_MOSI_SCL_RX_WAKE_PIN)
    #define COZIR_SET_I2C_SCL_DR(val) \
                            COZIR_spi_mosi_i2c_scl_uart_rx_wake_Write(val)

    #define COZIR_SET_I2C_SCL_HSIOM_SEL(sel) \
                    COZIR_SET_HSIOM_SEL(COZIR_MOSI_SCL_RX_WAKE_HSIOM_REG,  \
                                                   COZIR_MOSI_SCL_RX_WAKE_HSIOM_MASK, \
                                                   COZIR_MOSI_SCL_RX_WAKE_HSIOM_POS,  \
                                                   (sel))

    #define COZIR_WAIT_SCL_SET_HIGH  (0u == COZIR_spi_mosi_i2c_scl_uart_rx_wake_Read())

#elif(COZIR_MOSI_SCL_RX_PIN)
    #define COZIR_SET_I2C_SCL_DR(val) \
                            COZIR_spi_mosi_i2c_sda_uart_rx_Write(val)


    #define COZIR_SET_I2C_SCL_HSIOM_SEL(sel) \
                            COZIR_SET_HSIOM_SEL(COZIR_MOSI_SCL_RX_HSIOM_REG,  \
                                                           COZIR_MOSI_SCL_RX_HSIOM_MASK, \
                                                           COZIR_MOSI_SCL_RX_HSIOM_POS,  \
                                                           (sel))

    #define COZIR_WAIT_SCL_SET_HIGH  (0u == COZIR_spi_mosi_i2c_sda_uart_rx_Read())

#else
    #define COZIR_SET_I2C_SCL_DR(val) \
                                                    do{ /* Does nothing */ }while(0)
    #define COZIR_SET_I2C_SCL_HSIOM_SEL(sel) \
                                                    do{ /* Does nothing */ }while(0)

    #define COZIR_WAIT_SCL_SET_HIGH  (0u)
#endif /* (COZIR_MOSI_SCL_RX_PIN) */

/* SCB I2C: sda signal */
#if(COZIR_I2C_PINS)
    #define COZIR_WAIT_SDA_SET_HIGH  (0u == COZIR_sda_Read())

/* Unconfigured SCB: sda signal */
#elif(COZIR_MISO_SDA_TX_PIN)
    #define COZIR_WAIT_SDA_SET_HIGH  (0u == COZIR_spi_miso_i2c_scl_uart_tx_Read())

#else
    #define COZIR_WAIT_SDA_SET_HIGH  (0u)
#endif /* (COZIR_MOSI_SCL_RX_PIN) */

#endif /* (CY_SCB_PINS_COZIR_H) */


/* [] END OF FILE */
