/////////////////////////////////////////////////////////////////////////////
//
// File: timer2_configure_manual_reload_calc.c
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

#include "timer2.h"


///////////////////////////////////////////
// Internal defines
///////////////////////////////////////////
#define TIMER2_CONFIG_OPTION_CCEN_WRITE_MASK		0xFF	//Mask for the options used for CCEN
#define TIMER2_CONFIG_OPTION_T2CON_WRITE_MASK		0x9B	//Mask for the options used for T2CON


/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// void timer2_configure_manual_reload_calc(uint16_t timer2_config_options, uint16_t auto_reload_or_compare_value)
//
// Description:
//  Configures timer 2
//
// Parameters:
//  uint16_t timer2_config_options - timer 2 configuration options
//  uint16_t auto_reload_or_compare_value - if using auto-reload (either mode), this is the auto-reload value used to init CRC ***and*** T2
//                                              if not using auto-reload, but instead using compare with CCEN, this is the compare value used to init CRC (T2 is init to 0)
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void timer2_configure_manual_reload_calc(uint16_t timer2_config_options, uint16_t auto_reload_or_compare_value)
{
	//If timer 2 is being run in either auto-reload mode, then set the reload value in T2 and CRC
	if(((timer2_config_options & (T2CON_RELOAD_MODE_MASK << TIMER2_CONFIG_OPTION_TCON2_OFFSET_SHIFT)) == TIMER2_CONFIG_OPTION_RELOAD_ON_OVERFLOW) ||
	   ((timer2_config_options & (T2CON_RELOAD_MODE_MASK << TIMER2_CONFIG_OPTION_TCON2_OFFSET_SHIFT)) == TIMER2_CONFIG_OPTION_RELOAD_ON_T2EX_FALL))
	{
		timer2_set_crc_and_t2_vals(auto_reload_or_compare_value);
	}

	//Set up CCEN and T2CON registers from timer2_config_options
	CCEN = ((uint8_t)(timer2_config_options >> TIMER2_CONFIG_OPTION_CCEN_OFFSET_SHIFT)) & TIMER2_CONFIG_OPTION_CCEN_WRITE_MASK;
	T2CON = (T2CON & ~TIMER2_CONFIG_OPTION_T2CON_WRITE_MASK) | (((uint8_t)(timer2_config_options >> TIMER2_CONFIG_OPTION_TCON2_OFFSET_SHIFT)) & TIMER2_CONFIG_OPTION_T2CON_WRITE_MASK);
}
