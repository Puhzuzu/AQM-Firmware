/*******************************************************************************
* File Name: CounterSP1.h
* Version 2.0
*
* Description:
*  This file provides constants and parameter values for the CounterSP1
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

#if !defined(CY_TCPWM_CounterSP1_H)
#define CY_TCPWM_CounterSP1_H


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
} CounterSP1_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  CounterSP1_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define CounterSP1_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define CounterSP1_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define CounterSP1_CONFIG                         (1lu)

/* Quad Mode */
/* Parameters */
#define CounterSP1_QUAD_ENCODING_MODES            (0lu)

/* Signal modes */
#define CounterSP1_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define CounterSP1_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define CounterSP1_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define CounterSP1_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define CounterSP1_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define CounterSP1_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define CounterSP1_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define CounterSP1_TC_RUN_MODE                    (0lu)
#define CounterSP1_TC_COUNTER_MODE                (0lu)
#define CounterSP1_TC_COMP_CAP_MODE               (2lu)
#define CounterSP1_TC_PRESCALER                   (0lu)

/* Signal modes */
#define CounterSP1_TC_RELOAD_SIGNAL_MODE          (1lu)
#define CounterSP1_TC_COUNT_SIGNAL_MODE           (3lu)
#define CounterSP1_TC_START_SIGNAL_MODE           (0lu)
#define CounterSP1_TC_STOP_SIGNAL_MODE            (0lu)
#define CounterSP1_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define CounterSP1_TC_RELOAD_SIGNAL_PRESENT       (1lu)
#define CounterSP1_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define CounterSP1_TC_START_SIGNAL_PRESENT        (0lu)
#define CounterSP1_TC_STOP_SIGNAL_PRESENT         (0lu)
#define CounterSP1_TC_CAPTURE_SIGNAL_PRESENT      (1lu)

/* Interrupt Mask */
#define CounterSP1_TC_INTERRUPT_MASK              (0lu)

/* PWM Mode */
/* Parameters */
#define CounterSP1_PWM_KILL_EVENT                 (0lu)
#define CounterSP1_PWM_STOP_EVENT                 (0lu)
#define CounterSP1_PWM_MODE                       (4lu)
#define CounterSP1_PWM_OUT_N_INVERT               (0lu)
#define CounterSP1_PWM_OUT_INVERT                 (0lu)
#define CounterSP1_PWM_ALIGN                      (0lu)
#define CounterSP1_PWM_RUN_MODE                   (0lu)
#define CounterSP1_PWM_DEAD_TIME_CYCLE            (0lu)
#define CounterSP1_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define CounterSP1_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define CounterSP1_PWM_COUNT_SIGNAL_MODE          (3lu)
#define CounterSP1_PWM_START_SIGNAL_MODE          (0lu)
#define CounterSP1_PWM_STOP_SIGNAL_MODE           (0lu)
#define CounterSP1_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define CounterSP1_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define CounterSP1_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define CounterSP1_PWM_START_SIGNAL_PRESENT       (0lu)
#define CounterSP1_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define CounterSP1_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define CounterSP1_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define CounterSP1_TC_PERIOD_VALUE                (65535lu)
#define CounterSP1_TC_COMPARE_VALUE               (65535lu)
#define CounterSP1_TC_COMPARE_BUF_VALUE           (65535lu)
#define CounterSP1_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define CounterSP1_PWM_PERIOD_VALUE               (65535lu)
#define CounterSP1_PWM_PERIOD_BUF_VALUE           (65535lu)
#define CounterSP1_PWM_PERIOD_SWAP                (0lu)
#define CounterSP1_PWM_COMPARE_VALUE              (65535lu)
#define CounterSP1_PWM_COMPARE_BUF_VALUE          (65535lu)
#define CounterSP1_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define CounterSP1__LEFT 0
#define CounterSP1__RIGHT 1
#define CounterSP1__CENTER 2
#define CounterSP1__ASYMMETRIC 3

#define CounterSP1__X1 0
#define CounterSP1__X2 1
#define CounterSP1__X4 2

#define CounterSP1__PWM 4
#define CounterSP1__PWM_DT 5
#define CounterSP1__PWM_PR 6

