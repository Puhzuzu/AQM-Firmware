/*******************************************************************************
* File Name: CounterLP1.h
* Version 2.0
*
* Description:
*  This file provides constants and parameter values for the CounterLP1
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

#if !defined(CY_TCPWM_CounterLP1_H)
#define CY_TCPWM_CounterLP1_H


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
} CounterLP1_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  CounterLP1_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define CounterLP1_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define CounterLP1_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define CounterLP1_CONFIG                         (1lu)

/* Quad Mode */
/* Parameters */
#define CounterLP1_QUAD_ENCODING_MODES            (0lu)

/* Signal modes */
#define CounterLP1_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define CounterLP1_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define CounterLP1_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define CounterLP1_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define CounterLP1_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define CounterLP1_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define CounterLP1_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define CounterLP1_TC_RUN_MODE                    (0lu)
#define CounterLP1_TC_COUNTER_MODE                (0lu)
#define CounterLP1_TC_COMP_CAP_MODE               (2lu)
#define CounterLP1_TC_PRESCALER                   (0lu)

/* Signal modes */
#define CounterLP1_TC_RELOAD_SIGNAL_MODE          (1lu)
#define CounterLP1_TC_COUNT_SIGNAL_MODE           (3lu)
#define CounterLP1_TC_START_SIGNAL_MODE           (0lu)
#define CounterLP1_TC_STOP_SIGNAL_MODE            (0lu)
#define CounterLP1_TC_CAPTURE_SIGNAL_MODE         (2lu)

/* Signal present */
#define CounterLP1_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define CounterLP1_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define CounterLP1_TC_START_SIGNAL_PRESENT        (0lu)
#define CounterLP1_TC_STOP_SIGNAL_PRESENT         (0lu)
#define CounterLP1_TC_CAPTURE_SIGNAL_PRESENT      (1lu)

/* Interrupt Mask */
#define CounterLP1_TC_INTERRUPT_MASK              (0lu)

/* PWM Mode */
/* Parameters */
#define CounterLP1_PWM_KILL_EVENT                 (0lu)
#define CounterLP1_PWM_STOP_EVENT                 (0lu)
#define CounterLP1_PWM_MODE                       (4lu)
#define CounterLP1_PWM_OUT_N_INVERT               (0lu)
#define CounterLP1_PWM_OUT_INVERT                 (0lu)
#define CounterLP1_PWM_ALIGN                      (0lu)
#define CounterLP1_PWM_RUN_MODE                   (0lu)
#define CounterLP1_PWM_DEAD_TIME_CYCLE            (0lu)
#define CounterLP1_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define CounterLP1_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define CounterLP1_PWM_COUNT_SIGNAL_MODE          (3lu)
#define CounterLP1_PWM_START_SIGNAL_MODE          (0lu)
#define CounterLP1_PWM_STOP_SIGNAL_MODE           (0lu)
#define CounterLP1_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define CounterLP1_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define CounterLP1_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define CounterLP1_PWM_START_SIGNAL_PRESENT       (0lu)
#define CounterLP1_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define CounterLP1_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define CounterLP1_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define CounterLP1_TC_PERIOD_VALUE                (65535lu)
#define CounterLP1_TC_COMPARE_VALUE               (65535lu)
#define CounterLP1_TC_COMPARE_BUF_VALUE           (65535lu)
#define CounterLP1_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define CounterLP1_PWM_PERIOD_VALUE               (65535lu)
#define CounterLP1_PWM_PERIOD_BUF_VALUE           (65535lu)
#define CounterLP1_PWM_PERIOD_SWAP                (0lu)
#define CounterLP1_PWM_COMPARE_VALUE              (65535lu)
#define CounterLP1_PWM_COMPARE_BUF_VALUE          (65535lu)
#define CounterLP1_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define CounterLP1__LEFT 0
#define CounterLP1__RIGHT 1
#define CounterLP1__CENTER 2
#define CounterLP1__ASYMMETRIC 3

#define CounterLP1__X1 0
#define CounterLP1__X2 1
#define CounterLP1__X4 2

#define CounterLP1__PWM 4
#define CounterLP1__PWM_DT 5
#define CounterLP1__PWM_PR 6

