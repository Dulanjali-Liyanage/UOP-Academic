#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 1000

int main(){

	DDRD = 0x00; //portD is input
	DDRB |= (1<<0); //PB0 is output
	DDRB |= (1<<1); //PB1 is output

	//INT0 rising edge
	EICRA |= (1<<ISC01);
	EICRA |= (1<<ISC00);

	sei();

	EIMSK |= (1<<INT0);

	while(1){

	}

	return 0;
}

ISR(INT0_vect){

	//EICRA |= (1<<ISC11);
	//EICRA |= (0<<ISC10);

	sei();

	EIMSK |=  (1<<INT1);


	PORTB |= (1<<0);
	_delay_ms(BLINK_DELAY_MS);
	PORTB &= ~(1<<0);
}

ISR(INT1_vect){
	PORTB |= (1<<1);
	_delay_ms(BLINK_DELAY_MS);
	PORTB &= ~(1<<1);
}