#define CounterSP1__INVERSE 1
#define CounterSP1__DIRECT 0

#define CounterSP1__CAPTURE 2
#define CounterSP1__COMPARE 0

#define CounterSP1__TRIG_LEVEL 3
#define CounterSP1__TRIG_RISING 0
#define CounterSP1__TRIG_FALLING 1
#define CounterSP1__TRIG_BOTH 2

#define CounterSP1__INTR_MASK_TC 1
#define CounterSP1__INTR_MASK_CC_MATCH 2
#define CounterSP1__INTR_MASK_NONE 0
#define CounterSP1__INTR_MASK_TC_CC 3

#define CounterSP1__UNCONFIG 8
#define CounterSP1__TIMER 1
#define CounterSP1__QUAD 3
#define CounterSP1__PWM_SEL 7

#define CounterSP1__COUNT_UP 0
#define CounterSP1__COUNT_DOWN 1
#define CounterSP1__COUNT_UPDOWN0 2
#define CounterSP1__COUNT_UPDOWN1 3


/* Prescaler */
#define CounterSP1_PRESCALE_DIVBY1                ((uint32)(0u << CounterSP1_PRESCALER_SHIFT))
#define CounterSP1_PRESCALE_DIVBY2                ((uint32)(1u << CounterSP1_PRESCALER_SHIFT))
#define CounterSP1_PRESCALE_DIVBY4                ((uint32)(2u << CounterSP1_PRESCALER_SHIFT))
#define CounterSP1_PRESCALE_DIVBY8                ((uint32)(3u << CounterSP1_PRESCALER_SHIFT))
#define CounterSP1_PRESCALE_DIVBY16               ((uint32)(4u << CounterSP1_PRESCALER_SHIFT))
#define CounterSP1_PRESCALE_DIVBY32               ((uint32)(5u << CounterSP1_PRESCALER_SHIFT))
#define CounterSP1_PRESCALE_DIVBY64               ((uint32)(6u << CounterSP1_PRESCALER_SHIFT))
#define CounterSP1_PRESCALE_DIVBY128              ((uint32)(7u << CounterSP1_PRESCALER_SHIFT))

/* TCPWM set modes */
#define CounterSP1_MODE_TIMER_COMPARE             ((uint32)(CounterSP1__COMPARE         <<  \
                                                                  CounterSP1_MODE_SHIFT))
#define CounterSP1_MODE_TIMER_CAPTURE             ((uint32)(CounterSP1__CAPTURE         <<  \
                                                                  CounterSP1_MODE_SHIFT))
#define CounterSP1_MODE_QUAD                      ((uint32)(CounterSP1__QUAD            <<  \
                                                                  CounterSP1_MODE_SHIFT))
#define CounterSP1_MODE_PWM                       ((uint32)(CounterSP1__PWM             <<  \
                                                                  CounterSP1_MODE_SHIFT))
#define CounterSP1_MODE_PWM_DT                    ((uint32)(CounterSP1__PWM_DT          <<  \
                                                                  CounterSP1_MODE_SHIFT))
#define CounterSP1_MODE_PWM_PR                    ((uint32)(CounterSP1__PWM_PR          <<  \
                                                                  CounterSP1_MODE_SHIFT))

/* Quad Modes */
#define CounterSP1_MODE_X1                        ((uint32)(CounterSP1__X1              <<  \
                                                                  CounterSP1_QUAD_MODE_SHIFT))
#define CounterSP1_MODE_X2                        ((uint32)(CounterSP1__X2              <<  \
                                                                  CounterSP1_QUAD_MODE_SHIFT))
#define CounterSP1_MODE_X4                        ((uint32)(CounterSP1__X4              <<  \
                                                                  CounterSP1_QUAD_MODE_SHIFT))

/* Counter modes */
#define CounterSP1_COUNT_UP                       ((uint32)(CounterSP1__COUNT_UP        <<  \
                                                                  CounterSP1_UPDOWN_SHIFT))
#define CounterSP1_COUNT_DOWN                     ((uint32)(CounterSP1__COUNT_DOWN      <<  \
                                                                  CounterSP1_UPDOWN_SHIFT))
