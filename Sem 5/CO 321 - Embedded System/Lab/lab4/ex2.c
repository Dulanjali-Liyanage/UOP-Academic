#include <avr/io.h>
//#include <util/delay.h>

void delay_timer1(){
	TCNT1 = 3036; //init value of the timer

	TCCR1A = 0x00;
	TCCR1B = 0x04; //normal mode and 1/256 prescaler

	while((TIFR1 & 0x01) == 0); //wait till timer 1 overflows and flag bit set

	TCCR1A = 0x00;
	TCCR1B = 0x00; //stops the clock

	TIFR1 = 0x01; //clear flag bit
}

int main(){

	TCCR0A = (1<<WGM00) | (1<<WGM01); // Fast PWM (TOP = OxFF)

	TCCR0A |= (1 << COM0A1); // non-inverting  Fast PWM

	TCCR0B |= 3; //Prescaler is 64

	DDRD |= (1<<6); //PD6 - OC0A

	while(1){
		int i;
		for(i = 0; i < 256;i = i + 5){
			OCR0A = i;
			delay_timer1();
		}
		int j;
		for(j = 255;j >= 0;j = j - 5){
			OCR0A = j;
			delay_timer1();
		}
	}

	return 0;
}