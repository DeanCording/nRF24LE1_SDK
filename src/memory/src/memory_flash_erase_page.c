/////////////////////////////////////////////////////////////////////////////
//
// File: memory_flash_erase_page.c
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
// memory_flash_return_t memory_flash_erase_page(uint8_t page_num)
//
// Description:
//  Erases the specified page in memory
//
// Parameters:
//  uint8_t page_num - the page number to erase
//
// Return value:
//  memory_flash_return_t
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
memory_flash_return_t memory_flash_erase_page(uint8_t page_num)
{
	//Check to make sure that the requested page is valid
	if(page_num >= MEMORY_FLASH_NUM_PAGES)
	{
		return MEMORY_FLASH_BAD_PARAMS;
	}

	//Save global interrupt bit and disable
	interrupt_save_global_flag(PSW_SB_F0);
	interrupt_control_global_disable();

	//Enable writing
	memory_flash_enable_write_access();

	//Erase the page
	FCR = page_num;

	//Wait for the operation to complete and disable write accesses
	memory_flash_wait_for_write_complete();
	memory_flash_disable_write_access();

	//Restore previous value of global interrupt bit
	interrupt_restore_global_flag(PSW_SB_F0);

	return MEMORY_FLASH_OK;
}
