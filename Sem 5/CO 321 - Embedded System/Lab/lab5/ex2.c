#include <avr/io.h>
#include <util/delay.h>

int main(){
	DDRC &= ~(1<<1); // PC1 input (A1) --> LDR connect
	DDRB |= (1<<5); // PB5 output - LED connect

	ADCSRA |= (1<<ADEN); // enable ADC
	ADCSRA = ADCSRA | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0); // 128 presacler - 125kHz

	ADMUX |= (1<<REFS0); // AVcc with external capacitor at AREF pin

	ADMUX |= (1<<MUX0); // ADC1 input channel

	ADMUX |= (1<<ADLAR); // left justified

	while(1){
		ADCSRA |= (1<<ADSC); // start conversion

		while((ADCSRA & 0b00010000) == 0){} // wait till the conversion end

		ADCSRA |= (1<<ADIF); // clear the flag bit

		//first read the ADCL and then ADCH
		//uint16_t theTenBitResult = (ADCL>>6) | (ADCH<<2); // read the converted value
		

		if(ADCH  < 125){
			PORTB |= (1<<5); // dark - led on
		}else{
			PORTB &= ~(1<<5); //light - led off
		}

	}

	return 0;
}