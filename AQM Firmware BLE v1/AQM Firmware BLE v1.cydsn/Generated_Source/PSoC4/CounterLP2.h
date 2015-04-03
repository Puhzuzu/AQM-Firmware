/*******************************************************************************
* File Name: CounterLP2.h
* Version 2.0
*
* Description:
*  This file provides constants and parameter values for the CounterLP2
*  component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_TCPWM_CounterLP2_H)
#define CY_TCPWM_CounterLP2_H


#include "CyLib.h"
#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} CounterLP2_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  CounterLP2_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define CounterLP2_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define CounterLP2_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define CounterLP2_CONFIG                         (1lu)

/* Quad Mode */
/* Parameters */
#define CounterLP2_QUAD_ENCODING_MODES            (0lu)

/* Signal modes */
#define CounterLP2_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define CounterLP2_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define CounterLP2_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define CounterLP2_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define CounterLP2_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define CounterLP2_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define CounterLP2_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define CounterLP2_TC_RUN_MODE                    (0lu)
#define CounterLP2_TC_COUNTER_MODE                (0lu)
#define CounterLP2_TC_COMP_CAP_MODE               (2lu)
#define CounterLP2_TC_PRESCALER                   (0lu)

/* Signal modes */
#define CounterLP2_TC_RELOAD_SIGNAL_MODE          (1lu)
#define CounterLP2_TC_COUNT_SIGNAL_MODE           (0lu)
#define CounterLP2_TC_START_SIGNAL_MODE           (0lu)
#define CounterLP2_TC_STOP_SIGNAL_MODE            (0lu)
#define CounterLP2_TC_CAPTURE_SIGNAL_MODE         (2lu)

/* Signal present */
#define CounterLP2_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define CounterLP2_TC_COUNT_SIGNAL_PRESENT        (1lu)
#define CounterLP2_TC_START_SIGNAL_PRESENT        (0lu)
#define CounterLP2_TC_STOP_SIGNAL_PRESENT         (0lu)
#define CounterLP2_TC_CAPTURE_SIGNAL_PRESENT      (1lu)

/* Interrupt Mask */
#define CounterLP2_TC_INTERRUPT_MASK              (0lu)

/* PWM Mode */
/* Parameters */
#define CounterLP2_PWM_KILL_EVENT                 (0lu)
#define CounterLP2_PWM_STOP_EVENT                 (0lu)
#define CounterLP2_PWM_MODE                       (4lu)
#define CounterLP2_PWM_OUT_N_INVERT               (0lu)
#define CounterLP2_PWM_OUT_INVERT                 (0lu)
#define CounterLP2_PWM_ALIGN                      (0lu)
#define CounterLP2_PWM_RUN_MODE                   (0lu)
#define CounterLP2_PWM_DEAD_TIME_CYCLE            (0lu)
#define CounterLP2_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define CounterLP2_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define CounterLP2_PWM_COUNT_SIGNAL_MODE          (3lu)
#define CounterLP2_PWM_START_SIGNAL_MODE          (0lu)
#define CounterLP2_PWM_STOP_SIGNAL_MODE           (0lu)
#define CounterLP2_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define CounterLP2_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define CounterLP2_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define CounterLP2_PWM_START_SIGNAL_PRESENT       (0lu)
#define CounterLP2_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define CounterLP2_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define CounterLP2_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define CounterLP2_TC_PERIOD_VALUE                (65535lu)
#define CounterLP2_TC_COMPARE_VALUE               (65535lu)
#define CounterLP2_TC_COMPARE_BUF_VALUE           (65535lu)
#define CounterLP2_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define CounterLP2_PWM_PERIOD_VALUE               (65535lu)
#define CounterLP2_PWM_PERIOD_BUF_VALUE           (65535lu)
#define CounterLP2_PWM_PERIOD_SWAP                (0lu)
#define CounterLP2_PWM_COMPARE_VALUE              (65535lu)
#define CounterLP2_PWM_COMPARE_BUF_VALUE          (65535lu)
#define CounterLP2_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define CounterLP2__LEFT 0
#define CounterLP2__RIGHT 1
#define CounterLP2__CENTER 2
#define CounterLP2__ASYMMETRIC 3

