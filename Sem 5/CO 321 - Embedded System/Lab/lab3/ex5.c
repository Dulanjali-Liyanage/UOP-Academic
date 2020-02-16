#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 100

//2ms delay
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
	DDRB = 0xFF; //PORTB output
	int z;

	sei();
	TIMSK1 = 0x01; 	// enable Timer 1 overflow interrupt

	TCNT1 = 3036; 	// Load timer/counter 1 register

	TCCR1A = 0x00; 	// normal mode
	TCCR1B = 0x04;  //normal mode and 1/256 prescaler

	while(1){
		for(z=3; z>=0; z--){
			PORTB = PORTB | (1<<z); /* set pin  high to turn led on */
			int i;
			for(i = 0;i < 50;i++){
				delay_timer0();
			}
			PORTB = PORTB &~(1<<z); /* set pin  low to turn led off */
			int i;
			for(i = 0;i < 50;i++){
				delay_timer0();
			}

		}

		for(z=2; z>0; z--){
			PORTB = PORTB | (1<<z); /* set pin  high to turn led on */
			int i;
			for(i = 0;i < 50;i++){
				delay_timer0();
			}
			PORTB = PORTB &~(1<<z); /* set pin  low to turn led off */
			int i;
			for(i = 0;i < 50;i++){
				delay_timer0();
			}

		}

	}

	return 0;
}

ISR(TIMER1_OVF_vect){
	PORTB = PORTB ^ (1<<5);
	TCNT1 = 3036; 	// Load timer/counter 1 register
}