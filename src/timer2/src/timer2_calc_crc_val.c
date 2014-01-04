/////////////////////////////////////////////////////////////////////////////
//
// File: timer2_calc_crc_val.c
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
#include "pwr_clk_mgmt.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// uint16_t timer2_calc_crc_val(float period_in_seconds, bool t2ps_bit_val)
//
// Description:
//  Gets the closest reload value for timer 2 based on the input timer period and prescaler value
//
// Parameters:
//  float period_in_seconds - length of the expected timer period in nanoseconds
//  bool t2ps_bit_val - value of the T2CON.T2PS value (timer 2's prescaler)
//
// Return value:
//  Value to set the CRCH:CRCL registers (and initialize TH2:TH1 registers) based on the input timer
//   period
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
uint16_t timer2_calc_crc_val(float period_in_seconds, bool t2ps_bit_val)
{
	float calc_crc_val_f;

	//Calculates the CRCH:CRCL value from the desired timer overflow period
	//
	//                      period * CCLK_FREQ
	//CRC = 65536 - -----------------------------------
	//              (2 ^ PRESCALER) * 12 clocks/timer++
	//
	calc_crc_val_f = (float)65536 - ((period_in_seconds * (float)pwr_clk_mgmt_get_cclk_freq_in_hz()) / ((float)(((t2ps_bit_val ? 2 : 1) * 12))));

	//Check if the calculated value will overflow or underflow the CRC register
	if(calc_crc_val_f >= (float)65535)
	{
		//The value will overflow, so just return the maximum possible value
		return 65535;
	}
	else if(calc_crc_val_f <= (float)0)
	{
		//The value will underflow, so just return the minimum possible value
		return 0;
	}
	else
	{
		//Round the floating point number to the nearest integer by adding 0.5, then return that integer
		return ((uint16_t)(calc_crc_val_f + 0.5));
	}
}