#define CounterLP2__X1 0
#define CounterLP2__X2 1
#define CounterLP2__X4 2

#define CounterLP2__PWM 4
#define CounterLP2__PWM_DT 5
#define CounterLP2__PWM_PR 6

#define CounterLP2__INVERSE 1
#define CounterLP2__DIRECT 0

#define CounterLP2__CAPTURE 2
#define CounterLP2__COMPARE 0

#define CounterLP2__TRIG_LEVEL 3
#define CounterLP2__TRIG_RISING 0
#define CounterLP2__TRIG_FALLING 1
#define CounterLP2__TRIG_BOTH 2

#define CounterLP2__INTR_MASK_TC 1
#define CounterLP2__INTR_MASK_CC_MATCH 2
#define CounterLP2__INTR_MASK_NONE 0
#define CounterLP2__INTR_MASK_TC_CC 3

#define CounterLP2__UNCONFIG 8
#define CounterLP2__TIMER 1
#define CounterLP2__QUAD 3
#define CounterLP2__PWM_SEL 7

#define CounterLP2__COUNT_UP 0
#define CounterLP2__COUNT_DOWN 1
#define CounterLP2__COUNT_UPDOWN0 2
#define CounterLP2__COUNT_UPDOWN1 3


/* Prescaler */
#define CounterLP2_PRESCALE_DIVBY1                ((uint32)(0u << CounterLP2_PRESCALER_SHIFT))
#define CounterLP2_PRESCALE_DIVBY2                ((uint32)(1u << CounterLP2_PRESCALER_SHIFT))
#define CounterLP2_PRESCALE_DIVBY4                ((uint32)(2u << CounterLP2_PRESCALER_SHIFT))
#define CounterLP2_PRESCALE_DIVBY8                ((uint32)(3u << CounterLP2_PRESCALER_SHIFT))
#define CounterLP2_PRESCALE_DIVBY16               ((uint32)(4u << CounterLP2_PRESCALER_SHIFT))
#define CounterLP2_PRESCALE_DIVBY32               ((uint32)(5u << CounterLP2_PRESCALER_SHIFT))
#define CounterLP2_PRESCALE_DIVBY64               ((uint32)(6u << CounterLP2_PRESCALER_SHIFT))
#define CounterLP2_PRESCALE_DIVBY128              ((uint32)(7u << CounterLP2_PRESCALER_SHIFT))

/* TCPWM set modes */
#define CounterLP2_MODE_TIMER_COMPARE             ((uint32)(CounterLP2__COMPARE         <<  \
                                                                  CounterLP2_MODE_SHIFT))
#define CounterLP2_MODE_TIMER_CAPTURE             ((uint32)(CounterLP2__CAPTURE         <<  \
                                                                  CounterLP2_MODE_SHIFT))
#define CounterLP2_MODE_QUAD                      ((uint32)(CounterLP2__QUAD            <<  \
                                                                  CounterLP2_MODE_SHIFT))
#define CounterLP2_MODE_PWM                       ((uint32)(CounterLP2__PWM             <<  \
                                                                  CounterLP2_MODE_SHIFT))
#define CounterLP2_MODE_PWM_DT                    ((uint32)(CounterLP2__PWM_DT          <<  \
                                                                  CounterLP2_MODE_SHIFT))
#define CounterLP2_MODE_PWM_PR                    ((uint32)(CounterLP2__PWM_PR          <<  \
                                                                  CounterLP2_MODE_SHIFT))

/* Quad Modes */
#define CounterLP2_MODE_X1                        ((uint32)(CounterLP2__X1              <<  \
                                                                  CounterLP2_QUAD_MODE_SHIFT))
#define CounterLP2_MODE_X2                        ((uint32)(CounterLP2__X2              <<  \
                                                                  CounterLP2_QUAD_MODE_SHIFT))
#define CounterLP2_MODE_X4                        ((uint32)(CounterLP2__X4              <<  \
                                                                  CounterLP2_QUAD_MODE_SHIFT))

/* Counter modes */
#define CounterLP2_COUNT_UP                       ((uint32)(CounterLP2__COUNT_UP        <<  \
                                                                  CounterLP2_UPDOWN_SHIFT))
