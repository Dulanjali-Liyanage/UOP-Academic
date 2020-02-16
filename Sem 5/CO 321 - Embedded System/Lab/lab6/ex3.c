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

char caeser_cipher(char encryp_char){
	int customCode;
	int cipherVal;
	int ascii_char = (int)encryp_char; // convert to the ascii value

	if(ascii_char >= 65 && ascii_char <= 90){ // check whether the character is in alphabet(capital)
		customCode = ascii_char - 65; // to take to the 0-25 code range and can use 26
		cipherVal = (customCode + 3)%26;//encrypt with caeser cipher
		return (char)(cipherVal + 65); // make it a ascii value
		
	}else if(ascii_char >= 97 && ascii_char <= 122){// check whether the character is in alphabet(simple)
		customCode = ascii_char - 97;// to take to the 0-25 code range and can use 26
		cipherVal = (customCode + 3)%26;//encrypt with caeser cipher
		return (char)(cipherVal + 97);// make it a ascii value
	}
	return encryp_char; // if it is not in the alphabet do not add encryption
}

int main(){
	usart_init();
	char receivedByte;
	char encryp_char;
	while(1){
		receivedByte = usart_receive();
		encryp_char = caeser_cipher(receivedByte);
		usart_send(encryp_char);
	}
	return 0;
}