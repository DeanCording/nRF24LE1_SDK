////////////////////////////////////////////////////////////////////////////////////
//
// File: owi_read_rom.c
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
// void owi_read_rom(gpio_pin_id_t owi_pin_id, uint8_t * ptr_rom)
//
// Description:
//  Sends the READ ROM command and reads back the ROM id
//
// Parameters:
//  gpio_pin_id_t owi_pin_id - ID of the OWI pin
//  uint8_t * ptr_rom - A pointer where the ROM data will be placed
//
// Return value:
//  None
//
////////////////////////////////////////////////////////////////////////////////////
void owi_read_rom(gpio_pin_id_t owi_pin_id, uint8_t * ptr_rom)
{
	register uint8_t i;
	
	// Send the READ ROM command on the bus.
	owi_send_byte(owi_pin_id, OWI_READ_ROM);
	
	// Do 8 times.
	for (i = 8; i; i--)
	{
		// Place the received data in memory.
		*ptr_rom++ = owi_receive_byte(owi_pin_id);
	}
}
