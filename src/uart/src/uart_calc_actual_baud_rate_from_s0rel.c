/////////////////////////////////////////////////////////////////////////////
//
// File: uart_calc_actual_baud_rate_from_s0rel.c
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
// uint32_t uart_calc_actual_baud_rate_from_s0rel(uint16_t s0rel_reg_value, bool smod_bit_value)
//
// Description:
//  Calculates a baud rate from the passed in values for S0REL and SMOD
//
// Parameters:
//  uint16_t s0rel_reg_value - value of S0REL to use in the calculation
//  bool smod_bit_value - value of SMOD to use in the calculation
//
// Return value:
//  Actual baud rate (subject to rounding errors) calculated given S0REL and SMOD values
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
uint32_t uart_calc_actual_baud_rate_from_s0rel(uint16_t s0rel_reg_value, bool smod_bit_value)
{
	//Calculates the actual baud rate from the formula
	//
	//     (2 ^ SMOD) * CCLK_FREQ
	//BR = ----------------------
	//       64 * (1024 - S0REL)
	//
	//The formula below also rounds to the nearest whole number
	return (uint32_t)(((((uint32_t)(2 * ((smod_bit_value != 0) ? 2 : 1) * pwr_clk_mgmt_get_cclk_freq_in_hz())) / ((uint32_t)(64 * (1024 - s0rel_reg_value)))) + 1) / 2);
}
