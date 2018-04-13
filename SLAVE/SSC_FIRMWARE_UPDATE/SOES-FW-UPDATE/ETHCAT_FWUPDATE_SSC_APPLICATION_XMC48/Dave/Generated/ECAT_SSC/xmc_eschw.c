/*********************************************************************************************************************
* DAVE APP Name : ECAT_SSC       APP Version: 4.0.8
*
* NOTE:
* This file is generated by DAVE. Any manual modification done to this file will be lost when the code is regenerated.
*********************************************************************************************************************/

/**
 * @cond
 ***********************************************************************************************************************
 *
 * Copyright (c) 2016, Infineon Technologies AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,are permitted provided that the
 * following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright notice, this list of conditions and the  following
 *   disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *   following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *   Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 *   products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * To improve the quality of the software, users are encouraged to share modifications, enhancements or bug fixes
 * with Infineon Technologies AG (dave@infineon.com).
 ***********************************************************************************************************************
 *
 * Change History
 * --------------
 *
 * 2016-01-20:
 *     - Initial version
 *
 * 2016-06-07:
 *     - Fixed code generation error for project folder paths with spaces in between.
 * @endcond
 *
 */

/***********************************************************************************************************************
 * HEADER FILES
 **********************************************************************************************************************/
#include <xmc_gpio.h>
#include <xmc_ecat.h>
#include "xmc_eschw.h"
#include "SSC/Src/ecatappl.h"
#include "SSC/Src/ecatslv.h"
#include "../INTERRUPT/interrupt.h"

/* PHY management interface signal definitions*/
#define ECAT_MDO              P0_12
#define ECAT_MCLK             P3_3

/* EtherCAT slave physical layer pin configurations */
#define ECAT_CLK25            P6_0
#define ECAT_PHY_RESET        P0_0
#define ECAT_LED_RUN          P0_8
#define ECAT_LED_ERR          P0_7

/* EtherCAT slave physical layer Port 0 pin configurations */
#define ECAT_P0_LINK_STATUS   P1_15
#define ECAT_P0_LED_LINK_ACT  P6_3
#define ECAT_P0_RXD3          P5_7
#define ECAT_P0_RXD2          P5_2
#define ECAT_P0_RXD1          P5_1
#define ECAT_P0_RXD0          P5_0
#define ECAT_P0_RX_DV         P5_6
#define ECAT_P0_RX_CLK        P5_4
#define ECAT_P0_RX_ERR        P2_6
#define ECAT_P0_TXD3          P6_6
#define ECAT_P0_TXD2          P6_5
#define ECAT_P0_TXD1          P6_4
#define ECAT_P0_TXD0          P6_2
#define ECAT_P0_TX_EN         P6_1
#define ECAT_P0_TX_CLK        P5_5

/* EtherCAT slave physical layer Port 1 pin configurations */
#define ECAT_P1_LINK_STATUS   P3_4
#define ECAT_P1_LED_LINK_ACT  P3_12
#define ECAT_P1_RXD3          P0_4
#define ECAT_P1_RXD2          P0_5
#define ECAT_P1_RXD1          P0_6
#define ECAT_P1_RXD0          P0_11
#define ECAT_P1_RX_DV         P0_9
#define ECAT_P1_RX_CLK        P0_1
#define ECAT_P1_RX_ERR        P15_2
#define ECAT_P1_TXD3          P0_3
#define ECAT_P1_TXD2          P0_2
#define ECAT_P1_TXD1          P3_2
#define ECAT_P1_TXD0          P3_1
#define ECAT_P1_TX_EN         P3_0
#define ECAT_P1_TX_CLK        P0_10

/* Maximum Sync Managers supported */
#define MAX_SYNC_MAN          (8U)

/* Timer tick counter variable initialization */
static uint32_t ticks = 0U;

/* Extern declarations for Beckhoff SSC functions and variables */
extern uint8_t aEepromData[];
extern UINT8 *pEEPROM;
extern UINT16 (* pAPPL_EEPROM_Reload)(void);
extern UINT16 (* pAPPL_EEPROM_Write)(UINT32 wordaddr);

