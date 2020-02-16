#include <avr/io.h>
#include <avr/eeprom.h>
#include <util/delay.h>

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
	EECR |= (1<<EEMPE); // when EEMPE set to 1 by software hardware clears the bit after 4 clock cycles

	//when EEPE is cleared EERIE is set to avoid any interrupt keep the SREG I bit disable

	//start eeprom write
	EECR |= (1<<EEPE);//when write access time has elapsed, the EEPE is cleared by the software
}


char EEPROMread(unsigned int address){

	//wait for complettion of writes
	while(EECR & (1<<EEPE));

	//set up address
	EEAR = address;

	//start eeprom read
	EECR |= (1<<EERE); // hardware clears the EERE

	//return data
	return EEDR;
}

int main(){

	usart_init();
	
	char str[1024];
	unsigned int x = 0;

	unsigned int j = 0;

	while(1){
		char receivedByte = usart_receive();
		unsigned int i = 0;
		while(receivedByte != '\n'){
			str[i] = receivedByte;
			receivedByte = usart_receive();
			i++;		
		}

		str[i] = receivedByte; //to get the '\n'

		if(j == 1024){
			j = 0;
			x = 0; //x used to get the j value 0 to i range as i always start from 0
		}
	
		while(j-x <= i){
			usart_send(str[j-x]);
			EEPROMwrite(j,str[j-x]);
			j++;
		}

		x = j;
	}	

	return 0;
}