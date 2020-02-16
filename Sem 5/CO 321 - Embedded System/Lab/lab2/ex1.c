#include <avr/io.h>
#include <util/delay.h>
#define BLINK_DELAY_MS 1000

int main(){
	DDRD &= ~(1<<7); //PD7 is input

	DDRB = 0xFF; //PORTB is output

	unsigned char count = 0;

	while(count <= 63){
		if(PIND & (1 << 7)){ // check whether the input of PD7 is set to HIGH
			count = count + 1;
			//PORTB = 0x00;
			//_delay_ms(BLINK_DELAY_MS);
			PORTB = count;
			_delay_ms(BLINK_DELAY_MS);
			PORTB = 0x00;

		}

	}
	return 0;
}