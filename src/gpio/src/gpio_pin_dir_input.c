/////////////////////////////////////////////////////////////////////////////
//
// File: gpio_pin_dir_input.c
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

#include "gpio.h"


///////////////////////////////////////////////////////////////////////////////////////////////
//
// void gpio_pin_dir_input(gpio_pin_id_t gpio_pin_id, uint8_t gpio_pin_config_options)
//
// Description:
//  Configures a GPIO pin as an input
//
// Parameters:
//  gpio_pin_id_t gpio_pin_id - ID of the GPIO pin to be configured as an input
//  uint8_t gpio_pin_config_options - GPIO pin configuration options
//
// Return value:
//  None
//
///////////////////////////////////////////////////////////////////////////////////////////////
void gpio_pin_dir_input(gpio_pin_id_t gpio_pin_id, uint8_t gpio_pin_config_options)
{
	//Process the request based on the pin block
	if(gpio_pin_id <= GPIO_PIN_ID_P0_7)
	{
		gpio_pins_dir_input(P0DIR, (1 << (gpio_pin_id % 8)));

		//Set up the options (other than the actual direction) for the pin here
		P0CON = ((gpio_pin_id % 8) & PXCON_BIT_ADDR_MASK) |
				(gpio_pin_config_options & PXCON_PINMODE_MASK);
	}
	else if(gpio_pin_id <= GPIO_PIN_ID_P1_7)
	{
		gpio_pins_dir_input(P1DIR, (1 << (gpio_pin_id % 8)));

		//Set up the options (other than the actual direction) for the pin here
		P1CON = ((gpio_pin_id % 8) & PXCON_BIT_ADDR_MASK) |
				(gpio_pin_config_options & PXCON_PINMODE_MASK);
	}
	else if(gpio_pin_id <= GPIO_PIN_ID_P2_7)
	{
		gpio_pins_dir_input(P2DIR, (1 << (gpio_pin_id % 8)));

		//Set up the options (other than the actual direction) for the pin here
		P2CON = ((gpio_pin_id % 8) & PXCON_BIT_ADDR_MASK) |
				(gpio_pin_config_options & PXCON_PINMODE_MASK);
	}
	else if(gpio_pin_id <= GPIO_PIN_ID_P3_6)
	{
		gpio_pins_dir_input(P2DIR, (1 << (gpio_pin_id % 8)));

		//Set up the options (other than the actual direction) for the pin here
		P3CON = ((gpio_pin_id % 8) & PXCON_BIT_ADDR_MASK) |
				(gpio_pin_config_options & PXCON_PINMODE_MASK);
	}
}
