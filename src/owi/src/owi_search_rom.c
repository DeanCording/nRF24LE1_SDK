////////////////////////////////////////////////////////////////////////////////////
//
// File: owi_search_rom.c
//
// Copyright Aleksandr Svalov (Alarus), 2014
//
// The author provides no guarantees, warantees, or promises, implied or
// otherwise.  By using this software you agree to indemnify the author
// of any damages incurred by using it.
//
////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////
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
// void owi_search_rom(gpio_pin_id_t owi_pin_id, uint8_t * ptr_rom, uint8_t last)
//
// Description:
//  Sends the SEARCH ROM command and returns 1 id found on the OWI
//
// Parameters:
//  gpio_pin_id_t owi_pin_id - ID of the OWI pin
//  uint8_t * ptr_rom - A pointer to an 8 byte char array where the 
//						discovered identifier will be placed. When 
//						searching for several slaves, a copy of the 
//						last found identifier should be supplied in 
//						the array, or the search will fail
// uint8_t last_bit   - The bit position where the algorithm made a 
//						choice the last time it was run. This argument 
//						should be 0 when a search is initiated. Supplying 
//						the return argument of this function when calling 
//						repeatedly will go through the complete slave 
//						search.
//
// Return value:
//  uint8_t  -  The last bit position where there was a discrepancy between
//				slave addresses the last time this function was run.
//				Returns OWI_SEARCH_ROM_FAILED if an error was detected
//				(e.g. a device was connected to the bus during the search),
//				or OWI_SEARCH_ROM_FINISHED when there are no more
//				devices to be discovered.
//
////////////////////////////////////////////////////////////////////////////////////
uint8_t owi_search_rom(gpio_pin_id_t owi_pin_id, uint8_t * ptr_rom, uint8_t last_bit)
{
	uint8_t bit, bit_a, bit_b;
	uint8_t next_bit = 0x00;
	uint8_t mask = 0x01;
	
	// Send SEARCH ROM command on the bus.
	owi_send_byte(owi_pin_id, OWI_SEARCH_ROM);
	
	// Walk through all 64 bits.
	for (bit = 1; bit <= 64; bit++)
	{
		// Read bit from bus twice.
		bit_a = owi_read_bit(owi_pin_id);
		bit_b = owi_read_bit(owi_pin_id);
		
		if (bit_a && bit_b)
		{
			// Both bits 1 (Error).
			return OWI_SEARCH_ROM_FAILED;
		}
		else if (bit_a ^ bit_b)
		{
			// Bits A and B are different. All devices have the same bit here.
			// Set the bit in ROM to this value.
			if (bit_a)
			{
				(*ptr_rom) |= mask;
			}
			else
			{
				(*ptr_rom) &= ~mask;
			}
		}
		else // Both bits 0
		{
			// If this is where a choice was made the last time,
			// a '1' bit is selected this time.
			if (bit == last_bit)
			{
				(*ptr_rom) |= mask;
			}
			// For the rest of the ROM, '0' bits are selected when
			// discrepancies occur.
			else if (bit > last_bit)
			{
				(*ptr_rom) &= ~mask;
				next_bit = bit;
			}
			// If current bit in bit pattern = 0, then this is
			// out new deviation.
			else if (!(*ptr_rom & mask))
			{
				next_bit = bit;
			}
		}
		
		// Send the selected bit to the bus.
		if ((*ptr_rom) & mask)
		{
			owi_write_bit_1(owi_pin_id);
		}
		else
		{
			owi_write_bit_0(owi_pin_id);
		}
		
		// Adjust mask and ROM pointer.
		mask <<= 1;
		if (!mask)
		{
			mask = 0x01;
			ptr_rom++;
		}
	}
	return next_bit;
}
