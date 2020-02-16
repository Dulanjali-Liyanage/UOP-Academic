#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main(){
	char input[LINE_MAX];
	File *ifp = fopen("text.txt","w");

	if(ifp == NULL){
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	while (fgets(input,LINE_MAX,stdin) != NULL){
		if(input[0] == '\n'){
			break;
		}

		fprintf(ifp,"%s",input);
	}

	fclose(ifp);

	return 0;
}