/* EtherCAT Beckhoff HW abstraction layer interface API to initialize XMC ESC */
UINT16 HW_Init(void)
{
  uint8_t i;
  XMC_ECAT_PORT_CTRL_t port_control;
  XMC_GPIO_CONFIG_t gpio_config;

  /* EEPROM interface API registration */
  pEEPROM = &aEepromData[0U];
  pAPPL_EEPROM_Reload = HW_EepromReload;
  pAPPL_EEPROM_Write  = HW_EepromWrite;

  /* EtherCAT slave physical layer pin settings */
  gpio_config.mode = XMC_GPIO_MODE_INPUT_TRISTATE;
  XMC_GPIO_Init(ECAT_P0_LINK_STATUS, &gpio_config);
  XMC_GPIO_Init(ECAT_P0_RXD3, &gpio_config);
  XMC_GPIO_Init(ECAT_P0_RXD2, &gpio_config);
  XMC_GPIO_Init(ECAT_P0_RXD1, &gpio_config);
  XMC_GPIO_Init(ECAT_P0_RXD0, &gpio_config);
  XMC_GPIO_Init(ECAT_P0_RX_DV, &gpio_config);
  XMC_GPIO_Init(ECAT_P0_RX_CLK, &gpio_config);
  XMC_GPIO_Init(ECAT_P0_RX_ERR, &gpio_config);
  XMC_GPIO_Init(ECAT_P0_TX_CLK, &gpio_config);

  XMC_GPIO_Init(ECAT_P1_LINK_STATUS, &gpio_config);
  XMC_GPIO_Init(ECAT_P1_RXD3, &gpio_config);
  XMC_GPIO_Init(ECAT_P1_RXD2, &gpio_config);
  XMC_GPIO_Init(ECAT_P1_RXD1, &gpio_config);
  XMC_GPIO_Init(ECAT_P1_RXD0, &gpio_config);
  XMC_GPIO_Init(ECAT_P1_RX_DV, &gpio_config);
  XMC_GPIO_Init(ECAT_P1_RX_CLK, &gpio_config);
  XMC_GPIO_Init(ECAT_P1_RX_ERR, &gpio_config);
  XMC_GPIO_Init(ECAT_P1_TX_CLK, &gpio_config);

  port_control.common.enable_rstreq = false;
  port_control.common.mdio = XMC_ECAT_PORT_CTRL_MDIO_P0_12;
  port_control.common.phyaddr_offset = 0;
  port_control.common.latch_input0 = XMC_ECAT_PORT_CTRL_LATCHIN0_P14_5;
  port_control.common.latch_input1 = XMC_ECAT_PORT_CTRL_LATCHIN1_P14_4;
  port_control.port0.rxd0 = XMC_ECAT_PORT0_CTRL_RXD0_P5_0;
  port_control.port0.rxd1 = XMC_ECAT_PORT0_CTRL_RXD1_P5_1;
  port_control.port0.rxd2 = XMC_ECAT_PORT0_CTRL_RXD2_P5_2;
  port_control.port0.rxd3 = XMC_ECAT_PORT0_CTRL_RXD3_P5_7;
  port_control.port0.rx_clk = XMC_ECAT_PORT0_CTRL_RX_CLK_P5_4;
  port_control.port0.rx_dv = XMC_ECAT_PORT0_CTRL_RX_DV_P5_6;
  port_control.port0.rx_err = XMC_ECAT_PORT0_CTRL_RX_ERR_P2_6;
  port_control.port0.link = XMC_ECAT_PORT0_CTRL_LINK_P1_15;
  port_control.port0.tx_clk = XMC_ECAT_PORT0_CTRL_TX_CLK_P5_5;
  port_control.port0.tx_shift = XMC_ECAT_PORT0_CTRL_TX_SHIFT_0NS; 
  port_control.port1.rxd0 = XMC_ECAT_PORT1_CTRL_RXD0_P0_11;
  port_control.port1.rxd1 = XMC_ECAT_PORT1_CTRL_RXD1_P0_6;
  port_control.port1.rxd2 = XMC_ECAT_PORT1_CTRL_RXD2_P0_5;
  port_control.port1.rxd3 = XMC_ECAT_PORT1_CTRL_RXD3_P0_4;
  port_control.port1.rx_clk = XMC_ECAT_PORT1_CTRL_RX_CLK_P0_1;
  port_control.port1.rx_dv = XMC_ECAT_PORT1_CTRL_RX_DV_P0_9;
  port_control.port1.rx_err = XMC_ECAT_PORT1_CTRL_RX_ERR_P15_2;
  port_control.port1.link = XMC_ECAT_PORT1_CTRL_LINK_P3_4;
  port_control.port1.tx_clk = XMC_ECAT_PORT1_CTRL_TX_CLK_P0_10;
  port_control.port1.tx_shift = XMC_ECAT_PORT1_CTRL_TX_SHIFT_0NS;
  XMC_ECAT_SetPortControl(port_control);

  /* EtherCAT slave enable and intialization using LLD function */
  XMC_ECAT_Init((XMC_ECAT_CONFIG_t *)(void*)aEepromData);

  /* EtherCAT slave physical layer pin configurations */
  gpio_config.output_strength = XMC_GPIO_OUTPUT_STRENGTH_STRONG_SHARP_EDGE;
  gpio_config.mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT4;
  XMC_GPIO_Init(ECAT_P0_TXD3, &gpio_config);
  gpio_config.mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT4;
  XMC_GPIO_Init(ECAT_P0_TXD2, &gpio_config);
  gpio_config.mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT4;
  XMC_GPIO_Init(ECAT_P0_TXD1, &gpio_config);
  gpio_config.mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT4;
  XMC_GPIO_Init(ECAT_P0_TXD0, &gpio_config);
  gpio_config.mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT4;
  XMC_GPIO_Init(ECAT_P0_TX_EN, &gpio_config);

  gpio_config.mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT1;
  XMC_GPIO_Init(ECAT_P1_TXD3, &gpio_config);
  gpio_config.mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT1;
  XMC_GPIO_Init(ECAT_P1_TXD2, &gpio_config);
  gpio_config.mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT3;
  XMC_GPIO_Init(ECAT_P1_TXD1, &gpio_config);
  gpio_config.mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT3;
  XMC_GPIO_Init(ECAT_P1_TXD0, &gpio_config);
  gpio_config.mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT4;
  XMC_GPIO_Init(ECAT_P1_TX_EN, &gpio_config);

  gpio_config.mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT4;
  XMC_GPIO_Init(ECAT_CLK25, &gpio_config);

  gpio_config.mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT4;
  XMC_GPIO_Init(ECAT_MCLK, &gpio_config);
  gpio_config.mode = XMC_GPIO_MODE_INPUT_TRISTATE;
  XMC_GPIO_Init(ECAT_MDO, &gpio_config);
  XMC_GPIO_SetHardwareControl(ECAT_MDO, XMC_GPIO_HWCTRL_PERIPHERAL1);

  gpio_config.output_strength = XMC_GPIO_OUTPUT_STRENGTH_STRONG_SOFT_EDGE;
  gpio_config.mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT4;
  XMC_GPIO_Init(ECAT_P0_LED_LINK_ACT, &gpio_config);

  gpio_config.mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT1;
  XMC_GPIO_Init(ECAT_P1_LED_LINK_ACT, &gpio_config);

  gpio_config.mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT3;
  XMC_GPIO_Init(ECAT_LED_RUN, &gpio_config);
  XMC_GPIO_SetHardwareControl(ECAT_LED_RUN, XMC_GPIO_HWCTRL_DISABLED);

  gpio_config.mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT3;
  XMC_GPIO_Init(ECAT_LED_ERR, &gpio_config);
  XMC_GPIO_SetHardwareControl(ECAT_LED_ERR, XMC_GPIO_HWCTRL_DISABLED);

  gpio_config.mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT1;
  XMC_GPIO_Init(ECAT_PHY_RESET, &gpio_config);

  /* Disable all supported sync manager channels */
  for (i = 0U; i < MAX_SYNC_MAN; i++)
  {
    XMC_ECAT_DisableSyncManChannel(i);
  }

  /* EtherCAT slave event disable */
  XMC_ECAT_DisableEvent(0xffffffffU);

  /* ECAT interrupt priority settings */
  NVIC_SetPriority(ECAT0_0_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),
                                                     63U,
                                                     0U));

  /* EtherCAT slave interrupt enable */
  ENABLE_ESC_INT();

  return ((uint16_t)0U);
}

