////////////////////////////////////////////////////////////////////////////////////
//
// File: owi_search_devices.c
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
// uint8_t owi_search_devices(gpio_pin_id_t owi_pin_id, owi_device_t * devices, uint8_t max_devices)
//
// Description:
//  Perform an OWI search
//
// Parameters:
//  gpio_pin_id_t owi_pin_id -  ID of the OWI pin
//  owi_device_t * devices   -  A Pointer to an array of type OWI_device
//  uint8_t max_devices      -  The number of the device array
//
// Return value:
//  uint8_t - Return number found devices or error code OWI_SEARCH_ERROR
//
////////////////////////////////////////////////////////////////////////////////////
uint8_t owi_search_devices(gpio_pin_id_t owi_pin_id, owi_device_t * devices, uint8_t max_devices)
{
	register uint8_t * ptr_rom;
	register uint8_t last_bit;
	register uint8_t num_devices = 0;

	// Clear array the ROMs.
	memset(devices, 0, max_devices * 8);

	// Search all ROM and writing to the array.
	do
	{
		ptr_rom = devices[num_devices].rom;
		if (owi_detect_presence(owi_pin_id))
		{
			return OWI_SEARCH_ERROR;
		}
		last_bit = owi_search_rom(owi_pin_id, ptr_rom, last_bit);
		if (last_bit == OWI_SEARCH_ROM_FAILED)
		{
			return OWI_SEARCH_ERROR;
		}
		num_devices++;
	}
	while ((last_bit != OWI_SEARCH_ROM_FINISHED) && (num_devices < max_devices));

	last_bit = num_devices;

	// Go through all the devices and do CRC check.
	for (num_devices = 0; num_devices < last_bit; num_devices++)
	{
		// If any id has a crc error, return error.
		if (owi_check_rom(devices[num_devices].rom) == OWI_CRC_ERROR)
		{
			break;
		}
	}
	return num_devices;
}
