#include <avr/io.h>
#include <util/delay.h>
#define BLINK_DELAY_MS

int main (void){
	DDRB = DDRB|(1<<5); /* configure pin 5 of PORTB for output*/
	DDRB = DDRB|(1<<4);
	DDRB = DDRB|(1<<3);
	DDRB = DDRB|(1<<2);
	while(1){
		PORTB = PORTB | (1<<5); /* set pin 5 high to turn led on */
		PORTB = PORTB|(1<<4);
		PORTB = PORTB|(1<<3);
		PORTB = PORTB|(1<<2);
		_delay_ms(100);

		PORTB = PORTB &~(1<<5); /* set pin 5 low to turn led off */
		PORTB = PORTB &~(1<<4);
		PORTB = PORTB &~(1<<3);
		PORTB = PORTB &~(1<<2);
		_delay_ms(100);

	}
}