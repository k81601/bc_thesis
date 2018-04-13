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
#include "xmc_flash.h"
#include "flashprog.h"
#include <xmc_fce.h>

/****************************************************************
* MACROS AND DEFINES
***************************************************************/

/****************************************************************
* LOCAL DATA
***************************************************************/
uint32_t* physical_sector_addresses[XMC_FLASH_SECTOR_COUNT_MAX + 1]=
{
  XMC_FLASH_PHY_SECTOR_0,
  XMC_FLASH_PHY_SECTOR_4,
  XMC_FLASH_PHY_SECTOR_8,
  XMC_FLASH_PHY_SECTOR_9,
  XMC_FLASH_PHY_SECTOR_10,
  XMC_FLASH_PHY_SECTOR_11,
  XMC_FLASH_PHY_SECTOR_12,
  XMC_FLASH_PHY_SECTOR_13,
  XMC_FLASH_PHY_SECTOR_14,
  XMC_FLASH_PHY_SECTOR_15,
  XMC_FLASH_PHY_SECTOR_15 + 0x040000UL  /*end address +1 of last sector */
};

/* Specification to initialize FCE for CRC32 calculation*/
static XMC_FCE_t FCE_config0 =
{
  .kernel_ptr    = XMC_FCE_CRC32_0,    /**< FCE Kernel Pointer */
  .fce_cfg_update.config_xsel = true,
  .fce_cfg_update.config_refin = true,
  .fce_cfg_update.config_refout = true,
  .seedvalue = 0xffffffff
};

static uint32_t* gl_flash_write_address;
static uint32_t* gl_flash_write_start_address;
static uint32_t  gl_flash_bytes_written=0;
static uint8_t   gl_flash_check_prog;
static uint16_t  gl_flash_erased;
static uint32_t  gl_flash_max_size=0;
static uint8_t   gl_flash_page_prep[256];
static uint32_t  gl_flash_page_prep_index=0;

/****************************************************************
* API PROTOTYPES
***************************************************************/

/****************************************************************
* API IMPLEMENTATION
***************************************************************/
/**
 * @brief Flash_lGetPhysicalSector
 *
 * Returns the sector start address of physical sector to which an address belongs
 *
 * @input :  address : address for which the start address of physical sector
 *                     is returned
 *
 * @output : none
 *
 * @return : start address of physical sector
 *
 */
uint32_t* Flash_lGetPhysicalSector(uint32_t* address)
{
  uint8_t sector_number;

  for (sector_number=0; sector_number<XMC_FLASH_SECTOR_COUNT_MAX; sector_number++)
  {
    if ((address>=physical_sector_addresses[sector_number]) && (address<physical_sector_addresses[sector_number+1]))
      return physical_sector_addresses[sector_number];
  }
  /* should not be reached */
  return 0;
}

/**
 * @brief Flash_lGetPhysicalSectorNumber
 *
 * Returns the sector number of physical sector having a certain start address
 *
 * @input :  physical_sector_start_address : address of physical sector for which the
 *                                   sector number is returned
 *
 * @output : none
 *
 * @return : sector number
 *
 */
uint8_t Flash_lGetPhysicalSectorNumber(uint32_t* physical_sector_start_address)
{
  uint8_t sector_number;

  for (sector_number=0; sector_number<XMC_FLASH_SECTOR_COUNT_MAX; sector_number++)
  {
    if (physical_sector_start_address==physical_sector_addresses[sector_number])
      return sector_number;
  }
  return 0;
}

/**
 * @brief Flash_lGetPhysicalSectorAddress
 *
 * Returns the start address of a physical sector defined by a sector number
 *
 * @input :  physical_sector_number : number of physical sector
 *
 * @output : none
 *
 * @return : start address of the physical sector
 *
 */
uint32_t* Flash_lGetPhysicalSectorAddress(uint8_t physical_sector_number)
{
  return physical_sector_addresses[physical_sector_number];
}

/**
 * @brief Flash_lCheckPhysicalSectorNumberInRange
 *
 * Checks if a physical sector defined by a sector number overlaps with an address range
 *
 * @input :  ptr_startaddress : start address of range
 *           size_bytes       : size of range in bytes
 *           sector_number    : sector number to check
 *
 * @output : none
 *
 * @return : FLASH_SECTOR_NOT_IN_RANGE - sector does not overlap with address range
 *           FLASH_SECTOR_IN_RANGE - sector overlaps with address range
 *
 */
