/////////////////////////////////////////////////////////////////////////////
//
// File: memory_flash_get_page_start_address.c
//
// Copyright S. Brennen Ball, 2011
//
// The author provides no guarantees, warantees, or promises, implied or
//  otherwise.  By using this software you agree to indemnify the author
//  of any damages incurred by using it.
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
/////////////////////////////////////////////////////////////////////////////

#include "memory.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// memory_flash_return_t memory_flash_get_page_start_address(uint8_t page_num, uint16_t * start_address)
//
// Description:
//  Gets the start address of the requested flash page
//
// Parameters:
//  uint8_t page_num - the page number that we need the start address for
//  uint16_t * start_address - pointer to a variable where the start address will be saved
//
// Return value:
//  memory_flash_return_t
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
memory_flash_return_t memory_flash_get_page_start_address(uint8_t page_num, uint16_t * start_address)
{
	//Check to make sure that the requested page is valid
	if(page_num >= MEMORY_FLASH_NUM_PAGES)
	{
		return MEMORY_FLASH_BAD_PARAMS;
	}

	//Determine first where we are in the flash array (code, extended endurance NV, standard endurance NV) and then copy the start address
	if(page_num < MEMORY_FLASH_CODE_NUM_PAGES)
	{
		(*start_address) = MEMORY_FLASH_CODE_START_ADDRESS + ((page_num - MEMORY_FLASH_CODE_FIRST_PAGE_NUM) * MEMORY_FLASH_CODE_PAGE_SIZE);
	}
	else if(page_num < (MEMORY_FLASH_CODE_NUM_PAGES + MEMORY_FLASH_NV_EXT_END_NUM_PAGES))
	{
		(*start_address) = MEMORY_FLASH_NV_EXT_END_START_ADDRESS + ((page_num - MEMORY_FLASH_NV_EXT_END_FIRST_PAGE_NUM) * MEMORY_FLASH_NV_EXT_END_PAGE_SIZE);
	}
	else
	{
		(*start_address) = MEMORY_FLASH_NV_STD_END_START_ADDRESS + ((page_num - MEMORY_FLASH_NV_STD_END_FIRST_PAGE_NUM) * MEMORY_FLASH_NV_STD_END_PAGE_SIZE);
	}

	return MEMORY_FLASH_OK;
}