#define CounterLP1__INVERSE 1
#define CounterLP1__DIRECT 0

#define CounterLP1__CAPTURE 2
#define CounterLP1__COMPARE 0

#define CounterLP1__TRIG_LEVEL 3
#define CounterLP1__TRIG_RISING 0
#define CounterLP1__TRIG_FALLING 1
#define CounterLP1__TRIG_BOTH 2

#define CounterLP1__INTR_MASK_TC 1
#define CounterLP1__INTR_MASK_CC_MATCH 2
#define CounterLP1__INTR_MASK_NONE 0
#define CounterLP1__INTR_MASK_TC_CC 3

#define CounterLP1__UNCONFIG 8
#define CounterLP1__TIMER 1
#define CounterLP1__QUAD 3
#define CounterLP1__PWM_SEL 7

#define CounterLP1__COUNT_UP 0
#define CounterLP1__COUNT_DOWN 1
#define CounterLP1__COUNT_UPDOWN0 2
#define CounterLP1__COUNT_UPDOWN1 3


/* Prescaler */
#define CounterLP1_PRESCALE_DIVBY1                ((uint32)(0u << CounterLP1_PRESCALER_SHIFT))
#define CounterLP1_PRESCALE_DIVBY2                ((uint32)(1u << CounterLP1_PRESCALER_SHIFT))
#define CounterLP1_PRESCALE_DIVBY4                ((uint32)(2u << CounterLP1_PRESCALER_SHIFT))
#define CounterLP1_PRESCALE_DIVBY8                ((uint32)(3u << CounterLP1_PRESCALER_SHIFT))
#define CounterLP1_PRESCALE_DIVBY16               ((uint32)(4u << CounterLP1_PRESCALER_SHIFT))
#define CounterLP1_PRESCALE_DIVBY32               ((uint32)(5u << CounterLP1_PRESCALER_SHIFT))
#define CounterLP1_PRESCALE_DIVBY64               ((uint32)(6u << CounterLP1_PRESCALER_SHIFT))
#define CounterLP1_PRESCALE_DIVBY128              ((uint32)(7u << CounterLP1_PRESCALER_SHIFT))

/* TCPWM set modes */
#define CounterLP1_MODE_TIMER_COMPARE             ((uint32)(CounterLP1__COMPARE         <<  \
                                                                  CounterLP1_MODE_SHIFT))
#define CounterLP1_MODE_TIMER_CAPTURE             ((uint32)(CounterLP1__CAPTURE         <<  \
                                                                  CounterLP1_MODE_SHIFT))
#define CounterLP1_MODE_QUAD                      ((uint32)(CounterLP1__QUAD            <<  \
                                                                  CounterLP1_MODE_SHIFT))
#define CounterLP1_MODE_PWM                       ((uint32)(CounterLP1__PWM             <<  \
                                                                  CounterLP1_MODE_SHIFT))
#define CounterLP1_MODE_PWM_DT                    ((uint32)(CounterLP1__PWM_DT          <<  \
                                                                  CounterLP1_MODE_SHIFT))
#define CounterLP1_MODE_PWM_PR                    ((uint32)(CounterLP1__PWM_PR          <<  \
                                                                  CounterLP1_MODE_SHIFT))

/* Quad Modes */
#define CounterLP1_MODE_X1                        ((uint32)(CounterLP1__X1              <<  \
                                                                  CounterLP1_QUAD_MODE_SHIFT))
#define CounterLP1_MODE_X2                        ((uint32)(CounterLP1__X2              <<  \
                                                                  CounterLP1_QUAD_MODE_SHIFT))
#define CounterLP1_MODE_X4                        ((uint32)(CounterLP1__X4              <<  \
                                                                  CounterLP1_QUAD_MODE_SHIFT))

/* Counter modes */
#define CounterLP1_COUNT_UP                       ((uint32)(CounterLP1__COUNT_UP        <<  \
                                                                  CounterLP1_UPDOWN_SHIFT))
#define CounterLP1_COUNT_DOWN                     ((uint32)(CounterLP1__COUNT_DOWN      <<  \
                                                                  CounterLP1_UPDOWN_SHIFT))
