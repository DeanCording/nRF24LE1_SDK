/////////////////////////////////////////////////////////////////////////////
//
// File: timer1_configure.c
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

#include "timer1.h"


///////////////////////////////////////////
// Internal defines
///////////////////////////////////////////
#define TIMER1_CONFIG_OPTION_TMOD_MASK	0xF0	//Mask for the options used for TMOD


/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// void timer1_configure(uint8_t timer1_config_options, uint16_t t1_val)
//
// Description:
//  Configures timer 1
//
// Parameters:
//  uint8_t timer1_config_options - timer 1 configuration options
//  uint16_t t1_val - this is the auto-reload value in mode 2, and the TH1:TL1 (T1) value in other modes
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void timer1_configure(uint8_t timer1_config_options, uint16_t t1_val)
{
	//If timer 1 is being run as 2 8-bit timers with auto-reload, then set the reload value in TH1 and TL1
	if((timer1_config_options & TMOD_MODE1_MASK) == TIMER1_CONFIG_OPTION_MODE_2_8_BIT_AUTO_RLD_TMR)
	{
		TH1 = (uint8_t)t1_val;
		TL1 = (uint8_t)t1_val;
	}
	else
	{
		timer1_set_t1_val(t1_val);
	}

	//Set up TMOD register from timer1_config_options
	TMOD = (TMOD & ~TIMER1_CONFIG_OPTION_TMOD_MASK) | (timer1_config_options & TIMER1_CONFIG_OPTION_TMOD_MASK);
}
