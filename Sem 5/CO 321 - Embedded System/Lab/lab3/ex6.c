#include <avr/io.h>
#include <avr/interrupt.h>

int n = 0;

int main(){
	DDRB = DDRB | (1<<5); //PB5 output

	sei();
	TIMSK0 = 0x01; 	// enable Timer 0 overflow interrupt

	TCNT0 = 231; 	// Load timer/counter 0 register with an initial value

	TCCR0A = 0x00; 	// normal mode
	TCCR0B = 0x05;  //normal mode and 1/1024 prescaler

	while(1){

	}

	return 0;
}

ISR(TIMER0_OVF_vect){
	n++;

	if(n == 7){
		n = 0;
		PORTB = PORTB ^ (1<<5);
		TCNT0 = 231; 	// Load timer/counter 1 register with an initial value
	}
}