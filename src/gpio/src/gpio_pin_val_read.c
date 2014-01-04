/////////////////////////////////////////////////////////////////////////////
//
// File: gpio_pin_val_read.c
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
// bool gpio_pin_val_read(gpio_pin_id_t gpio_pin_id)
//
// Description:
//  Returns the value of the requested GPIO pin
//
// Parameters:
//  gpio_pin_id_t gpio_pin_id - ID of the GPIO pin to be read
//
// Return value:
//  The value of the requested GPIO pin
//
///////////////////////////////////////////////////////////////////////////////////////////////
bool gpio_pin_val_read(gpio_pin_id_t gpio_pin_id)
{
	bool value = false;

	//Process the request based on the pin block
	if(gpio_pin_id <= GPIO_PIN_ID_P0_7)
	{
		value = P0 & (1 << (gpio_pin_id % 8));
	}
	else if(gpio_pin_id <= GPIO_PIN_ID_P1_7)
	{
		value = P1 & (1 << (gpio_pin_id % 8));
	}
	else if(gpio_pin_id <= GPIO_PIN_ID_P2_7)
	{
		value = P2 & (1 << (gpio_pin_id % 8));
	}
	else if(gpio_pin_id <= GPIO_PIN_ID_P3_6)
	{
		value = P3 & (1 << (gpio_pin_id % 8));
	}

	if(value)
	{
		return true;
	}
	else
	{
		return false;
	}
}
