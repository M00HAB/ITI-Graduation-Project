/*
 * lcd.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Mohab Ashraf
 */

#ifndef LCD_H_
#define LCD_H_

/********* CONFIG. *********/

/********* LCD CONTROL PINS *********/
#define LCD_PIN_RS DIO_PORTC,DIO_PIN7
#define LCD_PIN_RW DIO_PORTC,DIO_PIN6
#define LCD_PIN_EN DIO_PORTC,DIO_PIN5

/********* LCD DATA PINS *********/
#define LCD_PIN_D0 DIO_PORTD,DIO_PIN0
#define LCD_PIN_D1 DIO_PORTD,DIO_PIN1
#define LCD_PIN_D2 DIO_PORTD,DIO_PIN2
#define LCD_PIN_D3 DIO_PORTD,DIO_PIN3
#define LCD_PIN_D4 DIO_PORTD,DIO_PIN4
#define LCD_PIN_D5 DIO_PORTD,DIO_PIN5
#define LCD_PIN_D6 DIO_PORTD,DIO_PIN6
#define LCD_PIN_D7 DIO_PORTD,DIO_PIN7


void lcdSendCommand(u8 command);
void lcdSendData(u8 command);
void lcdInit(void);

void lcdSendSrting(const u8 * str);
void goToXY(u8 x,u8 y);

#endif /* LCD_H_ */
