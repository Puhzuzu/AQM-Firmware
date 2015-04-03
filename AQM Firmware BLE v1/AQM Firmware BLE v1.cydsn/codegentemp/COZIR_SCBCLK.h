/*******************************************************************************
* File Name: COZIR_SCBCLK.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_COZIR_SCBCLK_H)
#define CY_CLOCK_COZIR_SCBCLK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void COZIR_SCBCLK_StartEx(uint32 alignClkDiv);
#define COZIR_SCBCLK_Start() \
    COZIR_SCBCLK_StartEx(COZIR_SCBCLK__PA_DIV_ID)

#else

void COZIR_SCBCLK_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void COZIR_SCBCLK_Stop(void);

void COZIR_SCBCLK_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 COZIR_SCBCLK_GetDividerRegister(void);
uint8  COZIR_SCBCLK_GetFractionalDividerRegister(void);

#define COZIR_SCBCLK_Enable()                         COZIR_SCBCLK_Start()
#define COZIR_SCBCLK_Disable()                        COZIR_SCBCLK_Stop()
#define COZIR_SCBCLK_SetDividerRegister(clkDivider, reset)  \
    COZIR_SCBCLK_SetFractionalDividerRegister((clkDivider), 0u)
#define COZIR_SCBCLK_SetDivider(clkDivider)           COZIR_SCBCLK_SetDividerRegister((clkDivider), 1u)
#define COZIR_SCBCLK_SetDividerValue(clkDivider)      COZIR_SCBCLK_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define COZIR_SCBCLK_DIV_ID     COZIR_SCBCLK__DIV_ID

#define COZIR_SCBCLK_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define COZIR_SCBCLK_CTRL_REG   (*(reg32 *)COZIR_SCBCLK__CTRL_REGISTER)
#define COZIR_SCBCLK_DIV_REG    (*(reg32 *)COZIR_SCBCLK__DIV_REGISTER)

#define COZIR_SCBCLK_CMD_DIV_SHIFT          (0u)
#define COZIR_SCBCLK_CMD_PA_DIV_SHIFT       (8u)
#define COZIR_SCBCLK_CMD_DISABLE_SHIFT      (30u)
#define COZIR_SCBCLK_CMD_ENABLE_SHIFT       (31u)

#define COZIR_SCBCLK_CMD_DISABLE_MASK       ((uint32)((uint32)1u << COZIR_SCBCLK_CMD_DISABLE_SHIFT))
#define COZIR_SCBCLK_CMD_ENABLE_MASK        ((uint32)((uint32)1u << COZIR_SCBCLK_CMD_ENABLE_SHIFT))

#define COZIR_SCBCLK_DIV_FRAC_MASK  (0x000000F8u)
#define COZIR_SCBCLK_DIV_FRAC_SHIFT (3u)
#define COZIR_SCBCLK_DIV_INT_MASK   (0xFFFFFF00u)
#define COZIR_SCBCLK_DIV_INT_SHIFT  (8u)

#else 

#define COZIR_SCBCLK_DIV_REG        (*(reg32 *)COZIR_SCBCLK__REGISTER)
#define COZIR_SCBCLK_ENABLE_REG     COZIR_SCBCLK_DIV_REG
#define COZIR_SCBCLK_DIV_FRAC_MASK  COZIR_SCBCLK__FRAC_MASK
#define COZIR_SCBCLK_DIV_FRAC_SHIFT (16u)
#define COZIR_SCBCLK_DIV_INT_MASK   COZIR_SCBCLK__DIVIDER_MASK
#define COZIR_SCBCLK_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_COZIR_SCBCLK_H) */

/* [] END OF FILE */
