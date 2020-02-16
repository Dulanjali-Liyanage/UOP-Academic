/* Sample TCP client */
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
#include <stdio.h> 
#include <string.h>
#include <stdlib.h> 

int main(int argc, char**argv) { 

	int sockfd,n; 
	struct sockaddr_in servaddr; 
	char msgreq[10000];
	char buffer[10000];
	char msgcont[1000];
	char filesize[10000];
	FILE *fp; 

	if (argc != 2) { 
		printf("usage:  ./%s <IP address>\n",argv[0]); 

		return -1; 
	} 

	/* socket to connect */ 
	sockfd=socket(AF_INET,SOCK_STREAM,0); 

	/* IP address information of the server to connect to */
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr=inet_addr(argv[1]); 
	servaddr.sin_port=htons(32000); 
	connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	gets(msgreq); 


       	fp = fopen("fileclient.txt","a");
	
	sendto(sockfd,msgreq,strlen(msgreq),0, (struct sockaddr *)&servaddr,sizeof(servaddr)); 

	n=recvfrom(sockfd,buffer,10000,0,NULL,NULL); 
	buffer[n]=0;

	printf("Received file size: ");

	int i;
	for(i = 0;buffer[i] != '\n';i++){
		msgcont[i] = buffer[i];
		printf("%c",msgcont[i]);
	}
	printf("\n");
	

       	fprintf(fp,"%s",buffer);
       	fclose(fp);

	return 0; 

}