#define CounterLP1_COUNT_UPDOWN0                  ((uint32)(CounterLP1__COUNT_UPDOWN0   <<  \
                                                                  CounterLP1_UPDOWN_SHIFT))
#define CounterLP1_COUNT_UPDOWN1                  ((uint32)(CounterLP1__COUNT_UPDOWN1   <<  \
                                                                  CounterLP1_UPDOWN_SHIFT))

/* PWM output invert */
#define CounterLP1_INVERT_LINE                    ((uint32)(CounterLP1__INVERSE         <<  \
                                                                  CounterLP1_INV_OUT_SHIFT))
#define CounterLP1_INVERT_LINE_N                  ((uint32)(CounterLP1__INVERSE         <<  \
                                                                  CounterLP1_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define CounterLP1_TRIG_RISING                    ((uint32)CounterLP1__TRIG_RISING)
#define CounterLP1_TRIG_FALLING                   ((uint32)CounterLP1__TRIG_FALLING)
#define CounterLP1_TRIG_BOTH                      ((uint32)CounterLP1__TRIG_BOTH)
#define CounterLP1_TRIG_LEVEL                     ((uint32)CounterLP1__TRIG_LEVEL)

/* Interrupt mask */
#define CounterLP1_INTR_MASK_TC                   ((uint32)CounterLP1__INTR_MASK_TC)
#define CounterLP1_INTR_MASK_CC_MATCH             ((uint32)CounterLP1__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define CounterLP1_CC_MATCH_SET                   (0x00u)
#define CounterLP1_CC_MATCH_CLEAR                 (0x01u)
#define CounterLP1_CC_MATCH_INVERT                (0x02u)
#define CounterLP1_CC_MATCH_NO_CHANGE             (0x03u)
#define CounterLP1_OVERLOW_SET                    (0x00u)
#define CounterLP1_OVERLOW_CLEAR                  (0x04u)
#define CounterLP1_OVERLOW_INVERT                 (0x08u)
#define CounterLP1_OVERLOW_NO_CHANGE              (0x0Cu)
#define CounterLP1_UNDERFLOW_SET                  (0x00u)
#define CounterLP1_UNDERFLOW_CLEAR                (0x10u)
#define CounterLP1_UNDERFLOW_INVERT               (0x20u)
#define CounterLP1_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define CounterLP1_PWM_MODE_LEFT                  (CounterLP1_CC_MATCH_CLEAR        |   \
                                                         CounterLP1_OVERLOW_SET           |   \
                                                         CounterLP1_UNDERFLOW_NO_CHANGE)
#define CounterLP1_PWM_MODE_RIGHT                 (CounterLP1_CC_MATCH_SET          |   \
                                                         CounterLP1_OVERLOW_NO_CHANGE     |   \
                                                         CounterLP1_UNDERFLOW_CLEAR)
#define CounterLP1_PWM_MODE_ASYM                  (CounterLP1_CC_MATCH_INVERT       |   \
                                                         CounterLP1_OVERLOW_SET           |   \
                                                         CounterLP1_UNDERFLOW_CLEAR)

#if (CounterLP1_CY_TCPWM_V2)
    #if(CounterLP1_CY_TCPWM_4000)
        #define CounterLP1_PWM_MODE_CENTER                (CounterLP1_CC_MATCH_INVERT       |   \
                                                                 CounterLP1_OVERLOW_NO_CHANGE     |   \
                                                                 CounterLP1_UNDERFLOW_CLEAR)
    #else
        #define CounterLP1_PWM_MODE_CENTER                (CounterLP1_CC_MATCH_INVERT       |   \
                                                                 CounterLP1_OVERLOW_SET           |   \
                                                                 CounterLP1_UNDERFLOW_CLEAR)
    #endif /* (CounterLP1_CY_TCPWM_4000) */
#else
    #define CounterLP1_PWM_MODE_CENTER                (CounterLP1_CC_MATCH_INVERT       |   \
                                                             CounterLP1_OVERLOW_NO_CHANGE     |   \
                                                             CounterLP1_UNDERFLOW_CLEAR)
#endif /* (CounterLP1_CY_TCPWM_NEW) */

