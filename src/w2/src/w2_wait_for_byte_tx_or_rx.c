/////////////////////////////////////////////////////////////////////////////
//
// File: w2_wait_for_byte_tx_or_rx.c
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
// uint8_t w2_wait_for_byte_tx_or_rx()
//
// Description:
//  Waits for the TX/RX interrupt to occur and returns the last read value of W2CON1
//
// Parameters:
//  None
//
// Return value:
//  The last read value of W2CON1
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
uint8_t w2_wait_for_byte_tx_or_rx()
{
	uint8_t local_w2con1;

	//Wait until we get an interrupt and make sure it's TX/RX
	do
	{
		w2_wait_for_irq();
		local_w2con1 = W2CON1;
	} while(!w2_data_txed_or_rxed(local_w2con1));

	return local_w2con1;
}
