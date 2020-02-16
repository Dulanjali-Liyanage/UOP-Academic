#include <avr/io.h>

void delay_timer0(){
	TCNT0 = 131; //init value of the timer

	TCCR0A = 0x00;
	TCCR0B = 0x04; //normal mode and 1/256 prescaler

	while((TIFR0 & 0x01) == 0); //wait till timer 0 overflows and flag bit set

	TCCR0A = 0x00;
	TCCR0B = 0x00; //stops the clock

	TIFR0 = 0x01; //clear flag bit
}

int main(){
	DDRB = DDRB | (1<<5); // PB5 output

	while(1){
		PORTB = PORTB ^ (1<<5);
		delay_timer0();
	}

	return 0;
}