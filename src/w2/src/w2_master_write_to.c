/////////////////////////////////////////////////////////////////////////////
//
// File: w2_master_write_to.c
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

#include "w2_src.h"
#include "delay.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// w2_ack_nack_val_t w2_master_write_to(uint8_t slave_address, uint8_t * data_address, uint8_t data_address_len, uint8_t * data_buf, uint32_t data_len)
//
// Description:
//  Writes the desired number of bytes to a slave device, and sends a stop condition afterward if desired.
//
// Parameters:
//  uint8_t slave_address - address of the slave to send data (DO NOT SHIFT THIS VALUE BY ONE BIT!!!!)
//  uint8_t * data_address - buffer holding address data to send to the slave
//  uint8_t data_address_len - number of bytes of address data to send to the slave
//  uint8_t * data_buf - buffer holding data to send to the slave
//  uint32_t data_len - number of bytes to send to the slave
//  w2_start_stop_condition_t send_stop_after_last_tx_byte - if set to W2_STOP_CONDITION_SEND, the function will
//   send a stop condition after the last byte to be transmitted
//
// Return value:
//  ACK/NACK value of the last byte written
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
w2_ack_nack_val_t w2_master_write_to(uint8_t slave_address, uint8_t * data_address, uint8_t data_address_len, uint8_t * data_buf, uint32_t data_len)
{
	uint32_t x;
	w2_ack_nack_val_t ack_nack_val;
	w2_start_stop_condition_t send_start_stop_conditions;

	//Send the start condition, control byte, and address byte(s) in a write operation
	ack_nack_val = w2_master_write_control_bytes(slave_address, data_address, data_address_len);

	if(ack_nack_val == W2_NACK_VAL)
	{
		w2_send_stop_condition();
		return W2_NACK_VAL;
	}

	//Write as many data bytes over the bus as are requested
	for(x = 0; x < data_len; x++)
	{
		//Send a stop condition before writing the last byte
		if(x == (data_len - 1))
		{
			send_start_stop_conditions = W2_SEND_ONLY_STOP_CONDITION;
		}
		else
		{
			send_start_stop_conditions = W2_DONT_SEND_START_OR_STOP_CONDITIONS;
		}

		ack_nack_val = w2_master_tx_byte(data_buf[x], send_start_stop_conditions);

		if(ack_nack_val == W2_NACK_VAL)
		{
			w2_send_stop_condition();
			return W2_NACK_VAL;
		}
	}

	//Wait for the write operation to finish
	do
	{
		ack_nack_val = w2_master_tx_byte(((uint8_t)(slave_address << W2DAT_ADDRESS_SHIFT) & W2DAT_ADDRESS_MASK) | W2_MASTER_WRITE, W2_SEND_BOTH_START_AND_STOP_CONDITIONS);
	} while(ack_nack_val == W2_NACK_VAL);

	return W2_ACK_VAL;
}
