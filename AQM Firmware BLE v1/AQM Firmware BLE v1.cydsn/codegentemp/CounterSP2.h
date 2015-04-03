/*******************************************************************************
* File Name: CounterSP2.h
* Version 2.0
*
* Description:
*  This file provides constants and parameter values for the CounterSP2
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

#if !defined(CY_TCPWM_CounterSP2_H)
#define CY_TCPWM_CounterSP2_H


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
} CounterSP2_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  CounterSP2_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define CounterSP2_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define CounterSP2_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define CounterSP2_CONFIG                         (1lu)

/* Quad Mode */
/* Parameters */
#define CounterSP2_QUAD_ENCODING_MODES            (0lu)

/* Signal modes */
#define CounterSP2_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define CounterSP2_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define CounterSP2_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define CounterSP2_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define CounterSP2_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define CounterSP2_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define CounterSP2_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define CounterSP2_TC_RUN_MODE                    (0lu)
#define CounterSP2_TC_COUNTER_MODE                (0lu)
#define CounterSP2_TC_COMP_CAP_MODE               (2lu)
#define CounterSP2_TC_PRESCALER                   (0lu)

/* Signal modes */
#define CounterSP2_TC_RELOAD_SIGNAL_MODE          (1lu)
#define CounterSP2_TC_COUNT_SIGNAL_MODE           (0lu)
#define CounterSP2_TC_START_SIGNAL_MODE           (0lu)
#define CounterSP2_TC_STOP_SIGNAL_MODE            (0lu)
#define CounterSP2_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define CounterSP2_TC_RELOAD_SIGNAL_PRESENT       (1lu)
#define CounterSP2_TC_COUNT_SIGNAL_PRESENT        (1lu)
#define CounterSP2_TC_START_SIGNAL_PRESENT        (0lu)
#define CounterSP2_TC_STOP_SIGNAL_PRESENT         (0lu)
#define CounterSP2_TC_CAPTURE_SIGNAL_PRESENT      (1lu)

/* Interrupt Mask */
#define CounterSP2_TC_INTERRUPT_MASK              (0lu)

/* PWM Mode */
/* Parameters */
#define CounterSP2_PWM_KILL_EVENT                 (0lu)
#define CounterSP2_PWM_STOP_EVENT                 (0lu)
#define CounterSP2_PWM_MODE                       (4lu)
#define CounterSP2_PWM_OUT_N_INVERT               (0lu)
#define CounterSP2_PWM_OUT_INVERT                 (0lu)
#define CounterSP2_PWM_ALIGN                      (0lu)
#define CounterSP2_PWM_RUN_MODE                   (0lu)
#define CounterSP2_PWM_DEAD_TIME_CYCLE            (0lu)
#define CounterSP2_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define CounterSP2_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define CounterSP2_PWM_COUNT_SIGNAL_MODE          (3lu)
#define CounterSP2_PWM_START_SIGNAL_MODE          (0lu)
#define CounterSP2_PWM_STOP_SIGNAL_MODE           (0lu)
#define CounterSP2_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define CounterSP2_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define CounterSP2_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define CounterSP2_PWM_START_SIGNAL_PRESENT       (0lu)
#define CounterSP2_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define CounterSP2_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define CounterSP2_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define CounterSP2_TC_PERIOD_VALUE                (5494lu)
#define CounterSP2_TC_COMPARE_VALUE               (65535lu)
#define CounterSP2_TC_COMPARE_BUF_VALUE           (65535lu)
#define CounterSP2_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define CounterSP2_PWM_PERIOD_VALUE               (65535lu)
#define CounterSP2_PWM_PERIOD_BUF_VALUE           (65535lu)
#define CounterSP2_PWM_PERIOD_SWAP                (0lu)
#define CounterSP2_PWM_COMPARE_VALUE              (65535lu)
#define CounterSP2_PWM_COMPARE_BUF_VALUE          (65535lu)
#define CounterSP2_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define CounterSP2__LEFT 0
#define CounterSP2__RIGHT 1
#define CounterSP2__CENTER 2
#define CounterSP2__ASYMMETRIC 3

#define CounterSP2__X1 0
#define CounterSP2__X2 1
#define CounterSP2__X4 2

