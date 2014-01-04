/////////////////////////////////////////////////////////////////////////////
//
// File: w2_src.h
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

#ifndef W2_SRC_H_
#define W2_SRC_H_

#include "w2.h"
#include "gpio.h"


////////////////////////////////////////////////////////////////////////////
// Enumeration to hold the values for read and write for masters
////////////////////////////////////////////////////////////////////////////
typedef enum
{
	W2_MASTER_WRITE = 0x00,
	W2_MASTER_READ  = 0x01
} w2_master_direction_t;

////////////////////////////////////////////////////////////////////////////
// Enumeration to hold the values for read and write for masters
////////////////////////////////////////////////////////////////////////////
typedef enum
{
	W2_SEND_ONLY_START_CONDITION,
	W2_SEND_ONLY_STOP_CONDITION,
	W2_SEND_BOTH_START_AND_STOP_CONDITIONS,
	W2_DONT_SEND_START_OR_STOP_CONDITIONS,
} w2_start_stop_condition_t;


////////////////////////////
// Function macros
////////////////////////////
#define w2_prepare_scl_sda()	gpio_pin_val_sbit_clear(GPIO_PIN_SBIT_FUNC_W2SCL);\
								gpio_pin_val_sbit_clear(GPIO_PIN_SBIT_FUNC_W2SDA)						//Clear the GPIO values of the pins
#define w2_clear_sda()			gpio_pins_dir_output(GPIO_PIN_REG_FUNC_W2SDA, GPIO_PIN_MASK_FUNC_W2SDA)	//This causes the bus to see a value of 0 (call w2_prepare_scl_sda() first)
#define w2_set_sda()			gpio_pins_dir_input(GPIO_PIN_REG_FUNC_W2SDA, GPIO_PIN_MASK_FUNC_W2SDA)	//This causes the bus to see a value of 1
#define w2_read_sda()			(GPIO_PIN_SBIT_FUNC_W2SDA)												//Returns the current value of W2SDA
#define w2_clear_scl()			gpio_pins_dir_output(GPIO_PIN_REG_FUNC_W2SCL, GPIO_PIN_MASK_FUNC_W2SCL)	//This causes the bus to see a value of 0 (call w2_prepare_scl_sda() first)
#define w2_set_scl()			gpio_pins_dir_input(GPIO_PIN_REG_FUNC_W2SCL, GPIO_PIN_MASK_FUNC_W2SCL)	//This causes the bus to see a value of 1
#define w2_read_scl()			(GPIO_PIN_SBIT_FUNC_W2SCL)												//Returns the current value of W2SCL


////////////////////////////
// Function prototypes
////////////////////////////
w2_ack_nack_val_t w2_master_tx_byte(uint8_t tx_data, w2_start_stop_condition_t send_start_stop_conditions);
w2_ack_nack_val_t w2_master_rx_byte(uint8_t * rx_byte, w2_start_stop_condition_t send_start_stop_conditions);
void w2_master_process_start_request(w2_start_stop_condition_t send_start_stop_conditions);
void w2_master_process_stop_request(w2_start_stop_condition_t send_start_stop_conditions);
uint8_t w2_wait_for_byte_tx_or_rx();
w2_ack_nack_val_t w2_master_write_control_bytes(uint8_t slave_address, uint8_t * data_address, uint8_t data_address_len);
void w2_master_software_reset();


#endif /* W2_SRC_H_ */
