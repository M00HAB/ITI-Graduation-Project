/*
 * dio.c
 *
 *  Created on: Aug 16, 2023
 *      Author: Mohab Ashraf
 */

#include"avr/io.h"
#include"Dio.h"
#include"bitmath.h"
#include"stdtype.h"

void dioSetPortMode(DioPortType port ,DioPortMode mode)
{
	switch(port)
	{
	case DIO_PORTA:
		DDRA = mode;
		break;
	case DIO_PORTB:
		DDRB = mode;
		break;
	case DIO_PORTC:
		DDRC = mode;
		break;
	case DIO_PORTD:
		DDRD = mode;
		break;
	default:
		break;
	}
}

void dioSetPortLevel(DioPortType port,DioPortLevel level){
	switch(port)
		{
		case DIO_PORTA:
			PORTA = level;
			break;
		case DIO_PORTB:
			PORTB = level;
			break;
		case DIO_PORTC:
			PORTC = level;
			break;
		case DIO_PORTD:
			PORTD = level;
			break;
		default:
			break;
		}
}

DioPortLevel dioReadPortLevel(DioPortType port){
	DioPortLevel level = DIO_PORT_LOW;
	switch(port)
			{
			case DIO_PORTA:
				level = PINA;
				break;
			case DIO_PORTB:
				level = PINB;
				break;
			case DIO_PORTC:
				level = PINC;
				break;
			case DIO_PORTD:
				level = PIND;
				break;
			default:
				break;
			}
	return level;
}

void dioSetPinMode(DioPortType port,DioPinType pin,DioPinMode mode){
	if(mode == DIO_PIN_OUTPUT){
		switch(port)
		{
			case DIO_PORTA:
				setBit(DDRA,pin);
				break;
			case DIO_PORTB:
				setBit(DDRB,pin);
				break;
			case DIO_PORTC:
				setBit(DDRC,pin);
				break;
			case DIO_PORTD:
				setBit(DDRD,pin);
				break;
			default :
				break;
		}
	}else if(mode == DIO_PIN_INPUT_FLOATING){

		switch(port)
				{
					case DIO_PORTA:
						clrBit(DDRA,pin);
						clrBit(PORTA,pin);
						break;
					case DIO_PORTB:
						clrBit(DDRB,pin);
						clrBit(PORTB,pin);
						break;
					case DIO_PORTC:
						clrBit(DDRC,pin);
						clrBit(PORTC,pin);
						break;
					case DIO_PORTD:
						clrBit(DDRD,pin);
						clrBit(PORTD,pin);
						break;
					default :
						break;
				}
	}else if(mode == DIO_PIN_INPUT_PULLUP){
		switch(port)
						{
							case DIO_PORTA:
								clrBit(DDRA,pin);
								setBit(PORTA,pin);
								break;
							case DIO_PORTB:
								clrBit(DDRB,pin);
								setBit(PORTB,pin);
								break;
							case DIO_PORTC:
								clrBit(DDRC,pin);
								setBit(PORTC,pin);
								break;
							case DIO_PORTD:
								clrBit(DDRD,pin);
								setBit(PORTD,pin);
								break;
							default :
								break;
						}
	}
}

void dioSetPinLevel(DioPortType port,DioPinType pin,DioPinLevel level){
	if(level == STD_HIGH){
		switch(port)
			{
			case DIO_PORTA:
				setBit(PORTA,pin);
				break;
			case DIO_PORTB:
				setBit(PORTB,pin);
				break;
			case DIO_PORTC:
				setBit(PORTC,pin);
				break;
			case DIO_PORTD:
				setBit(PORTD,pin);
				break;
			default:
				break;
			}
	}else if(level == STD_LOW){
		switch(port)
					{
					case DIO_PORTA:
						clrBit(PORTA,pin);
						break;
					case DIO_PORTB:
						clrBit(PORTB,pin);
						break;
					case DIO_PORTC:
						clrBit(PORTC,pin);
						break;
					case DIO_PORTD:
						clrBit(PORTD,pin);
						break;
					default:
						break;
					}
	}
}

DioPinLevel dioFlipPinLevel(DioPortType port,DioPinType pin){
	DioPinLevel level = STD_HIGH;
	switch(port)
			{
				case DIO_PORTA:
					togBit(DDRA,pin);
					level = getBit(PORTA,pin);
					break;
				case DIO_PORTB:
					togBit(DDRB,pin);
					level = getBit(PORTB,pin);
					break;
				case DIO_PORTC:
					togBit(DDRC,pin);
					level = getBit(PORTC,pin);
					break;
				case DIO_PORTD:
					togBit(DDRD,pin);
					level = getBit(PORTD,pin);
					break;
				default :
					break;
			}
	return level;
}

DioPinLevel dioReadPinLevel(DioPortType port,DioPinType pin){
	DioPinLevel level = STD_LOW;

	switch(port)
				{
				case DIO_PORTA:
					if(getBit(PINA,pin) == 1){
						level = STD_HIGH;
					}
					break;
				case DIO_PORTB:
					if(getBit(PINB,pin) == 1){
						level = STD_HIGH;
					}
					break;
				case DIO_PORTC:
					if(getBit(PINC,pin) == 1){
						level = STD_HIGH;
					}
					break;
				case DIO_PORTD:
					if(getBit(PIND,pin) == 1){
						level = STD_HIGH;
					}
					break;
				default :
					break;
				}
	return level;
}
