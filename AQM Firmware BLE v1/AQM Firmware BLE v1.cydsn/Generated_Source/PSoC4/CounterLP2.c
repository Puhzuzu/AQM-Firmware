/*******************************************************************************
* File Name: CounterLP2.c
* Version 2.0
*
* Description:
*  This file provides the source code to the API for the CounterLP2
*  component
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

#include "CounterLP2.h"

uint8 CounterLP2_initVar = 0u;


/*******************************************************************************
* Function Name: CounterLP2_Init
********************************************************************************
*
* Summary:
*  Initialize/Restore default CounterLP2 configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void CounterLP2_Init(void)
{

    /* Set values from customizer to CTRL */
    #if (CounterLP2__QUAD == CounterLP2_CONFIG)
        CounterLP2_CONTROL_REG = CounterLP2_CTRL_QUAD_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        CounterLP2_TRIG_CONTROL1_REG  = CounterLP2_QUAD_SIGNALS_MODES;

        /* Set values from customizer to INTR */
        CounterLP2_SetInterruptMode(CounterLP2_QUAD_INTERRUPT_MASK);
        
         /* Set other values */
        CounterLP2_SetCounterMode(CounterLP2_COUNT_DOWN);
        CounterLP2_WritePeriod(CounterLP2_QUAD_PERIOD_INIT_VALUE);
        CounterLP2_WriteCounter(CounterLP2_QUAD_PERIOD_INIT_VALUE);
    #endif  /* (CounterLP2__QUAD == CounterLP2_CONFIG) */

    #if (CounterLP2__TIMER == CounterLP2_CONFIG)
        CounterLP2_CONTROL_REG = CounterLP2_CTRL_TIMER_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        CounterLP2_TRIG_CONTROL1_REG  = CounterLP2_TIMER_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        CounterLP2_SetInterruptMode(CounterLP2_TC_INTERRUPT_MASK);
        
        /* Set other values from customizer */
        CounterLP2_WritePeriod(CounterLP2_TC_PERIOD_VALUE );

        #if (CounterLP2__COMPARE == CounterLP2_TC_COMP_CAP_MODE)
            CounterLP2_WriteCompare(CounterLP2_TC_COMPARE_VALUE);

            #if (1u == CounterLP2_TC_COMPARE_SWAP)
                CounterLP2_SetCompareSwap(1u);
                CounterLP2_WriteCompareBuf(CounterLP2_TC_COMPARE_BUF_VALUE);
            #endif  /* (1u == CounterLP2_TC_COMPARE_SWAP) */
        #endif  /* (CounterLP2__COMPARE == CounterLP2_TC_COMP_CAP_MODE) */

        /* Initialize counter value */
        #if (CounterLP2_CY_TCPWM_V2 && CounterLP2_TIMER_UPDOWN_CNT_USED && !CounterLP2_CY_TCPWM_4000)
            CounterLP2_WriteCounter(1u);
        #elif(CounterLP2__COUNT_DOWN == CounterLP2_TC_COUNTER_MODE)
            CounterLP2_WriteCounter(CounterLP2_TC_PERIOD_VALUE);
        #else
            CounterLP2_WriteCounter(0u);
        #endif /* (CounterLP2_CY_TCPWM_V2 && CounterLP2_TIMER_UPDOWN_CNT_USED && !CounterLP2_CY_TCPWM_4000) */
    #endif  /* (CounterLP2__TIMER == CounterLP2_CONFIG) */

    #if (CounterLP2__PWM_SEL == CounterLP2_CONFIG)
        CounterLP2_CONTROL_REG = CounterLP2_CTRL_PWM_BASE_CONFIG;

        #if (CounterLP2__PWM_PR == CounterLP2_PWM_MODE)
            CounterLP2_CONTROL_REG |= CounterLP2_CTRL_PWM_RUN_MODE;
            CounterLP2_WriteCounter(CounterLP2_PWM_PR_INIT_VALUE);
        #else
            CounterLP2_CONTROL_REG |= CounterLP2_CTRL_PWM_ALIGN | CounterLP2_CTRL_PWM_KILL_EVENT;
            
            /* Initialize counter value */
            #if (CounterLP2_CY_TCPWM_V2 && CounterLP2_PWM_UPDOWN_CNT_USED && !CounterLP2_CY_TCPWM_4000)
                CounterLP2_WriteCounter(1u);
            #elif (CounterLP2__RIGHT == CounterLP2_PWM_ALIGN)
                CounterLP2_WriteCounter(CounterLP2_PWM_PERIOD_VALUE);
            #else 
                CounterLP2_WriteCounter(0u);
            #endif  /* (CounterLP2_CY_TCPWM_V2 && CounterLP2_PWM_UPDOWN_CNT_USED && !CounterLP2_CY_TCPWM_4000) */
        #endif  /* (CounterLP2__PWM_PR == CounterLP2_PWM_MODE) */

        #if (CounterLP2__PWM_DT == CounterLP2_PWM_MODE)
            CounterLP2_CONTROL_REG |= CounterLP2_CTRL_PWM_DEAD_TIME_CYCLE;
        #endif  /* (CounterLP2__PWM_DT == CounterLP2_PWM_MODE) */

        #if (CounterLP2__PWM == CounterLP2_PWM_MODE)
            CounterLP2_CONTROL_REG |= CounterLP2_CTRL_PWM_PRESCALER;
        #endif  /* (CounterLP2__PWM == CounterLP2_PWM_MODE) */

        /* Set values from customizer to CTRL1 */
        CounterLP2_TRIG_CONTROL1_REG  = CounterLP2_PWM_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        CounterLP2_SetInterruptMode(CounterLP2_PWM_INTERRUPT_MASK);

        /* Set values from customizer to CTRL2 */
        #if (CounterLP2__PWM_PR == CounterLP2_PWM_MODE)
            CounterLP2_TRIG_CONTROL2_REG =
                    (CounterLP2_CC_MATCH_NO_CHANGE    |
                    CounterLP2_OVERLOW_NO_CHANGE      |
                    CounterLP2_UNDERFLOW_NO_CHANGE);
        #else
            #if (CounterLP2__LEFT == CounterLP2_PWM_ALIGN)
                CounterLP2_TRIG_CONTROL2_REG = CounterLP2_PWM_MODE_LEFT;
            #endif  /* ( CounterLP2_PWM_LEFT == CounterLP2_PWM_ALIGN) */

            #if (CounterLP2__RIGHT == CounterLP2_PWM_ALIGN)
                CounterLP2_TRIG_CONTROL2_REG = CounterLP2_PWM_MODE_RIGHT;
            #endif  /* ( CounterLP2_PWM_RIGHT == CounterLP2_PWM_ALIGN) */

            #if (CounterLP2__CENTER == CounterLP2_PWM_ALIGN)
                CounterLP2_TRIG_CONTROL2_REG = CounterLP2_PWM_MODE_CENTER;
            #endif  /* ( CounterLP2_PWM_CENTER == CounterLP2_PWM_ALIGN) */

            #if (CounterLP2__ASYMMETRIC == CounterLP2_PWM_ALIGN)
                CounterLP2_TRIG_CONTROL2_REG = CounterLP2_PWM_MODE_ASYM;
            #endif  /* (CounterLP2__ASYMMETRIC == CounterLP2_PWM_ALIGN) */
        #endif  /* (CounterLP2__PWM_PR == CounterLP2_PWM_MODE) */

        /* Set other values from customizer */
        CounterLP2_WritePeriod(CounterLP2_PWM_PERIOD_VALUE );
        CounterLP2_WriteCompare(CounterLP2_PWM_COMPARE_VALUE);

        #if (1u == CounterLP2_PWM_COMPARE_SWAP)
            CounterLP2_SetCompareSwap(1u);
            CounterLP2_WriteCompareBuf(CounterLP2_PWM_COMPARE_BUF_VALUE);
        #endif  /* (1u == CounterLP2_PWM_COMPARE_SWAP) */

        #if (1u == CounterLP2_PWM_PERIOD_SWAP)
            CounterLP2_SetPeriodSwap(1u);
            CounterLP2_WritePeriodBuf(CounterLP2_PWM_PERIOD_BUF_VALUE);
        #endif  /* (1u == CounterLP2_PWM_PERIOD_SWAP) */
    #endif  /* (CounterLP2__PWM_SEL == CounterLP2_CONFIG) */
    
}


