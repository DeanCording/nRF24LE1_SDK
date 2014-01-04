/////////////////////////////////////////////////////////////////////////////
//
// File: timer0_configure.c
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

#include "timer0.h"


///////////////////////////////////////////
// Internal defines
///////////////////////////////////////////
#define TIMER0_CONFIG_OPTION_TMOD_MASK	0x0F	//Mask for the options used for TMOD


/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// void timer0_configure(uint8_t timer0_config_options, uint16_t t0_val)
//
// Description:
//  Configures timer 0
//
// Parameters:
//  uint8_t timer0_config_options - timer 0 configuration options
//  uint16_t t0_val - this is the auto-reload value in mode 2, and the TH0:TL0 (T0) value in other modes
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void timer0_configure(uint8_t timer0_config_options, uint16_t t0_val)
{
	//If timer 0 is being run as 2 8-bit timers with auto-reload, then set the reload value in TH0 and TL0
	if((timer0_config_options & TMOD_MODE0_MASK) == TIMER0_CONFIG_OPTION_MODE_2_8_BIT_AUTO_RLD_TMR)
	{
		TH0 = (uint8_t)t0_val;
		TL0 = (uint8_t)t0_val;
	}
	else
	{
		timer0_set_t0_val(t0_val);
	}

	//Set up TMOD register from timer0_config_options
	TMOD = (TMOD & ~TIMER0_CONFIG_OPTION_TMOD_MASK) | (timer0_config_options & TIMER0_CONFIG_OPTION_TMOD_MASK);
}
