#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>

const int PORT = 0x210;
const int LENGTH = 2;

//output
void write_port(void){

	int port,data;
	while(1){
		printf("\nEnter port address to WRITE TO: ");
		scanf("%x",&port);
		if(port <0){
			return;
		}

		if(port<PORT || port > PORT+LENGTH){
			printf("\tERR: Port address out of range 0x%x - 0x%x",PORT,PORT+LENGTH);
		}else{
			printf("Enter data: ");
			scanf("%x",&data);
			outb(data,port); //output
		}
	}
}

//input
void read_port(void){
	int port,data;
	while(1){
		printf("\nEnter port address to READ FROM: ");
		scanf("%x",&port);
		if(port <0){
			return;
		}
		if(port<PORT || port > PORT+LENGTH){
			printf("\tERR: Port address out of range 0x%x - 0x%x",PORT,PORT+LENGTH);
		}else{
			//input
			data = inb(port);
		}
	}
}

void main(){

	if(ioperm(PORT,LENGTH+1,1)){
		fprintf(stderr,"Access denied to %x\n",PORT),
		exit(1);
	}

	read_port();
	write_port();
}