#define CounterSP1_COUNT_UPDOWN0                  ((uint32)(CounterSP1__COUNT_UPDOWN0   <<  \
                                                                  CounterSP1_UPDOWN_SHIFT))
#define CounterSP1_COUNT_UPDOWN1                  ((uint32)(CounterSP1__COUNT_UPDOWN1   <<  \
                                                                  CounterSP1_UPDOWN_SHIFT))

/* PWM output invert */
#define CounterSP1_INVERT_LINE                    ((uint32)(CounterSP1__INVERSE         <<  \
                                                                  CounterSP1_INV_OUT_SHIFT))
#define CounterSP1_INVERT_LINE_N                  ((uint32)(CounterSP1__INVERSE         <<  \
                                                                  CounterSP1_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define CounterSP1_TRIG_RISING                    ((uint32)CounterSP1__TRIG_RISING)
#define CounterSP1_TRIG_FALLING                   ((uint32)CounterSP1__TRIG_FALLING)
#define CounterSP1_TRIG_BOTH                      ((uint32)CounterSP1__TRIG_BOTH)
#define CounterSP1_TRIG_LEVEL                     ((uint32)CounterSP1__TRIG_LEVEL)

/* Interrupt mask */
#define CounterSP1_INTR_MASK_TC                   ((uint32)CounterSP1__INTR_MASK_TC)
#define CounterSP1_INTR_MASK_CC_MATCH             ((uint32)CounterSP1__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define CounterSP1_CC_MATCH_SET                   (0x00u)
#define CounterSP1_CC_MATCH_CLEAR                 (0x01u)
#define CounterSP1_CC_MATCH_INVERT                (0x02u)
#define CounterSP1_CC_MATCH_NO_CHANGE             (0x03u)
#define CounterSP1_OVERLOW_SET                    (0x00u)
#define CounterSP1_OVERLOW_CLEAR                  (0x04u)
#define CounterSP1_OVERLOW_INVERT                 (0x08u)
#define CounterSP1_OVERLOW_NO_CHANGE              (0x0Cu)
#define CounterSP1_UNDERFLOW_SET                  (0x00u)
#define CounterSP1_UNDERFLOW_CLEAR                (0x10u)
#define CounterSP1_UNDERFLOW_INVERT               (0x20u)
#define CounterSP1_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define CounterSP1_PWM_MODE_LEFT                  (CounterSP1_CC_MATCH_CLEAR        |   \
                                                         CounterSP1_OVERLOW_SET           |   \
                                                         CounterSP1_UNDERFLOW_NO_CHANGE)
#define CounterSP1_PWM_MODE_RIGHT                 (CounterSP1_CC_MATCH_SET          |   \
                                                         CounterSP1_OVERLOW_NO_CHANGE     |   \
                                                         CounterSP1_UNDERFLOW_CLEAR)
#define CounterSP1_PWM_MODE_ASYM                  (CounterSP1_CC_MATCH_INVERT       |   \
                                                         CounterSP1_OVERLOW_SET           |   \
                                                         CounterSP1_UNDERFLOW_CLEAR)

#if (CounterSP1_CY_TCPWM_V2)
    #if(CounterSP1_CY_TCPWM_4000)
        #define CounterSP1_PWM_MODE_CENTER                (CounterSP1_CC_MATCH_INVERT       |   \
                                                                 CounterSP1_OVERLOW_NO_CHANGE     |   \
                                                                 CounterSP1_UNDERFLOW_CLEAR)
    #else
        #define CounterSP1_PWM_MODE_CENTER                (CounterSP1_CC_MATCH_INVERT       |   \
                                                                 CounterSP1_OVERLOW_SET           |   \
                                                                 CounterSP1_UNDERFLOW_CLEAR)
    #endif /* (CounterSP1_CY_TCPWM_4000) */
#else
    #define CounterSP1_PWM_MODE_CENTER                (CounterSP1_CC_MATCH_INVERT       |   \
                                                             CounterSP1_OVERLOW_NO_CHANGE     |   \
                                                             CounterSP1_UNDERFLOW_CLEAR)
#endif /* (CounterSP1_CY_TCPWM_NEW) */

