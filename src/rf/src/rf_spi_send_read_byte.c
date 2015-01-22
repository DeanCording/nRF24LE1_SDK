/////////////////////////////////////////////////////////////////////////////
//
// File: rf_read_register.c
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
// uint8_t rf_spi_send_read_byte(uint8_t byte)
//
// Description:
//  Sends a byte over SPI, waits for the transaction to complete, then returns the byte read over SPI
//
// Parameters:
//  uint8_t byte - data byte to be sent over SPI
//
// Return value:
//  Value read from SPI
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
uint8_t rf_spi_send_read_byte(uint8_t byte)
{
	SPIRDAT = byte; //Send byte over SPI

	while(!(SPIRSTAT & SPIRSTAT_IRQ_RX_FIFO_READY)); //Wait for the transaction to finish

	IRCON_SB_RFRDY = BIT_FALSE; //Clear the IRQ bit

	return SPIRDAT; //Return the received value
}
