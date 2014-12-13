#ifndef TARGET_NRF24LE1_SDK_H_
#define TARGET_NRF24LE1_SDK_H_

//DO NOT include reg24le1.h here or a circular include will happen
//This header file is included by reg24le1.h to provide it a package variant
#define __TARG_PACKAGE_TYPE		NRF24LE1_PACKAGE_24_PIN

//Encryption/decryption subsystem #defines
#define __TARG_ENC_DEC_ACCEL_ALLOW_INLINING		1	//If non-zero, this allows the enc_dec_accel_galois_multiply() function to be inlined (requires compiler option --std-c99)

#endif /* TARGET_NRF24LE1_SDK_H_ */
