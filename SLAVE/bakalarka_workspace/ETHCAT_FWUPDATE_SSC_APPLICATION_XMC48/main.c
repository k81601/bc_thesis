/*
 * Copyright (C) 2015 Infineon Technologies AG. All rights reserved.
 *
 * Infineon Technologies AG (Infineon) is supplying this software for use with
 * Infineon's microcontrollers.
 * This file can be freely distributed within development tools that are
 * supporting such microcontrollers.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 * ATTENTION:
 * This example demonstrates the ethercat peripheral of XMC 4800. For this purpose an
 * ethercat slave node implemented inside a library is included into this project.
 * This library is for demonstration purpose within this example only and is
 * not certified, not safe and not meant to be used in any other context than here.
 *
 */


/**
 * @file
 * @date 15 Feb, 2018
 * @version 3.0.0
 *
 * @brief XMC4800 Relax Kit EtherCat firmware update demo example
 *
 * This example initializes am ethercat slave node and makes only sense to be evaluated with a ethercat host.
 * The example demonstrates how to perform an software update via FoE (File over EtherCAT).
 *
 * Version 1.0.0 Initial (SSC 5.11, ECAT APP used, distributed clocks used)<br>
 * Version 2.0.0 Skipped <br>
 * Version 3.0.0 Upgraded example for SSC 5.12 <br>
 *
 */

/****************************************************************
* HEADER FILES
***************************************************************/
#include <DAVE.h>               //Declarations from DAVE Code Generation (includes SFR declaration)
#include "SSC/Src/XMC_ESCObjects.h"
#include "flashprog.h"
#include "firmwareupdate_SSC.h"

/****************************************************************
* MACROS AND DEFINES
***************************************************************/
#define P_LED1 P1_14
#define P_LED2 P0_14
#define P_LED3 P3_14
#define P_LED4 P0_15
#define P_LED5 P1_2
#define P_LED6 P3_13
#define P_LED7 P5_3
#define P_LED8 P3_11
#define MAP2LEVEL(x) ((x==0)?XMC_GPIO_OUTPUT_LEVEL_HIGH:XMC_GPIO_OUTPUT_LEVEL_LOW)

/****************************************************************
* LOCAL DATA
***************************************************************/

/****************************************************************
* API PROTOTYPES
***************************************************************/

/****************************************************************
* API IMPLEMENTATION
***************************************************************/

/**
 * @brief Init_ECAT_Adapt_LED
 *
 * Initializes the 8 LEDs available on the shield of XMC4800 Relax EtherCAT Kit
 * to output push pull.
 *
 * @input :  none
 *
 * @output : none
 *
 * @return : none
 *
 */
void Init_ECAT_Adapt_LED ()
{
  /* Set mode of all LED ports to push-pull and output level to low*/
  XMC_GPIO_SetMode(P_LED1, XMC_GPIO_MODE_OUTPUT_PUSH_PULL);
  XMC_GPIO_SetOutputHigh(P_LED1);
  XMC_GPIO_SetMode(P_LED2, XMC_GPIO_MODE_OUTPUT_PUSH_PULL);
  XMC_GPIO_SetOutputHigh(P_LED2);
  XMC_GPIO_SetMode(P_LED3, XMC_GPIO_MODE_OUTPUT_PUSH_PULL);
  XMC_GPIO_SetOutputHigh(P_LED3);
  XMC_GPIO_SetMode(P_LED4, XMC_GPIO_MODE_OUTPUT_PUSH_PULL);
  XMC_GPIO_SetOutputHigh(P_LED4);
  XMC_GPIO_SetMode(P_LED5, XMC_GPIO_MODE_OUTPUT_PUSH_PULL);
  XMC_GPIO_SetOutputHigh(P_LED5);
  XMC_GPIO_SetMode(P_LED6, XMC_GPIO_MODE_OUTPUT_PUSH_PULL);
  XMC_GPIO_SetOutputHigh(P_LED6);
  XMC_GPIO_SetMode(P_LED7, XMC_GPIO_MODE_OUTPUT_PUSH_PULL);
  XMC_GPIO_SetOutputHigh(P_LED7);
  XMC_GPIO_SetMode(P_LED8, XMC_GPIO_MODE_OUTPUT_PUSH_PULL);
  XMC_GPIO_SetOutputHigh(P_LED8);
}

/**
 * @brief Init_Relax_Button
 *
 * Initializes the 8 two BUTTON inputs available on XMC4800 Relax EtherCAT Kit
 * to input.
 *
 * @input :  none
 *
 * @output : none
 *
 * @return : none
 *
 */
void Init_Relax_Button ()
{
  /* INITIALIZE BUTTON1 ON PORT 5.13 FOR INPUT */
  /* Set mode to input tristate */
  XMC_GPIO_SetMode(P15_13, XMC_GPIO_MODE_INPUT_TRISTATE);
  /* Enable digital input. Only needed because P15.13 is an analog port */
  XMC_GPIO_EnableDigitalInput(P15_13);

  /* INITIALIZE BUTTON2 ON PORT 5.12 FOR INPUT */
  /* Set mode to input tristate */
  XMC_GPIO_SetMode(P15_12, XMC_GPIO_MODE_INPUT_TRISTATE);
  /* Enable digital input. Only needed because P15.12 is an analog port */
  XMC_GPIO_EnableDigitalInput(P15_12);
}

