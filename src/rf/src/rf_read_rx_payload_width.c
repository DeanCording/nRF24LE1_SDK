/////////////////////////////////////////////////////////////////////////////
//
// File: rf_read_rx_payload_width.c
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
// uint8_t rf_read_rx_payload_width(uint8_t * dataptr)
//
// Description:
//  Reads the width of the current RX payload
//
// Parameters:
//  uint8_t * dataptr - pointer to which the read payload width is stored (one byte)
//
// Return value:
//  Read value of the STATUS register
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
uint8_t rf_read_rx_payload_width(uint8_t * dataptr)
{
	uint8_t status;

	status = rf_spi_execute_command(RF_R_RX_PL_WID, dataptr, 1, true);

	return status; //Return the STATUS register value
}