uint8_t Flash_lCheckPhysicalSectorNumberInRange(uint32_t* ptr_startaddress, uint32_t size_bytes, uint32_t sector_number)
{
  uint8_t hit=FLASH_SECTOR_NOT_IN_RANGE;
  uint32_t* ptr_endaddress=ptr_startaddress + size_bytes / 4;

  /* Check if startaddress is inside physical sector */
  if ((ptr_startaddress>=physical_sector_addresses[sector_number]) && (ptr_startaddress<physical_sector_addresses[sector_number+1]))
    hit=FLASH_SECTOR_IN_RANGE;
  /* Check if endaddress is inside physical sector */
  if ((ptr_endaddress>=physical_sector_addresses[sector_number]) && (ptr_endaddress<physical_sector_addresses[sector_number+1]))
    hit=FLASH_SECTOR_IN_RANGE;
  /* Check if complete physical sector is covered by range  */
  if ((physical_sector_addresses[sector_number]>=ptr_startaddress) && (physical_sector_addresses[sector_number+1]<(ptr_endaddress)))
    hit=FLASH_SECTOR_IN_RANGE;

  return hit;
}

/**
 * @brief FLASHPROG_Init
 *
 * Initializes flash programming with flash destination address,
 * size of available space inside EEPROM and options (erase before writing and
 * check programming)
 *
 * @input :  dest_address          : ptr to destination data inside flash
 *           max_size              : amount of data (bytes) available at destination location
 *                                   inside flash
 *           erase                 : specifies if physical sectors must be deleted
 *                                   before programming starts
 *                                   FLASH_OPT_ERASE - no erase executed
 *                                   FLASH_OPT_NO_ERASE - erase exectued
 *           check_prog            : specifies if content is checked for
 *                                   correctness after each page programming
 *                                   FLASH_OPT_CHECK - data check enabled
 *                                   FLASH_OPT_NO_CHECK - data check disabled
 *
 * @output : none
 *
 *
 * @return : none
 *
 */
void FLASHPROG_Init(uint32_t* dest_address, uint32_t max_size, uint8_t erase, uint8_t check_prog)
{
  gl_flash_write_address = dest_address;
  gl_flash_write_start_address = dest_address;
  gl_flash_max_size = max_size;
  gl_flash_check_prog = check_prog;
  gl_flash_bytes_written = 0;
  if (erase == FLASH_OPT_NO_ERASE)
    gl_flash_erased = 0xffffU;
  else
    gl_flash_erased = 0U;
  gl_flash_page_prep_index = 0U;
}

/**
 * @brief FLASHPROG_Data
 *
 * Provides next data for programming flash
 *
 * @input :  src_data  : ptr to source data
 *           size_bytes: amount of data (bytes) available at src location
 *
 * @output : none
 *
 * @return : FLASH_FULL_ERROR - no more space left inside destination
 *           FLASH_PROG_ERROR - programming error
 *
 */
uint32_t FLASHPROG_Data(void* src_data, uint32_t size_bytes)
{
  uint32_t result = FLASH_OK;
  uint32_t bytes_processed = 0;

  while((size_bytes > bytes_processed) && (result == FLASH_OK))
  {
    while((gl_flash_page_prep_index < XMC_FLASH_BYTES_PER_PAGE) && (size_bytes > bytes_processed))
    {
      gl_flash_page_prep[gl_flash_page_prep_index]=((uint8_t*)src_data)[bytes_processed];
      bytes_processed+=1;
      gl_flash_page_prep_index++;
    }

    /* Complete page prepared ? */
    if (gl_flash_page_prep_index == XMC_FLASH_BYTES_PER_PAGE)
    {
      if ((gl_flash_bytes_written + XMC_FLASH_BYTES_PER_PAGE) <= gl_flash_max_size)
      {
        /* One complete page is prepared; start programming */

        /* Check if physical sector already has been deleted; if not, delete */
        uint32_t* PhysicalSector = Flash_lGetPhysicalSector(gl_flash_write_address);
        uint8_t PhysicalSectorNumber = Flash_lGetPhysicalSectorNumber(PhysicalSector);
        if (!(gl_flash_erased & 1 << PhysicalSectorNumber))
        {
          XMC_FLASH_ErasePhysicalSector(PhysicalSector);
          gl_flash_erased |= (1<<PhysicalSectorNumber);
        }

        /* Program page */
        XMC_FLASH_ProgramPage((void*)gl_flash_write_address,(void*)gl_flash_page_prep);

        /* Check for programming errors */
        if (gl_flash_check_prog == FLASH_OPT_CHECK)
        {
          for (uint32_t offset = 0; offset < 64; offset ++)
          {
            if ( gl_flash_write_address[offset] != ((uint32_t*)gl_flash_page_prep)[offset] )
              result = FLASH_PROG_ERROR;
          }
        }

        gl_flash_write_address = gl_flash_write_address + XMC_FLASH_BYTES_PER_PAGE / 4;
        gl_flash_bytes_written = gl_flash_bytes_written + XMC_FLASH_BYTES_PER_PAGE;
        gl_flash_page_prep_index=0;
      }
      else
      {
        result = FLASH_FULL_ERROR;
      }
    }
  }
  return result;
}

