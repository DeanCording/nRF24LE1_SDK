/////////////////////////////////////////////////////////////////////////////
//
// File: memory_flash_can_byte_be_written_without_page_erase.c
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
#include <stdio.h>


/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// bool memory_flash_can_byte_be_written_without_page_erase(uint8_t cur_flash_val, uint8_t write_val)
//
// Description:
//  Determines whether a specified value could be written over a value currently in flash memory without
//   needing to erase the page first.  This function does not actually write the byte, it simply tests
//   the necessity of a page erase for the given write.
//
// Parameters:
//  uint8_t cur_flash_val - current value of flash location
//  uint8_t write_val - value that would be written to the specified flash location
//
// Return value:
//  true if the value could be written without an erase, false otherwise
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
bool memory_flash_can_byte_be_written_without_page_erase(uint8_t cur_flash_val, uint8_t write_val)
{
	uint8_t temp_val;

	//XOR the current flash byte with the byte that would be written in its place to determine if there are
	// bits that have to change (resulting bit after the XOR becomes 1 if the two input bits were different).
	temp_val = cur_flash_val ^ write_val;

	//AND the result of the previous XOR with the value to be written to determine if the bits that are
	// changing are being set. If the result of the AND on any bit is 1, then that means we are trying to
	// change that flash bit from 0 -> 1.  This can only happen with a page erase, as code can only change
	// a flash bit from 1 -> 0.
	temp_val &= write_val;

	//If temp_val is 0, then that means that either no bits are changing or none of the bits that are changing
	// have to go from 0 -> 1, so a page erase is not needed.  If temp_val is non-zero, then one or more of
	// the bits needs to go from 0 -> 1, so a page erase must occur to successfully write this value.
	if(temp_val == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
