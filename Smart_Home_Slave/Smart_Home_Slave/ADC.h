/*****************************************************************
*
* File Name: ADC.h
*
* Date Created: 19/09/2020
*
* Author: Ahmed LNiwehy
*
*****************************************************************/


#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>

void ADC_Init();
unsigned short ADC_Read(unsigned char Channel);



#endif /* ADC_H_ */