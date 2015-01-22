/////////////////////////////////////////////////////////////////////////////
//
// File: uart_send_wait_for_complete.c
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

#include "uart.h"
#include "interrupt.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// void uart_send_wait_for_complete(uint8_t tx_data)
//
// Description:
//  Sends a byte over the UART and waits for it to complete
//
// Parameters:
//  uint8_t tx_data - byte to send over the UART
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void uart_send_wait_for_complete(uint8_t tx_data)
{
	interrupt_clear_uart_tx();

        uart_send(tx_data);

	interrupt_wait_for_uart_tx();

}
