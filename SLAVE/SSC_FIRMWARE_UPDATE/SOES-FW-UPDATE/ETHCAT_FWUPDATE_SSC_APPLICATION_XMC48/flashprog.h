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

/****************************************************************
* MACROS AND DEFINES
***************************************************************/
#define FLASH_OK                    0
#define FLASH_FULL_ERROR            1
#define FLASH_PROG_ERROR            2
#define FLASH_CRC_ERROR             3
#define FLASH_SECTOR_IN_RANGE       4
#define FLASH_SECTOR_NOT_IN_RANGE   5

#define FLASH_OPT_ERASE              100
#define FLASH_OPT_NO_ERASE           101
#define FLASH_OPT_CHECK              200
#define FLASH_OPT_NO_CHECK           201

#define XMC_FLASH_SECTOR_COUNT_MAX   10

/****************************************************************
* API PROTOTYPES
***************************************************************/

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
void FLASHPROG_Init(uint32_t* dest_address, uint32_t max_size, uint8_t erase, uint8_t check_prog);

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
uint32_t FLASHPROG_Data(void* src_data, uint32_t size_bytes);

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
uint32_t FLASHPROG_Close(void);

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
void FLASHPROG_Delete_physical_sector(uint32_t* ptr_sector_startaddress);

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
void FLASHPROG_Delete_physical_sectors(uint32_t* ptr_startaddress, uint32_t size_bytes);

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
uint32_t FLASHPROG_Bytes_written(void);

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
uint32_t FLASHPROG_CRC32_check(uint32_t* ptr_startaddress, uint32_t size_bytes);
