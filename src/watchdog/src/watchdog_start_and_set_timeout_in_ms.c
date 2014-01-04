/////////////////////////////////////////////////////////////////////////////
//
// File: watchdog_start_and_set_timeout_in_ms.c
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

#include "watchdog.h"
#include "pwr_clk_mgmt.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// uint16_t watchdog_start_and_set_timeout_in_ms(uint32_t milliseconds)
//
// Description:
//  Calculates the closest watchdog timeout value to the value of milliseconds and sets the watchdog to that value, thereby starting the
//   watchdog timer.  If no CLKLF source is enabled, the function will enable CLKLF in RCOSC32K mode, and then will wait for until CLKLF is
//   ready for use.  Returns the value that is assigned to the watchdog counter (WDSV).
//
// Parameters:
//  uint32_t milliseconds - approximate number of milliseconds to which the the watchdog timer should be set (max is 511,992 ms, or
//   approximately 512 seconds)
//
// Return value:
//  Value written to WDSV (this can be used in subsequent reloads of the watchdog using watchdog_set_wdsv_count())
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
uint16_t watchdog_start_and_set_timeout_in_ms(uint32_t milliseconds)
{
	uint16_t wd_value = 0;

	//CLKLF must be running to use the watchdog
	if(!pwr_clk_mgmt_is_clklf_enabled())
	{
		//CLKLF is not running, so enable RCOSC32K and wait until it is ready
		pwr_clk_mgmt_clklf_configure(PWR_CLK_MGMT_CLKLF_CONFIG_OPTION_CLK_SRC_XOSC16M);
		pwr_clk_mgmt_wait_until_clklf_is_ready();
	}

	//Approximate max timeout in milliseconds is 511,992, so anything higher gets clipped here
	if(milliseconds < 511992)
	{
		//From the formula on p. 104 of v1.6 of the nRF24LE1 datasheet, the equation for the watchdog timeout (in seconds) is given as
		//
		//                     WDSV * 256
		//    WD_timeout (s) = ----------
		//                       32768
		//
		// This then reduces to
		//
		//                     WDSV
		//    WD_timeout (s) = ----
		//                     128
		//
		// Then if we want the watchdog timeout to be in units of milliseconds
		//
		//                      WDSV * 1000
		//    WD_timeout (ms) = -----------
		//                          128
		//
		// Solving for WDSV
		//
		//           WD_timeout (ms) * 128
		//    WDSV = ---------------------
		//                   1000
		//
		// By adding 500 to the numerator before performing the division, the result gets rounded (as 500 is half of 1000, the denominator)
		wd_value = (uint16_t)(((uint32_t)(milliseconds * ((uint32_t)128)) + (uint32_t)500) / ((uint32_t)1000));
	}

	watchdog_set_wdsv_count(wd_value);

	return wd_value;
}