#define CounterSP2__PWM 4
#define CounterSP2__PWM_DT 5
#define CounterSP2__PWM_PR 6

#define CounterSP2__INVERSE 1
#define CounterSP2__DIRECT 0

#define CounterSP2__CAPTURE 2
#define CounterSP2__COMPARE 0

#define CounterSP2__TRIG_LEVEL 3
#define CounterSP2__TRIG_RISING 0
#define CounterSP2__TRIG_FALLING 1
#define CounterSP2__TRIG_BOTH 2

#define CounterSP2__INTR_MASK_TC 1
#define CounterSP2__INTR_MASK_CC_MATCH 2
#define CounterSP2__INTR_MASK_NONE 0
#define CounterSP2__INTR_MASK_TC_CC 3

#define CounterSP2__UNCONFIG 8
#define CounterSP2__TIMER 1
#define CounterSP2__QUAD 3
#define CounterSP2__PWM_SEL 7

#define CounterSP2__COUNT_UP 0
#define CounterSP2__COUNT_DOWN 1
#define CounterSP2__COUNT_UPDOWN0 2
#define CounterSP2__COUNT_UPDOWN1 3


/* Prescaler */
#define CounterSP2_PRESCALE_DIVBY1                ((uint32)(0u << CounterSP2_PRESCALER_SHIFT))
#define CounterSP2_PRESCALE_DIVBY2                ((uint32)(1u << CounterSP2_PRESCALER_SHIFT))
#define CounterSP2_PRESCALE_DIVBY4                ((uint32)(2u << CounterSP2_PRESCALER_SHIFT))
#define CounterSP2_PRESCALE_DIVBY8                ((uint32)(3u << CounterSP2_PRESCALER_SHIFT))
#define CounterSP2_PRESCALE_DIVBY16               ((uint32)(4u << CounterSP2_PRESCALER_SHIFT))
#define CounterSP2_PRESCALE_DIVBY32               ((uint32)(5u << CounterSP2_PRESCALER_SHIFT))
#define CounterSP2_PRESCALE_DIVBY64               ((uint32)(6u << CounterSP2_PRESCALER_SHIFT))
#define CounterSP2_PRESCALE_DIVBY128              ((uint32)(7u << CounterSP2_PRESCALER_SHIFT))

/* TCPWM set modes */
#define CounterSP2_MODE_TIMER_COMPARE             ((uint32)(CounterSP2__COMPARE         <<  \
                                                                  CounterSP2_MODE_SHIFT))
#define CounterSP2_MODE_TIMER_CAPTURE             ((uint32)(CounterSP2__CAPTURE         <<  \
                                                                  CounterSP2_MODE_SHIFT))
#define CounterSP2_MODE_QUAD                      ((uint32)(CounterSP2__QUAD            <<  \
                                                                  CounterSP2_MODE_SHIFT))
#define CounterSP2_MODE_PWM                       ((uint32)(CounterSP2__PWM             <<  \
                                                                  CounterSP2_MODE_SHIFT))
#define CounterSP2_MODE_PWM_DT                    ((uint32)(CounterSP2__PWM_DT          <<  \
                                                                  CounterSP2_MODE_SHIFT))
#define CounterSP2_MODE_PWM_PR                    ((uint32)(CounterSP2__PWM_PR          <<  \
                                                                  CounterSP2_MODE_SHIFT))

/* Quad Modes */
#define CounterSP2_MODE_X1                        ((uint32)(CounterSP2__X1              <<  \
                                                                  CounterSP2_QUAD_MODE_SHIFT))
#define CounterSP2_MODE_X2                        ((uint32)(CounterSP2__X2              <<  \
                                                                  CounterSP2_QUAD_MODE_SHIFT))
#define CounterSP2_MODE_X4                        ((uint32)(CounterSP2__X4              <<  \
                                                                  CounterSP2_QUAD_MODE_SHIFT))

/* Counter modes */
#define CounterSP2_COUNT_UP                       ((uint32)(CounterSP2__COUNT_UP        <<  \
                                                                  CounterSP2_UPDOWN_SHIFT))
