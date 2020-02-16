#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 100
unsigned char count = 0;

int main(){
	DDRD &= ~(1<<2); //PD2 (INT0) is input

	DDRB = 0xFF; //PORTB is output


	while(count <= 63){
		EICRA |= (1<<ISC01); // set for falling edge detection
		EICRA &= ~(1<<ISC00); // set for falling edge detection

		sei(); //enable global interrupts

		EIMSK |= (1<<INT0); // enable external interrupt for int0
	}

	return 0;
}

ISR(INT0_vect){
		count = count + 1;
		//PORTB = 0x00;
		//_delay_ms(BLINK_DELAY_MS);
		PORTB = count;
}