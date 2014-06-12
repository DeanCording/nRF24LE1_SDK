////////////////////////////////////////////////////////////////////////////////////
//
// File: owi_check_scratchpad.c
//
// Copyright Aleksandr Svalov (Alarus), 2014
//
// The author provides no guarantees, warantees, or promises, implied or
// otherwise.  By using this software you agree to indemnify the author
// of any damages incurred by using it.
//
////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////
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
////////////////////////////////////////////////////////////////////////////////////

#include "owi.h"


////////////////////////////////////////////////////////////////////////////////////
//
// uint8_t owi_check_scratchpad(uint8_t * ptr_scratchpad)
//
// Description:
//  Calculate and check the CRC of a Scratchpad
//
// Parameters:
//  uint8_t * ptr_rom - A pointer to an array Scratchpad data
//
// Return value:
//  uint8_t OWI_CRC_OK      The CRC's matched
//  uint8_t OWI_CRC_ERROR   There was a discrepancy between the calculated and the stored CRC
//
////////////////////////////////////////////////////////////////////////////////////
uint8_t owi_check_scratchpad(uint8_t * ptr_scratchpad)
{
	register uint8_t i;
	register uint8_t crc = 0;
	
	for (i = 8; i; i--)
	{
		crc = owi_crc(*ptr_scratchpad, crc);
		ptr_scratchpad++;
	}
	if (crc == (*ptr_scratchpad))
	{
		return OWI_CRC_OK;
	}
	return OWI_CRC_ERROR;
}
