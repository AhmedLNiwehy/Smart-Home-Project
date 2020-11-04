/*****************************************************************
*
* File Name: SSegments.c
*
* Date Created: 10/10/2020
*
* Author: Ahmed LNiwehy
*
******************************************************************/


#include "SSegments.h"

void SSEG_Init()
{
	DDRC |= (1<<0) | (1<<1) | (1<<2) | (1<<3);
	DDRA |= (1<<1) | (1<<2);
}

void SSEG_display(float dist)
{
	unsigned char d1, d2;
	
	d1 = (int)dist % 10;     dist = (dist - d1 ) / 10;  
	
	PORTC = (PORTC & 0xF0) | d1;
	PORTA |= (1<<2);
	_delay_ms(5);
	PORTA &= (~(1<<2));
	
	d2 = (int)dist % 10;     dist = (dist - d2 ) / 10;
	
	PORTC = (PORTC & 0xF0) | d2;
	PORTA |= (1<<1);
	_delay_ms(5);
	PORTA &= (~(1<<1));
}