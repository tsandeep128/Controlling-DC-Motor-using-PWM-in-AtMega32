/*
 * PWM.c
 *
 * Created: 31-12-2015 01:41:05
 *  Author: Sandeep
 */ 


#include <avr/io.h>

int main(void)
{
	DDRB |= (1<<PB5 | 1<<PB6);
	TCCR1A |= (1<<COM1A1 | 1<<COM1A0);		//inverting mode
	TCCR1A |= (1<<COM1B1 | 1<<COM1B0);		//inverting mode	
	TCCR1A |= (1<<WGM11);				//WGM 10=0,11=12=13=1 FAST PWM, ICRn
	TCCR1A &= ~(1<<WGM10);
	TCCR1B |= (1<<WGM13 | 1<<WGM12);
	TCCR3B |= (1<<CS10);				//CS 10=1,11=12=0; no prescaling	
	TCCR3B &= ~(1<<CS11 | 1<<CS12);
	
	ICR1 = 60000;       //=100%
	OCR1A = 6000;	
	OCR1B = 6000;
		
	
    while(1)
    {
        
    }
}