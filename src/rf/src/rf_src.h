/////////////////////////////////////////////////////////////////////////////
//
// File: rf_src.h
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

#ifndef RF_SRC_H_
#define RF_SRC_H_

#include "rf.h"


///////////////////////////////////////////
// Function macros
///////////////////////////////////////////
#define rf_clear_csn()	sbit_clear(RFCON_SB_RFCSN)	//Clears the CSN pin
#define rf_set_csn()	sbit_set(RFCON_SB_RFCSN)	//Sets the CSN pin
#define rf_get_csn()	RFCON_SB_RFCSN				//Gets the value of the CE pin


///////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////
void rf_spi_send_read(uint8_t * dataptr, uint16_t len, bool copydata);
uint8_t rf_spi_send_read_byte(uint8_t byte);


#endif /* RF_SRC_H_ */