#define CounterSP2_COUNT_DOWN                     ((uint32)(CounterSP2__COUNT_DOWN      <<  \
                                                                  CounterSP2_UPDOWN_SHIFT))
#define CounterSP2_COUNT_UPDOWN0                  ((uint32)(CounterSP2__COUNT_UPDOWN0   <<  \
                                                                  CounterSP2_UPDOWN_SHIFT))
#define CounterSP2_COUNT_UPDOWN1                  ((uint32)(CounterSP2__COUNT_UPDOWN1   <<  \
                                                                  CounterSP2_UPDOWN_SHIFT))

/* PWM output invert */
#define CounterSP2_INVERT_LINE                    ((uint32)(CounterSP2__INVERSE         <<  \
                                                                  CounterSP2_INV_OUT_SHIFT))
#define CounterSP2_INVERT_LINE_N                  ((uint32)(CounterSP2__INVERSE         <<  \
                                                                  CounterSP2_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define CounterSP2_TRIG_RISING                    ((uint32)CounterSP2__TRIG_RISING)
#define CounterSP2_TRIG_FALLING                   ((uint32)CounterSP2__TRIG_FALLING)
#define CounterSP2_TRIG_BOTH                      ((uint32)CounterSP2__TRIG_BOTH)
#define CounterSP2_TRIG_LEVEL                     ((uint32)CounterSP2__TRIG_LEVEL)

/* Interrupt mask */
#define CounterSP2_INTR_MASK_TC                   ((uint32)CounterSP2__INTR_MASK_TC)
#define CounterSP2_INTR_MASK_CC_MATCH             ((uint32)CounterSP2__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define CounterSP2_CC_MATCH_SET                   (0x00u)
#define CounterSP2_CC_MATCH_CLEAR                 (0x01u)
#define CounterSP2_CC_MATCH_INVERT                (0x02u)
#define CounterSP2_CC_MATCH_NO_CHANGE             (0x03u)
#define CounterSP2_OVERLOW_SET                    (0x00u)
#define CounterSP2_OVERLOW_CLEAR                  (0x04u)
#define CounterSP2_OVERLOW_INVERT                 (0x08u)
#define CounterSP2_OVERLOW_NO_CHANGE              (0x0Cu)
#define CounterSP2_UNDERFLOW_SET                  (0x00u)
#define CounterSP2_UNDERFLOW_CLEAR                (0x10u)
#define CounterSP2_UNDERFLOW_INVERT               (0x20u)
#define CounterSP2_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define CounterSP2_PWM_MODE_LEFT                  (CounterSP2_CC_MATCH_CLEAR        |   \
                                                         CounterSP2_OVERLOW_SET           |   \
                                                         CounterSP2_UNDERFLOW_NO_CHANGE)
#define CounterSP2_PWM_MODE_RIGHT                 (CounterSP2_CC_MATCH_SET          |   \
                                                         CounterSP2_OVERLOW_NO_CHANGE     |   \
                                                         CounterSP2_UNDERFLOW_CLEAR)
#define CounterSP2_PWM_MODE_ASYM                  (CounterSP2_CC_MATCH_INVERT       |   \
                                                         CounterSP2_OVERLOW_SET           |   \
                                                         CounterSP2_UNDERFLOW_CLEAR)

#if (CounterSP2_CY_TCPWM_V2)
    #if(CounterSP2_CY_TCPWM_4000)
        #define CounterSP2_PWM_MODE_CENTER                (CounterSP2_CC_MATCH_INVERT       |   \
                                                                 CounterSP2_OVERLOW_NO_CHANGE     |   \
                                                                 CounterSP2_UNDERFLOW_CLEAR)
    #else
        #define CounterSP2_PWM_MODE_CENTER                (CounterSP2_CC_MATCH_INVERT       |   \
                                                                 CounterSP2_OVERLOW_SET           |   \
                                                                 CounterSP2_UNDERFLOW_CLEAR)
    #endif /* (CounterSP2_CY_TCPWM_4000) */
#else
    #define CounterSP2_PWM_MODE_CENTER                (CounterSP2_CC_MATCH_INVERT       |   \
                                                             CounterSP2_OVERLOW_NO_CHANGE     |   \
                                                             CounterSP2_UNDERFLOW_CLEAR)
