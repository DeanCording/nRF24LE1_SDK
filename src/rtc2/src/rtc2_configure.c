/////////////////////////////////////////////////////////////////////////////
//
// File: rtc2_configure.c
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

#include "rtc2.h"


///////////////////////////////////////////
// Internal defines
///////////////////////////////////////////
#define RTC2_CONFIG_OPTION_RTC2CON_MASK	0x0F	//Mask for the options used for RTC2CON


/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// void rtc2_configure(uint8_t rtc2_config_options, uint16_t compare_value)
//
// Description:
//  Configures RTC2
//
// Parameters:
//  uint8_t rtc2_config_options - RTC2 configuration options
//  uint8_t compare_value - if using modes 2 or 3, this is the compare value
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void rtc2_configure(uint8_t rtc2_config_options, uint16_t compare_value)
{
	//If RTC2 is running in either mode 0 or 1, then setup the compare value
	if(((rtc2_config_options & RTC2CON_COMPARE_MODE_MASK) == RTC2_CONFIG_OPTION_COMPARE_MODE_0_RESET_AT_IRQ) ||
	   ((rtc2_config_options & RTC2CON_COMPARE_MODE_MASK) == RTC2_CONFIG_OPTION_COMPARE_MODE_1_WRAP_AT_IRQ))
	{
		rtc2_set_compare_val(compare_value);
	}

	//Set up RTC2CON register from rtc2_config_options
	RTC2CON = (RTC2CON & ~RTC2_CONFIG_OPTION_RTC2CON_MASK) | (rtc2_config_options & RTC2_CONFIG_OPTION_RTC2CON_MASK);
}