/* Command operations without condition */
#define CounterLP1_CMD_CAPTURE                    (0u)
#define CounterLP1_CMD_RELOAD                     (8u)
#define CounterLP1_CMD_STOP                       (16u)
#define CounterLP1_CMD_START                      (24u)

/* Status */
#define CounterLP1_STATUS_DOWN                    (1u)
#define CounterLP1_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   CounterLP1_Init(void);
void   CounterLP1_Enable(void);
void   CounterLP1_Start(void);
void   CounterLP1_Stop(void);

void   CounterLP1_SetMode(uint32 mode);
void   CounterLP1_SetCounterMode(uint32 counterMode);
void   CounterLP1_SetPWMMode(uint32 modeMask);
void   CounterLP1_SetQDMode(uint32 qdMode);

void   CounterLP1_SetPrescaler(uint32 prescaler);
void   CounterLP1_TriggerCommand(uint32 mask, uint32 command);
void   CounterLP1_SetOneShot(uint32 oneShotEnable);
uint32 CounterLP1_ReadStatus(void);

void   CounterLP1_SetPWMSyncKill(uint32 syncKillEnable);
void   CounterLP1_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   CounterLP1_SetPWMDeadTime(uint32 deadTime);
void   CounterLP1_SetPWMInvert(uint32 mask);

void   CounterLP1_SetInterruptMode(uint32 interruptMask);
uint32 CounterLP1_GetInterruptSourceMasked(void);
uint32 CounterLP1_GetInterruptSource(void);
void   CounterLP1_ClearInterrupt(uint32 interruptMask);
void   CounterLP1_SetInterrupt(uint32 interruptMask);

void   CounterLP1_WriteCounter(uint32 count);
uint32 CounterLP1_ReadCounter(void);

uint32 CounterLP1_ReadCapture(void);
uint32 CounterLP1_ReadCaptureBuf(void);

void   CounterLP1_WritePeriod(uint32 period);
uint32 CounterLP1_ReadPeriod(void);
void   CounterLP1_WritePeriodBuf(uint32 periodBuf);
uint32 CounterLP1_ReadPeriodBuf(void);

void   CounterLP1_WriteCompare(uint32 compare);
uint32 CounterLP1_ReadCompare(void);
void   CounterLP1_WriteCompareBuf(uint32 compareBuf);
uint32 CounterLP1_ReadCompareBuf(void);

void   CounterLP1_SetPeriodSwap(uint32 swapEnable);
void   CounterLP1_SetCompareSwap(uint32 swapEnable);

void   CounterLP1_SetCaptureMode(uint32 triggerMode);
void   CounterLP1_SetReloadMode(uint32 triggerMode);
void   CounterLP1_SetStartMode(uint32 triggerMode);
void   CounterLP1_SetStopMode(uint32 triggerMode);
void   CounterLP1_SetCountMode(uint32 triggerMode);

