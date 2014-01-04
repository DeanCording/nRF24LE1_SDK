/////////////////////////////////////////////////////////////////////////////
//
// File: gpio_pin_val_write.c
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
// void gpio_pin_val_write(gpio_pin_id_t gpio_pin_id, bool value)
//
// Description:
//  Writes the specified value to a GPIO pin
//
// Parameters:
//  gpio_pin_id_t gpio_pin_id - ID of the GPIO pin to be cleared
//  bool value - value to be written to the GPIO pin
//
// Return value:
//  None
//
///////////////////////////////////////////////////////////////////////////////////////////////
void gpio_pin_val_write(gpio_pin_id_t gpio_pin_id, bool value)
{
	//Process the request based on the specified value
	if(value)
	{
		gpio_pin_val_set(gpio_pin_id);
	}
	else
	{
		gpio_pin_val_clear(gpio_pin_id);
	}
}
