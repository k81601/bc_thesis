/******************************************************************************
* Software License Agreement
*
* Copyright (c) 2016, Infineon Technologies AG
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* Redistributions of source code must retain the above copyright notice,
* this list of conditions and the following disclaimer.
*
* Redistributions in binary form must reproduce the above copyright notice,
* this list of conditions and the following disclaimer in the documentation
* and/or other materials provided with the distribution.
*
* Neither the name of the copyright holders nor the names of its contributors
* may be used to endorse or promote products derived from this software
* without specific prior written permission

* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
* To improve the quality of the software, users are encouraged to share
* modifications, enhancements or bug fixes with Infineon Technologies AG
* (dave@infineon.com).
*
*****************************************************************************/

/****************************************************************
* HEADER FILES
***************************************************************/
#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)
#include "xmc_scu.h"
#include "xmc_gpio.h"
#include "flashprog.h"

/****************************************************************
* MACROS AND DEFINES
***************************************************************/
/** MagicKey value for \ref ABM_Header_t. see */
#define ABM_HEADER_MAGIC_KEY 0xA5C3E10F
/* start address of back up buffer (@1MByte)*/
#define START_ADDRESS_BACKUP_PARTITION       (uint32_t*)0x0C100000
/* start address of application buffer
 * (@128kByte after bootloader(64k) and EEPROM(64k)*/
#define START_ADDRESS_APP_PARTITION          (uint32_t*)0x0C020000
/* first 128KByte is occupied by bootlader */
#define APP_PARTITION_MAX_SIZE               (1024 * 1024 - 128 * 1024)
/* backup space including meta-info space */
#define BACKUP_PARTITION_MAX_SIZE            (1024 * 1024)
/* offset to backup start address
 * of page to store file size inside backup */
#define METAINFO_OFFSET                      (1024 * 1024 - 256)

/**
 * \brief Alternative Boot Mode structure
 *
 * This structure is used by ABM0, ABM1 and PSRAM boot mode. If the code is
 * scattered in non conious memory regions, the CRC check of the application
 * code can be disabled with setting \ref Length and \ref ApplicationCRC32
 * to 0xFFFFFFFF. To calculate the HeaderCRC32 the following code could be used:
 * \code{.c}
 * SCU_RESET->PRCLR2 = SCU_RESET_PRCLR2_FCERS_Msk;
 * while((SCU_RESET->PRSTAT2 & SCU_RESET_PRSTAT2_FCERS_Msk));
 * FCE->CLC = 0;
 * while((FCE->CLC & FCE_CLC_DISS_Msk));
 * FCE_KE0->CFG = 0;
 * FCE_KE0->CRC = 0;
 * FCE_KE0->IR = *((uint32_t*)0x0C00FFE0);
 * FCE_KE0->IR = *((uint32_t*)(0x0C00FFE0+4));
 * FCE_KE0->IR = *((uint32_t*)(0x0C00FFE0+8));
 * FCE_KE0->IR = *((uint32_t*)(0x0C00FFE0+12));
 * uint32_t HeaderCRC32 = FCE_KE0->RES;
 * \endcode
 */
typedef struct ABM_Header {
  uint32_t MagicKey; /**< Magic key. Always 0xA5C3E10F */
  uint32_t StartAddress; /**< Start address of the programm to load */
  uint32_t Length; /**< Length of the programm to load. */
  uint32_t ApplicationCRC32; /**< CRC32 Sum of the complete application code */
  uint32_t HeaderCRC32; /**< CRC32 Sum of the four fields before */
} ABM_Header_t;

/****************************************************************
* LOCAL DATA
***************************************************************/
static const ABM_Header_t  __attribute__((section(".flash_abm")))
ABM0_Header = {
  .MagicKey = ABM_HEADER_MAGIC_KEY,
  .StartAddress = 0x08020000,  /* Start Flash Physical Sector 1 */
  .Length = 0xFFFFFFFF,
  .ApplicationCRC32 = 0xFFFFFFFF,
  .HeaderCRC32 =  0xEF423163
};

/****************************************************************
* API PROTOTYPES
***************************************************************/

