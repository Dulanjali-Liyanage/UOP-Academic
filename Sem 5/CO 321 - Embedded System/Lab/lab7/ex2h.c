#include <avr/io.h>
#include <avr/eeprom.h>

void usart_init(){
	UBRR0 = 103; // 9600 baud rate // 9600 = 16*(10^6)/16*(UBRR+1)
	UCSR0C &= ~(1 << UMSEL01) & ~(1 << UMSEL00); // select the Asynchronous mode
	UCSR0C &= ~(1 << UPM01) & ~(1 << UPM00); // no parity
	UCSR0C &= ~(1 << USBS0); // 1 stop bit
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00); // 8 bit data

	UCSR0B |= (1 << TXEN0); // enable the USART transmitter

	UCSR0B |= (1 << RXEN0); // enable the USART receiver

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


void EEPROMwrite(unsigned int address,char data){

	//wait for completion of prevoius write
	while(EECR & (1<<EEPE));

	//set up address and data regs
	EEAR = address;
	EEDR = data;

	//write logical 1 to EEMPE
	EECR |= (1<<EEMPE);

	//start eeprom write
	EECR |= (1<<EEPE);
}


char EEPROMread(unsigned int address){

	//wait for complettion of writes
	while(EECR & (1<<EEPE));

	//set up address
	EEAR = address;

	//start eeprom read
	EECR |= (1<<EERE);

	//return data
	return EEDR;
}

int main(){

	usart_init();

	unsigned int j;
	for(j = 0; j < 1024; j++){
		usart_send(EEPROMread(j));
	}
	

	return 0;
}