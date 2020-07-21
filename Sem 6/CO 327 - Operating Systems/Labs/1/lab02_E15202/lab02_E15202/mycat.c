#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(){

	char ch;
	FILE *fp;

	fp = fopen("filename.txt","r");

	if(fp == NULL){
		perror("Error while opening the file\n");
		return 0;
	}

	while((ch = fgetc(fp)) != EOF){
		printf("%c",ch);
	}
	
	fclose(fp);

	return 0;
}