/////////////////////////////////////////////////////////////////////////////
//
// File: w2.h
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

#ifndef W2_H_
#define W2_H_

#include "reg24le1.h"
#include "interrupt.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Bit shifts used due to the fact that we're using one argument to hold values for 2 different hardware registers used
//  in w2_configure() function...DO NOT USE THESE DIRECTLY IN USER CODE!!!!
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define	W2_CONFIG_OPTION_W2CON0_OFFSET_SHIFT	(0)		//Shift for the options used for W2CON0...DO NOT USE IN CODE
#define	W2_CONFIG_OPTION_W2CON1_OFFSET_SHIFT	(8)		//Shift for the options used for W2CON1...DO NOT USE IN CODE


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Configuration defines for use in w2_configure() function...OR these together to form the w2_config_options argument
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define W2_CONFIG_OPTION_DISABLE							(0)																					//Disable W2
#define W2_CONFIG_OPTION_ENABLE								((W2CON0_ENABLE) << W2_CONFIG_OPTION_W2CON0_OFFSET_SHIFT)							//Enable W2

#define W2_CONFIG_OPTION_MODE_SLAVE							(0)																					//Run as a slave
#define W2_CONFIG_OPTION_MODE_MASTER						((W2CON0_MASTER_SELECT) << W2_CONFIG_OPTION_W2CON0_OFFSET_SHIFT)					//Run as a master

#define W2_CONFIG_OPTION_CLOCK_FREQ_IDLE					((0x00 << W2CON0_CLOCK_FREQUENCY_SHIFT) << W2_CONFIG_OPTION_W2CON0_OFFSET_SHIFT)	//Keep clock idle
#define W2_CONFIG_OPTION_CLOCK_FREQ_100_KHZ					((0x01 << W2CON0_CLOCK_FREQUENCY_SHIFT) << W2_CONFIG_OPTION_W2CON0_OFFSET_SHIFT)	//Run clock at 100 kHz (requires system clock of >= 4 MHz)
#define W2_CONFIG_OPTION_CLOCK_FREQ_400_KHZ					((0x02 << W2CON0_CLOCK_FREQUENCY_SHIFT) << W2_CONFIG_OPTION_W2CON0_OFFSET_SHIFT)	//Run clock at 400 kHz (requires system clock of >= 8 MHz)

#define W2_CONFIG_OPTION_SLAVE_IRQ_ON_ADDR_MATCH_ENABLE		(0)																					//For slaves, enable interrupt on address match
#define W2_CONFIG_OPTION_SLAVE_IRQ_ON_ADDR_MATCH_DISABLE	((W2CON0_SLAVE_DISABLE_IRQ_ON_ADDR_MATCH) << W2_CONFIG_OPTION_W2CON0_OFFSET_SHIFT)	//For slaves, disable interrupt on address match

#define W2_CONFIG_OPTION_SLAVE_IRQ_ON_STOP_ENABLE			(0)																					//For slaves, enable interrupt on reception of stop condition
#define W2_CONFIG_OPTION_SLAVE_IRQ_ON_STOP_DISABLE			((W2CON0_SLAVE_DISABLE_IRQ_ON_STOP) << W2_CONFIG_OPTION_W2CON0_OFFSET_SHIFT)		//For slaves, disable interrupt on reception of stop condition

#define W2_CONFIG_OPTION_SLAVE_CLOCK_ACTIVE_BETWEEN_XFERS	(0)																					//For slaves, keep clock low between transmitted bytes (clock stretching)
#define W2_CONFIG_OPTION_SLAVE_CLOCK_LOW_BETWEEN_XFERS		((W2CON0_SLAVE_CLOCK_STOP) << W2_CONFIG_OPTION_W2CON0_OFFSET_SHIFT)				//For slaves, keep clock running between transmitted bytes

#define W2_CONFIG_OPTION_SLAVE_BROADCAST_DISABLE			(0)																					//For slaves, do not respond to broadcast address (0x00)
#define W2_CONFIG_OPTION_SLAVE_BROADCAST_ENABLE				((W2CON0_SLAVE_BROADCAST_ENABLE) << W2_CONFIG_OPTION_W2CON0_OFFSET_SHIFT)			//For slaves, respond to broadcast address (0x00)

#define W2_CONFIG_OPTION_SLAVE_BROADCAST_DISABLE			(0)																					//For slaves, do not respond to broadcast address (0x00)
#define W2_CONFIG_OPTION_SLAVE_BROADCAST_ENABLE				((W2CON0_SLAVE_BROADCAST_ENABLE) << W2_CONFIG_OPTION_W2CON0_OFFSET_SHIFT)			//For slaves, respond to broadcast address (0x00)