#define CounterLP2_COUNT_DOWN                     ((uint32)(CounterLP2__COUNT_DOWN      <<  \
                                                                  CounterLP2_UPDOWN_SHIFT))
#define CounterLP2_COUNT_UPDOWN0                  ((uint32)(CounterLP2__COUNT_UPDOWN0   <<  \
                                                                  CounterLP2_UPDOWN_SHIFT))
#define CounterLP2_COUNT_UPDOWN1                  ((uint32)(CounterLP2__COUNT_UPDOWN1   <<  \
                                                                  CounterLP2_UPDOWN_SHIFT))

/* PWM output invert */
#define CounterLP2_INVERT_LINE                    ((uint32)(CounterLP2__INVERSE         <<  \
                                                                  CounterLP2_INV_OUT_SHIFT))
#define CounterLP2_INVERT_LINE_N                  ((uint32)(CounterLP2__INVERSE         <<  \
                                                                  CounterLP2_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define CounterLP2_TRIG_RISING                    ((uint32)CounterLP2__TRIG_RISING)
#define CounterLP2_TRIG_FALLING                   ((uint32)CounterLP2__TRIG_FALLING)
#define CounterLP2_TRIG_BOTH                      ((uint32)CounterLP2__TRIG_BOTH)
#define CounterLP2_TRIG_LEVEL                     ((uint32)CounterLP2__TRIG_LEVEL)

/* Interrupt mask */
#define CounterLP2_INTR_MASK_TC                   ((uint32)CounterLP2__INTR_MASK_TC)
#define CounterLP2_INTR_MASK_CC_MATCH             ((uint32)CounterLP2__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define CounterLP2_CC_MATCH_SET                   (0x00u)
#define CounterLP2_CC_MATCH_CLEAR                 (0x01u)
#define CounterLP2_CC_MATCH_INVERT                (0x02u)
#define CounterLP2_CC_MATCH_NO_CHANGE             (0x03u)
#define CounterLP2_OVERLOW_SET                    (0x00u)
#define CounterLP2_OVERLOW_CLEAR                  (0x04u)
#define CounterLP2_OVERLOW_INVERT                 (0x08u)
#define CounterLP2_OVERLOW_NO_CHANGE              (0x0Cu)
#define CounterLP2_UNDERFLOW_SET                  (0x00u)
#define CounterLP2_UNDERFLOW_CLEAR                (0x10u)
#define CounterLP2_UNDERFLOW_INVERT               (0x20u)
#define CounterLP2_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define CounterLP2_PWM_MODE_LEFT                  (CounterLP2_CC_MATCH_CLEAR        |   \
                                                         CounterLP2_OVERLOW_SET           |   \
                                                         CounterLP2_UNDERFLOW_NO_CHANGE)
#define CounterLP2_PWM_MODE_RIGHT                 (CounterLP2_CC_MATCH_SET          |   \
                                                         CounterLP2_OVERLOW_NO_CHANGE     |   \
                                                         CounterLP2_UNDERFLOW_CLEAR)
#define CounterLP2_PWM_MODE_ASYM                  (CounterLP2_CC_MATCH_INVERT       |   \
                                                         CounterLP2_OVERLOW_SET           |   \
                                                         CounterLP2_UNDERFLOW_CLEAR)

#if (CounterLP2_CY_TCPWM_V2)
    #if(CounterLP2_CY_TCPWM_4000)
        #define CounterLP2_PWM_MODE_CENTER                (CounterLP2_CC_MATCH_INVERT       |   \
                                                                 CounterLP2_OVERLOW_NO_CHANGE     |   \
                                                                 CounterLP2_UNDERFLOW_CLEAR)
    #else
        #define CounterLP2_PWM_MODE_CENTER                (CounterLP2_CC_MATCH_INVERT       |   \
                                                                 CounterLP2_OVERLOW_SET           |   \
                                                                 CounterLP2_UNDERFLOW_CLEAR)
    #endif /* (CounterLP2_CY_TCPWM_4000) */
#else
    #define CounterLP2_PWM_MODE_CENTER                (CounterLP2_CC_MATCH_INVERT       |   \
                                                             CounterLP2_OVERLOW_NO_CHANGE     |   \
                                                             CounterLP2_UNDERFLOW_CLEAR)
