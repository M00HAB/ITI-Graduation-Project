/*
 * dio.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Mohab Ashraf
 */

#ifndef DIO_H_
#define DIO_H_

typedef enum {
	DIO_PORTA,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD
}DioPortType;

typedef enum{
	DIO_PIN0,
	DIO_PIN1,
	DIO_PIN2,
	DIO_PIN3,
	DIO_PIN4,
	DIO_PIN5,
	DIO_PIN6,
	DIO_PIN7
}DioPinType;

typedef enum{
	DIO_PIN_OUTPUT,
	DIO_PIN_INPUT_FLOATING,
	DIO_PIN_INPUT_PULLUP
}DioPinMode;

typedef enum{
	DIO_PORT_OUTPUT = 0XFF,
	DIO_PORT_INPUT = 0
}DioPortMode;

typedef enum{
	DIO_PORT_LOW = 0,
	DIO_PORT_HIGH = 0XFF
}DioPortLevel;

typedef enum{
	STD_LOW ,
	STD_HIGH
}DioPinLevel;

void dioSetPortMode(DioPortType port ,DioPortMode mode);
void dioSetPortLevel(DioPortType port,DioPortLevel type);
DioPortLevel dioReadPortLevel(DioPortType port);

void dioSetPinMode(DioPortType port,DioPinType pin,DioPinMode mode);
void dioSetPinLevel(DioPortType port,DioPinType pin,DioPinLevel level);
DioPinLevel dioFlipPinLevel(DioPortType port,DioPinType pin);
DioPinLevel dioReadPinLevel(DioPortType port,DioPinType pin);

#endif /* DIO_H_ */
