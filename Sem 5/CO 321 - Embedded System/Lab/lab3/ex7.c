#include <avr/io.h>
#include <avr/interrupt.h>

int n = 0;

int main(){
	DDRB = 0xFF; // PORTB output

	sei();
	TIMSK0 = 0x01; 	// enable Timer 0 overflow interrupt
	TIMSK1 = 0x01; //  enable Timer 1 overflow interrupt

	TCNT0 = 244; 	// Load timer/counter 0 register with an initial value
	TCNT1 = 34286;

	TCCR0A = 0x00; 	// normal mode
	TCCR0B = 0x05;  //normal mode and 1/1024 prescaler

	TCCR1A = 0x00; 	// normal mode
	TCCR1B = 0x04;  //normal mode and 1/256 prescaler

	while(1){

	}

	return 0;
}

//50ms delay
ISR(TIMER0_OVF_vect){
	n++;

	if(n == 4){
		n = 0;
		PORTB = PORTB ^ (1<<5);
		TCNT0 = 244; 	// Load timer/counter 1 register with an initial value
	}
}

//500ms delay
ISR(TIMER1_OVF_vect){
	PORTB = PORTB ^ (1<<4);
	TCNT1 = 34286;
}