/* Beckhoff Hw abstraction layer interface API to release the consumed resources */
void HW_Release(void)
{

}

/* Beckhoff Hw abstraction layer interface API to reset the XMC ECAT module */
void HW_RestartTarget(void)
{

}


/* Beckhoff Hw abstraction layer interface API to write new configuration parameters to slave EEPROM area */
UINT16 HW_EepromWrite(UINT32 wordaddr)
{
  UINT32 status;
  UINT16 EEPROMReg = 0U; /* Regvalue 0x502 - 0x5003 */
  status = 0U;
  if ((wordaddr <= (uint32_t)ESC_EEPROM_SIZE) && (pEEPROM != NULL))
  {
     UINT16 *pData = (UINT16 *)(void*)pEEPROM;
     HW_EscRead((MEM_ADDR *)(void*)&pData[(wordaddr)], (uint16_t)ESC_EEPROM_DATA_OFFSET, (uint16_t)EEPROM_WRITE_SIZE);
     if ( (wordaddr == (uint32_t)7U) || (wordaddr ==  (((uint32_t)ESC_EEPROM_SIZE >> (uint32_t)1U) - (uint32_t)1U)) )
     {
      /*lets program the complete EEPROM new prepare Data for EEPROM */
      E_EEPROM_XMC4_WriteArray((uint16_t)0U,aEepromData,(uint16_t)ESC_EEPROM_SIZE);

      HW_EscReadWord(EEPROMReg,ESC_EEPROM_CONTROL_OFFSET);
      HW_EscWriteWord(EEPROMReg & (~ESC_EEPROM_BUSY_MASK),ESC_EEPROM_CONTROL_OFFSET);

      __disable_irq();
      /* Program the RAM contents to Emulated EEPROM*/
      status = (uint32_t)E_EEPROM_XMC4_UpdateFlashContents();
      __enable_irq();
     }
  }

  return (uint16_t)status;
}

