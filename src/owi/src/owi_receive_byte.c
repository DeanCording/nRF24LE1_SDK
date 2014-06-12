////////////////////////////////////////////////////////////////////////////////////
//
// File: owi_receive_byte.c
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
// uint8_t owi_receive_byte(gpio_pin_id_t owi_pin_id)
//
// Description:
//  This function automates the task of receiving a complete byte of data from the OWI
//
// Parameters:
//  gpio_pin_id_t owi_pin_id - ID of the OWI pin
//  
// Return value:
//  uint8_t - The byte read from the OWI
//
////////////////////////////////////////////////////////////////////////////////////
uint8_t owi_receive_byte(gpio_pin_id_t owi_pin_id)
{
	// Clear the input variable.
	register uint8_t mask = 0x01;
	register uint8_t data = 0x00;
	
	// Do once for each bit
	do
	{
		// Set the msb if a '1' value is read from the bus.
		// Leave as it is ('0') else.
		if (owi_read_bit(owi_pin_id))
		{
			// Set current bit
			data |= mask;
		}
		// Left shift the mask.
		mask <<= 1;
	}
	while (mask);
	return data;
}
