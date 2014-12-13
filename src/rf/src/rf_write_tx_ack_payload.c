/////////////////////////////////////////////////////////////////////////////
//
// File: rf_write_tx_ack_payload.c
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

#include "rf.h"
#include "rf_src.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// uint8_t rf_write_tx_ack_payload(uint8_t * dataptr, uint16_t len,)
//
// Description:
//  Writes the acknowledge payload for the TX FIFO
//
// Parameters:
//  uint8_t * dataptr - pointer from which the acknowledge payload data is read
//  uint16_t len - number of bytes to write to the acknowledge payload
//
// Return value:
//  Read value of the STATUS register
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
uint8_t rf_write_tx_ack_payload(uint8_t * dataptr, uint16_t len)
{
	uint8_t status;

	status = rf_spi_execute_command(RF_W_ACK_PAYLOAD, dataptr, len, false); //Write the ack payload

	return status; //Return the value of STATUS
}
