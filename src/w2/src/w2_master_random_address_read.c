/////////////////////////////////////////////////////////////////////////////
//
// File: w2_master_random_address_read.c
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


/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// w2_ack_nack_val_t w2_master_random_address_read(uint8_t slave_address, uint8_t * data_address, uint8_t data_address_len, uint8_t * data_buf, uint32_t data_len);
//
// Description:
//  Reads the desired number of bytes from a slave device, starting from the specified address
//
// Parameters:
//  uint8_t slave_address - address of the slave to send data (DO NOT SHIFT THIS VALUE BY ONE BIT!!!!)
//  uint8_t * data_address - buffer holding address data to send to the slave
//  uint8_t data_address_len - number of bytes of address data to send to the slave
//  uint8_t * data_buf - buffer that gets filled with data received from the slave
//  uint32_t data_len - number of bytes to receive from the slave
//
// Return value:
//  ACK/NACK value of the last byte received
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
w2_ack_nack_val_t w2_master_random_address_read(uint8_t slave_address, uint8_t * data_address, uint8_t data_address_len, uint8_t * data_buf, uint32_t data_len)
{
	w2_ack_nack_val_t ack_nack_val;

	//Send the start condition, control byte, and address byte(s) in a write operation
	ack_nack_val = w2_master_write_control_bytes(slave_address, data_address, data_address_len);

	if(ack_nack_val == W2_NACK_VAL)
	{
		return W2_NACK_VAL;
	}

	//Send the start condition and the control byte
	ack_nack_val = w2_master_cur_address_read(slave_address, data_buf, data_len);

	return ack_nack_val;
}
