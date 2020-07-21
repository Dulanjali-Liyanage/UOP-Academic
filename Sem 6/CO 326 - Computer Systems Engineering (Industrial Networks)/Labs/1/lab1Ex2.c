#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>

#define DATA_PORT 0x378
#define STATUS_PORT DATA_PORT+1
#define CONTROL_PORT DATA_PORT+2

unsigned char status,data;

void main(){
	if(ioperm(DATA_PORT,1,1)){
		fprintf(stderr,"Access denied to %x\n",DATA_PORT),
		exit(1);
	}

	if(ioperm(STATUS_PORT,1,1)){
			fprintf(stderr,"Access denied to %x\n",STATUS_PORT),
			exit(1);
	}

	status = inb(STATUS_PORT);


	unsigned char arr[10] = {0b0000,0b0001,0b0010,0b0011,0b0100,0b0101,0b0110,0b0111,0b1000,0b1001};
	unsigned char p2;

	while(1){
		int i;
		for(i = 0; i < 10;i++){
			p2 = arr[i];
			data = (1<<5) |(1<<4)| p2;
			outb(data,DATA_PORT);
			sleep(2);
		}
	}
}