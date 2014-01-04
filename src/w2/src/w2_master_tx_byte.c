/////////////////////////////////////////////////////////////////////////////
//
// File: w2_master_tx_byte.c
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
// w2_ack_nack_val_t w2_master_tx_byte(uint8_t tx_data, w2_start_stop_condition_t send_start_stop_conditions)
//
// Description:
//  Sends a byte over W2, waits for it to complete, and returns the value of the ACK/NACK received.
//  Also sends a stop condition after this byte if requested by the user.
//
// Parameters:
//  uint8_t tx_data - value to be sent over 2 wire
//  w2_start_stop_condition_t send_start_stop_conditions - send a start condition before this byte, and/or
//   send a stop condition after this byte
//
// Return value:
//  Value of the ACK/NACK received
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
w2_ack_nack_val_t w2_master_tx_byte(uint8_t tx_data, w2_start_stop_condition_t send_start_stop_conditions)
{
	uint8_t temp_w2con1;

	//Process start request
	w2_master_process_start_request(send_start_stop_conditions);

	//Send the current byte over the bus
	w2_send_byte(tx_data);

	//Process stop request
	w2_master_process_stop_request(send_start_stop_conditions);

	//Wait until we get the TX/RX interrupt
	temp_w2con1 = w2_wait_for_byte_tx_or_rx();

	//Return the last ACK/NACK value
	return w2_get_last_rxed_ack(temp_w2con1);
}
