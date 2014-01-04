/////////////////////////////////////////////////////////////////////////////
//
// File: watchdog.h
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

#ifndef WATCHDOG_H_
#define WATCHDOG_H_

#include "reg24le1.h"


///////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////
uint16_t watchdog_start_and_set_timeout_in_ms(uint32_t timeout);
void watchdog_set_wdsv_count(uint16_t wdsv_value);
uint16_t watchdog_get_wdsv_count();
void watchdog_cause_software_reset();


#endif /* WATCHDOG_H_ */
