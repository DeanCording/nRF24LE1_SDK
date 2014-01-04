/////////////////////////////////////////////////////////////////////////////
//
// File: memory_flash_read_bytes.c
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
// memory_flash_return_t memory_flash_read_bytes(uint16_t start_address, uint16_t num_bytes_to_read, uint8_t * data_array)
//
// Description:
//  Reads the values from the specified addresses in flash memory
//
// Parameters:
//  uint16_t start_address - first address to write
//  uint16_t num_bytes_to_read - number of bytes to read
//  uint8_t * data_array - pointer to array to copy read values into
//
// Return value:
//  memory_flash_return_t
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
memory_flash_return_t memory_flash_read_bytes(uint16_t start_address, uint16_t num_bytes_to_read, uint8_t * data_array)
{
	uint16_t x;

	//Check parameters
	if(num_bytes_to_read == 0)
	{
		return MEMORY_FLASH_BAD_PARAMS;
	}

	//Make sure all addresses exist
	for(x = 0; x < num_bytes_to_read; x++)
	{
		if(!memory_flash_does_address_exist_in_flash(start_address + x))
		{
			return MEMORY_FLASH_BAD_PARAMS;
		}
	}

	//Read the entire array byte-by-byte, while making sure that all the addresses are valid
	for(x = 0; x < num_bytes_to_read; x++)
	{
		if(memory_flash_read_byte(start_address + x, &data_array[x]) != MEMORY_FLASH_OK)
		{
			return MEMORY_FLASH_BAD_PARAMS;
		}
	}

	return MEMORY_FLASH_OK;
}
