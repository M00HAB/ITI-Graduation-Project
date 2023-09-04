/*
 * lcd.c
 *
 *  Created on: Aug 16, 2023
 *      Author: Mohab Ashraf
 */

#include"stdtype.h"
#include"avr/delay.h"
#include"Dio.h"
#include"Lcd.h"
#include"bitmath.h"


void lcdSendCommand(u8 command)
{
	dioSetPinLevel(LCD_PIN_RS,STD_LOW);
	dioSetPinLevel(LCD_PIN_RW,STD_LOW);

	dioSetPinLevel(LCD_PIN_D0,getBit(command,0));
	dioSetPinLevel(LCD_PIN_D1,getBit(command,1));
	dioSetPinLevel(LCD_PIN_D2,getBit(command,2));
	dioSetPinLevel(LCD_PIN_D3,getBit(command,3));
	dioSetPinLevel(LCD_PIN_D4,getBit(command,4));
	dioSetPinLevel(LCD_PIN_D5,getBit(command,5));
	dioSetPinLevel(LCD_PIN_D6,getBit(command,6));
	dioSetPinLevel(LCD_PIN_D7,getBit(command,7));

	dioSetPinLevel(LCD_PIN_EN,STD_HIGH);
	_delay_ms(2);
	dioSetPinLevel(LCD_PIN_EN,STD_LOW);
}

void lcdSendData(u8 command)
{
	dioSetPinLevel(LCD_PIN_RS,STD_HIGH);
	dioSetPinLevel(LCD_PIN_RW,STD_LOW);

	dioSetPinLevel(LCD_PIN_D0,getBit(command,0));
	dioSetPinLevel(LCD_PIN_D1,getBit(command,1));
	dioSetPinLevel(LCD_PIN_D2,getBit(command,2));
	dioSetPinLevel(LCD_PIN_D3,getBit(command,3));
	dioSetPinLevel(LCD_PIN_D4,getBit(command,4));
	dioSetPinLevel(LCD_PIN_D5,getBit(command,5));
	dioSetPinLevel(LCD_PIN_D6,getBit(command,6));
	dioSetPinLevel(LCD_PIN_D7,getBit(command,7));

	dioSetPinLevel(LCD_PIN_EN,STD_HIGH);
	_delay_ms(2);
	dioSetPinLevel(LCD_PIN_EN,STD_LOW);
}

void lcdInit(void){
	_delay_ms(40);

	//function set command : 2 lines : 5 * 8 font size
	lcdSendCommand(0b00111000);
	_delay_ms(1);

	//Display on/off Control : Display Enable,disable cursor,no blink
	lcdSendCommand(0b00001100);
	_delay_ms(1);

	//Display Clear
	lcdSendCommand(0b00000001);
	_delay_ms(1);

}

void lcdSendSrting(const u8 * str){
	while(*str != '\0'){
		lcdSendData(*str++);
	}
}

void goToXY(u8 x,u8 y){
	u8 localaddress;

	if(x == 1){
		localaddress = y;
	}else if(x == 2){
		localaddress = y + 0x40;
	}

	lcdSendCommand(localaddress + 128);
}
