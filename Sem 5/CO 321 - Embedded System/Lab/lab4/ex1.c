#include <avr/io.h>

int main(){


	OCR0A = 127; // 50% duty cycle

	TCCR0A = (1<<WGM00) | (1<<WGM01); // Fast PWM (TOP = OxFF)

	TCCR0A |= (1 << COM0A1); // non-inverting mode Fast PWM

	TCCR0B = 3; //Prescaler is 64

	DDRD |= (1<<6);

	while(1){}

	return 0;
}