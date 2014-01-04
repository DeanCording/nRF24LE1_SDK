/////////////////////////////////////////////////////////////////////////////
//
// File: uart_configure_auto_baud_calc.c
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
#include "timer1.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// void uart_configure_auto_baud_calc(uint8_t uart_config_options, uint32_t baud_rate)
//
// Description:
//  Configures the UART and calculates all values based on desired baud rate
//
// Parameters:
//  uint8_t uart_config_options - UART configuration options
//  uint32_t desired_baud_rate - desired baud rate
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void uart_configure_auto_baud_calc(uint8_t uart_config_options, uint32_t baud_rate)
{
	//We only need to configure the baud rate for modes 1 and 3
	if(((uart_config_options & UART_CONFIG_OPTION_MODE_MASK) == UART_CONFIG_OPTION_MODE_1_UART_8_BIT) ||
	   ((uart_config_options & UART_CONFIG_OPTION_MODE_MASK) == UART_CONFIG_OPTION_MODE_3_UART_9_BIT))
	{
		uint32_t calc_br_with_smod_cleared, calc_br_with_smod_set;
		uint32_t error_calc_br_with_smod_cleared, error_calc_br_with_smod_set;

		//Calculate values based on whether the request is for the BR generator or timer 1
		if((uart_config_options & UART_CONFIG_OPTION_CLOCK_MASK) == UART_CONFIG_OPTION_CLOCK_FOR_MODES_1_3_USE_BR_GEN)
		{
			uint16_t s0rel_with_smod_cleared, s0rel_with_smod_set;

			//Calculate the values of S0REL with SMOD cleared and set
			s0rel_with_smod_cleared = uart_calc_s0rel_value(baud_rate, 0);
			s0rel_with_smod_set = uart_calc_s0rel_value(baud_rate, 1);

			//Plug the above values back into the baud rate calculation to see what the actual BR is with each
			calc_br_with_smod_cleared = uart_calc_actual_baud_rate_from_s0rel(s0rel_with_smod_cleared, false);
			calc_br_with_smod_set = uart_calc_actual_baud_rate_from_s0rel(s0rel_with_smod_set, true);

			//Calculate the magnitude of the error of the baud rate with each of the calculated baud rates versus the requested one
			error_calc_br_with_smod_cleared = (calc_br_with_smod_cleared > baud_rate) ? (calc_br_with_smod_cleared - baud_rate) : (baud_rate - calc_br_with_smod_cleared);
			error_calc_br_with_smod_set = (calc_br_with_smod_set > baud_rate) ? (calc_br_with_smod_set - baud_rate) : (baud_rate - calc_br_with_smod_set);

			//Use the values that had the least error (tie goes to SMOD set)
			if(error_calc_br_with_smod_cleared < error_calc_br_with_smod_set)
			{
				uart_configure_manual_baud_calc(((uart_config_options & ~UART_CONFIG_OPTION_BIT_SMOD_MASK) | UART_CONFIG_OPTION_BIT_SMOD_CLEAR),
												s0rel_with_smod_cleared);
			}
			else
			{
				uart_configure_manual_baud_calc(((uart_config_options & ~UART_CONFIG_OPTION_BIT_SMOD_MASK) | UART_CONFIG_OPTION_BIT_SMOD_SET),
												s0rel_with_smod_set);
			}
		}
		else
		{
			uint8_t th1_with_smod_cleared, th1_with_smod_set;

			//Calculate the values of TH1 with SMOD cleared and set
			th1_with_smod_cleared = uart_calc_th1_value(baud_rate, 0);
			th1_with_smod_set = uart_calc_th1_value(baud_rate, 1);

			//Plug the above values back into the baud rate calculation to see what the actual BR is with each
			calc_br_with_smod_cleared = uart_calc_actual_baud_rate_from_th1(th1_with_smod_cleared, false);
			calc_br_with_smod_set = uart_calc_actual_baud_rate_from_th1(th1_with_smod_set, true);

			//Calculate the magnitude of the error of the baud rate with each of the calculated baud rates versus the requested one
			error_calc_br_with_smod_cleared = (calc_br_with_smod_cleared > baud_rate) ? (calc_br_with_smod_cleared - baud_rate) : (baud_rate - calc_br_with_smod_cleared);
			error_calc_br_with_smod_set = (calc_br_with_smod_set > baud_rate) ? (calc_br_with_smod_set - baud_rate) : (baud_rate - calc_br_with_smod_set);

			//Use the values that had the least error (tie goes to SMOD set)
			if(error_calc_br_with_smod_cleared < error_calc_br_with_smod_set)
			{
				uart_configure_manual_baud_calc(((uart_config_options & ~UART_CONFIG_OPTION_BIT_SMOD_MASK) | UART_CONFIG_OPTION_BIT_SMOD_CLEAR),
												(uint16_t)th1_with_smod_cleared);
			}
			else
			{
				uart_configure_manual_baud_calc(((uart_config_options & ~UART_CONFIG_OPTION_BIT_SMOD_MASK) | UART_CONFIG_OPTION_BIT_SMOD_SET),
												(uint16_t)th1_with_smod_set);
			}
		}
	}
}
