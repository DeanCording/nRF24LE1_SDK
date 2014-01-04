/////////////////////////////////////////////////////////////////////////////
//
// File: memory_flash_does_address_exist_in_flash.c
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
// memory_flash_return_t memory_flash_does_address_exist_in_flash(uint16_t address)
//
// Description:
//  Determines whether a specified value exists in flash or not.
//
// Parameters:
//  uint16_t address - the address that we need to check for flash existence
//  uint16_t * address_exists - pointer to a variable where the page size will be saved
//
// Return value:
//  true if the address exists in flash, false otherwise
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
bool memory_flash_does_address_exist_in_flash(uint16_t address)
{
	//Determine first where we are in the flash array (code, extended endurance NV, standard endurance NV) and then copy the start address
	if(address <= MEMORY_FLASH_CODE_END_ADDRESS) //Don't need to check start, as it's 0 and address type is unsigned
	{
		return true;
	}
	else if((address >= MEMORY_FLASH_NV_EXT_END_START_ADDRESS) && (address <= MEMORY_FLASH_NV_EXT_END_END_ADDRESS))
	{
		return true;
	}
	else if(address >= MEMORY_FLASH_NV_STD_END_START_ADDRESS) //Don't need to check end, as it's 65535 and address type is uint16_t
	{
		return true;
	}

	return false;
}
