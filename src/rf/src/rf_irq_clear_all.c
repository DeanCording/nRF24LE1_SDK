/////////////////////////////////////////////////////////////////////////////
//
// File: rf_irq_clear_all.c
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
// void rf_irq_clear_all()
//
// Description:
//  Clears all interrupts
//
// Parameters:
//  None
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void rf_irq_clear_all()
{
	//Clear all three possible interrupt sources by writing a '1' to their location in STATUS
	uint8_t dataptr = RF_STATUS_RX_DR | RF_STATUS_TX_DS | RF_STATUS_MAX_RT;

	rf_write_register(RF_STATUS, &dataptr, 1);

	sbit_clear(IRCON_SB_RFIRQ); //Clear the master interrupt
}