/* Command operations without condition */
#define CounterSP1_CMD_CAPTURE                    (0u)
#define CounterSP1_CMD_RELOAD                     (8u)
#define CounterSP1_CMD_STOP                       (16u)
#define CounterSP1_CMD_START                      (24u)

/* Status */
#define CounterSP1_STATUS_DOWN                    (1u)
#define CounterSP1_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   CounterSP1_Init(void);
void   CounterSP1_Enable(void);
void   CounterSP1_Start(void);
void   CounterSP1_Stop(void);

void   CounterSP1_SetMode(uint32 mode);
void   CounterSP1_SetCounterMode(uint32 counterMode);
void   CounterSP1_SetPWMMode(uint32 modeMask);
void   CounterSP1_SetQDMode(uint32 qdMode);

void   CounterSP1_SetPrescaler(uint32 prescaler);
void   CounterSP1_TriggerCommand(uint32 mask, uint32 command);
void   CounterSP1_SetOneShot(uint32 oneShotEnable);
uint32 CounterSP1_ReadStatus(void);

void   CounterSP1_SetPWMSyncKill(uint32 syncKillEnable);
void   CounterSP1_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   CounterSP1_SetPWMDeadTime(uint32 deadTime);
void   CounterSP1_SetPWMInvert(uint32 mask);

void   CounterSP1_SetInterruptMode(uint32 interruptMask);
uint32 CounterSP1_GetInterruptSourceMasked(void);
uint32 CounterSP1_GetInterruptSource(void);
void   CounterSP1_ClearInterrupt(uint32 interruptMask);
void   CounterSP1_SetInterrupt(uint32 interruptMask);

void   CounterSP1_WriteCounter(uint32 count);
uint32 CounterSP1_ReadCounter(void);

uint32 CounterSP1_ReadCapture(void);
uint32 CounterSP1_ReadCaptureBuf(void);

void   CounterSP1_WritePeriod(uint32 period);
uint32 CounterSP1_ReadPeriod(void);
void   CounterSP1_WritePeriodBuf(uint32 periodBuf);
uint32 CounterSP1_ReadPeriodBuf(void);

void   CounterSP1_WriteCompare(uint32 compare);
uint32 CounterSP1_ReadCompare(void);
void   CounterSP1_WriteCompareBuf(uint32 compareBuf);
uint32 CounterSP1_ReadCompareBuf(void);

void   CounterSP1_SetPeriodSwap(uint32 swapEnable);
void   CounterSP1_SetCompareSwap(uint32 swapEnable);

void   CounterSP1_SetCaptureMode(uint32 triggerMode);
void   CounterSP1_SetReloadMode(uint32 triggerMode);
void   CounterSP1_SetStartMode(uint32 triggerMode);
void   CounterSP1_SetStopMode(uint32 triggerMode);
void   CounterSP1_SetCountMode(uint32 triggerMode);

