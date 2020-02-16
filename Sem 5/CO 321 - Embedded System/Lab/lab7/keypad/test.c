#include <avr/io.h>
#include <util/delay.h>


char keyMap[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

void usart_init(){
  UBRR0 = 103; // 9600 baud rate // 9600 = 16*(10^6)/16*(UBRR+1)
  UCSR0C &= ~(1 << UMSEL01) & ~(1 << UMSEL00); // select the Asynchronous mode
  UCSR0C &= ~(1 << UPM01) & ~(1 << UPM00); // no parity
  UCSR0C &= ~(1 << USBS0); // 1 stop bit
  UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00); // 8 bit data

  UCSR0B |= (1 << TXEN0); // enable the USART transmitter

  UCSR0B |= (1 << RXEN0); // enable the USART receiver

  //UBRR0L = BAUD_PRESCALE;   /* Load lower 8-bits of the baud rate value */
  //UBRR0H = (BAUD_PRESCALE >> 8);  /* Load upper 8-bits*/
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


void Col_init(void)
{
  DDRB = 0xF0;  // bit 0.3 are columns (0 is input)
  PORTB = 0x0F;  //pullups on these bits 

  DDRC = 0b01111000;  // bit 3..6 used for rows
  DDRD = DDRD | (1<<6);
  
  PORTC = 0x00;
  PORTD &= ~(1<<6); // PD6 used for row
  //very short delay
  asm volatile ("nop");  
  asm volatile ("nop"); 
}

void Row_init(void)
{
  DDRC = 0b00000111;  // bit 3..5 used for rows
  DDRD &= ~(1<<6);  // PD6 used for row
  
  PORTC = 0b01111000;
  PORTD = DDRD | (1<<6); 
  
  DDRB = 0x0F;
  PORTB = 0x00;
  _delay_ms(1);
}

unsigned char Read_key(void){
  unsigned char col,row;	
  
  Col_init();      //set up columns to read
 
  col=10; row=10;       // init value

	// read columns first - 0 if key in that column pressed
	if (!(PINB & (1<<0))) 
			    {col = 0; }  // Col2 = bit0 is low
  else if (!(PINB & (1<<1))) 
			    {col = 1;}   // Col1 = bit1 is low
  else if (!(PINB & (1<<2))) 
          {col = 2; }  // Col0 = bit2 is low 
  else if (!(PINB & (1<<3))) 
          {col = 3; }  // Col0 = bit2 is low 

  Row_init();   //set up rows to read
				
			
  if (!(PINC & (1<<3))) 
          {row = 0; }  // Col2 = bit0 is low
  else if (!(PINC & (1<<4))) 
          {row = 1;}   // Col1 = bit1 is low
  else if (!(PINC & (1<<5))) 
          {row = 2; }  // Col0 = bit2 is low 
  else if (!(PIND & (1<<6))) 
          {row = 3; }  // Col0 = bit2 is low 
    
	_delay_ms(50); // switch debounce 
  if (col==10 | row==10)
    return;
	return keyMap[row][col];  // value is sum of row and column   
}

int main(){
  usart_init();
  unsigned char read_val;
  // get keypad value and set the state
 
  while(1){
     Col_init();
    if ((PINB != 0xF0)) {   // if a column is pressed bit 0,1,2 or 3 will go low active 0
        read_val= Read_key();   // read keypad    
        _delay_ms(100);
        usart_send(read_val);       
    } 
  }

  return 0;
}