#endif /* (CounterLP2_CY_TCPWM_NEW) */

/* Command operations without condition */
#define CounterLP2_CMD_CAPTURE                    (0u)
#define CounterLP2_CMD_RELOAD                     (8u)
#define CounterLP2_CMD_STOP                       (16u)
#define CounterLP2_CMD_START                      (24u)

/* Status */
#define CounterLP2_STATUS_DOWN                    (1u)
#define CounterLP2_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   CounterLP2_Init(void);
void   CounterLP2_Enable(void);
void   CounterLP2_Start(void);
void   CounterLP2_Stop(void);

void   CounterLP2_SetMode(uint32 mode);
void   CounterLP2_SetCounterMode(uint32 counterMode);
void   CounterLP2_SetPWMMode(uint32 modeMask);
void   CounterLP2_SetQDMode(uint32 qdMode);

void   CounterLP2_SetPrescaler(uint32 prescaler);
void   CounterLP2_TriggerCommand(uint32 mask, uint32 command);
void   CounterLP2_SetOneShot(uint32 oneShotEnable);
uint32 CounterLP2_ReadStatus(void);

void   CounterLP2_SetPWMSyncKill(uint32 syncKillEnable);
void   CounterLP2_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   CounterLP2_SetPWMDeadTime(uint32 deadTime);
void   CounterLP2_SetPWMInvert(uint32 mask);

void   CounterLP2_SetInterruptMode(uint32 interruptMask);
uint32 CounterLP2_GetInterruptSourceMasked(void);
uint32 CounterLP2_GetInterruptSource(void);
void   CounterLP2_ClearInterrupt(uint32 interruptMask);
void   CounterLP2_SetInterrupt(uint32 interruptMask);

void   CounterLP2_WriteCounter(uint32 count);
uint32 CounterLP2_ReadCounter(void);

uint32 CounterLP2_ReadCapture(void);
uint32 CounterLP2_ReadCaptureBuf(void);

void   CounterLP2_WritePeriod(uint32 period);
uint32 CounterLP2_ReadPeriod(void);
void   CounterLP2_WritePeriodBuf(uint32 periodBuf);
uint32 CounterLP2_ReadPeriodBuf(void);

void   CounterLP2_WriteCompare(uint32 compare);
uint32 CounterLP2_ReadCompare(void);
void   CounterLP2_WriteCompareBuf(uint32 compareBuf);
uint32 CounterLP2_ReadCompareBuf(void);

void   CounterLP2_SetPeriodSwap(uint32 swapEnable);
void   CounterLP2_SetCompareSwap(uint32 swapEnable);

void   CounterLP2_SetCaptureMode(uint32 triggerMode);
void   CounterLP2_SetReloadMode(uint32 triggerMode);
void   CounterLP2_SetStartMode(uint32 triggerMode);
void   CounterLP2_SetStopMode(uint32 triggerMode);
void   CounterLP2_SetCountMode(uint32 triggerMode);

