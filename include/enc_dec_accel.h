/////////////////////////////////////////////////////////////////////////////
//
// File: enc_dec_accel.h
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

#ifndef ENC_DEC_ACCEL_H_
#define ENC_DEC_ACCEL_H_

#include "reg24le1.h"


///////////////////////////////////////////
// Compilation defines
///////////////////////////////////////////
// Verify existence of __TARG_ENC_DEC_ACCEL_ALLOW_INLINING
#ifndef __TARG_ENC_DEC_ACCEL_ALLOW_INLINING
#error "You must define __TARG_ENC_DEC_ACCEL_ALLOW_INLINING in the appropriate target_nrf24le1_sdk.h file to use this header file"
#endif


///////////////////////////////////////////
// Function macros
///////////////////////////////////////////
#if (__TARG_ENC_DEC_ACCEL_ALLOW_INLINING == 0)
//See enc_dec_accel_galois_multiply.c for function details (function body is the same, except 'output' is the return in this macro)
#define enc_dec_accel_galois_multiply(input_a, input_b, output)\
	CCPDATIA = input_a;\
	CCPDATIB = input_b;\
	output = CCPDATO
#endif


///////////////////////////////////////////
// Inline function definitions
///////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// static __INLINE uint8_t enc_dec_accel_galois_multiply(uint8_t a, uint8_t b) __reentrant
//
// Description:
//  Performs a GF(2^8) mutliplication in hardware and returns the result
//
// Parameters:
//  uint8_t a - multiplier in the operation
//  uint8_t b - multiplicand in the operation
//
// Return value:
//  Result of the GF(2^8) multiplication
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if (__TARG_ENC_DEC_ACCEL_ALLOW_INLINING != 0)
//See enc_dec_accel_galois_multiply.c for function details (function body is the same)
static inline uint8_t enc_dec_accel_galois_multiply(uint8_t a, uint8_t b) __reentrant
{
	//Load the hardware registers for the operators
	CCPDATIA = a;
	CCPDATIB = b;

	//Return the result of the hardware GF(2^8) multiplication
	return CCPDATO;
}
#endif

#endif /* ENC_DEC_ACCEL_H_ */
