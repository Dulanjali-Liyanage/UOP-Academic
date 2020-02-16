#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


int main(){
	DDRD = 0x00; // PORTD is input (PD2-A & PD3-B)
	DDRB = 0xFF; // PORTB is output(led connect)

		//PD2 - A - detect '0'
		EICRA |= (1<<ISC01); // set for rising edge detection
		EICRA |= (1<<ISC00); // set for rising edge detection

		sei(); //enable global interrupts

		EIMSK |= (1<<INT0); // enable external interrupt for int0

		//PD3 - B - detect '1'
		EICRA |= (1<<ISC11); // set for rising edge detection
		EICRA |= (1<<ISC10); // set for rising edge detection

		sei(); //enable global interrupts

		EIMSK |= (1<<INT1); // enable external interruptfor int1

		while (1){
	}

	return 0;
}

ISR(INT0_vect){
	PORTB = PORTB<<1;
	PORTB &= ~(1<<0);
}

ISR(INT1_vect){
	PORTB = PORTB<<1;
	PORTB |= (1<<0);
}