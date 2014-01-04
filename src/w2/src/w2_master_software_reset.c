/////////////////////////////////////////////////////////////////////////////
//
// File: w2_master_software_reset.c
//
// Copyright S. Brennen Ball, 2011
//
// The author provides no guarantees, warantees, or promises, implied or
//  otherwise.By using this software you agree to indemnify the author
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
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA02110-1301USA
/////////////////////////////////////////////////////////////////////////////

#include "w2_src.h"
#include "delay.h"
#include "gpio.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// void w2_master_software_reset()
//
// Description:
//  Resets the W2 bus
//  Note: this function is a ported/modified version of hal_w2_soft_reset() from Nordic's nAN-20
//   application note source code
//
// Parameters:
//  None
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void w2_master_software_reset()
{
	uint8_t w2con0_copy;

	//Store the current W2CON0 settings
	w2con0_copy = W2CON0;

	//Clear the actual GPIO values (this only affects the pin value when the pin is configured as an output)
	w2_prepare_scl_sda();

	//Set up for the first part of a stop condition (SCL = 0, SDA = 1)
	//This will take effect after the call to w2_disable() below
	w2_clear_scl();
	w2_set_sda();

	//Reset W2 by bringing the clock to idle and disabling the hardware block
	w2_master_set_clock_idle();
	w2_master_set_clock_100_khz();
	w2_disable();
	delay_us(5);

	//Clear SDA
	w2_clear_sda();
	delay_us(5);

	//Set SCL
	w2_set_scl();
	delay_us(5);

	//Set SDA to complete the stop condition
	w2_set_sda();
	delay_us(5);

	//Return to the W2CON0 settings that were in place before this function was called
	W2CON0 = w2con0_copy;
}