/**
 * @brief FLASHPROG_Close
 * Finalize flash programming. Flush remaining data into last page.
 *
 * @input :  none
 *
 * @output : none
 *
 * @return : none
 *
 */
uint32_t FLASHPROG_Close(void)
{
  /* Data remaining in page preparation ? */
  if (gl_flash_page_prep_index!=0)
  {
    if ((gl_flash_bytes_written + 256) < gl_flash_max_size)
    {
      /* Programm remaining data */
      XMC_FLASH_ProgramPage((void*)gl_flash_write_address,(void*)gl_flash_page_prep);
      gl_flash_bytes_written = gl_flash_bytes_written + gl_flash_page_prep_index;
    }
    else
    {
      return FLASH_FULL_ERROR;
    }
  }
  return FLASH_OK;
}

/**
 * @brief FLASHPROG_Delete_physical_sector
 * Delete physical sector starting with the given start address
 *
 * @input :  ptr_sector_startaddress : start address of physical section
 *
 * @output : none
 *
 * @return : none
 *
 */
void FLASHPROG_Delete_physical_sector(uint32_t* ptr_sector_startaddress)
{
  XMC_FLASH_ErasePhysicalSector(ptr_sector_startaddress);
}

/**
 * @brief FLASHPROG_Delete_physical_sectors
 * Delete all physical sectors overlapping with the given address range
 *
 * @input :  ptr_startaddress : start address of range
 *           size_bytes       : amount of data (bytes) in range
 *
 * @output : none
 *
 * @return : none
 *
 */
void FLASHPROG_Delete_physical_sectors(uint32_t* ptr_startaddress, uint32_t size_bytes)
{
  uint8_t sector_number;

  for (sector_number=0; sector_number<XMC_FLASH_SECTOR_COUNT_MAX; sector_number++)
  {
    if (Flash_lCheckPhysicalSectorNumberInRange(ptr_startaddress, size_bytes, sector_number)==FLASH_SECTOR_IN_RANGE)
    {
      XMC_FLASH_ErasePhysicalSector(Flash_lGetPhysicalSectorAddress(sector_number));
    }
  }
}

/**
 * @brief FLASHPROG_Bytes_written
 * Returns amount of data written to flash
 *
 * @input :  none
 *
 * @output : none
 *
 * @return : number of bytes written
 *
 */
uint32_t FLASHPROG_Bytes_written(void)
{
  return gl_flash_bytes_written;
}

/**
 * @brief FLASHPROG_CRC32_check
 * CRC32 check of data programmed into address range.
 * Last word inside the range is expected to carry CRC32.
 *
 * @input :  ptr_startaddress : start address of
 *           size_bytes       : amount of data (bytes)
 *
 * @output : none
 *
 * @return : FLASH_OK - CRC32 check is ok
 *           FLAHS_CRC_ERROR - CRC32 check failed
 *
 */
uint32_t FLASHPROG_CRC32_check(uint32_t* ptr_startaddress, uint32_t size_bytes)
{
  uint32_t crc32_result;
  uint32_t crc32_expected;
  XMC_FCE_STATUS_t fce_status;

  XMC_FCE_Enable();
  XMC_FCE_Init(&FCE_config0);
  fce_status = XMC_FCE_CalculateCRC32(&FCE_config0,  ptr_startaddress, size_bytes - 4, &crc32_result);
  XMC_FCE_GetCRCResult(&FCE_config0, &crc32_result);
  if (fce_status == XMC_FCE_STATUS_OK)
  {
    crc32_expected = *(ptr_startaddress + size_bytes/4 - 1);
    if (crc32_result != crc32_expected)
    {
      return FLASH_CRC_ERROR;
    }
  }
  return FLASH_OK;
}