void   CounterSP1_SaveConfig(void);
void   CounterSP1_RestoreConfig(void);
void   CounterSP1_Sleep(void);
void   CounterSP1_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define CounterSP1_BLOCK_CONTROL_REG              (*(reg32 *) CounterSP1_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define CounterSP1_BLOCK_CONTROL_PTR              ( (reg32 *) CounterSP1_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define CounterSP1_COMMAND_REG                    (*(reg32 *) CounterSP1_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define CounterSP1_COMMAND_PTR                    ( (reg32 *) CounterSP1_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define CounterSP1_INTRRUPT_CAUSE_REG             (*(reg32 *) CounterSP1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define CounterSP1_INTRRUPT_CAUSE_PTR             ( (reg32 *) CounterSP1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define CounterSP1_CONTROL_REG                    (*(reg32 *) CounterSP1_cy_m0s8_tcpwm_1__CTRL )
#define CounterSP1_CONTROL_PTR                    ( (reg32 *) CounterSP1_cy_m0s8_tcpwm_1__CTRL )
#define CounterSP1_STATUS_REG                     (*(reg32 *) CounterSP1_cy_m0s8_tcpwm_1__STATUS )
#define CounterSP1_STATUS_PTR                     ( (reg32 *) CounterSP1_cy_m0s8_tcpwm_1__STATUS )
#define CounterSP1_COUNTER_REG                    (*(reg32 *) CounterSP1_cy_m0s8_tcpwm_1__COUNTER )
#define CounterSP1_COUNTER_PTR                    ( (reg32 *) CounterSP1_cy_m0s8_tcpwm_1__COUNTER )
#define CounterSP1_COMP_CAP_REG                   (*(reg32 *) CounterSP1_cy_m0s8_tcpwm_1__CC )
#define CounterSP1_COMP_CAP_PTR                   ( (reg32 *) CounterSP1_cy_m0s8_tcpwm_1__CC )
#define CounterSP1_COMP_CAP_BUF_REG               (*(reg32 *) CounterSP1_cy_m0s8_tcpwm_1__CC_BUFF )
#define CounterSP1_COMP_CAP_BUF_PTR               ( (reg32 *) CounterSP1_cy_m0s8_tcpwm_1__CC_BUFF )
#define CounterSP1_PERIOD_REG                     (*(reg32 *) CounterSP1_cy_m0s8_tcpwm_1__PERIOD )
#define CounterSP1_PERIOD_PTR                     ( (reg32 *) CounterSP1_cy_m0s8_tcpwm_1__PERIOD )
#define CounterSP1_PERIOD_BUF_REG                 (*(reg32 *) CounterSP1_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define CounterSP1_PERIOD_BUF_PTR                 ( (reg32 *) CounterSP1_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define CounterSP1_TRIG_CONTROL0_REG              (*(reg32 *) CounterSP1_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define CounterSP1_TRIG_CONTROL0_PTR              ( (reg32 *) CounterSP1_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define CounterSP1_TRIG_CONTROL1_REG              (*(reg32 *) CounterSP1_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define CounterSP1_TRIG_CONTROL1_PTR              ( (reg32 *) CounterSP1_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define CounterSP1_TRIG_CONTROL2_REG              (*(reg32 *) CounterSP1_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define CounterSP1_TRIG_CONTROL2_PTR              ( (reg32 *) CounterSP1_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define CounterSP1_INTERRUPT_REQ_REG              (*(reg32 *) CounterSP1_cy_m0s8_tcpwm_1__INTR )
#define CounterSP1_INTERRUPT_REQ_PTR              ( (reg32 *) CounterSP1_cy_m0s8_tcpwm_1__INTR )
#define CounterSP1_INTERRUPT_SET_REG              (*(reg32 *) CounterSP1_cy_m0s8_tcpwm_1__INTR_SET )
#define CounterSP1_INTERRUPT_SET_PTR              ( (reg32 *) CounterSP1_cy_m0s8_tcpwm_1__INTR_SET )
#define CounterSP1_INTERRUPT_MASK_REG             (*(reg32 *) CounterSP1_cy_m0s8_tcpwm_1__INTR_MASK )
#define CounterSP1_INTERRUPT_MASK_PTR             ( (reg32 *) CounterSP1_cy_m0s8_tcpwm_1__INTR_MASK )
#define CounterSP1_INTERRUPT_MASKED_REG           (*(reg32 *) CounterSP1_cy_m0s8_tcpwm_1__INTR_MASKED )
#define CounterSP1_INTERRUPT_MASKED_PTR           ( (reg32 *) CounterSP1_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define CounterSP1_MASK                           ((uint32)CounterSP1_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define CounterSP1_RELOAD_CC_SHIFT                (0u)
#define CounterSP1_RELOAD_PERIOD_SHIFT            (1u)
#define CounterSP1_PWM_SYNC_KILL_SHIFT            (2u)
#define CounterSP1_PWM_STOP_KILL_SHIFT            (3u)
#define CounterSP1_PRESCALER_SHIFT                (8u)
#define CounterSP1_UPDOWN_SHIFT                   (16u)
#define CounterSP1_ONESHOT_SHIFT                  (18u)
#define CounterSP1_QUAD_MODE_SHIFT                (20u)
#define CounterSP1_INV_OUT_SHIFT                  (20u)
#define CounterSP1_INV_COMPL_OUT_SHIFT            (21u)
#define CounterSP1_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define CounterSP1_RELOAD_CC_MASK                 ((uint32)(CounterSP1_1BIT_MASK        <<  \
                                                                            CounterSP1_RELOAD_CC_SHIFT))
#define CounterSP1_RELOAD_PERIOD_MASK             ((uint32)(CounterSP1_1BIT_MASK        <<  \
                                                                            CounterSP1_RELOAD_PERIOD_SHIFT))
#define CounterSP1_PWM_SYNC_KILL_MASK             ((uint32)(CounterSP1_1BIT_MASK        <<  \
                                                                            CounterSP1_PWM_SYNC_KILL_SHIFT))