void   CounterLP2_SaveConfig(void);
void   CounterLP2_RestoreConfig(void);
void   CounterLP2_Sleep(void);
void   CounterLP2_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define CounterLP2_BLOCK_CONTROL_REG              (*(reg32 *) CounterLP2_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define CounterLP2_BLOCK_CONTROL_PTR              ( (reg32 *) CounterLP2_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define CounterLP2_COMMAND_REG                    (*(reg32 *) CounterLP2_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define CounterLP2_COMMAND_PTR                    ( (reg32 *) CounterLP2_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define CounterLP2_INTRRUPT_CAUSE_REG             (*(reg32 *) CounterLP2_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define CounterLP2_INTRRUPT_CAUSE_PTR             ( (reg32 *) CounterLP2_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define CounterLP2_CONTROL_REG                    (*(reg32 *) CounterLP2_cy_m0s8_tcpwm_1__CTRL )
#define CounterLP2_CONTROL_PTR                    ( (reg32 *) CounterLP2_cy_m0s8_tcpwm_1__CTRL )
#define CounterLP2_STATUS_REG                     (*(reg32 *) CounterLP2_cy_m0s8_tcpwm_1__STATUS )
#define CounterLP2_STATUS_PTR                     ( (reg32 *) CounterLP2_cy_m0s8_tcpwm_1__STATUS )
#define CounterLP2_COUNTER_REG                    (*(reg32 *) CounterLP2_cy_m0s8_tcpwm_1__COUNTER )
#define CounterLP2_COUNTER_PTR                    ( (reg32 *) CounterLP2_cy_m0s8_tcpwm_1__COUNTER )
#define CounterLP2_COMP_CAP_REG                   (*(reg32 *) CounterLP2_cy_m0s8_tcpwm_1__CC )
#define CounterLP2_COMP_CAP_PTR                   ( (reg32 *) CounterLP2_cy_m0s8_tcpwm_1__CC )
#define CounterLP2_COMP_CAP_BUF_REG               (*(reg32 *) CounterLP2_cy_m0s8_tcpwm_1__CC_BUFF )
#define CounterLP2_COMP_CAP_BUF_PTR               ( (reg32 *) CounterLP2_cy_m0s8_tcpwm_1__CC_BUFF )
#define CounterLP2_PERIOD_REG                     (*(reg32 *) CounterLP2_cy_m0s8_tcpwm_1__PERIOD )
#define CounterLP2_PERIOD_PTR                     ( (reg32 *) CounterLP2_cy_m0s8_tcpwm_1__PERIOD )
#define CounterLP2_PERIOD_BUF_REG                 (*(reg32 *) CounterLP2_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define CounterLP2_PERIOD_BUF_PTR                 ( (reg32 *) CounterLP2_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define CounterLP2_TRIG_CONTROL0_REG              (*(reg32 *) CounterLP2_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define CounterLP2_TRIG_CONTROL0_PTR              ( (reg32 *) CounterLP2_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define CounterLP2_TRIG_CONTROL1_REG              (*(reg32 *) CounterLP2_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define CounterLP2_TRIG_CONTROL1_PTR              ( (reg32 *) CounterLP2_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define CounterLP2_TRIG_CONTROL2_REG              (*(reg32 *) CounterLP2_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define CounterLP2_TRIG_CONTROL2_PTR              ( (reg32 *) CounterLP2_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define CounterLP2_INTERRUPT_REQ_REG              (*(reg32 *) CounterLP2_cy_m0s8_tcpwm_1__INTR )
#define CounterLP2_INTERRUPT_REQ_PTR              ( (reg32 *) CounterLP2_cy_m0s8_tcpwm_1__INTR )
#define CounterLP2_INTERRUPT_SET_REG              (*(reg32 *) CounterLP2_cy_m0s8_tcpwm_1__INTR_SET )
#define CounterLP2_INTERRUPT_SET_PTR              ( (reg32 *) CounterLP2_cy_m0s8_tcpwm_1__INTR_SET )
#define CounterLP2_INTERRUPT_MASK_REG             (*(reg32 *) CounterLP2_cy_m0s8_tcpwm_1__INTR_MASK )
#define CounterLP2_INTERRUPT_MASK_PTR             ( (reg32 *) CounterLP2_cy_m0s8_tcpwm_1__INTR_MASK )
#define CounterLP2_INTERRUPT_MASKED_REG           (*(reg32 *) CounterLP2_cy_m0s8_tcpwm_1__INTR_MASKED )
#define CounterLP2_INTERRUPT_MASKED_PTR           ( (reg32 *) CounterLP2_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define CounterLP2_MASK                           ((uint32)CounterLP2_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define CounterLP2_RELOAD_CC_SHIFT                (0u)
#define CounterLP2_RELOAD_PERIOD_SHIFT            (1u)
#define CounterLP2_PWM_SYNC_KILL_SHIFT            (2u)
#define CounterLP2_PWM_STOP_KILL_SHIFT            (3u)
#define CounterLP2_PRESCALER_SHIFT                (8u)
#define CounterLP2_UPDOWN_SHIFT                   (16u)
#define CounterLP2_ONESHOT_SHIFT                  (18u)
#define CounterLP2_QUAD_MODE_SHIFT                (20u)
#define CounterLP2_INV_OUT_SHIFT                  (20u)
#define CounterLP2_INV_COMPL_OUT_SHIFT            (21u)
#define CounterLP2_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define CounterLP2_RELOAD_CC_MASK                 ((uint32)(CounterLP2_1BIT_MASK        <<  \
                                                                            CounterLP2_RELOAD_CC_SHIFT))
#define CounterLP2_RELOAD_PERIOD_MASK             ((uint32)(CounterLP2_1BIT_MASK        <<  \
                                                                            CounterLP2_RELOAD_PERIOD_SHIFT))
#define CounterLP2_PWM_SYNC_KILL_MASK             ((uint32)(CounterLP2_1BIT_MASK        <<  \
                                                                            CounterLP2_PWM_SYNC_KILL_SHIFT))