#endif /* (CounterSP2_CY_TCPWM_NEW) */

/* Command operations without condition */
#define CounterSP2_CMD_CAPTURE                    (0u)
#define CounterSP2_CMD_RELOAD                     (8u)
#define CounterSP2_CMD_STOP                       (16u)
#define CounterSP2_CMD_START                      (24u)

/* Status */
#define CounterSP2_STATUS_DOWN                    (1u)
#define CounterSP2_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   CounterSP2_Init(void);
void   CounterSP2_Enable(void);
void   CounterSP2_Start(void);
void   CounterSP2_Stop(void);

void   CounterSP2_SetMode(uint32 mode);
void   CounterSP2_SetCounterMode(uint32 counterMode);
void   CounterSP2_SetPWMMode(uint32 modeMask);
void   CounterSP2_SetQDMode(uint32 qdMode);

void   CounterSP2_SetPrescaler(uint32 prescaler);
void   CounterSP2_TriggerCommand(uint32 mask, uint32 command);
void   CounterSP2_SetOneShot(uint32 oneShotEnable);
uint32 CounterSP2_ReadStatus(void);

void   CounterSP2_SetPWMSyncKill(uint32 syncKillEnable);
void   CounterSP2_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   CounterSP2_SetPWMDeadTime(uint32 deadTime);
void   CounterSP2_SetPWMInvert(uint32 mask);

void   CounterSP2_SetInterruptMode(uint32 interruptMask);
uint32 CounterSP2_GetInterruptSourceMasked(void);
uint32 CounterSP2_GetInterruptSource(void);
void   CounterSP2_ClearInterrupt(uint32 interruptMask);
void   CounterSP2_SetInterrupt(uint32 interruptMask);

void   CounterSP2_WriteCounter(uint32 count);
uint32 CounterSP2_ReadCounter(void);

uint32 CounterSP2_ReadCapture(void);
uint32 CounterSP2_ReadCaptureBuf(void);

void   CounterSP2_WritePeriod(uint32 period);
uint32 CounterSP2_ReadPeriod(void);
void   CounterSP2_WritePeriodBuf(uint32 periodBuf);
uint32 CounterSP2_ReadPeriodBuf(void);

void   CounterSP2_WriteCompare(uint32 compare);
uint32 CounterSP2_ReadCompare(void);
void   CounterSP2_WriteCompareBuf(uint32 compareBuf);
uint32 CounterSP2_ReadCompareBuf(void);

void   CounterSP2_SetPeriodSwap(uint32 swapEnable);
void   CounterSP2_SetCompareSwap(uint32 swapEnable);

void   CounterSP2_SetCaptureMode(uint32 triggerMode);
void   CounterSP2_SetReloadMode(uint32 triggerMode);
void   CounterSP2_SetStartMode(uint32 triggerMode);
void   CounterSP2_SetStopMode(uint32 triggerMode);
void   CounterSP2_SetCountMode(uint32 triggerMode);

