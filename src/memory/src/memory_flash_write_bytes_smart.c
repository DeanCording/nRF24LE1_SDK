/////////////////////////////////////////////////////////////////////////////
//
// File: memory_flash_write_bytes.c
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
// memory_flash_return_t memory_flash_write_bytes_smart(uint16_t start_address, uint16_t num_bytes_to_write, uint8_t * data_array, uint8_t * page_buffer)
//
// Description:
//  Writes the specified values to the specified addresses in flash memory, but also handles erasing pages
//   and writing untouched data back
//
// Parameters:
//  uint16_t start_address - first address to write
//  uint16_t num_bytes_to_write - number of bytes to write
//  uint8_t * data_array - pointer to array that holds bytes to write
//  uint8_t * data_array - pointer to array is used to hold the current page (should be of size MEMORY_FLASH_PAGE_SIZE
//   or larger)
//
// Return value:
//  memory_flash_return_t
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
memory_flash_return_t memory_flash_write_bytes_smart(uint16_t start_address, uint16_t num_bytes_to_write, uint8_t * data_array, uint8_t * page_buffer)
{
	uint8_t cur_page_num;
	uint16_t i, page_start_offset, bytes_written = 0, page_size, page_start_address;
	bool erase_cur_page, write_cur_page;

	//Check parameters
	if(num_bytes_to_write == 0)
	{
		return MEMORY_FLASH_BAD_PARAMS;
	}

	//Make sure all addresses exist
	for(i = 0; i < num_bytes_to_write; i++)
	{
		if(!memory_flash_does_address_exist_in_flash(start_address + i))
		{
			return MEMORY_FLASH_BAD_PARAMS;
		}
	}

	//The initial cur_page_num value is the page in which start_address is located
	if(memory_flash_get_page_num_from_address(start_address, &cur_page_num) != MEMORY_FLASH_OK)
	{
		return MEMORY_FLASH_BAD_PARAMS;
	}

	//The initial page_size is the size of the page in which start_address is located
	if(memory_flash_get_page_size(cur_page_num, &page_size) != MEMORY_FLASH_OK)
	{
		return MEMORY_FLASH_BAD_PARAMS;
	}

	//The initial page_start_offset value is the offset in the page in which start_address is located
	if(memory_flash_get_page_start_address(cur_page_num, &page_start_address) != MEMORY_FLASH_OK)
	{
		return MEMORY_FLASH_BAD_PARAMS;
	}

	page_start_offset = start_address - page_start_address;

	//Write all the bytes
	while(bytes_written < num_bytes_to_write)
	{
		//Initialize the erase and write variables to false
		erase_cur_page = false;
		write_cur_page = false;

		//Copy the current flash page to RAM
		if(memory_flash_copy_page_to_ram(cur_page_num, page_buffer) != MEMORY_FLASH_OK)
		{
			return MEMORY_FLASH_BAD_PARAMS;
		}

		//Copy the values to be written in the RAM page
		for(i = page_start_offset; (i < page_size) && (bytes_written < num_bytes_to_write); i++, bytes_written++)
		{
			//Check if the byte that will be written is different from the current byte
			if(page_buffer[i] != data_array[bytes_written])
			{
				//The bytes are different, so we know that we will have to write this RAM page back to flash.  This
				// value needs to stick if it goes true, so do not set it to false in the event that the bytes were
				// the same
				write_cur_page = true;

				//The bytes are different, so check if this pair of bytes will require us to erase this page.  This
				// value needs to stick if it goes to true, so only check if it is false.
				if(!erase_cur_page)
				{
					erase_cur_page = !memory_flash_can_byte_be_written_without_page_erase(page_buffer[i], data_array[bytes_written]);
				}
			}

			//Write the current page location with its corresponding location in the passed in array of values to write
			page_buffer[i] = data_array[bytes_written];
		}

		//If we determined we needed to erase the page, then do so now
		if(erase_cur_page)
		{
			if(memory_flash_erase_page(cur_page_num) != MEMORY_FLASH_OK)
			{
				return MEMORY_FLASH_BAD_PARAMS;
			}
		}

		//Copy the RAM page back to the flash page if necessary (checking erase_cur_page is just in case there's a problem with write_cur_page)
		if(write_cur_page || erase_cur_page)
		{
			if(memory_flash_copy_ram_to_page(cur_page_num, page_buffer) != MEMORY_FLASH_OK)
			{
				return MEMORY_FLASH_BAD_PARAMS;
			}
		}

		//After the first run, we are guaranteed to be writing the start of a page if we are to continue.  Increment
		// the page counter to the next page.
		page_start_offset = 0;

		cur_page_num++;

		memory_flash_get_page_size(cur_page_num, &page_size);
	}

	return MEMORY_FLASH_OK;
}
