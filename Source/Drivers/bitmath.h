/*
 * bitmath.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Mohab Ashraf
 */

#ifndef BITMATH_H_
#define BITMATH_H_

#define setBit(var,k) (var) |= (1 << (k))
#define clrBit(var,k) (var) &= ~(1 << k)
#define togBit(var,k) (var) ^= (1 << k)
#define getBit(var,k) ((var) >> (k) & 0x01)

#endif /* BITMATH_H_ */
