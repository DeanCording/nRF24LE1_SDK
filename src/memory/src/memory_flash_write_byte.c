/////////////////////////////////////////////////////////////////////////////
//
// File: memory_flash_write_byte.c
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
#include "interrupt.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// memory_flash_return_t memory_flash_write_byte(uint16_t address, uint8_t write_val)
//
// Description:
//  Writes the specified value to the specified address in flash memory
//
// Parameters:
//  uint16_t address - address to write
//  uint8_t write_val - value to write
//
// Return value:
//  memory_flash_return_t
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
memory_flash_return_t memory_flash_write_byte(uint16_t address, uint8_t write_val)
{
	uint8_t page_num;
	uint8_t pcon_temp;

	//Check to make sure that the requested address is valid
	if(!memory_flash_does_address_exist_in_flash(address))
	{
		return MEMORY_FLASH_BAD_PARAMS;
	}

	//Find the page based on the address
	memory_flash_get_page_num_from_address(address, &page_num);

	//Check to make sure that the page found is valid
	if(page_num >= MEMORY_FLASH_NUM_PAGES)
	{
		return MEMORY_FLASH_BAD_PARAMS;
	}

	//Save global interrupt bit and disable
	interrupt_save_global_flag(PSW_SB_F0);
	interrupt_control_global_disable();

	//Save the current value of PCON and set PCON.PWM such that movx instructions access code memory
	pcon_temp = PCON;

	//Save the current value of PCON and set PCON.PWM such that movx instructions access code memory
	if(page_num < MEMORY_FLASH_CODE_NUM_PAGES)
	{
		memory_movx_accesses_code_memory();
	}
	else if(page_num < MEMORY_FLASH_NUM_PAGES)
	{
		memory_movx_accesses_data_memory();
	}

	//Enable writing
	memory_flash_enable_write_access();

	//Write the value by first casting the address variable to a pointer to xdata memory, then dereference the pointer and
	// assign the specified value to that address location
	*((__xdata uint8_t *)address) = write_val;

	//Wait for the operation to complete and disable write accesses
	memory_flash_wait_for_write_complete();
	memory_flash_disable_write_access();

	//Restore previous value of PCON
	PCON = pcon_temp;

	//Restore previous value of global interrupt bit
	interrupt_restore_global_flag(PSW_SB_F0);

	return MEMORY_FLASH_OK;
}
