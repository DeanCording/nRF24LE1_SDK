/////////////////////////////////////////////////////////////////////////////
//
// File: interrupt_set_priority.c
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

#include "interrupt.h"


///////////////////////////////////////////
// Internal defines
///////////////////////////////////////////
#define INTERRUPT_IP0_MASK				0x01	//Mask for interrupt_priority_level_t that determines if the bit in IP0 needs to be set or cleared
#define INTERRUPT_IP1_MASK				0x02	//Mask for interrupt_priority_level_t that determines if the bit in IP1 needs to be set or cleared

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// void interrupt_set_priority(interrupt_priority_group_t interrupt_priority_group, interrupt_priority_level_t interrupt_priority_level)
//
// Description:
//  Configures the interrupt priority level of a specified priority group.
//
// Parameters:
//	interrupt_priority_group_t interrupt_priority_group - the interrupt priority group to configure
//  interrupt_priority_level_t interrupt_priority_level - the interrupt priority level to assign to this interrupt priority group
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void interrupt_set_priority(interrupt_priority_group_t interrupt_priority_group, interrupt_priority_level_t interrupt_priority_level)
{
	//Make sure the arguments are valid
	if((interrupt_priority_group >= INTERRUPT_PRIORITY_GROUP_NUM) || (interrupt_priority_level >= INTERRUPT_PRIORITY_LEVEL_NUM))
	{
		return;
	}

	//There are two registers that determine the interrupt priority for a particular group, IP0 and IP1.  The interrupt priority
	// is a number from 0 to 3, with the least-significant bit being assigned to IP0 and the most-significant bit being assigned
	// to IP1.  The bit positions in IP0 and IP1 are the same as the interrupt priority group number, so to get the bit values of
	// IP0 and IP1, we simply left-shift interrupt_priority_group times the proper bit of interrupt_priority_level.
	if(interrupt_priority_level & INTERRUPT_IP0_MASK)
	{
		IP0 |= (1 << interrupt_priority_group);
	}
	else
	{
		IP0 &= (~(1 << interrupt_priority_group));
	}

	if(interrupt_priority_level & INTERRUPT_IP1_MASK)
	{
		IP1 |= (1 << interrupt_priority_group);
	}
	else
	{
		IP1 &= (~(1 << interrupt_priority_group));
	}
}