void   CounterSP2_SaveConfig(void);
void   CounterSP2_RestoreConfig(void);
void   CounterSP2_Sleep(void);
void   CounterSP2_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define CounterSP2_BLOCK_CONTROL_REG              (*(reg32 *) CounterSP2_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define CounterSP2_BLOCK_CONTROL_PTR              ( (reg32 *) CounterSP2_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define CounterSP2_COMMAND_REG                    (*(reg32 *) CounterSP2_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define CounterSP2_COMMAND_PTR                    ( (reg32 *) CounterSP2_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define CounterSP2_INTRRUPT_CAUSE_REG             (*(reg32 *) CounterSP2_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define CounterSP2_INTRRUPT_CAUSE_PTR             ( (reg32 *) CounterSP2_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define CounterSP2_CONTROL_REG                    (*(reg32 *) CounterSP2_cy_m0s8_tcpwm_1__CTRL )
#define CounterSP2_CONTROL_PTR                    ( (reg32 *) CounterSP2_cy_m0s8_tcpwm_1__CTRL )
#define CounterSP2_STATUS_REG                     (*(reg32 *) CounterSP2_cy_m0s8_tcpwm_1__STATUS )
#define CounterSP2_STATUS_PTR                     ( (reg32 *) CounterSP2_cy_m0s8_tcpwm_1__STATUS )
#define CounterSP2_COUNTER_REG                    (*(reg32 *) CounterSP2_cy_m0s8_tcpwm_1__COUNTER )
#define CounterSP2_COUNTER_PTR                    ( (reg32 *) CounterSP2_cy_m0s8_tcpwm_1__COUNTER )
#define CounterSP2_COMP_CAP_REG                   (*(reg32 *) CounterSP2_cy_m0s8_tcpwm_1__CC )
#define CounterSP2_COMP_CAP_PTR                   ( (reg32 *) CounterSP2_cy_m0s8_tcpwm_1__CC )
#define CounterSP2_COMP_CAP_BUF_REG               (*(reg32 *) CounterSP2_cy_m0s8_tcpwm_1__CC_BUFF )
#define CounterSP2_COMP_CAP_BUF_PTR               ( (reg32 *) CounterSP2_cy_m0s8_tcpwm_1__CC_BUFF )
#define CounterSP2_PERIOD_REG                     (*(reg32 *) CounterSP2_cy_m0s8_tcpwm_1__PERIOD )
#define CounterSP2_PERIOD_PTR                     ( (reg32 *) CounterSP2_cy_m0s8_tcpwm_1__PERIOD )
#define CounterSP2_PERIOD_BUF_REG                 (*(reg32 *) CounterSP2_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define CounterSP2_PERIOD_BUF_PTR                 ( (reg32 *) CounterSP2_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define CounterSP2_TRIG_CONTROL0_REG              (*(reg32 *) CounterSP2_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define CounterSP2_TRIG_CONTROL0_PTR              ( (reg32 *) CounterSP2_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define CounterSP2_TRIG_CONTROL1_REG              (*(reg32 *) CounterSP2_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define CounterSP2_TRIG_CONTROL1_PTR              ( (reg32 *) CounterSP2_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define CounterSP2_TRIG_CONTROL2_REG              (*(reg32 *) CounterSP2_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define CounterSP2_TRIG_CONTROL2_PTR              ( (reg32 *) CounterSP2_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define CounterSP2_INTERRUPT_REQ_REG              (*(reg32 *) CounterSP2_cy_m0s8_tcpwm_1__INTR )
#define CounterSP2_INTERRUPT_REQ_PTR              ( (reg32 *) CounterSP2_cy_m0s8_tcpwm_1__INTR )
#define CounterSP2_INTERRUPT_SET_REG              (*(reg32 *) CounterSP2_cy_m0s8_tcpwm_1__INTR_SET )
#define CounterSP2_INTERRUPT_SET_PTR              ( (reg32 *) CounterSP2_cy_m0s8_tcpwm_1__INTR_SET )
#define CounterSP2_INTERRUPT_MASK_REG             (*(reg32 *) CounterSP2_cy_m0s8_tcpwm_1__INTR_MASK )
#define CounterSP2_INTERRUPT_MASK_PTR             ( (reg32 *) CounterSP2_cy_m0s8_tcpwm_1__INTR_MASK )
#define CounterSP2_INTERRUPT_MASKED_REG           (*(reg32 *) CounterSP2_cy_m0s8_tcpwm_1__INTR_MASKED )
#define CounterSP2_INTERRUPT_MASKED_PTR           ( (reg32 *) CounterSP2_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define CounterSP2_MASK                           ((uint32)CounterSP2_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define CounterSP2_RELOAD_CC_SHIFT                (0u)
#define CounterSP2_RELOAD_PERIOD_SHIFT            (1u)
#define CounterSP2_PWM_SYNC_KILL_SHIFT            (2u)
#define CounterSP2_PWM_STOP_KILL_SHIFT            (3u)
#define CounterSP2_PRESCALER_SHIFT                (8u)
#define CounterSP2_UPDOWN_SHIFT                   (16u)
#define CounterSP2_ONESHOT_SHIFT                  (18u)
#define CounterSP2_QUAD_MODE_SHIFT                (20u)
#define CounterSP2_INV_OUT_SHIFT                  (20u)
#define CounterSP2_INV_COMPL_OUT_SHIFT            (21u)
#define CounterSP2_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define CounterSP2_RELOAD_CC_MASK                 ((uint32)(CounterSP2_1BIT_MASK        <<  \
                                                                            CounterSP2_RELOAD_CC_SHIFT))
#define CounterSP2_RELOAD_PERIOD_MASK             ((uint32)(CounterSP2_1BIT_MASK        <<  \
                                                                            CounterSP2_RELOAD_PERIOD_SHIFT))
#define CounterSP2_PWM_SYNC_KILL_MASK             ((uint32)(CounterSP2_1BIT_MASK        <<  \
                                                                            CounterSP2_PWM_SYNC_KILL_SHIFT))
