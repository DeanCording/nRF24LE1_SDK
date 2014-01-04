/////////////////////////////////////////////////////////////////////////////
//
// File: delay_us.c
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

#include "delay.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// void delay_us(uint16_t microseconds)
//
// Description:
//  Waits the specified number of milliseconds and returns (delay is approximate)
//
// Parameters:
//  uint16_t microseconds - number of microseconds to delay
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void delay_us(uint16_t microseconds)
{
	uint16_t count;

	//Try to account for the call to and return from this function
	if(microseconds == 0)
		return;
	else
		microseconds -= 1;

	for(count = 0; count < microseconds; count++)
	{
		nop();
		nop();
	}
}