#define CounterLP2_PWM_STOP_KILL_MASK             ((uint32)(CounterLP2_1BIT_MASK        <<  \
                                                                            CounterLP2_PWM_STOP_KILL_SHIFT))
#define CounterLP2_PRESCALER_MASK                 ((uint32)(CounterLP2_8BIT_MASK        <<  \
                                                                            CounterLP2_PRESCALER_SHIFT))
#define CounterLP2_UPDOWN_MASK                    ((uint32)(CounterLP2_2BIT_MASK        <<  \
                                                                            CounterLP2_UPDOWN_SHIFT))
#define CounterLP2_ONESHOT_MASK                   ((uint32)(CounterLP2_1BIT_MASK        <<  \
                                                                            CounterLP2_ONESHOT_SHIFT))
#define CounterLP2_QUAD_MODE_MASK                 ((uint32)(CounterLP2_3BIT_MASK        <<  \
                                                                            CounterLP2_QUAD_MODE_SHIFT))
#define CounterLP2_INV_OUT_MASK                   ((uint32)(CounterLP2_2BIT_MASK        <<  \
                                                                            CounterLP2_INV_OUT_SHIFT))
#define CounterLP2_MODE_MASK                      ((uint32)(CounterLP2_3BIT_MASK        <<  \
                                                                            CounterLP2_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define CounterLP2_CAPTURE_SHIFT                  (0u)
#define CounterLP2_COUNT_SHIFT                    (2u)
#define CounterLP2_RELOAD_SHIFT                   (4u)
#define CounterLP2_STOP_SHIFT                     (6u)
#define CounterLP2_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define CounterLP2_CAPTURE_MASK                   ((uint32)(CounterLP2_2BIT_MASK        <<  \
                                                                  CounterLP2_CAPTURE_SHIFT))
#define CounterLP2_COUNT_MASK                     ((uint32)(CounterLP2_2BIT_MASK        <<  \
                                                                  CounterLP2_COUNT_SHIFT))
#define CounterLP2_RELOAD_MASK                    ((uint32)(CounterLP2_2BIT_MASK        <<  \
                                                                  CounterLP2_RELOAD_SHIFT))
#define CounterLP2_STOP_MASK                      ((uint32)(CounterLP2_2BIT_MASK        <<  \
                                                                  CounterLP2_STOP_SHIFT))
#define CounterLP2_START_MASK                     ((uint32)(CounterLP2_2BIT_MASK        <<  \
                                                                  CounterLP2_START_SHIFT))

/* MASK */
#define CounterLP2_1BIT_MASK                      ((uint32)0x01u)
#define CounterLP2_2BIT_MASK                      ((uint32)0x03u)
#define CounterLP2_3BIT_MASK                      ((uint32)0x07u)
#define CounterLP2_6BIT_MASK                      ((uint32)0x3Fu)
#define CounterLP2_8BIT_MASK                      ((uint32)0xFFu)
#define CounterLP2_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define CounterLP2_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define CounterLP2_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(CounterLP2_QUAD_ENCODING_MODES     << CounterLP2_QUAD_MODE_SHIFT))       |\
         ((uint32)(CounterLP2_CONFIG                  << CounterLP2_MODE_SHIFT)))

#define CounterLP2_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(CounterLP2_PWM_STOP_EVENT          << CounterLP2_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(CounterLP2_PWM_OUT_INVERT          << CounterLP2_INV_OUT_SHIFT))         |\
         ((uint32)(CounterLP2_PWM_OUT_N_INVERT        << CounterLP2_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(CounterLP2_PWM_MODE                << CounterLP2_MODE_SHIFT)))

