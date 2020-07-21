#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>

#define DATA_PORT 0x378
#define STATUS_PORT DATA_PORT+1
#define CONTROL_PORT DATA_PORT+2


unsigned char status,data;
int count=0;

void main(){
printf("here");
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


	//p2 = arr[0];
	//data = (1<<5) |(1<<4)| p2;
	//outb(data,DATA_PORT);

	//sleep(1);

	while(1){

	status = inb(STATUS_PORT);
	printf("%d \n",(status & 0b00001000));
	if ((status & 0b00001000)/8==1 ){
		count++;
		printf("count %d\n",count);
		p2 = arr[count%10];
		
		outb(count%10,DATA_PORT);

		while((status & 0b00001000)/8==1)
		status = inb(STATUS_PORT);
		//sleep(1);
	
		
	}


	sleep(1);	
		
			
		
	}
}