/////////////////////////////////////////////////////////////////////////////
//
// File: w2_master_process_start_request.c
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
// void w2_master_process_start_request(w2_start_stop_condition_t send_start_stop_conditions)
//
// Description:
//  Processes start requests
//
// Parameters:
//  w2_start_stop_condition_t send_start_stop_conditions - if set to W2_SEND_ONLY_START_CONDITION or
//   W2_SEND_BOTH_START_AND_STOP_CONDITIONS, the function will issue a start condition
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void w2_master_process_start_request(w2_start_stop_condition_t send_start_stop_conditions)
{
	switch(send_start_stop_conditions)
	{
		case W2_SEND_ONLY_START_CONDITION:
		case W2_SEND_BOTH_START_AND_STOP_CONDITIONS:
			w2_send_start_condition();
			break;

		default:
			break;
	};
}