#define CounterSP2_PWM_STOP_KILL_MASK             ((uint32)(CounterSP2_1BIT_MASK        <<  \
                                                                            CounterSP2_PWM_STOP_KILL_SHIFT))
#define CounterSP2_PRESCALER_MASK                 ((uint32)(CounterSP2_8BIT_MASK        <<  \
                                                                            CounterSP2_PRESCALER_SHIFT))
#define CounterSP2_UPDOWN_MASK                    ((uint32)(CounterSP2_2BIT_MASK        <<  \
                                                                            CounterSP2_UPDOWN_SHIFT))
#define CounterSP2_ONESHOT_MASK                   ((uint32)(CounterSP2_1BIT_MASK        <<  \
                                                                            CounterSP2_ONESHOT_SHIFT))
#define CounterSP2_QUAD_MODE_MASK                 ((uint32)(CounterSP2_3BIT_MASK        <<  \
                                                                            CounterSP2_QUAD_MODE_SHIFT))
#define CounterSP2_INV_OUT_MASK                   ((uint32)(CounterSP2_2BIT_MASK        <<  \
                                                                            CounterSP2_INV_OUT_SHIFT))
#define CounterSP2_MODE_MASK                      ((uint32)(CounterSP2_3BIT_MASK        <<  \
                                                                            CounterSP2_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define CounterSP2_CAPTURE_SHIFT                  (0u)
#define CounterSP2_COUNT_SHIFT                    (2u)
#define CounterSP2_RELOAD_SHIFT                   (4u)
#define CounterSP2_STOP_SHIFT                     (6u)
#define CounterSP2_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define CounterSP2_CAPTURE_MASK                   ((uint32)(CounterSP2_2BIT_MASK        <<  \
                                                                  CounterSP2_CAPTURE_SHIFT))
#define CounterSP2_COUNT_MASK                     ((uint32)(CounterSP2_2BIT_MASK        <<  \
                                                                  CounterSP2_COUNT_SHIFT))
#define CounterSP2_RELOAD_MASK                    ((uint32)(CounterSP2_2BIT_MASK        <<  \
                                                                  CounterSP2_RELOAD_SHIFT))
#define CounterSP2_STOP_MASK                      ((uint32)(CounterSP2_2BIT_MASK        <<  \
                                                                  CounterSP2_STOP_SHIFT))
#define CounterSP2_START_MASK                     ((uint32)(CounterSP2_2BIT_MASK        <<  \
                                                                  CounterSP2_START_SHIFT))

/* MASK */
#define CounterSP2_1BIT_MASK                      ((uint32)0x01u)
#define CounterSP2_2BIT_MASK                      ((uint32)0x03u)
#define CounterSP2_3BIT_MASK                      ((uint32)0x07u)
#define CounterSP2_6BIT_MASK                      ((uint32)0x3Fu)
#define CounterSP2_8BIT_MASK                      ((uint32)0xFFu)
#define CounterSP2_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define CounterSP2_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define CounterSP2_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(CounterSP2_QUAD_ENCODING_MODES     << CounterSP2_QUAD_MODE_SHIFT))       |\
         ((uint32)(CounterSP2_CONFIG                  << CounterSP2_MODE_SHIFT)))

#define CounterSP2_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(CounterSP2_PWM_STOP_EVENT          << CounterSP2_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(CounterSP2_PWM_OUT_INVERT          << CounterSP2_INV_OUT_SHIFT))         |\
         ((uint32)(CounterSP2_PWM_OUT_N_INVERT        << CounterSP2_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(CounterSP2_PWM_MODE                << CounterSP2_MODE_SHIFT)))

