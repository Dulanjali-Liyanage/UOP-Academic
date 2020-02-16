#include <sys/socket.h>
#include <netinet/in.h> 
#include <strings.h> 
#include <stdio.h> 
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void delay(int mili_sec){
	clock_t start_time = clock();
	
	while(clock() < start_time + mili_sec);
}

void ToUp ( char *p ){
	while( *p ){
		*p=toupper( *p );
		p++;
	}
	
}

int main(int argc, char**argv) { 

	int sockfd,n; 
	struct sockaddr_in servaddr, cliaddr; 
	socklen_t len; 
	char mesg[1000];
	char num[1000];

	char* ack = "ack";

	
	
	sockfd=socket(AF_INET,SOCK_DGRAM,0); 
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(32000);
	bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr)); 
	
	
	len = sizeof(cliaddr);
	n = recvfrom(sockfd,num,sizeof(num),0,(struct sockaddr *)&cliaddr,&len);
	num[n] = 0; 
	sendto(sockfd,ack,1000,0,(struct sockaddr *)&cliaddr,sizeof(cliaddr));
		
		
	int noOfLines = atoi(num);


	
	int i;
	for(i = 0;i < noOfLines;i++){

		
		len = sizeof(cliaddr);
		n = recvfrom(sockfd,mesg,1000,0,(struct sockaddr *)&cliaddr,&len);
		mesg[n] = 0;
		
		
		ToUp(mesg);
		sendto(sockfd,mesg,1000,0,(struct sockaddr *)&cliaddr,sizeof(cliaddr));
		
	}

	
	return 0; 

}