/////////////////////////////////////////////////////////////////////////////
//
// File: uart.h
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

#ifndef UART_H_
#define UART_H_

#include "reg24le1.h"


///////////////////////////////////////////
// Configuration defines
///////////////////////////////////////////
#define UART_CONFIG_OPTION_CLOCK_SHIFT						(1)											//Shift for clock option below (do not use this option)
#define UART_CONFIG_OPTION_CLOCK_MASK						(1 << UART_CONFIG_OPTION_CLOCK_SHIFT)		//Mask for clock option below (do not use this option)
#define UART_CONFIG_OPTION_CLOCK_FOR_MODES_1_3_USE_TMR1		(0 << UART_CONFIG_OPTION_CLOCK_SHIFT)		//Configure UART to use timer 1 for baud-rate generation in modes 1 and 3
#define UART_CONFIG_OPTION_CLOCK_FOR_MODES_1_3_USE_BR_GEN	(1 << UART_CONFIG_OPTION_CLOCK_SHIFT)		//Configure UART to use the built-in baud-rate generator in modes 1 and 3

#define UART_CONFIG_OPTION_BIT_SMOD_SHIFT					(2)											//Shift for SMOD option below (do not use this option)
#define UART_CONFIG_OPTION_BIT_SMOD_MASK					(1 << UART_CONFIG_OPTION_BIT_SMOD_SHIFT)	//Mask for SMOD option below (do not use this option)
#define UART_CONFIG_OPTION_BIT_SMOD_CLEAR					(0 << UART_CONFIG_OPTION_BIT_SMOD_SHIFT)	//Configure UART with SMOD cleared (not necessary if using uart_configure_auto_baud_calc())
#define UART_CONFIG_OPTION_BIT_SMOD_SET						(1 << UART_CONFIG_OPTION_BIT_SMOD_SHIFT)	//Configure UART with SMOD set (not necessary if using uart_configure_auto_baud_calc())

#define UART_CONFIG_OPTION_DISABLE_RX						(0)											//Configure UART with receiver disabled
#define UART_CONFIG_OPTION_ENABLE_RX						(S0CON_REN0)								//Configure UART with receiver enabled

#define UART_CONFIG_OPTION_MULTI_PROC_DISABLE				(0)											//Configure UART with multi-processor communications disabled
#define UART_CONFIG_OPTION_MULTI_PROC_ENABLE				(S0CON_SM20)								//Configure UART with multi-processor communications enabled

#define UART_CONFIG_OPTION_MODE_MASK						S0CON_MODE_FIELD							//Mask for Mode option below (do not use this option)
#define UART_CONFIG_OPTION_MODE_0_SHIFT_REG					(0x00 << S0CON_MODE_SHIFT)					//Configure UART in mode 0 (shift register)
#define UART_CONFIG_OPTION_MODE_1_UART_8_BIT				(0x01 << S0CON_MODE_SHIFT)					//Configure UART in mode 1 (8-bit UART)
#define UART_CONFIG_OPTION_MODE_2_UART_9_BIT_CCLK_DIV		(0x02 << S0CON_MODE_SHIFT)					//Configure UART in mode 2 (9-bit UART using CCLK_DIV as baud generation)
#define UART_CONFIG_OPTION_MODE_3_UART_9_BIT				(0x03 << S0CON_MODE_SHIFT)					//Configure UART in mode 3 (9-bit UART)


//////////////////////////////////////////////////
// Function macros for easily setting up the UART
//////////////////////////////////////////////////
#define uart_configure_8_n_1_57600()			uart_configure_manual_baud_calc(UART_CONFIG_OPTION_ENABLE_RX | \
																				UART_CONFIG_OPTION_MODE_1_UART_8_BIT | \
																				UART_CONFIG_OPTION_CLOCK_FOR_MODES_1_3_USE_BR_GEN | \
																				UART_CONFIG_OPTION_BIT_SMOD_SET, \
																				1015)	//Configures the UART for 8-n-1, 57600 baud (assumes a 16 MHz clock)
#define uart_configure_8_n_1_38400()			uart_configure_manual_baud_calc(UART_CONFIG_OPTION_ENABLE_RX | \
																				UART_CONFIG_OPTION_MODE_1_UART_8_BIT | \
																				UART_CONFIG_OPTION_CLOCK_FOR_MODES_1_3_USE_BR_GEN | \
																				UART_CONFIG_OPTION_BIT_SMOD_SET, \
																				1011)	//Configures the UART for 8-n-1, 38400 baud (assumes a 16 MHz clock)
#define uart_configure_8_n_1_31250()			uart_configure_manual_baud_calc(UART_CONFIG_OPTION_ENABLE_RX | \
																				UART_CONFIG_OPTION_MODE_1_UART_8_BIT | \
																				UART_CONFIG_OPTION_CLOCK_FOR_MODES_1_3_USE_BR_GEN | \
																				UART_CONFIG_OPTION_BIT_SMOD_SET, \
																				1008)	//Configures the UART for 8-n-1, 31250 baud (assumes a 16 MHz clock)
#define uart_configure_8_n_1_19200()			uart_configure_manual_baud_calc(UART_CONFIG_OPTION_ENABLE_RX | \
																				UART_CONFIG_OPTION_MODE_1_UART_8_BIT | \
																				UART_CONFIG_OPTION_CLOCK_FOR_MODES_1_3_USE_BR_GEN | \
																				UART_CONFIG_OPTION_BIT_SMOD_SET, \
																				998)	//Configures the UART for 8-n-1, 19200 baud (assumes a 16 MHz clock)