/****************************************************************
* API IMPLEMENTATION
***************************************************************/
void BL_FlashABM0_Restart(void)
{
  /* Restart in alternative bootmode 0 */
  /* Clear the reset cause field for proper reset detection of the ssw */
  XMC_SCU_RESET_ClearDeviceResetReason();
  /* Set ABM0 as boot mode in SWCON field of STCON register */
  XMC_SCU_SetBootMode(XMC_SCU_BOOTMODE_ABM0);
  /* Trigger power on reset */
  PPB->AIRCR = 1 << PPB_AIRCR_SYSRESETREQ_Pos
		            |0x5FA<<PPB_AIRCR_VECTKEY_Pos
					| 0x1 << PPB_AIRCR_PRIGROUP_Pos;
}

void BL_Normal_Restart(void)
{
  /* Restart in alternative bootmode 0 */
  /* Clear the reset cause field for proper reset detection of the ssw */
  XMC_SCU_RESET_ClearDeviceResetReason();
  /* Set ABM0 as boot mode in SWCON field of STCON register */
  XMC_SCU_SetBootMode(XMC_SCU_BOOTMODE_NORMAL);
  /* Trigger power on reset */
  PPB->AIRCR = 1 << PPB_AIRCR_SYSRESETREQ_Pos
		            |0x5FA<<PPB_AIRCR_VECTKEY_Pos
					| 0x1 << PPB_AIRCR_PRIGROUP_Pos;
}

/**

 * @brief main() - Application entry point
 *
 * Initializes the DAVE(TM) subsystem, LEDs and USB device stack. Processing of the USB stack.
 */
uint32_t main(void)
{
  uint32_t firmware_size_bytes;
  uint32_t* ptr_backupdata = 0;
  firmware_size_bytes = (START_ADDRESS_BACKUP_PARTITION + METAINFO_OFFSET / 4)[63];

  /* check metainfo if firmware for update is available inside backup partition */
  if ( (firmware_size_bytes > 0) && (firmware_size_bytes < APP_PARTITION_MAX_SIZE) )
  {
    /* metainfo indicates a new firmware is available inside backup partition */
    /* check CRC32 of firmware inside backup partition */
    if (FLASHPROG_CRC32_check(START_ADDRESS_BACKUP_PARTITION,
    		                  firmware_size_bytes) == FLASH_OK)
    {
      /* CRC32 of backup partition is OK - start programming */

      /* program new firmware into application partition */
      FLASHPROG_Init(START_ADDRESS_APP_PARTITION,
                     APP_PARTITION_MAX_SIZE,
                     FLASH_OPT_ERASE,
                     FLASH_OPT_CHECK);
      FLASHPROG_Data(START_ADDRESS_BACKUP_PARTITION, firmware_size_bytes);
      FLASHPROG_Close();

      /* delete EEPROM content (2nd 64k sector) */
      FLASHPROG_Delete_physical_sector(XMC_FLASH_PHY_SECTOR_4);

      /* Check CRC32 of firmware inside application partition*/
      if (FLASHPROG_CRC32_check(START_ADDRESS_APP_PARTITION,
    		                          firmware_size_bytes) != FLASH_OK)
      {
        /* Restart to retry programming */
        BL_Normal_Restart();
      }
      /* OK - new firmware was successfully programmed into application partition */
    }
  }

  /* CRC32 checked software from backup partition was just successfully programmed
   * into application partition.
   * In any case, make sure backup partition is erased before restarting firmware inside
   * application partition.
   */
  ptr_backupdata = START_ADDRESS_BACKUP_PARTITION;
  while(ptr_backupdata<START_ADDRESS_BACKUP_PARTITION + BACKUP_PARTITION_MAX_SIZE / 4)
  {
    /* is erase needed? */
    if (*ptr_backupdata!=0)
    {
      /* erase backup partition */
      FLASHPROG_Delete_physical_sectors(ptr_backupdata, 1);
    }
    ptr_backupdata++;
  }

  /* Restart inside application partition */
  BL_FlashABM0_Restart();

  return 0;
}





