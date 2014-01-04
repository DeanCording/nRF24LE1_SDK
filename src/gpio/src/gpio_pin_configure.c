/////////////////////////////////////////////////////////////////////////////
//
// File: gpio_pin_configure.c
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
// void gpio_pin_configure(gpio_pin_id_t gpio_pin_id, uint8_t gpio_pin_config_options)
//
// Description:
//  Configures a GPIO pin
//
// Parameters:
//  gpio_pin_id_t gpio_pin_id - ID of the GPIO pin to be configured
//  uint8_t gpio_pin_config_options - GPIO pin configuration options
//
// Return value:
//  None
//
///////////////////////////////////////////////////////////////////////////////////////////////
void gpio_pin_configure(gpio_pin_id_t gpio_pin_id, uint8_t gpio_pin_config_options)
{
	//Process the request based on the pin block
	if(gpio_pin_id <= GPIO_PIN_ID_P0_7)
	{
		//The pin is in P0, so now check if the request is for input or output direction
		if(gpio_pin_config_options & GPIO_PIN_CONFIG_OPTION_DIR_OUTPUT)
		{
			//The request was output, so now check if the pin value should be cleared or set
			if(gpio_pin_config_options & GPIO_PIN_CONFIG_OPTION_OUTPUT_VAL_SET)
			{
				gpio_pins_val_set(P0, (1 << (gpio_pin_id % 8)));
			}
			else
			{
				gpio_pins_val_clear(P0, (1 << (gpio_pin_id % 8)));
			}

			//Set up the options (other than the actual direction) for the pin here
			P0CON = ((gpio_pin_id % 8) & PXCON_BIT_ADDR_MASK) |
					(gpio_pin_config_options & PXCON_PINMODE_MASK);

			//Finally, set up the GPIO pin as an output
			gpio_pins_dir_output(P0DIR, (1 << (gpio_pin_id % 8)));
		}
		else
		{
			//The request was input, so set up the options (other than the actual direction) for the pin here
			P0CON = ((gpio_pin_id % 8) & PXCON_BIT_ADDR_MASK) |
					PXCON_IN_OUT |
					(gpio_pin_config_options & PXCON_PINMODE_MASK);

			//Finally, set up the GPIO pin as an input
			gpio_pins_dir_input(P0DIR, (1 << (gpio_pin_id % 8)));
		}
	}
	else if(gpio_pin_id <= GPIO_PIN_ID_P1_7)
	{
		//The pin is in P1, so now check if the request is for input or output direction
		if(gpio_pin_config_options & GPIO_PIN_CONFIG_OPTION_DIR_OUTPUT)
		{
			//The request was output, so now check if the pin value should be cleared or set
			if(gpio_pin_config_options & GPIO_PIN_CONFIG_OPTION_OUTPUT_VAL_SET)
			{
				gpio_pins_val_set(P1, (1 << (gpio_pin_id % 8)));
			}
			else
			{
				gpio_pins_val_clear(P1, (1 << (gpio_pin_id % 8)));
			}

			//Set up the options (other than the actual direction) for the pin here
			P1CON = ((gpio_pin_id % 8) & PXCON_BIT_ADDR_MASK) |
					(gpio_pin_config_options & PXCON_PINMODE_MASK);

			//Finally, set up the GPIO pin as an input
			gpio_pins_dir_output(P1DIR, (1 << (gpio_pin_id % 8)));
		}
		else
		{
			//The request was input, so set up the options (other than the actual direction) for the pin here
			P1CON = ((gpio_pin_id % 8) & PXCON_BIT_ADDR_MASK) |
					PXCON_IN_OUT |
					(gpio_pin_config_options & PXCON_PINMODE_MASK);

			//Finally, set up the GPIO pin as an input
			gpio_pins_dir_input(P1DIR, (1 << (gpio_pin_id % 8)));
		}
	}
	else if(gpio_pin_id <= GPIO_PIN_ID_P2_7)
	{
		//The pin is in P2, so now check if the request is for input or output direction
		if(gpio_pin_config_options & GPIO_PIN_CONFIG_OPTION_DIR_OUTPUT)
		{
			//The request was output, so now check if the pin value should be cleared or set
			if(gpio_pin_config_options & GPIO_PIN_CONFIG_OPTION_OUTPUT_VAL_SET)
			{
				gpio_pins_val_set(P2, (1 << (gpio_pin_id % 8)));
			}
			else
			{
				gpio_pins_val_clear(P2, (1 << (gpio_pin_id % 8)));
			}

			//Set up the options (other than the actual direction) for the pin here
			P2CON = ((gpio_pin_id % 8) & PXCON_BIT_ADDR_MASK) |
					(gpio_pin_config_options & PXCON_PINMODE_MASK);

			//Finally, set up the GPIO pin as an input
			gpio_pins_dir_output(P2DIR, (1 << (gpio_pin_id % 8)));
		}
		else
		{
			//The request was input, so set up the options (other than the actual direction) for the pin here
			P2CON = ((gpio_pin_id % 8) & PXCON_BIT_ADDR_MASK) |
					PXCON_IN_OUT |
					(gpio_pin_config_options & PXCON_PINMODE_MASK);

			//Finally, set up the GPIO pin as an input
			gpio_pins_dir_input(P2DIR, (1 << (gpio_pin_id % 8)));
		}
	}
	else if(gpio_pin_id <= GPIO_PIN_ID_P3_6)
	{
		//The pin is in P3 (keep in mind there is no P3.7 on any part), so now check if the request is for input or output direction
		if(gpio_pin_config_options & GPIO_PIN_CONFIG_OPTION_DIR_OUTPUT)
		{
			//The request was output, so now check if the pin value should be cleared or set
			if(gpio_pin_config_options & GPIO_PIN_CONFIG_OPTION_OUTPUT_VAL_SET)
			{
				gpio_pins_val_set(P3, (1 << (gpio_pin_id % 8)));
			}
			else
			{
				gpio_pins_val_clear(P3, (1 << (gpio_pin_id % 8)));
			}

			//Set up the options (other than the actual direction) for the pin here
			P3CON = ((gpio_pin_id % 8) & PXCON_BIT_ADDR_MASK) |
					(gpio_pin_config_options & PXCON_PINMODE_MASK);

			//Finally, set up the GPIO pin as an input
			gpio_pins_dir_output(P3DIR, (1 << (gpio_pin_id % 8)));
		}
		else
		{
			//The request was input, so set up the options (other than the actual direction) for the pin here
			P3CON = ((gpio_pin_id % 8) & PXCON_BIT_ADDR_MASK) |
					PXCON_IN_OUT |
					(gpio_pin_config_options & PXCON_PINMODE_MASK);

			//Finally, set up the GPIO pin as an input
			gpio_pins_dir_input(P3DIR, (1 << (gpio_pin_id % 8)));
		}
	}
}
