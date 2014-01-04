/////////////////////////////////////////////////////////////////////////////
//
// File: uart_configure_manual_baud_calc.c
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


///////////////////////////////////////////
// Internal defines
///////////////////////////////////////////
#define UART_CONFIG_OPTION_S0CON_MASK	0xF0	//Mask for the options used for S0CON


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// void uart_configure_manual_baud_calc(uint8_t uart_config_options, uint16_t s0rel_val_if_br_gen_or_th1_val_if_tmr1)
//
// Description:
//  Configures the UART
//
// Parameters:
//  uint8_t uart_config_options - UART configuration options
//  uint16_t s0rel_val_if_br_gen_or_th1_val_if_tmr1 - value of S0REL if using the hardware baud rate generator or the value of
//   TH1 if using timer 1
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void uart_configure_manual_baud_calc(uint8_t uart_config_options, uint16_t s0rel_val_if_br_gen_or_th1_val_if_tmr1)
{
	//Set up SMOD as requested
	if(uart_config_options & UART_CONFIG_OPTION_BIT_SMOD_SET)
	{
		reg_bits_set(PCON, PCON_SMOD);
	}
	else
	{
		reg_bits_clear(PCON, PCON_SMOD);
	}

	//Set up the UART if one of the two modes that use baud rate generation is requested
	if(((uart_config_options & UART_CONFIG_OPTION_MODE_MASK) == UART_CONFIG_OPTION_MODE_1_UART_8_BIT) ||
	   ((uart_config_options & UART_CONFIG_OPTION_MODE_MASK) == UART_CONFIG_OPTION_MODE_3_UART_9_BIT))
	{
		//Set up based on whether the baud rate generator or timer 1 is being used to control timing
		if((uart_config_options & UART_CONFIG_OPTION_CLOCK_MASK) == UART_CONFIG_OPTION_CLOCK_FOR_MODES_1_3_USE_BR_GEN)
		{
			S0REL = s0rel_val_if_br_gen_or_th1_val_if_tmr1; //set S0REL to the value requested
			sbit_set(ADCON_SB_BD); //enable BR generator
		}
		else
		{
			sbit_clear(ADCON_SB_BD); //disable BR generator and use TMR1 overflow

			//Configure timer 1 for use as the baud rate generator
			timer1_configure(TIMER1_CONFIG_OPTION_MODE_2_8_BIT_AUTO_RLD_TMR |
							 TIMER1_CONFIG_OPTION_FUNCTION_TIMER |
							 TIMER1_CONFIG_OPTION_GATE_ALWAYS_RUN_TIMER,
							 (uint8_t)s0rel_val_if_br_gen_or_th1_val_if_tmr1);

			timer1_run(); //enable the timer
		}
	}

	//Set up SPIMCON0 register from mspi_config_options
	S0CON = uart_config_options & UART_CONFIG_OPTION_S0CON_MASK;
}
