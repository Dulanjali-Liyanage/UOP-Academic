/*************************************************************************
Title:    Testing output to a HD44780 based LCD display.
Author:   Peter Fleury  <pfleury@gmx.ch>  http://tinyurl.com/peterfleury
File:     $Id: test_lcd.c,v 1.8 2015/01/31 18:04:08 peter Exp $
Software: AVR-GCC 4.x
Hardware: HD44780 compatible LCD text display
          AVR with external SRAM interface if memory-mapped LCD interface is used
          any AVR with 7 free I/O pins if 4-bit IO port mode is used
**************************************************************************/
#include <stdlib.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "lcd.h"

#define KEY_ADDR 0

void EEPROMwrite(unsigned int address, char data){

  // wait for completion of previous write
  while (EECR & (1<<EEPE));

  // set up address and data regs
  EEAR = address;
  EEDR = data;

  // write logical 1 to EEMPE
  EECR |= (1<<EEMPE)

  // start eeprom write
  EECR |= (1<<EEPE);
}

char EEPROMread(unsigned int address){

  // wait for completion of previous write
  while (EECR & (1<<EEPE));

  // set up address
  EEAR = address;

  // start eeprom read
  EECR |= (1<<EERE);

  return EEDR;
}



char keyMap[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

void Col_init(void)
{
  DDRB = 0xF0;  // bit 0.3 are columns (0 is input)
  PORTB = 0x0F;  //pullups on these bits 

  DDRC = 0x0F;
  PORTC = 0x00;
  //very short delay
  asm volatile ("nop");  
  asm volatile ("nop"); 
}

void Row_init(void)
{
  DDRC = 0xF0;  // bit 3..6 used for rows
  PORTC = 0x0F;  //pullups on these bits 
  DDRB = 0x0F;
  PORTB = 0x00;
  _delay_ms(1);
}

unsigned char Read_key(void){
  unsigned char col,row;	
  
  Col_init();      //set up columns to read
 
  col=10; row=10;       // init value

	// read columns first - 0 if key in that column pressed
	if (!(PINB & 0x01)) 
			    {col = 0; }  // Col2 = bit0 is low
  else if (!(PINB & 0x02)) 
			    {col = 1;}   // Col1 = bit1 is low
  else if (!(PINB & 0x04)) 
          {col = 2; }  // Col0 = bit2 is low 
  else if (!(PINB & 0x08)) 
          {col = 3; }  // Col0 = bit2 is low 

  Row_init();   //set up rows to read
				
			
  if (!(PINC & 0x01)) 
          {row = 0; }  // Col2 = bit0 is low
  else if (!(PINC & 0x02)) 
          {row = 1;}   // Col1 = bit1 is low
  else if (!(PINC & 0x04)) 
          {row = 2; }  // Col0 = bit2 is low 
  else if (!(PINC & 0x08)) 
          {row = 3; }  // Col0 = bit2 is low 
    
	_delay_ms(50); // switch debounce 
  if (col==10 | row==10)
    return 'H';
	return keyMap[row][col];  // value is sum of row and column   
}


int main(void)
{
  Col_init();
  char buffer[17];
  int  key=0;
  unsigned char read_val;
  
  /* initialize display, cursor off */
  lcd_init(LCD_DISP_ON);

  // load key at startup
  key = (int) EEPROMread(KEY_ADDR);

  int state = 0;
  int i;

  for (;;) {
	
  	switch (state){
  	
  	  case 0: // No option selected
          
      	/* clear display and home cursor */
        lcd_clrscr();
              
      	lcd_puts("1.Set Key\n");
        lcd_gotoxy(0,1);  
      	lcd_puts("2.Enter String\n");
        _delay_ms(100);
      	
      	// get keypad value and set the state
        Col_init();
      	while(1){
          if (!(PINB == 0x0F)) {      // if a column is pressed bit 0,1,2 or 3 will go low active 0
      		  read_val= Read_key();   // read keypad		
            _delay_ms(100);
            break;      		
      	  } 
        }
      	if (read_val=='1'){
          state = 1;
        }else if (read_val=='2'){
          state = 2;
        }
      	break;

  	case 1: // Input the key value
        lcd_clrscr();
        /* turn on cursor */
        lcd_command(LCD_DISP_ON_CURSOR);
	
      	i=0;
  	    // get keypad value and increment the cursor while displaying and storing in buff	
        while (i<3){
          Col_init();
          while(1){
            if (!(PINB == 0x0F)) {      // if a column is pressed bit 0,1,2 or 3 will go low active 0
              read_val= Read_key();   // read keypad    
              _delay_ms(100);
              break;          
            }
          }
          if (!((read_val>='0') & (read_val<='9')))
            continue;
          lcd_putc(read_val);
          buffer[i] = read_val;
          i++;
          lcd_gotoxy(i,0); 
        }
        buffer[i] = 0;

          
  	    //convert buff the integer and put it to key variable
        key = atoi(buffer);

        _delay_ms(100);


        lcd_gotoxy(0,0);
        lcd_puts("Key set!");
        lcd_gotoxy(0,1);
        lcd_puts(buffer);
        _delay_ms(500);


        //save it in EEPROM
        EEPROMwrite(KEY_ADDR, (char)key);

        state = 0;
        break;

  	case 2: // geting the input string

  	    lcd_clrscr();
        /* turn on cursor */
        lcd_command(LCD_DISP_ON_CURSOR);
  
        i=0;
        // get keypad value and increment the cursor while displaying and storing in buff 
        while (i<16){
          Col_init();
          while(1){
            if (!(PINB) & 0x0F) {      // if a column is pressed bit 0,1,2 or 3 will go low active 0
              read_val= Read_key();   // read keypad
              _delay_ms(100);
              break;          
            }
          }
          if (read_val=='H')
            continue;
          lcd_putc(read_val);
          buffer[i] = read_val;
          i++;
          lcd_gotoxy(i,0); 
        }
        buffer[i] = 0;

        //cypher the string
        i=0;
        while (buffer[i]){
          buffer[i++]+=key;
        }

        //display cipher text
        lcd_clrscr();
        lcd_puts("Cipher text");
        lcd_gotoxy(0,1);
        lcd_puts(buffer);


        /* turn off cursor */
        lcd_command(LCD_DISP_ON);
        _delay_ms(1000);
        state = 0;
        break;
  	}
	             
  }

}