#define CounterSP1_PWM_STOP_KILL_MASK             ((uint32)(CounterSP1_1BIT_MASK        <<  \
                                                                            CounterSP1_PWM_STOP_KILL_SHIFT))
#define CounterSP1_PRESCALER_MASK                 ((uint32)(CounterSP1_8BIT_MASK        <<  \
                                                                            CounterSP1_PRESCALER_SHIFT))
#define CounterSP1_UPDOWN_MASK                    ((uint32)(CounterSP1_2BIT_MASK        <<  \
                                                                            CounterSP1_UPDOWN_SHIFT))
#define CounterSP1_ONESHOT_MASK                   ((uint32)(CounterSP1_1BIT_MASK        <<  \
                                                                            CounterSP1_ONESHOT_SHIFT))
#define CounterSP1_QUAD_MODE_MASK                 ((uint32)(CounterSP1_3BIT_MASK        <<  \
                                                                            CounterSP1_QUAD_MODE_SHIFT))
#define CounterSP1_INV_OUT_MASK                   ((uint32)(CounterSP1_2BIT_MASK        <<  \
                                                                            CounterSP1_INV_OUT_SHIFT))
#define CounterSP1_MODE_MASK                      ((uint32)(CounterSP1_3BIT_MASK        <<  \
                                                                            CounterSP1_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define CounterSP1_CAPTURE_SHIFT                  (0u)
#define CounterSP1_COUNT_SHIFT                    (2u)
#define CounterSP1_RELOAD_SHIFT                   (4u)
#define CounterSP1_STOP_SHIFT                     (6u)
#define CounterSP1_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define CounterSP1_CAPTURE_MASK                   ((uint32)(CounterSP1_2BIT_MASK        <<  \
                                                                  CounterSP1_CAPTURE_SHIFT))
#define CounterSP1_COUNT_MASK                     ((uint32)(CounterSP1_2BIT_MASK        <<  \
                                                                  CounterSP1_COUNT_SHIFT))
#define CounterSP1_RELOAD_MASK                    ((uint32)(CounterSP1_2BIT_MASK        <<  \
                                                                  CounterSP1_RELOAD_SHIFT))
#define CounterSP1_STOP_MASK                      ((uint32)(CounterSP1_2BIT_MASK        <<  \
                                                                  CounterSP1_STOP_SHIFT))
#define CounterSP1_START_MASK                     ((uint32)(CounterSP1_2BIT_MASK        <<  \
                                                                  CounterSP1_START_SHIFT))

/* MASK */
#define CounterSP1_1BIT_MASK                      ((uint32)0x01u)
#define CounterSP1_2BIT_MASK                      ((uint32)0x03u)
#define CounterSP1_3BIT_MASK                      ((uint32)0x07u)
#define CounterSP1_6BIT_MASK                      ((uint32)0x3Fu)
#define CounterSP1_8BIT_MASK                      ((uint32)0xFFu)
#define CounterSP1_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define CounterSP1_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define CounterSP1_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(CounterSP1_QUAD_ENCODING_MODES     << CounterSP1_QUAD_MODE_SHIFT))       |\
         ((uint32)(CounterSP1_CONFIG                  << CounterSP1_MODE_SHIFT)))

#define CounterSP1_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(CounterSP1_PWM_STOP_EVENT          << CounterSP1_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(CounterSP1_PWM_OUT_INVERT          << CounterSP1_INV_OUT_SHIFT))         |\
         ((uint32)(CounterSP1_PWM_OUT_N_INVERT        << CounterSP1_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(CounterSP1_PWM_MODE                << CounterSP1_MODE_SHIFT)))

