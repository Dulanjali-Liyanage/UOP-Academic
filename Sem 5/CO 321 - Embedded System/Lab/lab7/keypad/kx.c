#include <avr/io.h>
#include <util/delay.h>

#define ROWS  4 
#define COLS  4 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

int col;

//byte rowPins[ROWS] = {6, 7, 8, 9}; 
//byte colPins[COLS] = {10, 11, 12, 13}; 

//Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);




void usart_init(){
	UBRR0 = 103; // 9600 baud rate // 9600 = 16*(10^6)/16*(UBRR+1)
	UCSR0C &= ~(1 << UMSEL01) & ~(1 << UMSEL00); // select the Asynchronous mode
	UCSR0C &= ~(1 << UPM01) & ~(1 << UPM00); // no parity
	UCSR0C &= ~(1 << USBS0); // 1 stop bit
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00); // 8 bit data

	UCSR0B |= (1 << TXEN0); // enable the USART transmitter

	UCSR0B |= (1 << RXEN0); // enable the USART receiver

	//UBRR0L = BAUD_PRESCALE;		/* Load lower 8-bits of the baud rate value */
	//UBRR0H = (BAUD_PRESCALE >> 8);	/* Load upper 8-bits*/
}

void usart_send(char sendByte){

	while((UCSR0A & (1 << UDRE0)) == 0){} // wait until the UDR0 is ready for next byte // wait for empty transmit buffer
	UCSR0A |= (1 << UDRE0); // clear the flag	
	UDR0 = sendByte; // character byte to be transmitted
	while((UCSR0A & (1 << TXC0)) == 0){} // wait until the transmission is completed
	UCSR0A |= (1 << TXC0); // clear the flag	
}

char usart_receive(){
	
	while((UCSR0A & (1 << RXC0)) == 0){} // wait until the entire character is received
	UCSR0A |= (1 << RXC0); // clear the flag
	return UDR0; // return the character byte received		
}

void col_init(){

	DDRB |= (1<<1) | (1<<0); // Row (R3(8) ---- R4(9)) -- output
	DDRD |= (1<<7) | (1<<6); // Row (R2(7)--R1(6)) -- output
	DDRB &= ~(1<<2) & ~(1<<3) & ~(1<<4) & ~(1<<5); // Column  (C1(10)--C2(11)--C3(12)--C4(13)) -- input

	PORTB |= (1<<1) | (1<<0); // Row (R3(8) ---- R4(9)) -- power up(pull up)
	PORTD |= (1<<7) | (1<<6); // Row (R2(7)--R1(6)) -- power up(pull up)
	PORTB |= (1<<2) | (1<<3) | (1<<4) | (1<<5); // Column  (C1(10)--C2(11)--C3(12)--C4(13)) -- input (pull up)

	_delay_ms(1);

}

void row_init(){
	DDRB &= ~(1<<1) & ~(1<<0); // Row (R3(8) ---- R4(9)) -- input
	DDRD &= ~(1<<7) & ~(1<<6); // Row (R2(7)--R1(6)) -- input
	DDRB |= (1<<2) | (1<<3) | (1<<4) | (1<<5); // Column  (C1(10)--C2(11)--C3(12)--C4(13)) -- output

	PORTB |= (1<<1) | (1<<0); // Row (R3(8) ---- R4(9)) -- input(pull up)
	PORTD |= (1<<7) | (1<<6); // Row (R2(7)--R1(6)) -- input(pull up)
	PORTB |= (1<<2) | (1<<3) | (1<<4) | (1<<5); // Column  (C1(10)--C2(11)--C3(12)--C4(13)) -- power up (pull up)

	_delay_ms(5);

}

char getKey(){

	int row = 10;

	row_init();

	if(PIND & (1<<6)){
		row = 0;
	}else if(PIND & (1<<7)){
		row = 1;
	}else if(PINB & (1<<0)){
		row = 2;
	}else if(PINB & (1<<1)){
		row = 3;
	}

	if(col == 10 && row == 10){
		return 'H';
	}

	return hexaKeys[row][col];
} 

   
int main(){
	usart_init();
	char customKey;
	DDRD = 0x00;
	PORTD = 0xFF;

	while(1){
		
		//col_init();
		col = 10;
		_delay_ms(5);
		

		if(!(PIND & (1<<2))){
			col = 0;
			//customKey = getKey();
			usart_send('A');
			//usart_send(customKey);
		}/*else if(PINB & (1<<3)){
			col = 1;
			customKey = getKey();
			//usart_send('1');
			usart_send(customKey);
		}else if(PINB & (1<<4)){
			col = 2;
			customKey = getKey();
			//usart_send('2');
			usart_send(customKey);
		}else if(PINB & (1<<5)){
			col = 3;
			customKey = getKey();
			//usart_send('3');
			usart_send(customKey);
		}else{}
		//usart_send('M');*/
	}

  return 0;
}
