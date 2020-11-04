/*****************************************************************
*
* File Name: ADC.c
*
* Date Created: 19/09/2020
*
* Author: Ahmed LNiwehy
*
*******************************************************************/


#include "ADC.h"

void ADC_Init()
{
	ADMUX |= (1<<REFS1) | (1<<REFS0);                         // INTERNAL REF VOLTAGE
	ADCSRA |= (1<<ADEN) | (ADPS0) | (1<<ADPS1) | (1<<ADPS2);  //ENABLE ADC AND 128 PRESCALE
}

unsigned short ADC_Read(unsigned char Channel)
{
	unsigned short data = 0;
	ADMUX = (ADMUX & 0xE0) | (Channel & 0x1F);
	ADCSRA |= (1<<ADSC);                              //START CONVERSION
	while(!(ADCSRA & (1<<ADIF)));                     //WAIT 25 OR 13 ADC CYCLE
	ADCSRA |= (1<<ADIF);         //CLEAR ADIF BIT
	
	data = ADCL;
	data |= (ADCH << 8);         //READ DATA
	
	return data;
}