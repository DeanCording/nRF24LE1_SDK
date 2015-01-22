/////////////////////////////////////////////////////////////////////////////
//
// File: rf_write_tx_payload_noack.c
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
// uint8_t rf_write_tx_payload_noack(uint8_t * dataptr, uint16_t len, bool transmit)
//
// Description:
//  Writes the payload to the TX FIFO and forces it to be sent as a no-ack payload
//
// Parameters:
//  uint8_t * dataptr - pointer from which the payload data is read
//  uint16_t len - number of bytes to write to the payload
//  bool transmit - true to transmit the payload immediately, false otherwise
//
// Return value:
//  Read value of the STATUS register
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
uint8_t rf_write_tx_payload_noack(uint8_t * dataptr, uint16_t len, bool transmit)
{
	uint8_t status;

	status = rf_spi_execute_command(RF_W_TX_PAYLOAD, dataptr, len, false); //Write the payload

	//Transmit the payload immediately if requested
	if(transmit == true)
	{
		rf_transmit();
	}

	return status; //Return the value of STATUS
}
