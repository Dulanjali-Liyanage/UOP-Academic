#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc,char **argv){
	int rout;
	int wout;
	size_t size = 20;	

	if(argc != 3){
		printf("Usage : %s <Source_file_name.txt> <Target_file_name.txt>",argv[0]);
		return 0;
	}

	//Reading the source file
	rout = open(argv[1],O_RDONLY);

	if(rout == -1){
		fprintf(stderr,"Couldn't open the file\n");
		return 1;
	}

	char* buffer = malloc(size+1);

	size_t ret = read(rout,buffer,size);

	if(ret == -1){
		fprintf(stderr,"Error reading from file");
		return 1;
	}

	buffer[ret] = '\0';

	ret = close(rout);

	if(ret == -1){
		fprintf(stderr,"Error closing the file after writing\n");
		return 1;
	}

	//Writing to the targetted file
	wout = open(argv[2],O_WRONLY | O_TRUNC | O_CREAT,S_IRUSR | S_IWUSR);

	if(wout == -1){
		fprintf(stderr,"Couldn't open the file for writing\n");
		return 1;
	}

	ret = write(wout,buffer,size);

	if(ret == -1){
		fprintf(stderr,"Error writing to the file\n");
		return 1;
	}

	ret = close(wout);

	if(ret == -1){
		fprintf(stderr,"Error closing the file after writing\n");
		return 1;
	}

	free(buffer);	

	return 0;
}