/*******************************************************************************
* Function Name: CounterLP2_Enable
********************************************************************************
*
* Summary:
*  Enables the CounterLP2.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void CounterLP2_Enable(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    CounterLP2_BLOCK_CONTROL_REG |= CounterLP2_MASK;
    CyExitCriticalSection(enableInterrupts);

    /* Start Timer or PWM if start input is absent */
    #if (CounterLP2__PWM_SEL == CounterLP2_CONFIG)
        #if (0u == CounterLP2_PWM_START_SIGNAL_PRESENT)
            CounterLP2_TriggerCommand(CounterLP2_MASK, CounterLP2_CMD_START);
        #endif /* (0u == CounterLP2_PWM_START_SIGNAL_PRESENT) */
    #endif /* (CounterLP2__PWM_SEL == CounterLP2_CONFIG) */

    #if (CounterLP2__TIMER == CounterLP2_CONFIG)
        #if (0u == CounterLP2_TC_START_SIGNAL_PRESENT)
            CounterLP2_TriggerCommand(CounterLP2_MASK, CounterLP2_CMD_START);
        #endif /* (0u == CounterLP2_TC_START_SIGNAL_PRESENT) */
    #endif /* (CounterLP2__TIMER == CounterLP2_CONFIG) */
}


/*******************************************************************************
* Function Name: CounterLP2_Start
********************************************************************************
*
* Summary:
*  Initializes the CounterLP2 with default customizer
*  values when called the first time and enables the CounterLP2.
*  For subsequent calls the configuration is left unchanged and the component is
*  just enabled.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  CounterLP2_initVar: global variable is used to indicate initial
*  configuration of this component.  The variable is initialized to zero and set
*  to 1 the first time CounterLP2_Start() is called. This allows
*  enabling/disabling a component without re-initialization in all subsequent
*  calls to the CounterLP2_Start() routine.
*
*******************************************************************************/
void CounterLP2_Start(void)
{
    if (0u == CounterLP2_initVar)
    {
        CounterLP2_Init();
        CounterLP2_initVar = 1u;
    }

    CounterLP2_Enable();
}