#define CounterSP1_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(CounterSP1_PWM_RUN_MODE         << CounterSP1_ONESHOT_SHIFT))
            
#define CounterSP1_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(CounterSP1_PWM_ALIGN            << CounterSP1_UPDOWN_SHIFT))

#define CounterSP1_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(CounterSP1_PWM_KILL_EVENT      << CounterSP1_PWM_SYNC_KILL_SHIFT))

#define CounterSP1_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(CounterSP1_PWM_DEAD_TIME_CYCLE  << CounterSP1_PRESCALER_SHIFT))

#define CounterSP1_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(CounterSP1_PWM_PRESCALER        << CounterSP1_PRESCALER_SHIFT))

#define CounterSP1_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(CounterSP1_TC_PRESCALER            << CounterSP1_PRESCALER_SHIFT))       |\
         ((uint32)(CounterSP1_TC_COUNTER_MODE         << CounterSP1_UPDOWN_SHIFT))          |\
         ((uint32)(CounterSP1_TC_RUN_MODE             << CounterSP1_ONESHOT_SHIFT))         |\
         ((uint32)(CounterSP1_TC_COMP_CAP_MODE        << CounterSP1_MODE_SHIFT)))
        
#define CounterSP1_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(CounterSP1_QUAD_PHIA_SIGNAL_MODE   << CounterSP1_COUNT_SHIFT))           |\
         ((uint32)(CounterSP1_QUAD_INDEX_SIGNAL_MODE  << CounterSP1_RELOAD_SHIFT))          |\
         ((uint32)(CounterSP1_QUAD_STOP_SIGNAL_MODE   << CounterSP1_STOP_SHIFT))            |\
         ((uint32)(CounterSP1_QUAD_PHIB_SIGNAL_MODE   << CounterSP1_START_SHIFT)))

#define CounterSP1_PWM_SIGNALS_MODES                                                              \
        (((uint32)(CounterSP1_PWM_SWITCH_SIGNAL_MODE  << CounterSP1_CAPTURE_SHIFT))         |\
         ((uint32)(CounterSP1_PWM_COUNT_SIGNAL_MODE   << CounterSP1_COUNT_SHIFT))           |\
         ((uint32)(CounterSP1_PWM_RELOAD_SIGNAL_MODE  << CounterSP1_RELOAD_SHIFT))          |\
         ((uint32)(CounterSP1_PWM_STOP_SIGNAL_MODE    << CounterSP1_STOP_SHIFT))            |\
         ((uint32)(CounterSP1_PWM_START_SIGNAL_MODE   << CounterSP1_START_SHIFT)))

#define CounterSP1_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(CounterSP1_TC_CAPTURE_SIGNAL_MODE  << CounterSP1_CAPTURE_SHIFT))         |\
         ((uint32)(CounterSP1_TC_COUNT_SIGNAL_MODE    << CounterSP1_COUNT_SHIFT))           |\
         ((uint32)(CounterSP1_TC_RELOAD_SIGNAL_MODE   << CounterSP1_RELOAD_SHIFT))          |\
         ((uint32)(CounterSP1_TC_STOP_SIGNAL_MODE     << CounterSP1_STOP_SHIFT))            |\
         ((uint32)(CounterSP1_TC_START_SIGNAL_MODE    << CounterSP1_START_SHIFT)))
        
#define CounterSP1_TIMER_UPDOWN_CNT_USED                                                          \
                ((CounterSP1__COUNT_UPDOWN0 == CounterSP1_TC_COUNTER_MODE)                  ||\
                 (CounterSP1__COUNT_UPDOWN1 == CounterSP1_TC_COUNTER_MODE))

#define CounterSP1_PWM_UPDOWN_CNT_USED                                                            \
                ((CounterSP1__CENTER == CounterSP1_PWM_ALIGN)                               ||\
                 (CounterSP1__ASYMMETRIC == CounterSP1_PWM_ALIGN))               
        
#define CounterSP1_PWM_PR_INIT_VALUE              (1u)
#define CounterSP1_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_CounterSP1_H */

/* [] END OF FILE */