/**
 * @brief process_app
 *
 * Callback called from SSC stack to process I/Os.
 *
 * @input :  OUT_GENERIC: pointer to output structure (host->slave)
 *
 * @output : IN_GENERIC : pointer to input structure (slave->host)
 *
 * @return : none
 *
 */
void process_app(TOBJ7000 *OUT_GENERIC, TOBJ6000 *IN_GENERIC)
{
  /* Check if INIT state is entered, after firmware update was started
   * If yes, trigger system on reset to start bootloader
   */
  if (FWUPDATE_GetDownloadFinished()==1)
  {
    /* Restart in normal bootmode */
    /* Clear the reset cause field for proper reset detection of the ssw */
	XMC_SCU_RESET_ClearDeviceResetReason();
    /* Set normal boot mode */
    XMC_SCU_SetBootMode(XMC_SCU_BOOTMODE_NORMAL);
    /* Trigger power on reset */
    PPB->AIRCR = 1 << PPB_AIRCR_SYSRESETREQ_Pos |0x5FA<<PPB_AIRCR_VECTKEY_Pos | 0x1 << PPB_AIRCR_PRIGROUP_Pos;
  }

  /* OUTPUT PROCESSING */
  /* Check bitfield set by master OUT_GEN_Bit1..8 and set LEDs accordingly */
  XMC_GPIO_SetOutputLevel(P_LED1, MAP2LEVEL(OUT_GENERIC->OUT_GEN_Bit1));
  XMC_GPIO_SetOutputLevel(P_LED2, MAP2LEVEL(OUT_GENERIC->OUT_GEN_Bit2));
  XMC_GPIO_SetOutputLevel(P_LED3, MAP2LEVEL(OUT_GENERIC->OUT_GEN_Bit3));
  XMC_GPIO_SetOutputLevel(P_LED4, MAP2LEVEL(OUT_GENERIC->OUT_GEN_Bit4));
  XMC_GPIO_SetOutputLevel(P_LED5, MAP2LEVEL(OUT_GENERIC->OUT_GEN_Bit5));
  XMC_GPIO_SetOutputLevel(P_LED6, MAP2LEVEL(OUT_GENERIC->OUT_GEN_Bit6));
  XMC_GPIO_SetOutputLevel(P_LED7, MAP2LEVEL(OUT_GENERIC->OUT_GEN_Bit7));
  XMC_GPIO_SetOutputLevel(P_LED8, MAP2LEVEL(OUT_GENERIC->OUT_GEN_Bit8));

  /* INPUT PROCESSING */
  /*Check Button 1 and set IN_GEN_Bit1 which is sent to master accordingly*/
  if (XMC_GPIO_GetInput(P15_13))
    IN_GENERIC->IN_GEN_Bit1 = 1;
  else
    IN_GENERIC->IN_GEN_Bit1 = 0;

  /*Check Button 2 and set IN_GEN_Bit2 which is sent to master accordingly*/
  if (XMC_GPIO_GetInput(P15_12))
    IN_GENERIC->IN_GEN_Bit2 = 1;
  else
    IN_GENERIC->IN_GEN_Bit2 = 0;
}

/**
 * @brief main
 *
 * Initializes all the consumed Apps & Creates and process SSC stack
 *
 * */
int main(void)
{
  /*Initialize DAVE */
  if(DAVE_Init() == DAVE_STATUS_FAILURE)
  {
    /* Placeholder for error handler code.*/
    XMC_DEBUG(("DAVE APPs initialization failed\n"));
    while(1U)
    {
      /* do nothing */
    }
  }

  /* Initialize the ports which drive LEDs on EtherCat shield*/
  Init_ECAT_Adapt_LED ();
  /* Initialize buttons on XMC4800 */
  Init_Relax_Button();

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  for( ;; )
  {
    MainLoop();
  }
}

/**

 * @brief SYNC0IRQHandler() - EtherCAT Interrupt Routine for SYNC0
 *
 * <b>Details of function</b><br>
 * This routine is handling the SYNC0 Interrupts and need to call the SSC Stack
 */
void SYNC0IRQHandler (void)
{
	Sync0_Isr();
}

/**

 * @brief SYNC1IRQHandler() - EtherCAT Interrupt Routine for SYNC1
 *
 * <b>Details of function</b><br>
 * This routine is handling the SYNC1 Interrupts and need to call the SSC Stack
 */
void SYNC1IRQHandler (void)
{
	Sync1_Isr();
}

/**

 * @brief ENABLE_ESC_INT_USER() - Enabling of user specific EtherCAT Interrupt Routines
 *
 * <b>Details of function</b><br>
 * This routine is called from ECAT_APP on request of SSC stack once interrupts (sync1/sync0) need to be enabled
 */
void ENABLE_ESC_INT_USER()
{
	INTERRUPT_Enable(&INT_SYNC0);
	INTERRUPT_Enable(&INT_SYNC1);
}

/**

 * @brief DISABLE_ESC_INT_USER() - Disabling of user specific EtherCAT Interrupt Routines
 *
 * <b>Details of function</b><br>
 * This routine is called from ECAT_APP on request of SSC stack once interrupts (sync1/sync0) need to be disabled
 */
void DISABLE_ESC_INT_USER()
{
	INTERRUPT_Disable(&INT_SYNC0);
	INTERRUPT_Disable(&INT_SYNC1);
}
