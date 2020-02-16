/*
 * ADC_new_ex1.c
 *
 * Created: 8/14/2019 9:56:44 PM
 * Author : DINITHI
 */ 

#include <avr/io.h>

unsigned char x;
unsigned char y;



int main(void)
{
    /* Replace with your application code */
	DDRC &= ~(1<<1); // INPUT
	DDRD = 0Xff; // OUTput
	ADCSRA |= (1<<ADPS2);
	ADCSRA |= (1<<ADEN);
	ADCSRA |= (1<<ADIE);
	ADMUX &= ~(1<<REFS1);
	ADMUX |= (1<<REFS0);
	ADMUX |= (1 << MUX0);
	ADMUX |= (1<<ADLAR);	
	
	

    while (1) 
    {
		ADCSRA |= (1<<ADSC);

		while((ADCSRA & (1<<ADIF))==0){}

		x = ADCL;
		y = ADCH;

		if (y > 240){
			PORTD = 0x5;
		}else if(y > 190){
			PORTD = 0x4;
		}
		else if ( y > 120){
			PORTD = 0x3;
			}else if ( y > 90){
				PORTD = 0x2;
			}else if ( y > 40){
				PORTD = 0x1;
			}
			else{
			PORTD = 0x0;
		}

		ADCSRA |= (1<<ADIF);
    }
}