void   CounterLP1_SaveConfig(void);
void   CounterLP1_RestoreConfig(void);
void   CounterLP1_Sleep(void);
void   CounterLP1_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define CounterLP1_BLOCK_CONTROL_REG              (*(reg32 *) CounterLP1_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define CounterLP1_BLOCK_CONTROL_PTR              ( (reg32 *) CounterLP1_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define CounterLP1_COMMAND_REG                    (*(reg32 *) CounterLP1_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define CounterLP1_COMMAND_PTR                    ( (reg32 *) CounterLP1_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define CounterLP1_INTRRUPT_CAUSE_REG             (*(reg32 *) CounterLP1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define CounterLP1_INTRRUPT_CAUSE_PTR             ( (reg32 *) CounterLP1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define CounterLP1_CONTROL_REG                    (*(reg32 *) CounterLP1_cy_m0s8_tcpwm_1__CTRL )
#define CounterLP1_CONTROL_PTR                    ( (reg32 *) CounterLP1_cy_m0s8_tcpwm_1__CTRL )
#define CounterLP1_STATUS_REG                     (*(reg32 *) CounterLP1_cy_m0s8_tcpwm_1__STATUS )
#define CounterLP1_STATUS_PTR                     ( (reg32 *) CounterLP1_cy_m0s8_tcpwm_1__STATUS )
#define CounterLP1_COUNTER_REG                    (*(reg32 *) CounterLP1_cy_m0s8_tcpwm_1__COUNTER )
#define CounterLP1_COUNTER_PTR                    ( (reg32 *) CounterLP1_cy_m0s8_tcpwm_1__COUNTER )
#define CounterLP1_COMP_CAP_REG                   (*(reg32 *) CounterLP1_cy_m0s8_tcpwm_1__CC )
#define CounterLP1_COMP_CAP_PTR                   ( (reg32 *) CounterLP1_cy_m0s8_tcpwm_1__CC )
#define CounterLP1_COMP_CAP_BUF_REG               (*(reg32 *) CounterLP1_cy_m0s8_tcpwm_1__CC_BUFF )
#define CounterLP1_COMP_CAP_BUF_PTR               ( (reg32 *) CounterLP1_cy_m0s8_tcpwm_1__CC_BUFF )
#define CounterLP1_PERIOD_REG                     (*(reg32 *) CounterLP1_cy_m0s8_tcpwm_1__PERIOD )
#define CounterLP1_PERIOD_PTR                     ( (reg32 *) CounterLP1_cy_m0s8_tcpwm_1__PERIOD )
#define CounterLP1_PERIOD_BUF_REG                 (*(reg32 *) CounterLP1_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define CounterLP1_PERIOD_BUF_PTR                 ( (reg32 *) CounterLP1_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define CounterLP1_TRIG_CONTROL0_REG              (*(reg32 *) CounterLP1_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define CounterLP1_TRIG_CONTROL0_PTR              ( (reg32 *) CounterLP1_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define CounterLP1_TRIG_CONTROL1_REG              (*(reg32 *) CounterLP1_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define CounterLP1_TRIG_CONTROL1_PTR              ( (reg32 *) CounterLP1_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define CounterLP1_TRIG_CONTROL2_REG              (*(reg32 *) CounterLP1_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define CounterLP1_TRIG_CONTROL2_PTR              ( (reg32 *) CounterLP1_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define CounterLP1_INTERRUPT_REQ_REG              (*(reg32 *) CounterLP1_cy_m0s8_tcpwm_1__INTR )
#define CounterLP1_INTERRUPT_REQ_PTR              ( (reg32 *) CounterLP1_cy_m0s8_tcpwm_1__INTR )
#define CounterLP1_INTERRUPT_SET_REG              (*(reg32 *) CounterLP1_cy_m0s8_tcpwm_1__INTR_SET )
#define CounterLP1_INTERRUPT_SET_PTR              ( (reg32 *) CounterLP1_cy_m0s8_tcpwm_1__INTR_SET )
#define CounterLP1_INTERRUPT_MASK_REG             (*(reg32 *) CounterLP1_cy_m0s8_tcpwm_1__INTR_MASK )
#define CounterLP1_INTERRUPT_MASK_PTR             ( (reg32 *) CounterLP1_cy_m0s8_tcpwm_1__INTR_MASK )
#define CounterLP1_INTERRUPT_MASKED_REG           (*(reg32 *) CounterLP1_cy_m0s8_tcpwm_1__INTR_MASKED )
#define CounterLP1_INTERRUPT_MASKED_PTR           ( (reg32 *) CounterLP1_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define CounterLP1_MASK                           ((uint32)CounterLP1_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define CounterLP1_RELOAD_CC_SHIFT                (0u)
#define CounterLP1_RELOAD_PERIOD_SHIFT            (1u)
#define CounterLP1_PWM_SYNC_KILL_SHIFT            (2u)
#define CounterLP1_PWM_STOP_KILL_SHIFT            (3u)
#define CounterLP1_PRESCALER_SHIFT                (8u)
#define CounterLP1_UPDOWN_SHIFT                   (16u)
#define CounterLP1_ONESHOT_SHIFT                  (18u)
#define CounterLP1_QUAD_MODE_SHIFT                (20u)
#define CounterLP1_INV_OUT_SHIFT                  (20u)
#define CounterLP1_INV_COMPL_OUT_SHIFT            (21u)
#define CounterLP1_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define CounterLP1_RELOAD_CC_MASK                 ((uint32)(CounterLP1_1BIT_MASK        <<  \
                                                                            CounterLP1_RELOAD_CC_SHIFT))
#define CounterLP1_RELOAD_PERIOD_MASK             ((uint32)(CounterLP1_1BIT_MASK        <<  \
                                                                            CounterLP1_RELOAD_PERIOD_SHIFT))
#define CounterLP1_PWM_SYNC_KILL_MASK             ((uint32)(CounterLP1_1BIT_MASK        <<  \
                                                                            CounterLP1_PWM_SYNC_KILL_SHIFT))
