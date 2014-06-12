////////////////////////////////////////////////////////////////////////////////////
//
// File: owi.h
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

#ifndef OWI_H_
#define OWI_H_

#include <string.h>
#include "gpio.h"
#include "delay.h"


////////////////////////////////////////////////////////////////////////////////////
// ROM structure
////////////////////////////////////////////////////////////////////////////////////
typedef struct
{
	uint8_t rom[8];
} owi_device_t;


////////////////////////////////////////////////////////////////////////////////////
// Timing parameters
////////////////////////////////////////////////////////////////////////////////////
#define OWI_DELAY_A					(1)
#define OWI_DELAY_B					(49)
#define OWI_DELAY_C					(49)
#define OWI_DELAY_D					(1)
#define OWI_DELAY_E					(2)
#define OWI_DELAY_F					(47)
#define OWI_DELAY_G					(0)
#define OWI_DELAY_H					(480)
#define OWI_DELAY_I					(80)
#define OWI_DELAY_J					(400)


////////////////////////////////////////////////////////////////////////////////////
// ROM commands
////////////////////////////////////////////////////////////////////////////////////
#define OWI_READ_ROM				0x33
#define OWI_SKIP_ROM				0xCC
#define OWI_MATCH_ROM				0x55
#define OWI_SEARCH_ROM				0xF0


////////////////////////////////////////////////////////////////////////////////////
// CRC return codes
////////////////////////////////////////////////////////////////////////////////////
#define OWI_CRC_OK					0x00
#define OWI_CRC_ERROR				0x01


////////////////////////////////////////////////////////////////////////////////////
// Search return codes
////////////////////////////////////////////////////////////////////////////////////
#define OWI_SEARCH_ROM_FINISHED		0x00
#define OWI_SEARCH_ROM_FAILED		0xFF
#define OWI_SEARCH_ERROR			0x00


////////////////////////////////////////////////////////////////////////////////////
// Function prototypes
////////////////////////////////////////////////////////////////////////////////////
uint8_t owi_check_rom(uint8_t * ptr_rom);
uint8_t owi_check_scratchpad(uint8_t * ptr_scratchpad);
uint8_t owi_crc(uint8_t data, uint8_t seed);
uint8_t owi_detect_presence(gpio_pin_id_t owi_pin_id);
void owi_match_rom(gpio_pin_id_t owi_pin_id, uint8_t * ptr_rom);
void owi_pin_configure(gpio_pin_id_t owi_pin_id);
uint8_t owi_read_bit(gpio_pin_id_t owi_pin_id);
void owi_read_rom(gpio_pin_id_t owi_pin_id, uint8_t * ptr_rom);
uint8_t owi_receive_byte(gpio_pin_id_t owi_pin_id);
uint8_t owi_search_devices(gpio_pin_id_t owi_pin_id, owi_device_t * devices, uint8_t max_devices);
uint8_t owi_search_rom(gpio_pin_id_t owi_pin_id, uint8_t * ptr_rom, uint8_t last_deviation);
void owi_send_byte(gpio_pin_id_t owi_pin_id, uint8_t data);
void owi_skip_rom(gpio_pin_id_t owi_pin_id);
void owi_write_bit_0(gpio_pin_id_t owi_pin_id);
void owi_write_bit_1(gpio_pin_id_t owi_pin_id);


#endif /* OWI_H_ */
