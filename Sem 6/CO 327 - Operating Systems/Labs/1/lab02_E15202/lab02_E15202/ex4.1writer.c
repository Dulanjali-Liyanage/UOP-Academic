#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdio.h>

int main(){ 
    	int fdu,fdc; 
    	char * fifoUser = "/tmp/fifoUser";
	char * fifoCapital = "/tmp/fifoCapital";
	char inputstr[1024];
	char buf[1024];

	printf("Enter the string : ");

	fgets(inputstr,100,stdin);

    	mkfifo(fifoUser,0666); 
    	fdu = open(fifoUser, O_WRONLY); 
    	write(fdu, inputstr,1024);

	close(fdu);

	mkfifo(fifoCapital,0666);
	fdc = open(fifoCapital, O_RDONLY); 	
	read(fdc, buf, 1024); 
    	printf("\nmessage read = %s\n", buf);

    	
	close(fdc); 

    	unlink(fifoUser); 
	unlink(fifoCapital); 

    return 0; 
}
