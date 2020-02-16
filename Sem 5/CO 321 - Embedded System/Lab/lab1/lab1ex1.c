#include <avr/io.h>
#include <util/delay.h>
#define BLINK_DELAY_MS 1000

int main (void){
	DDRB = 0xFF;

	/* configure pin 5 of PORTB for output*/
	while(1){
		PORTB = 0xFF;
		_delay_ms(BLINK_DELAY_MS);

		PORTB = 0x00;
		_delay_ms(BLINK_DELAY_MS);
	}
}

