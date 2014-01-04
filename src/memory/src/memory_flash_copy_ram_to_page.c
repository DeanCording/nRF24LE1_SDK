/////////////////////////////////////////////////////////////////////////////
//
// File: memory_flash_copy_ram_to_page.c
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
// memory_flash_return_t memory_flash_copy_ram_to_page(uint8_t page_num, uint8_t * page_buffer)
//
// Description:
//  Copies the RAM memory into the specified page
//
// Parameters:
//  uint8_t page_num - the page number to copy into
//  uint8_t * page_buffer - a pointer to the area in RAM to copy into the flash page
//
// Return value:
//  memory_flash_return_t
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
memory_flash_return_t memory_flash_copy_ram_to_page(uint8_t page_num, uint8_t * page_buffer)
{
	uint16_t page_start_address;
	uint16_t page_size;

	//Check to make sure that the requested page is valid
	if(page_num >= MEMORY_FLASH_NUM_PAGES)
	{
		return MEMORY_FLASH_BAD_PARAMS;
	}

	memory_flash_get_page_start_address(page_num, &page_start_address);
	memory_flash_get_page_size(page_num, &page_size);

	//Write all of the bytes from the RAM buffer into flash
	if(memory_flash_write_bytes(page_start_address, page_size, page_buffer) != MEMORY_FLASH_OK)
	{
		return MEMORY_FLASH_BAD_PARAMS;
	}

	return MEMORY_FLASH_OK;
}