/*******************************************************************************
* Function Name: CounterLP2_Stop
********************************************************************************
*
* Summary:
*  Disables the CounterLP2.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void CounterLP2_Stop(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    CounterLP2_BLOCK_CONTROL_REG &= (uint32)~CounterLP2_MASK;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: CounterLP2_SetMode
********************************************************************************
*
* Summary:
*  Sets the operation mode of the CounterLP2. This function is used when
*  configured as a generic CounterLP2 and the actual mode of operation is
*  set at runtime. The mode must be set while the component is disabled.
*
* Parameters:
*  mode: Mode for the CounterLP2 to operate in
*   Values:
*   - CounterLP2_MODE_TIMER_COMPARE - Timer / Counter with
*                                                 compare capability
*         - CounterLP2_MODE_TIMER_CAPTURE - Timer / Counter with
*                                                 capture capability
*         - CounterLP2_MODE_QUAD - Quadrature decoder
*         - CounterLP2_MODE_PWM - PWM
*         - CounterLP2_MODE_PWM_DT - PWM with dead time
*         - CounterLP2_MODE_PWM_PR - PWM with pseudo random capability
*
* Return:
*  None
*
*******************************************************************************/
void CounterLP2_SetMode(uint32 mode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    CounterLP2_CONTROL_REG &= (uint32)~CounterLP2_MODE_MASK;
    CounterLP2_CONTROL_REG |= mode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: CounterLP2_SetQDMode
********************************************************************************
*
* Summary:
*  Sets the the Quadrature Decoder to one of the 3 supported modes.
*  Its functionality is only applicable to Quadrature Decoder operation.
*
* Parameters:
*  qdMode: Quadrature Decoder mode
*   Values:
*         - CounterLP2_MODE_X1 - Counts on phi 1 rising
*         - CounterLP2_MODE_X2 - Counts on both edges of phi1 (2x faster)
*         - CounterLP2_MODE_X4 - Counts on both edges of phi1 and phi2
*                                        (4x faster)
*
* Return:
*  None
*
*******************************************************************************/
void CounterLP2_SetQDMode(uint32 qdMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    CounterLP2_CONTROL_REG &= (uint32)~CounterLP2_QUAD_MODE_MASK;
    CounterLP2_CONTROL_REG |= qdMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: CounterLP2_SetPrescaler
********************************************************************************
*
* Summary:
*  Sets the prescaler value that is applied to the clock input.  Not applicable
*  to a PWM with the dead time mode or Quadrature Decoder mode.
*
* Parameters:
*  prescaler: Prescaler divider value
*   Values:
*         - CounterLP2_PRESCALE_DIVBY1    - Divide by 1 (no prescaling)
*         - CounterLP2_PRESCALE_DIVBY2    - Divide by 2
*         - CounterLP2_PRESCALE_DIVBY4    - Divide by 4
*         - CounterLP2_PRESCALE_DIVBY8    - Divide by 8
*         - CounterLP2_PRESCALE_DIVBY16   - Divide by 16
*         - CounterLP2_PRESCALE_DIVBY32   - Divide by 32
*         - CounterLP2_PRESCALE_DIVBY64   - Divide by 64
*         - CounterLP2_PRESCALE_DIVBY128  - Divide by 128
*
* Return:
*  None
*
*******************************************************************************/
void CounterLP2_SetPrescaler(uint32 prescaler)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    CounterLP2_CONTROL_REG &= (uint32)~CounterLP2_PRESCALER_MASK;
    CounterLP2_CONTROL_REG |= prescaler;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: CounterLP2_SetOneShot
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the CounterLP2 runs
*  continuously or stops when terminal count is reached.  By default the
*  CounterLP2 operates in the continuous mode.
*
* Parameters:
*  oneShotEnable
*   Values:
*     - 0 - Continuous
*     - 1 - Enable One Shot
*
* Return:
*  None
*
*******************************************************************************/
void CounterLP2_SetOneShot(uint32 oneShotEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    CounterLP2_CONTROL_REG &= (uint32)~CounterLP2_ONESHOT_MASK;
    CounterLP2_CONTROL_REG |= ((uint32)((oneShotEnable & CounterLP2_1BIT_MASK) <<
                                                               CounterLP2_ONESHOT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: CounterLP2_SetPWMMode
********************************************************************************
*
* Summary:
*  Writes the control register that determines what mode of operation the PWM
*  output lines are driven in.  There is a setting for what to do on a
*  comparison match (CC_MATCH), on an overflow (OVERFLOW) and on an underflow
*  (UNDERFLOW).  The value for each of the three must be ORed together to form
*  the mode.
*
* Parameters:
*  modeMask: A combination of three mode settings.  Mask must include a value
*  for each of the three or use one of the preconfigured PWM settings.
*   Values:
*     - CC_MATCH_SET        - Set on comparison match
*     - CC_MATCH_CLEAR      - Clear on comparison match
*     - CC_MATCH_INVERT     - Invert on comparison match
*     - CC_MATCH_NO_CHANGE  - No change on comparison match
*     - OVERLOW_SET         - Set on overflow
*     - OVERLOW_CLEAR       - Clear on  overflow
*     - OVERLOW_INVERT      - Invert on overflow
*     - OVERLOW_NO_CHANGE   - No change on overflow
*     - UNDERFLOW_SET       - Set on underflow
*     - UNDERFLOW_CLEAR     - Clear on underflow
*     - UNDERFLOW_INVERT    - Invert on underflow
*     - UNDERFLOW_NO_CHANGE - No change on underflow
*     - PWM_MODE_LEFT       - Setting for left aligned PWM.  Should be combined
*                             with up counting mode
*     - PWM_MODE_RIGHT      - Setting for right aligned PWM.  Should be combined
*                             with down counting mode
*     - PWM_MODE_CENTER     - Setting for center aligned PWM.  Should be
*                             combined with up/down 0 mode
*     - PWM_MODE_ASYM       - Setting for asymmetric PWM.  Should be combined
*                             with up/down 1 mode
*
* Return:
*  None
*
*******************************************************************************/
void CounterLP2_SetPWMMode(uint32 modeMask)
{
    CounterLP2_TRIG_CONTROL2_REG = (modeMask & CounterLP2_6BIT_MASK);
}



/*******************************************************************************
* Function Name: CounterLP2_SetPWMSyncKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes asynchronous or synchronous kill operation.  By default the kill
*  operation is asynchronous.  This functionality is only applicable to the PWM
*  and PWM with dead time modes.
*
*  For Synchronous mode the kill signal disables both the line and line_n
*  signals until the next terminal count.
*
*  For Asynchronous mode the kill signal disables both the line and line_n
*  signals when the kill signal is present.  This mode should only be used
*  when the kill signal (stop input) is configured in the pass through mode
*  (Level sensitive signal).

*
* Parameters:
*  syncKillEnable
*   Values:
*     - 0 - Asynchronous
*     - 1 - Synchronous
*
* Return:
*  None
*
*******************************************************************************/
void CounterLP2_SetPWMSyncKill(uint32 syncKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    CounterLP2_CONTROL_REG &= (uint32)~CounterLP2_PWM_SYNC_KILL_MASK;
    CounterLP2_CONTROL_REG |= ((uint32)((syncKillEnable & CounterLP2_1BIT_MASK)  <<
                                               CounterLP2_PWM_SYNC_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: CounterLP2_SetPWMStopOnKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes the PWM counter to stop.  By default the kill operation does not stop
*  the counter.  This functionality is only applicable to the three PWM modes.
*
*
* Parameters:
*  stopOnKillEnable
*   Values:
*     - 0 - Don't stop
*     - 1 - Stop
*
* Return:
*  None
*
*******************************************************************************/
void CounterLP2_SetPWMStopOnKill(uint32 stopOnKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    CounterLP2_CONTROL_REG &= (uint32)~CounterLP2_PWM_STOP_KILL_MASK;
    CounterLP2_CONTROL_REG |= ((uint32)((stopOnKillEnable & CounterLP2_1BIT_MASK)  <<
                                                         CounterLP2_PWM_STOP_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: CounterLP2_SetPWMDeadTime
********************************************************************************
*
* Summary:
*  Writes the dead time control value.  This value delays the rising edge of
*  both the line and line_n signals the designated number of cycles resulting
*  in both signals being inactive for that many cycles.  This functionality is
*  only applicable to the PWM in the dead time mode.

*
* Parameters:
*  Dead time to insert
*   Values: 0 to 255
*
* Return:
*  None
*
*******************************************************************************/
void CounterLP2_SetPWMDeadTime(uint32 deadTime)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    CounterLP2_CONTROL_REG &= (uint32)~CounterLP2_PRESCALER_MASK;
    CounterLP2_CONTROL_REG |= ((uint32)((deadTime & CounterLP2_8BIT_MASK) <<
                                                          CounterLP2_PRESCALER_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: CounterLP2_SetPWMInvert
********************************************************************************
*
* Summary:
*  Writes the bits that control whether the line and line_n outputs are
*  inverted from their normal output values.  This functionality is only
*  applicable to the three PWM modes.
*
* Parameters:
*  mask: Mask of outputs to invert.
*   Values:
*         - CounterLP2_INVERT_LINE   - Inverts the line output
*         - CounterLP2_INVERT_LINE_N - Inverts the line_n output
*
* Return:
*  None
*
*******************************************************************************/
void CounterLP2_SetPWMInvert(uint32 mask)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    CounterLP2_CONTROL_REG &= (uint32)~CounterLP2_INV_OUT_MASK;
    CounterLP2_CONTROL_REG |= mask;

    CyExitCriticalSection(enableInterrupts);
}



/*******************************************************************************
* Function Name: CounterLP2_WriteCounter
********************************************************************************
*
* Summary:
*  Writes a new 16bit counter value directly into the counter register, thus
*  setting the counter (not the period) to the value written. It is not
*  advised to write to this field when the counter is running.
*
* Parameters:
*  count: value to write
*
* Return:
*  None
*
*******************************************************************************/
void CounterLP2_WriteCounter(uint32 count)
{
    CounterLP2_COUNTER_REG = (count & CounterLP2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: CounterLP2_ReadCounter
********************************************************************************
*
* Summary:
*  Reads the current counter value.
*
* Parameters:
*  None
*
* Return:
*  Current counter value
*
*******************************************************************************/
uint32 CounterLP2_ReadCounter(void)
{
    return (CounterLP2_COUNTER_REG & CounterLP2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: CounterLP2_SetCounterMode
********************************************************************************
*
* Summary:
*  Sets the counter mode.  Applicable to all modes except Quadrature Decoder
*  and the PWM with a pseudo random output.
*
* Parameters:
*  counterMode: Enumerated counter type values
*   Values:
*     - CounterLP2_COUNT_UP       - Counts up
*     - CounterLP2_COUNT_DOWN     - Counts down
*     - CounterLP2_COUNT_UPDOWN0  - Counts up and down. Terminal count
*                                         generated when counter reaches 0
*     - CounterLP2_COUNT_UPDOWN1  - Counts up and down. Terminal count
*                                         generated both when counter reaches 0
*                                         and period
*
* Return:
*  None
*
*******************************************************************************/
void CounterLP2_SetCounterMode(uint32 counterMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    CounterLP2_CONTROL_REG &= (uint32)~CounterLP2_UPDOWN_MASK;
    CounterLP2_CONTROL_REG |= counterMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: CounterLP2_WritePeriod
********************************************************************************
*
* Summary:
*  Writes the 16 bit period register with the new period value.
*  To cause the counter to count for N cycles this register should be written
*  with N-1 (counts from 0 to period inclusive).
*
* Parameters:
*  period: Period value
*
* Return:
*  None
*
*******************************************************************************/
void CounterLP2_WritePeriod(uint32 period)
{
    CounterLP2_PERIOD_REG = (period & CounterLP2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: CounterLP2_ReadPeriod
********************************************************************************
*
* Summary:
*  Reads the 16 bit period register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 CounterLP2_ReadPeriod(void)
{
    return (CounterLP2_PERIOD_REG & CounterLP2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: CounterLP2_SetCompareSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the compare registers are
*  swapped. When enabled in the Timer/Counter mode(without capture) the swap
*  occurs at a TC event. In the PWM mode the swap occurs at the next TC event
*  following a hardware switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void CounterLP2_SetCompareSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    CounterLP2_CONTROL_REG &= (uint32)~CounterLP2_RELOAD_CC_MASK;
    CounterLP2_CONTROL_REG |= (swapEnable & CounterLP2_1BIT_MASK);

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: CounterLP2_WritePeriodBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit period buf register with the new period value.
*
* Parameters:
*  periodBuf: Period value
*
* Return:
*  None
*
*******************************************************************************/
void CounterLP2_WritePeriodBuf(uint32 periodBuf)
{
    CounterLP2_PERIOD_BUF_REG = (periodBuf & CounterLP2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: CounterLP2_ReadPeriodBuf
********************************************************************************
*
* Summary:
*  Reads the 16 bit period buf register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 CounterLP2_ReadPeriodBuf(void)
{
    return (CounterLP2_PERIOD_BUF_REG & CounterLP2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: CounterLP2_SetPeriodSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the period registers are
*  swapped. When enabled in Timer/Counter mode the swap occurs at a TC event.
*  In the PWM mode the swap occurs at the next TC event following a hardware
*  switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void CounterLP2_SetPeriodSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    CounterLP2_CONTROL_REG &= (uint32)~CounterLP2_RELOAD_PERIOD_MASK;
    CounterLP2_CONTROL_REG |= ((uint32)((swapEnable & CounterLP2_1BIT_MASK) <<
                                                            CounterLP2_RELOAD_PERIOD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: CounterLP2_WriteCompare
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compare: Compare value
*
* Return:
*  None
*
*******************************************************************************/
void CounterLP2_WriteCompare(uint32 compare)
{
    #if (CounterLP2_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (CounterLP2_CY_TCPWM_4000) */

    #if (CounterLP2_CY_TCPWM_4000)
        currentMode = ((CounterLP2_CONTROL_REG & CounterLP2_UPDOWN_MASK) >> CounterLP2_UPDOWN_SHIFT);

        if (((uint32)CounterLP2__COUNT_DOWN == currentMode) && (0xFFFFu != compare))
        {
            compare++;
        }
        else if (((uint32)CounterLP2__COUNT_UP == currentMode) && (0u != compare))
        {
            compare--;
        }
        else
        {
        }
        
    
    #endif /* (CounterLP2_CY_TCPWM_4000) */
    
    CounterLP2_COMP_CAP_REG = (compare & CounterLP2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: CounterLP2_ReadCompare
********************************************************************************
*
* Summary:
*  Reads the compare register. Not applicable for Timer/Counter with Capture
*  or in Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Compare value
*
*******************************************************************************/
uint32 CounterLP2_ReadCompare(void)
{
    #if (CounterLP2_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (CounterLP2_CY_TCPWM_4000) */

    #if (CounterLP2_CY_TCPWM_4000)
        currentMode = ((CounterLP2_CONTROL_REG & CounterLP2_UPDOWN_MASK) >> CounterLP2_UPDOWN_SHIFT);
        
        regVal = CounterLP2_COMP_CAP_REG;
        
        if (((uint32)CounterLP2__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)CounterLP2__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & CounterLP2_16BIT_MASK);
    #else
        return (CounterLP2_COMP_CAP_REG & CounterLP2_16BIT_MASK);
    #endif /* (CounterLP2_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: CounterLP2_WriteCompareBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare buffer register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compareBuf: Compare value
*
* Return:
*  None
*
*******************************************************************************/
void CounterLP2_WriteCompareBuf(uint32 compareBuf)
{
    #if (CounterLP2_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (CounterLP2_CY_TCPWM_4000) */

    #if (CounterLP2_CY_TCPWM_4000)
        currentMode = ((CounterLP2_CONTROL_REG & CounterLP2_UPDOWN_MASK) >> CounterLP2_UPDOWN_SHIFT);

        if (((uint32)CounterLP2__COUNT_DOWN == currentMode) && (0xFFFFu != compareBuf))
        {
            compareBuf++;
        }
        else if (((uint32)CounterLP2__COUNT_UP == currentMode) && (0u != compareBuf))
        {
            compareBuf --;
        }
        else
        {
        }
    #endif /* (CounterLP2_CY_TCPWM_4000) */
    
    CounterLP2_COMP_CAP_BUF_REG = (compareBuf & CounterLP2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: CounterLP2_ReadCompareBuf
********************************************************************************
*
* Summary:
*  Reads the compare buffer register. Not applicable for Timer/Counter with
*  Capture or in Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Compare buffer value
*
*******************************************************************************/
uint32 CounterLP2_ReadCompareBuf(void)
{
    #if (CounterLP2_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (CounterLP2_CY_TCPWM_4000) */

    #if (CounterLP2_CY_TCPWM_4000)
        currentMode = ((CounterLP2_CONTROL_REG & CounterLP2_UPDOWN_MASK) >> CounterLP2_UPDOWN_SHIFT);

        regVal = CounterLP2_COMP_CAP_BUF_REG;
        
        if (((uint32)CounterLP2__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)CounterLP2__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & CounterLP2_16BIT_MASK);
    #else
        return (CounterLP2_COMP_CAP_BUF_REG & CounterLP2_16BIT_MASK);
    #endif /* (CounterLP2_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: CounterLP2_ReadCapture
********************************************************************************
*
* Summary:
*  Reads the captured counter value. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture value
*
*******************************************************************************/
uint32 CounterLP2_ReadCapture(void)
{
    return (CounterLP2_COMP_CAP_REG & CounterLP2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: CounterLP2_ReadCaptureBuf
********************************************************************************
*
* Summary:
*  Reads the capture buffer register. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture buffer value
*
*******************************************************************************/
uint32 CounterLP2_ReadCaptureBuf(void)
{
    return (CounterLP2_COMP_CAP_BUF_REG & CounterLP2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: CounterLP2_SetCaptureMode
********************************************************************************
*
* Summary:
*  Sets the capture trigger mode. For PWM mode this is the switch input.
*  This input is not applicable to the Timer/Counter without Capture and
*  Quadrature Decoder modes.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - CounterLP2_TRIG_LEVEL     - Level
*     - CounterLP2_TRIG_RISING    - Rising edge
*     - CounterLP2_TRIG_FALLING   - Falling edge
*     - CounterLP2_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void CounterLP2_SetCaptureMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    CounterLP2_TRIG_CONTROL1_REG &= (uint32)~CounterLP2_CAPTURE_MASK;
    CounterLP2_TRIG_CONTROL1_REG |= triggerMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: CounterLP2_SetReloadMode
********************************************************************************
*
* Summary:
*  Sets the reload trigger mode. For Quadrature Decoder mode this is the index
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - CounterLP2_TRIG_LEVEL     - Level
*     - CounterLP2_TRIG_RISING    - Rising edge
*     - CounterLP2_TRIG_FALLING   - Falling edge
*     - CounterLP2_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void CounterLP2_SetReloadMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    CounterLP2_TRIG_CONTROL1_REG &= (uint32)~CounterLP2_RELOAD_MASK;
    CounterLP2_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << CounterLP2_RELOAD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: CounterLP2_SetStartMode
********************************************************************************
*
* Summary:
*  Sets the start trigger mode. For Quadrature Decoder mode this is the
*  phiB input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - CounterLP2_TRIG_LEVEL     - Level
*     - CounterLP2_TRIG_RISING    - Rising edge
*     - CounterLP2_TRIG_FALLING   - Falling edge
*     - CounterLP2_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void CounterLP2_SetStartMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    CounterLP2_TRIG_CONTROL1_REG &= (uint32)~CounterLP2_START_MASK;
    CounterLP2_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << CounterLP2_START_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: CounterLP2_SetStopMode
********************************************************************************
*
* Summary:
*  Sets the stop trigger mode. For PWM mode this is the kill input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - CounterLP2_TRIG_LEVEL     - Level
*     - CounterLP2_TRIG_RISING    - Rising edge
*     - CounterLP2_TRIG_FALLING   - Falling edge
*     - CounterLP2_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void CounterLP2_SetStopMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    CounterLP2_TRIG_CONTROL1_REG &= (uint32)~CounterLP2_STOP_MASK;
    CounterLP2_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << CounterLP2_STOP_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: CounterLP2_SetCountMode
********************************************************************************
*
* Summary:
*  Sets the count trigger mode. For Quadrature Decoder mode this is the phiA
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - CounterLP2_TRIG_LEVEL     - Level
*     - CounterLP2_TRIG_RISING    - Rising edge
*     - CounterLP2_TRIG_FALLING   - Falling edge
*     - CounterLP2_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void CounterLP2_SetCountMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    CounterLP2_TRIG_CONTROL1_REG &= (uint32)~CounterLP2_COUNT_MASK;
    CounterLP2_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << CounterLP2_COUNT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: CounterLP2_TriggerCommand
********************************************************************************
*
* Summary:
*  Triggers the designated command to occur on the designated TCPWM instances.
*  The mask can be used to apply this command simultaneously to more than one
*  instance.  This allows multiple TCPWM instances to be synchronized.
*
* Parameters:
*  mask: A combination of mask bits for each instance of the TCPWM that the
*        command should apply to.  This function from one instance can be used
*        to apply the command to any of the instances in the design.
*        The mask value for a specific instance is available with the MASK
*        define.
*  command: Enumerated command values. Capture command only applicable for
*           Timer/Counter with Capture and PWM modes.
*   Values:
*     - CounterLP2_CMD_CAPTURE    - Trigger Capture command
*     - CounterLP2_CMD_RELOAD     - Trigger Reload command
*     - CounterLP2_CMD_STOP       - Trigger Stop command
*     - CounterLP2_CMD_START      - Trigger Start command
*
* Return:
*  None
*
*******************************************************************************/
void CounterLP2_TriggerCommand(uint32 mask, uint32 command)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    CounterLP2_COMMAND_REG = ((uint32)(mask << command));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: CounterLP2_ReadStatus
********************************************************************************
*
* Summary:
*  Reads the status of the CounterLP2.
*
* Parameters:
*  None
*
* Return:
*  Status
*   Values:
*     - CounterLP2_STATUS_DOWN    - Set if counting down
*     - CounterLP2_STATUS_RUNNING - Set if counter is running
*
*******************************************************************************/
uint32 CounterLP2_ReadStatus(void)
{
    return ((CounterLP2_STATUS_REG >> CounterLP2_RUNNING_STATUS_SHIFT) |
            (CounterLP2_STATUS_REG & CounterLP2_STATUS_DOWN));
}


/*******************************************************************************
* Function Name: CounterLP2_SetInterruptMode
********************************************************************************
*
* Summary:
*  Sets the interrupt mask to control which interrupt
*  requests generate the interrupt signal.
*
* Parameters:
*   interruptMask: Mask of bits to be enabled
*   Values:
*     - CounterLP2_INTR_MASK_TC       - Terminal count mask
*     - CounterLP2_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void CounterLP2_SetInterruptMode(uint32 interruptMask)
{
    CounterLP2_INTERRUPT_MASK_REG =  interruptMask;
}


/*******************************************************************************
* Function Name: CounterLP2_GetInterruptSourceMasked
********************************************************************************
*
* Summary:
*  Gets the interrupt requests masked by the interrupt mask.
*
* Parameters:
*   None
*
* Return:
*  Masked interrupt source
*   Values:
*     - CounterLP2_INTR_MASK_TC       - Terminal count mask
*     - CounterLP2_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 CounterLP2_GetInterruptSourceMasked(void)
{
    return (CounterLP2_INTERRUPT_MASKED_REG);
}


/*******************************************************************************
* Function Name: CounterLP2_GetInterruptSource
********************************************************************************
*
* Summary:
*  Gets the interrupt requests (without masking).
*
* Parameters:
*  None
*
* Return:
*  Interrupt request value
*   Values:
*     - CounterLP2_INTR_MASK_TC       - Terminal count mask
*     - CounterLP2_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 CounterLP2_GetInterruptSource(void)
{
    return (CounterLP2_INTERRUPT_REQ_REG);
}


/*******************************************************************************
* Function Name: CounterLP2_ClearInterrupt
********************************************************************************
*
* Summary:
*  Clears the interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to clear
*   Values:
*     - CounterLP2_INTR_MASK_TC       - Terminal count mask
*     - CounterLP2_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void CounterLP2_ClearInterrupt(uint32 interruptMask)
{
    CounterLP2_INTERRUPT_REQ_REG = interruptMask;
}


/*******************************************************************************
* Function Name: CounterLP2_SetInterrupt
********************************************************************************
*
* Summary:
*  Sets a software interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to set
*   Values:
*     - CounterLP2_INTR_MASK_TC       - Terminal count mask
*     - CounterLP2_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void CounterLP2_SetInterrupt(uint32 interruptMask)
{
    CounterLP2_INTERRUPT_SET_REG = interruptMask;
}


/* [] END OF FILE */
