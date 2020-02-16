#include <avr/io.h>
#include <util/delay.h>
#define BLINK_DELAY_MS 100

int main (void){
	DDRB = 0xFF;
	int z ;
	/* configure pin 5 of PORTB for output*/
	while(1){
		for(z=3 ;z>=0;z--){
			PORTB = PORTB | (1<<z); /* set pin  high to turn led on */
			_delay_ms(BLINK_DELAY_MS);
			PORTB = PORTB &~(1<<z); /* set pin  low to turn led off */
			_delay_ms(BLINK_DELAY_MS);

		}

		for(z= 2;z>0;z--){
			PORTB = PORTB | (1<<z); /* set pin  high to turn led on */
			_delay_ms(BLINK_DELAY_MS);
			PORTB = PORTB &~(1<<z); /* set pin  low to turn led off */
			_delay_ms(BLINK_DELAY_MS);

		}





	}
}

