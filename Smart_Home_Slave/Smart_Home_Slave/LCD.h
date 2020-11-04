/*****************************************************************
*
* File Name: LCD.h
*
* Date Created: 19/09/2020
*
* Author: Ahmed LNiwehy
*
*****************************************************************/


#ifndef LCD_H_
#define LCD_H_

#include "DIO_HW.h"
#include "Std_Types.h"
#define F_CPU 16000000UL
#include <util/delay.h>

#define LCD_PRT  PORTD_REG
#define LCD_DDR  DDRD_REG
#define LCD_PIN  PIND_REG
#define LCD_RS  2
#define LCD_EN  3

#define TWO_LINE_LCD_FOUR_BIT_MODE 0x28
#define FOUR_BIT_MODE 0x32
#define RETURN_HOME 0x02
#define CURSOR_OFF  0x0C
#define CURSOR_ON   0x0E
#define CLEAR       0x01
#define SHIFT_DISPLAY_LEFT  0x18
#define SHIFT_DISPLAY_RIGHT 0x1C
#define SET_CURSOR_LOCATION 0x80
#define CURSOR_BLINKING_ON  0x0D
#define CURSOR_BLINKING_OFF 0x0C

void LCD_Command(uint8 cmd);
void LCD_Init(void);
void LCD_DisplayChar(uint8 data);
void LCD_DisplayString(sint8 *str);
void LCD_Gotoxy(uint8 x, uint8 y);
void LCD_Clear(void);
void LCD_CursorOff(void);
void LCD_CursorOn(void);
void LCD_CursorBlinkOn(void);
void LCD_CursorBlinkOff(void);
void LCD_ShiftScreenLeft(void);
void LCD_ShiftScreenRight(void);
void LCD_IntToString(uint32 data);

#endif /* LCD_H_ */