#define uart_configure_8_n_1_14400()			uart_configure_manual_baud_calc(UART_CONFIG_OPTION_ENABLE_RX | \
																				UART_CONFIG_OPTION_MODE_1_UART_8_BIT | \
																				UART_CONFIG_OPTION_CLOCK_FOR_MODES_1_3_USE_BR_GEN | \
																				UART_CONFIG_OPTION_BIT_SMOD_SET, \
																				989)	//Configures the UART for 8-n-1, 14400 baud (assumes a 16 MHz clock)
#define uart_configure_8_n_1_9600()				uart_configure_manual_baud_calc(UART_CONFIG_OPTION_ENABLE_RX | \
																				UART_CONFIG_OPTION_MODE_1_UART_8_BIT | \
																				UART_CONFIG_OPTION_CLOCK_FOR_MODES_1_3_USE_BR_GEN | \
																				UART_CONFIG_OPTION_BIT_SMOD_SET, \
																				972)	//Configures the UART for 8-n-1, 9600 baud (assumes a 16 MHz clock)
#define uart_configure_8_n_1_4800()				uart_configure_manual_baud_calc(UART_CONFIG_OPTION_ENABLE_RX | \
																				UART_CONFIG_OPTION_MODE_1_UART_8_BIT | \
																				UART_CONFIG_OPTION_CLOCK_FOR_MODES_1_3_USE_BR_GEN | \
																				UART_CONFIG_OPTION_BIT_SMOD_SET, \
																				920)	//Configures the UART for 8-n-1, 4800 baud (assumes a 16 MHz clock)
#define uart_configure_8_n_1_2400()				uart_configure_manual_baud_calc(UART_CONFIG_OPTION_ENABLE_RX | \
																				UART_CONFIG_OPTION_MODE_1_UART_8_BIT | \
																				UART_CONFIG_OPTION_CLOCK_FOR_MODES_1_3_USE_BR_GEN | \
																				UART_CONFIG_OPTION_BIT_SMOD_SET, \
																				816)	//Configures the UART for 8-n-1, 2400 baud (assumes a 16 MHz clock)
#define uart_configure_8_n_1_1200()				uart_configure_manual_baud_calc(UART_CONFIG_OPTION_ENABLE_RX | \
																				UART_CONFIG_OPTION_MODE_1_UART_8_BIT | \
																				UART_CONFIG_OPTION_CLOCK_FOR_MODES_1_3_USE_BR_GEN | \
																				UART_CONFIG_OPTION_BIT_SMOD_SET, \
																				607)	//Configures the UART for 8-n-1, 1200 baud (assumes a 16 MHz clock)
#define uart_configure_8_n_1_600()				uart_configure_manual_baud_calc(UART_CONFIG_OPTION_ENABLE_RX | \
																				UART_CONFIG_OPTION_MODE_1_UART_8_BIT | \
																				UART_CONFIG_OPTION_CLOCK_FOR_MODES_1_3_USE_BR_GEN | \
																				UART_CONFIG_OPTION_BIT_SMOD_SET, \
																				191)	//Configures the UART for 8-n-1, 600 baud (assumes a 16 MHz clock)
#define uart_configure_8_n_1_300()				uart_configure_manual_baud_calc(UART_CONFIG_OPTION_ENABLE_RX | \
																				UART_CONFIG_OPTION_MODE_1_UART_8_BIT | \
																				UART_CONFIG_OPTION_CLOCK_FOR_MODES_1_3_USE_BR_GEN | \
																				UART_CONFIG_OPTION_BIT_SMOD_CLEAR, \
																				191)	//Configures the UART for 8-n-1, 300 baud (assumes a 16 MHz clock)

//////////////////////////////////////////////
// Function macros for various hardware tasks
//////////////////////////////////////////////
#define uart_send(tx_data)						(S0BUF = tx_data)			//Send tx_data over the UART
#define uart_tx_data_sent()						(S0CON_SB_TI0)				//Returns true if the UART has transmitted data, false otherwise
#define uart_get()								(S0BUF)						//Get the last character recieved over the UART
#define uart_rx_data_ready()					(S0CON_SB_RI0)				//Returns true if the UART has received data, false otherwise
#define uart_rx_enable()						sbit_set(S0CON_SB_REN0)		//Enable the UART receiver
#define uart_rx_disable()						sbit_clear(S0CON_SB_REN0)	//Disable the UART receiver
#define uart_set_tx_bit_8()						sbit_set(S0CON_SB_TB80)		//Sets the ninth bit when using 9-bit communication
#define uart_clear_tx_bit_8()					sbit_clear(S0CON_SB_TB80)	//Clears the ninth bit when using 9-bit communication
#define uart_get_rx_bit_8()						(S0CON_SB_RB80)				//Gets the ninth bit of the last word recieved over the UART


///////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////
void uart_configure_auto_baud_calc(uint8_t uart_config_options, uint32_t baud_rate);
void uart_configure_manual_baud_calc(uint8_t uart_config_options, uint16_t s0rel_val_if_br_gen_or_th1_val_if_tmr1);
uint16_t  uart_calc_s0rel_value(uint32_t desired_baud_rate, bool smod_bit_value);
uint32_t uart_calc_actual_baud_rate_from_s0rel(uint16_t s0rel_reg_value, bool smod_bit_value);
uint8_t uart_calc_th1_value(uint32_t desired_baud_rate, bool smod_bit_value);
uint32_t uart_calc_actual_baud_rate_from_th1(uint8_t th1_reg_value, bool smod_bit_value);
void uart_send_wait_for_complete(uint8_t tx_data);
uint8_t uart_wait_for_rx_and_get();

// Allow stdio printf to output to uart
void putchar(char c);

#endif /*UART_H_*/