/* Beckhoff Hw abstraction layer interface API to reload slave EEPROM area */
UINT16 HW_EepromReload(void)
{
  UINT16 EEPROMReg = 0U; /* Regvalue 0x502 - 0x5003 */
  UINT32 cmd = (uint32_t)EEPROMReg  & (uint32_t)ESC_EEPROM_CMD_MASK;
  UINT32 addr;
  HW_EscReadDWord(addr,(uint32_t)ESC_EEPROM_ADDRESS_OFFSET);
  addr = SWAPDWORD(addr);

  /* EEPROM emulation ( 8Bytes EEPROM data) */
  if ((addr <= (uint32_t)ESC_EEPROM_SIZE) && (pEEPROM != NULL))
  {
    UINT16 *pData = (UINT16 *)(void*)pEEPROM;
    do
    {
    HW_EscWrite((MEM_ADDR *)(void*)&pData[(addr)], (uint16_t)ESC_EEPROM_DATA_OFFSET, (uint16_t)EEPROM_READ_SIZE);

     /*Clear error bits */
     EEPROMReg &= (uint16_t)(~(uint16_t)(ESC_EEPROM_ERROR_MASK));

     /*ack current reload segment */
     HW_EscWriteWord(EEPROMReg,(uint32_t)ESC_EEPROM_CONTROL_OFFSET);

     /* read EEPROM control (to check if the reload is still pending) */
     HW_EscReadWord(EEPROMReg,ESC_EEPROM_CONTROL_OFFSET);
     cmd = (uint32_t)EEPROMReg  & (uint32_t)ESC_EEPROM_CMD_MASK;

     HW_EscReadDWord(addr,(uint32_t)ESC_EEPROM_ADDRESS_OFFSET);

    } while(cmd == (uint32_t)ESC_EEPROM_CMD_RELOAD_MASK);
  }
  else
  {
    /* Set Error  */
    EEPROMReg |= (uint16_t)ESC_EEPROM_ERROR_CMD_ACK;
  }
  return 0U;
}

/* ECAT slave interrupt handler function */
void ECAT0_0_IRQHandler(void)
{
  PDI_Isr();
}

/* ECAT slave timer interrupt handler function */
void ecat_ssc_timer_handler(void)
{
  ticks++;
  ECAT_CheckTimer();
}

/* Beckhoff Hw abstraction layer interface API to get the current timer value in ticks */
UINT32 HW_GetTimer(void)
{
  return ticks;
}

