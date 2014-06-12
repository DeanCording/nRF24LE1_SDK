////////////////////////////////////////////////////////////////////////////////////
//
// File: owi_send_byte.c
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
// void owi_send_byte(gpio_pin_id_t owi_pin_id, uint8_t data)
//
// Description:
//  This function automates the task of sending a complete byte of data on the OWI
//
// Parameters:
//  gpio_pin_id_t owi_pin_id - ID of the OWI pin
//  uint8_t data - The data to send on the OWI
//
// Return value:
//  None
//
////////////////////////////////////////////////////////////////////////////////////
void owi_send_byte(gpio_pin_id_t owi_pin_id, uint8_t data)
{
	register uint8_t mask = 0x01;
	
	// Do once for each bit
	do
	{
		// Determine if lsb is '0' or '1' and transmit corresponding
		// waveform on the bus.
		if (mask & data)
		{
			owi_write_bit_1(owi_pin_id);
		}
		else
		{
			owi_write_bit_0(owi_pin_id);
		}
		// Left shift the mask.
		mask <<= 1;
	}
	while (mask);
}
