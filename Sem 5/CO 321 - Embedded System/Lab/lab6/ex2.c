#include <avr/io.h>

//#define USART_BAUDRATE 9600
//#define BAUD_PRESCALE (((16000000 / (USART_BAUDRATE * 16))) - 1)

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

void putStr(char *string){
	while(*string){
		usart_send(*string++);
	}
}

int main(){
	
	usart_init();
	int x = 0;
	
	while(x < 3){

		if(x == 0){
			putStr("Dinithi E/15/119\n");
		}else if(x == 1){
			putStr("Dulanjali E/15/202\n");
		}else{
			putStr("Roshani E/15/208\n");
		}
		x++;

	}

	/*while(1){
		char receivedByte = usart_receive();
		usart_send(receivedByte);
	}*/

	return 0;
}