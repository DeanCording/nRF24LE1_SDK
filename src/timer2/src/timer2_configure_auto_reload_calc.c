/////////////////////////////////////////////////////////////////////////////
//
// File: timer2_configure_auto_reload_calc.c
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


/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// void timer2_configure_auto_reload_calc(uint16_t timer2_config_options, float auto_reload_or_compare_period_in_seconds)
//
// Description:
//  Configures timer 2
//
// Parameters:
//  uint16_t timer2_config_options - timer 2 configuration options
//  uint16_t auto_reload_or_compare_period_in_seconds - if using auto-reload (either mode), this is the auto-reload value used to init CRC ***and*** T2
//                                                              if not using auto-reload, but instead using compare with CCEN, this is the compare value used to init CRC (T2 is init to 0)
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void timer2_configure_auto_reload_calc(uint16_t timer2_config_options, float auto_reload_or_compare_period_in_seconds)
{
	uint16_t calc_crc_with_ps_12, calc_crc_with_ps_24;
	float calc_overflow_period_with_ps_12, calc_overflow_period_with_ps_24;
	float error_calc_overflow_period_with_ps_12, error_calc_overflow_period_with_ps_24;

	calc_crc_with_ps_12 = timer2_calc_crc_val(auto_reload_or_compare_period_in_seconds, 0);
	calc_crc_with_ps_24 = timer2_calc_crc_val(auto_reload_or_compare_period_in_seconds, 1);

	calc_overflow_period_with_ps_12 = timer2_calc_actual_period(calc_crc_with_ps_12, 0);
	calc_overflow_period_with_ps_24 = timer2_calc_actual_period(calc_crc_with_ps_12, 1);

	//Calculate the magnitude of the error of the overflow time with each of the calculated overflow times versus the requested one
	error_calc_overflow_period_with_ps_12 = (calc_overflow_period_with_ps_12 > auto_reload_or_compare_period_in_seconds) ? (calc_overflow_period_with_ps_12 - auto_reload_or_compare_period_in_seconds) : (auto_reload_or_compare_period_in_seconds - calc_overflow_period_with_ps_12);
	error_calc_overflow_period_with_ps_24 = (calc_overflow_period_with_ps_24 > auto_reload_or_compare_period_in_seconds) ? (calc_overflow_period_with_ps_24 - auto_reload_or_compare_period_in_seconds) : (auto_reload_or_compare_period_in_seconds - calc_overflow_period_with_ps_24);

	//Use the values that had the least error (tie goes to divider set to 24)
	if(error_calc_overflow_period_with_ps_12 < error_calc_overflow_period_with_ps_24)
	{
		timer2_configure_manual_reload_calc(((timer2_config_options & ~TIMER2_CONFIG_OPTION_PRESCALER_DIV_MASK) | TIMER2_CONFIG_OPTION_PRESCALER_DIV_12),
											calc_crc_with_ps_12);
	}
	else
	{
		timer2_configure_manual_reload_calc(((timer2_config_options & ~TIMER2_CONFIG_OPTION_PRESCALER_DIV_MASK) | TIMER2_CONFIG_OPTION_PRESCALER_DIV_24),
											calc_crc_with_ps_24);
	}
}
