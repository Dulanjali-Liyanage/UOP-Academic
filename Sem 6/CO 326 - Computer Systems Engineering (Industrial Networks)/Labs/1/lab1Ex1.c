#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>

#define DATA_PORT 0x378
#define STATUS_PORT DATA_PORT+1
#deifne CONTROL_PORT DATA_PORT+2

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


	unsigned char arr[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F};
	unsigned char p2 = 0x00;

	while(1){
		int i;
		for(i = 0; i < 10;i++){
			p2 = arr[i];
			data = (1<<7) | ~p2;
			outb(data,DATA_PORT);
			sleep(2);
		}
	}
}