#define CounterSP2_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(CounterSP2_PWM_RUN_MODE         << CounterSP2_ONESHOT_SHIFT))
            
#define CounterSP2_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(CounterSP2_PWM_ALIGN            << CounterSP2_UPDOWN_SHIFT))

#define CounterSP2_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(CounterSP2_PWM_KILL_EVENT      << CounterSP2_PWM_SYNC_KILL_SHIFT))

#define CounterSP2_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(CounterSP2_PWM_DEAD_TIME_CYCLE  << CounterSP2_PRESCALER_SHIFT))

#define CounterSP2_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(CounterSP2_PWM_PRESCALER        << CounterSP2_PRESCALER_SHIFT))

#define CounterSP2_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(CounterSP2_TC_PRESCALER            << CounterSP2_PRESCALER_SHIFT))       |\
         ((uint32)(CounterSP2_TC_COUNTER_MODE         << CounterSP2_UPDOWN_SHIFT))          |\
         ((uint32)(CounterSP2_TC_RUN_MODE             << CounterSP2_ONESHOT_SHIFT))         |\
         ((uint32)(CounterSP2_TC_COMP_CAP_MODE        << CounterSP2_MODE_SHIFT)))
        
#define CounterSP2_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(CounterSP2_QUAD_PHIA_SIGNAL_MODE   << CounterSP2_COUNT_SHIFT))           |\
         ((uint32)(CounterSP2_QUAD_INDEX_SIGNAL_MODE  << CounterSP2_RELOAD_SHIFT))          |\
         ((uint32)(CounterSP2_QUAD_STOP_SIGNAL_MODE   << CounterSP2_STOP_SHIFT))            |\
         ((uint32)(CounterSP2_QUAD_PHIB_SIGNAL_MODE   << CounterSP2_START_SHIFT)))

#define CounterSP2_PWM_SIGNALS_MODES                                                              \
        (((uint32)(CounterSP2_PWM_SWITCH_SIGNAL_MODE  << CounterSP2_CAPTURE_SHIFT))         |\
         ((uint32)(CounterSP2_PWM_COUNT_SIGNAL_MODE   << CounterSP2_COUNT_SHIFT))           |\
         ((uint32)(CounterSP2_PWM_RELOAD_SIGNAL_MODE  << CounterSP2_RELOAD_SHIFT))          |\
         ((uint32)(CounterSP2_PWM_STOP_SIGNAL_MODE    << CounterSP2_STOP_SHIFT))            |\
         ((uint32)(CounterSP2_PWM_START_SIGNAL_MODE   << CounterSP2_START_SHIFT)))

#define CounterSP2_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(CounterSP2_TC_CAPTURE_SIGNAL_MODE  << CounterSP2_CAPTURE_SHIFT))         |\
         ((uint32)(CounterSP2_TC_COUNT_SIGNAL_MODE    << CounterSP2_COUNT_SHIFT))           |\
         ((uint32)(CounterSP2_TC_RELOAD_SIGNAL_MODE   << CounterSP2_RELOAD_SHIFT))          |\
         ((uint32)(CounterSP2_TC_STOP_SIGNAL_MODE     << CounterSP2_STOP_SHIFT))            |\
         ((uint32)(CounterSP2_TC_START_SIGNAL_MODE    << CounterSP2_START_SHIFT)))
        
#define CounterSP2_TIMER_UPDOWN_CNT_USED                                                          \
                ((CounterSP2__COUNT_UPDOWN0 == CounterSP2_TC_COUNTER_MODE)                  ||\
                 (CounterSP2__COUNT_UPDOWN1 == CounterSP2_TC_COUNTER_MODE))

#define CounterSP2_PWM_UPDOWN_CNT_USED                                                            \
                ((CounterSP2__CENTER == CounterSP2_PWM_ALIGN)                               ||\
                 (CounterSP2__ASYMMETRIC == CounterSP2_PWM_ALIGN))               
        
#define CounterSP2_PWM_PR_INIT_VALUE              (1u)
#define CounterSP2_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_CounterSP2_H */

/* [] END OF FILE */
