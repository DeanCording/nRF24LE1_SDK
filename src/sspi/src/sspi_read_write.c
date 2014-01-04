/////////////////////////////////////////////////////////////////////////////
//
// File: sspi_configure.c
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

#include "sspi.h"


////////////////////////////////////////////////////////////////////////////////
//
// uint8_t sspi_read_write(uint8_t sspi_data) __reentrant
//
// Description:
//  Sends a byte of data over SSPI, waits until the transaction is finished, and
//   then returns the value received over SSPI.
//
// Parameters:
//  uint8_t sspi_data - data to write to the SSPI bus
//
// Return value:
//  Data read from the SSPI bus after the transaction has completed
//
////////////////////////////////////////////////////////////////////////////////
uint8_t sspi_read_write(uint8_t sspi_data) __reentrant
{
	//make sure the RX FIFO is clear before sending the byte
	while(sspi_is_spi_slave_done(sspi_get_status()))
	{
		sspi_get_data();
	}

	//load the byte
	sspi_send_data(sspi_data);

	//wait until the transaction is complete
	while(!sspi_is_spi_slave_done(sspi_get_status()));

	//return the received byte
	return sspi_get_data();
}
