#include <sys/socket.h> 
#include <netinet/in.h>
#include <arpa/inet.h> 
#include <stdio.h> 
#include <string.h>
#include <stdlib.h> 

int main(int argc, char**argv) { 
	int sockfd,n; 
	struct sockaddr_in servaddr; 
	char sendline[1000];
	char sendnum[1000]; 
	char recvline[1000];
	int noOfLines; 

	if (argc != 2) { 
		printf("usage:  ./%s <IP address>\n",argv[0]); return -1;

	} 

	scanf("%d",&noOfLines);
	snprintf(sendnum,sizeof(sendnum),"%d",noOfLines);
	

	sockfd=socket(AF_INET,SOCK_DGRAM,0);

	bzero(&servaddr,sizeof(servaddr)); 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr=inet_addr(argv[1]); 
	servaddr.sin_port=htons(32000); 
	sendto(sockfd,sendnum,strlen(sendnum),0,(struct sockaddr *)&servaddr,sizeof(servaddr));

	n=recvfrom(sockfd,recvline,1000,0,NULL,NULL); 
	recvline[n]=0; 
	printf("Received: %s\n",recvline);

	gets(sendline);
	

	int i;
	for(i = 0;i < noOfLines;i++){
		
		gets(sendline);

		sockfd=socket(AF_INET,SOCK_DGRAM,0); 
	
		bzero(&servaddr,sizeof(servaddr)); 
		servaddr.sin_family = AF_INET; 
		servaddr.sin_addr.s_addr=inet_addr(argv[1]); 
		servaddr.sin_port=htons(32000); 
		sendto(sockfd,sendline,strlen(sendline),0,(struct sockaddr *)&servaddr,sizeof(servaddr));

		n=recvfrom(sockfd,recvline,1000,0,NULL,NULL); 
		recvline[n]=0; 
		printf("Received: %s\n",recvline);

	}
	
	return 0; 
}