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
#include "flashprog.h"
#include "ecatfoe.h"

/****************************************************************
* MACROS AND DEFINES
***************************************************************/
#define START_BACKUP_PARTITION (void*)0x0C100000           /* Start address of backup partition in the upper 1MByte */
#define MAX_SIZE               (1024 * 1024 - 128 * 1024)  /* 1st 64KByte occupied by bootlader
                                                            * 2nd 64kByte occupied by EetherCAT EEPROM */
#define METAINFO_OFFSET        (1024 * 1024 - 256)         /* store file size as meta-info in last page of backup partition */

/****************************************************************
* LOCAL DATA
***************************************************************/
static uint32_t meta_page[64];
static uint8_t g_firmware_download_started=0;
static uint8_t g_firmware_download_finished=0;

/****************************************************************
* API PROTOTYPES
***************************************************************/

void FWUPDATE_StartDownload(void)
{
  /* Check if a download has already been started,
   * if yes, return error */
  if (g_firmware_download_started)
    return ECAT_FOE_ERRCODE_EXISTS;

  /* remember a firmware download has started
   * --> issue system reset when INIT-state is requested
   * to flash new binary inside bootloader */
  g_firmware_download_started = 1;

  /* Initialize programming of XMC flash
   * - start address of backup partition
   * - MAX SIZE is limited by application partition
   * - Erase is already assured insid jhjhjhjhjhe bootloader executable
   * - Enable XMC flash programming check
   */
  FLASHPROG_Init(START_BACKUP_PARTITION, MAX_SIZE, FLASH_OPT_NO_ERASE, FLASH_OPT_CHECK);
}

void FWUPDATE_StateTransitionInit(void)
{
  /* If download started before, it is finished now
   * --> issue system reset  from process_app
   * to update firmware and/or cleanup flash
   */
  if (g_firmware_download_started==1)
    g_firmware_download_finished=1;
}

uint8_t FWUPDATE_GetDownloadFinished(void)
{
	return g_firmware_download_finished;
}

uint16_t FWUPDATE_Data(uint16_t *pdata, uint16_t size)
{
  /* Next data of firmware file received
   * Proceed with programming
   */
  switch( FLASHPROG_Data((void*)pdata, (uint32_t)size) )
  {
    case FLASH_FULL_ERROR:
    {
      /* Maximum firmware size reached */
      return ECAT_FOE_ERRCODE_DISKFULL;
    }
    case FLASH_PROG_ERROR:
    {
      /* XMC flash programming error occured */
      return ECAT_FOE_ERRCODE_PROGERROR;
	}
  }

  if ( size == (u16ReceiveMbxSize - MBX_HEADER_SIZE - FOE_HEADER_SIZE) )
  {
    /* Further data will follow */
    return 0;
  }
  else
  {
    /* last part of the file received */
	/* Finalize XMC flash programming */
  	FLASHPROG_Close();

  	/* Check CRC32 (last 4 bytes of image) */
   	if (FLASHPROG_CRC32_check(START_BACKUP_PARTITION, FLASHPROG_Bytes_written())==FLASH_CRC_ERROR)
   	{
   	  return ECAT_FOE_ERRCODE_INVALID_CHECKSUM;
   	}

   	/* Downloaded firmware binary is ok
   	 * now prepare meta info page to proceed
   	 * with flashing application partition from bootloader executable*/
    for (uint32_t i = 0; i < XMC_FLASH_BYTES_PER_PAGE / 4; i++)
   	{
      meta_page[i] = 0;
    }
    /* Set meta info; firmware binary size */
    meta_page[63] = FLASHPROG_Bytes_written();
  	/* store meta info */
    /* Initialize flash programming with offset to meta-info page */
   	FLASHPROG_Init(START_BACKUP_PARTITION + METAINFO_OFFSET, XMC_FLASH_BYTES_PER_PAGE, FLASH_OPT_NO_ERASE, FLASH_OPT_CHECK);
    switch( FLASHPROG_Data((void*)meta_page, (uint32_t)256) )
    {
      case FLASH_FULL_ERROR:
      {
        /* can never happen; however to be code complete ... */
        return ECAT_FOE_ERRCODE_DISKFULL;
      }
      case FLASH_PROG_ERROR:
      {
        /* XMC flash programming error occured */
        return ECAT_FOE_ERRCODE_PROGERROR;
      }
    }
    /* Finalize meta info programming inside XMC flash */
    FLASHPROG_Close();
    return FOE_ACKFINISHED;
  }
}















  
