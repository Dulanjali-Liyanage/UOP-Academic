#include <stdlib.h>
#include <string.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "lcd.h"


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

char keyMap[4][4] = {
  	{'1','2','3','A'},
  	{'4','5','6','B'},
  	{'7','8','9','C'},
  	{'*','0','#','D'}
};

void Col_init(void){
  	DDRB = 0xF0;  // bit 0.3 are columns (0 is input)
  	PORTB = 0x0F;  //pullups on these bits

  	DDRC = 0b01111000;  // bit 3,4,5 used for rows
  	DDRD = DDRD | (1<<6); // PD6 for row

  	PORTC = 0x00;
  	PORTD &= ~(1<<6); // PD6 used for row
  	//very short delay
  	asm volatile ("nop");
  	asm volatile ("nop");

  	_delay_ms(5);
}

void Row_init(void){
  	DDRC = 0b00000111;  // bit 3..5 used for rows
  	DDRD &= ~(1<<6);  // PD6 used for row

  	PORTC = 0b01111000;
  	PORTD = PORTD | (1<<6);

  	DDRB = 0x0F;
  	PORTB = 0x00;
  	_delay_ms(5);
}

unsigned char Read_key(void){
  	unsigned char col,row;

  	Col_init();      //set up columns to read

  	col = 10; row = 10;       // init value

	// read columns first - 0 if key in that column pressed
	if (!(PINB & (1<<0))){

		col = 0;

	}
  	else if (!(PINB & (1<<1))){

  		col = 1;

  	}
  	else if (!(PINB & (1<<2))){

  		col = 2;
  	}
  	else if (!(PINB & (1<<3))){

  		col = 3;

  	}

  	Row_init();   //set up rows to read


  	if (!(PINC & (1<<3))){

  		row = 0;

  	}
  	else if (!(PINC & (1<<4))){

  		row = 1;

  	}
  	else if (!(PINC & (1<<5))){

  		row = 2;

  	}
  	else if (!(PIND & (1<<6))){

  		row = 3;

  	}

	_delay_ms(500); // switch debounce
  	if (col==10 | row==10){
   	 	return 'H';
  	}
	return keyMap[row][col];
}


char caeser_cipher(char encryp_char,int key){
	int customCode;
	int cipherVal;
	int ascii_char = (int)encryp_char; // convert to the ascii value

	if(ascii_char >= 65 && ascii_char <= 90){ // check whether the character is in alphabet(capital)

		customCode = ascii_char - 65; // to take to the 0-25 code range and can use 26

		cipherVal = (customCode + key)%26;//encrypt with caeser cipher

		return (char)(cipherVal + 65); // make it a ascii value

	}
	return encryp_char; // if it is not in the alphabet do not add encryption
}

int main(){

	unsigned char read_val;
	char key_val[2];
	int key;
	char val;
	char encryp_char[10];
	char read_key;

	/* initialize display, cursor off */
    lcd_init(LCD_DISP_ON);

    for(;;){/* loop forever */

    	/* clear display and home cursor */
        lcd_clrscr();

        /* put string to display (line 1) with linefeed */
        lcd_puts("1.Encryp String\n");

        lcd_gotoxy(0,1); // move to next  line

        lcd_puts("2.Set Key\n");

        _delay_ms(100);

        Col_init();
        while(1){
    		if ((PINB != 0xF0)) {   // if a column is pressed bit 0,1,2 or 3 will go low active 0
    			read_val = Read_key();   // read keypad
    			if(read_val != 'H'){

        			/* initialize display, cursor off */
    				lcd_init(LCD_DISP_ON);

					/* clear display and home cursor */
        			lcd_clrscr();

        			lcd_putc(read_val);

        			break;
        		}
    		}
    	}

        _delay_ms(1000);

    	if(read_val == '2'){

			lcd_init(LCD_DISP_ON);

			lcd_clrscr();

			lcd_puts("Enter Key : ");

        	Col_init();
        	while(1){

    			if ((PINB != 0xF0)) {   // if a column is pressed bit 0,1,2 or 3 will go low active 0
    				read_key = Read_key();   // read keypad
    				if(read_key != 'H'){

						/* turn on cursor */
        				lcd_command(LCD_DISP_ON_CURSOR);

						lcd_gotoxy(12,0);

        				lcd_putc(read_key);

        				break;
        			}
    			}
    		}


    		EEPROMwrite(40,read_key);

    		_delay_ms(2000);
    	}

    	lcd_init(LCD_DISP_ON);

    	if(read_val == '1'){
    		key_val[0] = EEPROMread(40);
    		key_val[1] = '\0';

    		key = atoi(key_val); // convert the string to an integer

    		lcd_init(LCD_DISP_ON);

    		/* clear display and home cursor */
        	lcd_clrscr();

        	lcd_puts("Enter String : \n");

    		Col_init();
    		int i = 0;
        	while(1){

    			if ((PINB != 0xF0)) {   // if a column is pressed bit 0,1,2 or 3 will go low active 0
        			val = Read_key();   // read keypad

        			if(val != 'H'){
        				if(val == '*'){
        					break;
        				}

						/* turn on cursor */
        				lcd_command(LCD_DISP_ON_CURSOR);

        				lcd_gotoxy(i,1); // move to next  line

        				lcd_putc(val);

        				encryp_char[i] = caeser_cipher(val,key);

        				i++;

        				_delay_ms(200);
        			}

    			}
    		}

    		lcd_init(LCD_DISP_ON);

    		encryp_char[i] = '\0';

    		_delay_ms(100);

    		/* clear display and home cursor */
        	lcd_clrscr();

        	lcd_puts("Caeser Cipher :");

        	lcd_gotoxy(0,1);

        	lcd_puts(encryp_char);

        	_delay_ms(3000);
    	}
    }

	return 0;
}