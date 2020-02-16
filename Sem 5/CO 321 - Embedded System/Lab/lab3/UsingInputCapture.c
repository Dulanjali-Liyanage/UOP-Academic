// Measuring period of a square wave signal on ICP1 pin

#include <avr/io.h>
#include <avr/interrupt.h>
#include <inttypes.h>

uint16_t period; 			// data type: unsigned 16-bit integer

ISR(TIMER1_CAPT_vect){ 		// Timer1 input capture interrupt service routine
	period = ICR1; 			// period = value of Timer 1 stored in ICR1
	TCNT1 = 0; 				// reset Timer 1
	PORTD = ~(period >> 8); // display top 8-bit of period on PORT D
}

int main(void) {
	DDRD = 0xFF;  			// set port D for output 
	TCCR1A = 0b00000000;	// normal mode
	TCCR1B = 0b11000001;	// no prescaler, rising edge, noise canceller
	TIMSK = 0b00100000; 	// enable Timer 1 input capture interrupt
	
	sei(); 					// enable interrupt subsystem globally
	
	while (1){;} 			// infinite loop

	return 0;
}