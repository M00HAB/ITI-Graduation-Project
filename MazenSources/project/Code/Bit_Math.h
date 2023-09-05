/*
 * Bit_Math.h
 *
 *  Created on: Aug 25, 2023
 *      Author: Acer
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(VAR,BITNO) (VAR) |= (1<<(BITNO))
#define RESET_BIT(VAR,BITNO) (VAR) &= ~(1<<(BITNO))
#define TOGGLE_BIT(VAR,BITNO) (VAR) ^= (1<<(BITNO))
#define GET_BIT(VAR,BITNO) (((VAR) >> (BITNO)) &0x01)


#endif /* BIT_MATH_H_ */