#define CounterLP2_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(CounterLP2_PWM_RUN_MODE         << CounterLP2_ONESHOT_SHIFT))
            
#define CounterLP2_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(CounterLP2_PWM_ALIGN            << CounterLP2_UPDOWN_SHIFT))

#define CounterLP2_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(CounterLP2_PWM_KILL_EVENT      << CounterLP2_PWM_SYNC_KILL_SHIFT))

#define CounterLP2_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(CounterLP2_PWM_DEAD_TIME_CYCLE  << CounterLP2_PRESCALER_SHIFT))

#define CounterLP2_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(CounterLP2_PWM_PRESCALER        << CounterLP2_PRESCALER_SHIFT))

#define CounterLP2_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(CounterLP2_TC_PRESCALER            << CounterLP2_PRESCALER_SHIFT))       |\
         ((uint32)(CounterLP2_TC_COUNTER_MODE         << CounterLP2_UPDOWN_SHIFT))          |\
         ((uint32)(CounterLP2_TC_RUN_MODE             << CounterLP2_ONESHOT_SHIFT))         |\
         ((uint32)(CounterLP2_TC_COMP_CAP_MODE        << CounterLP2_MODE_SHIFT)))
        
#define CounterLP2_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(CounterLP2_QUAD_PHIA_SIGNAL_MODE   << CounterLP2_COUNT_SHIFT))           |\
         ((uint32)(CounterLP2_QUAD_INDEX_SIGNAL_MODE  << CounterLP2_RELOAD_SHIFT))          |\
         ((uint32)(CounterLP2_QUAD_STOP_SIGNAL_MODE   << CounterLP2_STOP_SHIFT))            |\
         ((uint32)(CounterLP2_QUAD_PHIB_SIGNAL_MODE   << CounterLP2_START_SHIFT)))

#define CounterLP2_PWM_SIGNALS_MODES                                                              \
        (((uint32)(CounterLP2_PWM_SWITCH_SIGNAL_MODE  << CounterLP2_CAPTURE_SHIFT))         |\
         ((uint32)(CounterLP2_PWM_COUNT_SIGNAL_MODE   << CounterLP2_COUNT_SHIFT))           |\
         ((uint32)(CounterLP2_PWM_RELOAD_SIGNAL_MODE  << CounterLP2_RELOAD_SHIFT))          |\
         ((uint32)(CounterLP2_PWM_STOP_SIGNAL_MODE    << CounterLP2_STOP_SHIFT))            |\
         ((uint32)(CounterLP2_PWM_START_SIGNAL_MODE   << CounterLP2_START_SHIFT)))

#define CounterLP2_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(CounterLP2_TC_CAPTURE_SIGNAL_MODE  << CounterLP2_CAPTURE_SHIFT))         |\
         ((uint32)(CounterLP2_TC_COUNT_SIGNAL_MODE    << CounterLP2_COUNT_SHIFT))           |\
         ((uint32)(CounterLP2_TC_RELOAD_SIGNAL_MODE   << CounterLP2_RELOAD_SHIFT))          |\
         ((uint32)(CounterLP2_TC_STOP_SIGNAL_MODE     << CounterLP2_STOP_SHIFT))            |\
         ((uint32)(CounterLP2_TC_START_SIGNAL_MODE    << CounterLP2_START_SHIFT)))
        
#define CounterLP2_TIMER_UPDOWN_CNT_USED                                                          \
                ((CounterLP2__COUNT_UPDOWN0 == CounterLP2_TC_COUNTER_MODE)                  ||\
                 (CounterLP2__COUNT_UPDOWN1 == CounterLP2_TC_COUNTER_MODE))

#define CounterLP2_PWM_UPDOWN_CNT_USED                                                            \
                ((CounterLP2__CENTER == CounterLP2_PWM_ALIGN)                               ||\
                 (CounterLP2__ASYMMETRIC == CounterLP2_PWM_ALIGN))               
        
#define CounterLP2_PWM_PR_INIT_VALUE              (1u)
#define CounterLP2_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_CounterLP2_H */

/* [] END OF FILE */
