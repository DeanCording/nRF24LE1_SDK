/////////////////////////////////////////////////////////////////////////////
//
// File: mspi_configure.c
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

#include "mspi.h"


////////////////////////////////////////////////////////////////////////////////
//
// uint8_t mspi_read_write(uint8_t mspi_data) __reentrant
//
// Description:
//  Sends a byte of data over MSPI, waits until the transaction is finished, and
//   then returns the value received over MSPI.
//
// Parameters:
//  uint8_t mspi_data - data to write to the MSPI bus
//
// Return value:
//  Data read from the MSPI bus after the transaction has completed
//
////////////////////////////////////////////////////////////////////////////////
uint8_t mspi_read_write(uint8_t mspi_data) __reentrant
{
	//make sure the RX FIFO is clear before sending the byte
	while(mspi_is_rx_data_ready())
	{
		mspi_get();
	}

	//send the byte
	mspi_send(mspi_data);

	//wait until the transaction is complete
	while(!mspi_is_rx_data_ready());

	//return the received byte
	return mspi_get();
}
