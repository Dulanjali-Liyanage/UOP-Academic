#include <avr/io.h>
#include <util/delay.h>
#define BLINK_DELAY_MS

int main (void){
	DDRB = DDRB|(1<<5); /* configure pin 5 of PORTB for output*/
	DDRB = DDRB|(1<<4);
	DDRB = DDRB|(1<<3);
	DDRB = DDRB|(1<<2);

	PORTB = PORTB | (1<<5);
	_delay_ms(100);
	PORTB = PORTB &~(1<<5);
	_delay_ms(100);

	PORTB = PORTB | (1<<4);
	_delay_ms(100);
	PORTB = PORTB &~(1<<4);
	_delay_ms(100);

	PORTB = PORTB | (1<<3);
	_delay_ms(100);
	PORTB = PORTB &~(1<<3);
	_delay_ms(100);

	PORTB = PORTB | (1<<2);

	while(1){
		PORTB = PORTB | (1<<3); /* set pin 5 high to turn led on */
		_delay_ms(100);
		PORTB = PORTB &~(1<<3); /* set pin 5 low to turn led off */
		_delay_ms(100);

		PORTB = PORTB | (1<<4);
		_delay_ms(100);
		PORTB = PORTB &~(1<<4);
		_delay_ms(100);

		PORTB = PORTB | (1<<5);
		_delay_ms(100);
		PORTB = PORTB &~(1<<5);
		_delay_ms(100);

		PORTB = PORTB | (1<<4);
		_delay_ms(100);
		PORTB = PORTB &~(1<<4);
		_delay_ms(100);

	}
}

