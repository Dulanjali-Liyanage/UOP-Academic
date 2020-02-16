#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 100

int main(){

       DDRD &= ~(1<<2); 
       DDRB |= (1<<0); 
       DDRB |= (1<<1); 
       EICRA |= (1<<ISC01); 
       EICRA |= (1<<ISC00);  

       sei();  

       EIMSK |= (1<<INT0);  

       while(1){
               PORTB |= (1<<1);
       }

       return 0;
}

ISR(INT0_vect){

       while(PIND&(1<<2)) {

               PORTB |= (1<<0);
               _delay_ms(BLINK_DELAY_MS);
               PORTB &= ~(1<<0);
               _delay_ms(BLINK_DELAY_MS);
       }

       PORTB &= ~(1<<0);
}

 