#define CounterLP1_PWM_STOP_KILL_MASK             ((uint32)(CounterLP1_1BIT_MASK        <<  \
                                                                            CounterLP1_PWM_STOP_KILL_SHIFT))
#define CounterLP1_PRESCALER_MASK                 ((uint32)(CounterLP1_8BIT_MASK        <<  \
                                                                            CounterLP1_PRESCALER_SHIFT))
#define CounterLP1_UPDOWN_MASK                    ((uint32)(CounterLP1_2BIT_MASK        <<  \
                                                                            CounterLP1_UPDOWN_SHIFT))
#define CounterLP1_ONESHOT_MASK                   ((uint32)(CounterLP1_1BIT_MASK        <<  \
                                                                            CounterLP1_ONESHOT_SHIFT))
#define CounterLP1_QUAD_MODE_MASK                 ((uint32)(CounterLP1_3BIT_MASK        <<  \
                                                                            CounterLP1_QUAD_MODE_SHIFT))
#define CounterLP1_INV_OUT_MASK                   ((uint32)(CounterLP1_2BIT_MASK        <<  \
                                                                            CounterLP1_INV_OUT_SHIFT))
#define CounterLP1_MODE_MASK                      ((uint32)(CounterLP1_3BIT_MASK        <<  \
                                                                            CounterLP1_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define CounterLP1_CAPTURE_SHIFT                  (0u)
#define CounterLP1_COUNT_SHIFT                    (2u)
#define CounterLP1_RELOAD_SHIFT                   (4u)
#define CounterLP1_STOP_SHIFT                     (6u)
#define CounterLP1_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define CounterLP1_CAPTURE_MASK                   ((uint32)(CounterLP1_2BIT_MASK        <<  \
                                                                  CounterLP1_CAPTURE_SHIFT))
#define CounterLP1_COUNT_MASK                     ((uint32)(CounterLP1_2BIT_MASK        <<  \
                                                                  CounterLP1_COUNT_SHIFT))
#define CounterLP1_RELOAD_MASK                    ((uint32)(CounterLP1_2BIT_MASK        <<  \
                                                                  CounterLP1_RELOAD_SHIFT))
#define CounterLP1_STOP_MASK                      ((uint32)(CounterLP1_2BIT_MASK        <<  \
                                                                  CounterLP1_STOP_SHIFT))
#define CounterLP1_START_MASK                     ((uint32)(CounterLP1_2BIT_MASK        <<  \
                                                                  CounterLP1_START_SHIFT))

/* MASK */
#define CounterLP1_1BIT_MASK                      ((uint32)0x01u)
#define CounterLP1_2BIT_MASK                      ((uint32)0x03u)
#define CounterLP1_3BIT_MASK                      ((uint32)0x07u)
#define CounterLP1_6BIT_MASK                      ((uint32)0x3Fu)
#define CounterLP1_8BIT_MASK                      ((uint32)0xFFu)
#define CounterLP1_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define CounterLP1_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define CounterLP1_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(CounterLP1_QUAD_ENCODING_MODES     << CounterLP1_QUAD_MODE_SHIFT))       |\
         ((uint32)(CounterLP1_CONFIG                  << CounterLP1_MODE_SHIFT)))

#define CounterLP1_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(CounterLP1_PWM_STOP_EVENT          << CounterLP1_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(CounterLP1_PWM_OUT_INVERT          << CounterLP1_INV_OUT_SHIFT))         |\
         ((uint32)(CounterLP1_PWM_OUT_N_INVERT        << CounterLP1_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(CounterLP1_PWM_MODE                << CounterLP1_MODE_SHIFT)))

