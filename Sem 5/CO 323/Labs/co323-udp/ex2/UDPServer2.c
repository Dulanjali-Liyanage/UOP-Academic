#include <sys/socket.h>
#include <netinet/in.h> 
#include <strings.h> 
#include <stdio.h> 
#include <time.h>
#include <stdlib.h>

void delay(int mili_sec){
	clock_t start_time = clock();
	
	while(clock() < start_time + mili_sec);
}

int main(int argc, char**argv) { 

	int sockfd,n; 
	struct sockaddr_in servaddr, cliaddr; 
	socklen_t len; 
	char mesg[1000];
	char buff[1024];
	time_t tick;

	char* banner = "Hello UDP client! This is UDP server";
	
	
	
		sockfd=socket(AF_INET,SOCK_DGRAM,0); 
		servaddr.sin_family = AF_INET;
		servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
		servaddr.sin_port=htons(32000);
		bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr)); 
	
	

	//echo server
	while(1){ 
		len = sizeof(cliaddr);
		n = recvfrom(sockfd,mesg,1000,0,(struct sockaddr *)&cliaddr,&len); 
		sendto(sockfd,mesg,n,0,(struct sockaddr *)&cliaddr,sizeof(cliaddr));
		mesg[n] = 0;
		printf("Received: %s\n",mesg); 
	
	}

	

	return 0; 

}