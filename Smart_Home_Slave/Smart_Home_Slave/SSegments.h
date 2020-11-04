/*****************************************************************
*
* File Name: SSegments.h
*
* Date Created: 10/10/2020
*
* Author: Ahmed LNiwehy
*
******************************************************************/


#ifndef SSEGMENTS_H_
#define SSEGMENTS_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void SSEG_display(float dist);
void SSEG_Init();

#endif /* SSEGMENTS_H_ */