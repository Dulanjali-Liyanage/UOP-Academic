#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define READ_END 0
#define WRITE_END 1

void parent(int* pipe1,int* pipe2){
	char userstr[100];
	char usercapital[100];

	printf("PARENT : Enter a string : ");
	fgets(userstr,100,stdin);

	printf("\nPARENT : User string : %s",userstr);
		
	close(pipe1[READ_END]);
	write(pipe1[WRITE_END],userstr,strlen(userstr));
	
	close(pipe2[WRITE_END]);
	int n = read(pipe2[READ_END],usercapital,strlen(usercapital));
	usercapital[n] = '\0';
	printf("\nPARENT : Capitalized string : %s",usercapital);
}

void child(int* pipe1,int* pipe2){
	close(pipe1[WRITE_END]);
	char usersimple[100];
	int n = read(pipe1[READ_END],usersimple,strlen(usersimple));
	usersimple[n] = '\0';
		
	printf("\nCHILD : Child read string : %s",usersimple);

	int j = 0;
	char ch;
	while(usersimple[j]){
		ch = usersimple[j];
		usersimple[j] = toupper(ch);
		j++;
	}

	printf("\nCHILD : Child capitalized string : %s",usersimple);

	close(pipe2[READ_END]);
	write(pipe2[WRITE_END],usersimple,strlen(usersimple));
}	

int main(){
	int pipe1[2]; // parent write child read
	int pipe2[2]; // child write parent read
	pid_t pid;
	
	if(pipe(pipe1)){
		perror("Pipe 1 creation");
		return -1;
	}

	if(pipe(pipe2)){
		perror("Pipe 2 creation");
		return -1;
	}

	pid = fork();

	if(pid < 0){
		perror("Fork");
		return -1;
	
	}

	if(pid > 0){ // parent
		parent(pipe1,pipe2);
	
	}

	if(pid == 0){//child
		child(pipe1,pipe2);	

	}

	return 0;
}