/////////////////////////////////////////////////////////////////////////////
//
// File: uart_calc_th1_value.c
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

#include "uart.h"
#include "pwr_clk_mgmt.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// uint16_t uart_calc_th1_value(uint32_t desired_baud_rate, bool smod_bit_value)
//
// Description:
//  Calculates a value for TH1 from the passed in values for baud rate and SMOD
//
// Parameters:
//  uint32_t desired_baud_rate - baud rate use in the calculation
//  bool smod_bit_value - value of SMOD to use in the calculation
//
// Return value:
//  Value to use for TH1 based on the desired baud rate and SMOD value
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
uint8_t uart_calc_th1_value(uint32_t desired_baud_rate, bool smod_bit_value)
{
	//Calculates the TH1 value from the desired baud rate from the formula
	//
	//            (2 ^ SMOD) * CCLK_FREQ
	//TH1 = 256 - -----------------------
	//            384 * desired_baud_rate
	//
	//The formula below also rounds to the nearest whole number
	return (uint8_t)(256 - (((((uint32_t)(2 * ((smod_bit_value != 0) ? 2 : 1) * pwr_clk_mgmt_get_cclk_freq_in_hz())) / ((uint32_t)(384 * desired_baud_rate))) + 1) / 2));
}