#define	W2_CONFIG_OPTION_ALL_INTERRUPTS_ENABLE				(0)																					//Allow interrupts that are enabled in W2CON0
#define	W2_CONFIG_OPTION_ALL_INTERRUPTS_DISABLE				((W2CON1_DISABLE_INTERRUPTS) << W2_CONFIG_OPTION_W2CON1_OFFSET_SHIFT)				//Disable all interrupts, whether they are enabled in W2CON0 or not


////////////////////////////////////////////////////////////////////////////
// Enumeration to hold the values for ACK and NACK
////////////////////////////////////////////////////////////////////////////
typedef enum
{
	W2_ACK_VAL   = 0,
	W2_NACK_VAL  = 1
} w2_ack_nack_val_t;


////////////////////////////
// Function macros
////////////////////////////
#define w2_enable()						W2CON0 |= W2CON0_ENABLE																			//Enable W2
#define w2_disable()					W2CON0 &= (~W2CON0_ENABLE)																		//Disable W2
#define w2_is_in_master_mode()			((W2CON0 & W2CON0_MASTER_SELECT) != 0 ? true : false)											//Returns true if running in master mode, false if running in slave mode
#define w2_send_start_condition()		W2CON0 |= W2CON0_MASTER_TX_START																//Transmit a start condition after any pending TX data or stop condition
#define w2_send_stop_condition()		W2CON0 |= W2CON0_MASTER_TX_STOP																	//Transmit a stop condition in RX after current byte is received, or in TX after any pending TX data is transmitted
#define w2_send_byte(tx_byte)			W2DAT = (tx_byte)																				//Send a byte over the bus
#define w2_get_rxed_byte()				(W2DAT)																							//Read the last byte received over the bus
#define w2_wait_for_irq()				interrupt_wait_for_spi_2wire();\
										interrupt_clear_spi_2wire()																		//Wait for and clear the W2 interrupt
#define w2_master_set_clock_idle()		W2CON0 = ((W2CON0 & (~W2CON0_CLOCK_FREQUENCY_MASK)) | (0x00 << W2CON0_CLOCK_FREQUENCY_SHIFT))	//Set W2 clock to idle
#define w2_master_set_clock_100_khz()	W2CON0 = ((W2CON0 & (~W2CON0_CLOCK_FREQUENCY_MASK)) | (0x01 << W2CON0_CLOCK_FREQUENCY_SHIFT))	//Set W2 clock to 100 kHz
#define w2_master_set_clock_400_khz()	W2CON0 = ((W2CON0 & (~W2CON0_CLOCK_FREQUENCY_MASK)) | (0x02 << W2CON0_CLOCK_FREQUENCY_SHIFT))	//Set W2 clock to 400 kHz

//Since W2CON1[4:0] all get cleared on a read of W2CON1, it is important to read the value of W2CON1 into a variable and use this variable in these macros when looking
// at more than one bit flag.  Alternately, if only one bit flag is ever being polled, W2CON1 can be inserted as the argument of the macro and no buffer is needed.
#define w2_data_txed_or_rxed(w2con1_value)				((w2con1_value & W2CON1_DATA_READY) != 0 ? true : false)						//Returns true if byte has finished transmitting/has been received, false otherwise
#define w2_get_last_rxed_ack(w2con1_value)				((w2con1_value & W2CON1_LAST_ACK) != 0 ? W2_NACK_VAL : W2_ACK_VAL)				//Returns the value of the last received acknowledgement (1 for NACK and 0 for ACK)
#define w2_irq_caused_by_addr_match(w2con1_value)		((w2con1_value & W2CON1_SLAVE_IRQ_DUE_TO_ADDR_MATCH) != true ? 1 : false)		//Returns true if IRQ was caused by an address match, false otherwise
#define w2_irq_caused_by_stop_cond(w2con1_value)		((w2con1_value & W2CON1_SLAVE_IRQ_DUE_TO_STOP) != true ? 1 : false)				//Returns true if IRQ was caused by a stop condition, false otherwise
#define w2_last_rxed_addr_was_broadcast(w2con1_value)	((w2con1_value & W2CON1_SLAVE_LAST_ADDR_WAS_BROADCAST) != true ? 1 : false)		//Returns true if last received address was the broadcast address (0x00), false otherwise


////////////////////////////
// Function prototypes
////////////////////////////
void w2_configure(uint16_t w2_config_options, uint8_t address_in_slave_mode);
w2_ack_nack_val_t w2_master_write_to(uint8_t slave_address, uint8_t * data_address, uint8_t data_address_len, uint8_t * data_buf, uint32_t data_len);
w2_ack_nack_val_t w2_master_cur_address_read(uint8_t slave_address, uint8_t * data_buf, uint32_t data_len);
w2_ack_nack_val_t w2_master_random_address_read(uint8_t slave_address, uint8_t * data_address, uint8_t data_address_len, uint8_t * data_buf, uint32_t data_len);


#endif /* W2_H_ */
