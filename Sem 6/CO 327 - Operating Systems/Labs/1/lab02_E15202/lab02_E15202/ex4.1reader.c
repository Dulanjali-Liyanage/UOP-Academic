#include <fcntl.h> 
#include <stdio.h> 
#include <sys/stat.h> 
#include <unistd.h> 

#define MAX_SIZE 1024 

int main(){ 
	int fdu,fdc; 
	char * fifoUser = "/tmp/fifoUser";
	char * fifoCapital = "/tmp/fifoCapital"; 

	char *tr_args[] = {"tr", "[:lower:]","[:upper:]",NULL}; 

	mkfifo(fifoUser,0666);
	mkfifo(fifoCapital,0666);

	fdu = open(fifoUser, O_RDONLY); 
	dup2(fdu,0);
	fdc = open(fifoCapital, O_WRONLY);
	dup2(fdc,1);

	execvp("tr",tr_args);	
	   
	close(fdu);
	close(fdc);

    return 0; 
}

