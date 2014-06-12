////////////////////////////////////////////////////////////////////////////////////
//
// File: owi_detect_presence.c
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
// uint8_t owi_detect_presence(gpio_pin_id_t owi_pin_id)
//
// Description:
//  Generates the waveform for transmission of a Reset pulse on the OWI and listens for presence signals.
//
// Parameters:
//  gpio_pin_id_t owi_pin_id - ID of the OWI pin
//
// Return value:
//  uint8_t "0" - Not detect presence
//  uint8_t "1" - Detect presence
//
////////////////////////////////////////////////////////////////////////////////////
uint8_t owi_detect_presence(gpio_pin_id_t owi_pin_id)
{
	// Delay before resetting.
	delay_us(OWI_DELAY_G);
	
	// Drive bus low and delay.
	gpio_pin_dir_output(owi_pin_id, GPIO_PIN_CONFIG_OPTION_PIN_MODE_OUTPUT_BUFFER_NORMAL_DRIVE_STRENGTH);
	delay_us(OWI_DELAY_H);
	
	// Release bus and delay.
	gpio_pin_dir_input(owi_pin_id, GPIO_PIN_CONFIG_OPTION_PIN_MODE_INPUT_BUFFER_ON_PULL_UP_RESISTOR);
	delay_us(OWI_DELAY_I);
	
	// Sample bus to detect presence signal and delay.
	if (gpio_pin_val_read(owi_pin_id))
	{
		delay_us(OWI_DELAY_J);
		return 1;
	}
	else
	{
		delay_us(OWI_DELAY_J);
		return 0;
	}
}