#define CounterLP1_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(CounterLP1_PWM_RUN_MODE         << CounterLP1_ONESHOT_SHIFT))
            
#define CounterLP1_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(CounterLP1_PWM_ALIGN            << CounterLP1_UPDOWN_SHIFT))

#define CounterLP1_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(CounterLP1_PWM_KILL_EVENT      << CounterLP1_PWM_SYNC_KILL_SHIFT))

#define CounterLP1_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(CounterLP1_PWM_DEAD_TIME_CYCLE  << CounterLP1_PRESCALER_SHIFT))

#define CounterLP1_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(CounterLP1_PWM_PRESCALER        << CounterLP1_PRESCALER_SHIFT))

#define CounterLP1_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(CounterLP1_TC_PRESCALER            << CounterLP1_PRESCALER_SHIFT))       |\
         ((uint32)(CounterLP1_TC_COUNTER_MODE         << CounterLP1_UPDOWN_SHIFT))          |\
         ((uint32)(CounterLP1_TC_RUN_MODE             << CounterLP1_ONESHOT_SHIFT))         |\
         ((uint32)(CounterLP1_TC_COMP_CAP_MODE        << CounterLP1_MODE_SHIFT)))
        
#define CounterLP1_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(CounterLP1_QUAD_PHIA_SIGNAL_MODE   << CounterLP1_COUNT_SHIFT))           |\
         ((uint32)(CounterLP1_QUAD_INDEX_SIGNAL_MODE  << CounterLP1_RELOAD_SHIFT))          |\
         ((uint32)(CounterLP1_QUAD_STOP_SIGNAL_MODE   << CounterLP1_STOP_SHIFT))            |\
         ((uint32)(CounterLP1_QUAD_PHIB_SIGNAL_MODE   << CounterLP1_START_SHIFT)))

#define CounterLP1_PWM_SIGNALS_MODES                                                              \
        (((uint32)(CounterLP1_PWM_SWITCH_SIGNAL_MODE  << CounterLP1_CAPTURE_SHIFT))         |\
         ((uint32)(CounterLP1_PWM_COUNT_SIGNAL_MODE   << CounterLP1_COUNT_SHIFT))           |\
         ((uint32)(CounterLP1_PWM_RELOAD_SIGNAL_MODE  << CounterLP1_RELOAD_SHIFT))          |\
         ((uint32)(CounterLP1_PWM_STOP_SIGNAL_MODE    << CounterLP1_STOP_SHIFT))            |\
         ((uint32)(CounterLP1_PWM_START_SIGNAL_MODE   << CounterLP1_START_SHIFT)))

#define CounterLP1_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(CounterLP1_TC_CAPTURE_SIGNAL_MODE  << CounterLP1_CAPTURE_SHIFT))         |\
         ((uint32)(CounterLP1_TC_COUNT_SIGNAL_MODE    << CounterLP1_COUNT_SHIFT))           |\
         ((uint32)(CounterLP1_TC_RELOAD_SIGNAL_MODE   << CounterLP1_RELOAD_SHIFT))          |\
         ((uint32)(CounterLP1_TC_STOP_SIGNAL_MODE     << CounterLP1_STOP_SHIFT))            |\
         ((uint32)(CounterLP1_TC_START_SIGNAL_MODE    << CounterLP1_START_SHIFT)))
        
#define CounterLP1_TIMER_UPDOWN_CNT_USED                                                          \
                ((CounterLP1__COUNT_UPDOWN0 == CounterLP1_TC_COUNTER_MODE)                  ||\
                 (CounterLP1__COUNT_UPDOWN1 == CounterLP1_TC_COUNTER_MODE))

#define CounterLP1_PWM_UPDOWN_CNT_USED                                                            \
                ((CounterLP1__CENTER == CounterLP1_PWM_ALIGN)                               ||\
                 (CounterLP1__ASYMMETRIC == CounterLP1_PWM_ALIGN))               
        
#define CounterLP1_PWM_PR_INIT_VALUE              (1u)
#define CounterLP1_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_CounterLP1_H */

/* [] END OF FILE */
