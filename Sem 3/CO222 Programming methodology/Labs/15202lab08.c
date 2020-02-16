#include <stdio.h>
#include <stdlib.h>

int main(int argc,char** argv){

	int width = atoi(argv[1]);

	int x;

	char check[20];
	FILE *ofp = fopen(argv[2],"r");




	if((argc > 3) || (argc < 3)){
		printf("Usage: %s <width> <input-file>\n",argv[0]);
		return 0;
	}

	if(ofp == NULL){
		printf("Segmentation fault (core dumped)\n");
		return 0;
	}


	while(fscanf(ofp,"%s",check) != EOF){
		int j = snprintf(NULL,0,"%s",check);

		if(width < j){
			printf("Word length must be less than screen width\n");
			return 0;
		}
	}
	fclose(ofp);

	FILE *ifp = fopen(argv[2],"r");

	while(fgetc(ifp) != EOF){

		fseek(ifp,-1,SEEK_CUR);//move the file pointer one step back

		char line[width+2];
		char a;
		int i;
		line[width] = '*';

		for(i = 0;i < width;i++){
			line[i] = fgetc(ifp);

			if(line[i] == '\n'){
				x = 1;
				fseek(ifp,-1,SEEK_CUR);//move the file pointer one step back
				line[i+1] = '*';
				break;
			}
			x = 0;
		}

		a = fgetc(ifp);

		if((a == ' ') || (a == '\n') || (line[i-1] == ' ')){
			int j;
			for(j = 0;line[j] != '*';j++){
				printf("%c",line[j]);
			}

			if(x == 0){
				printf("\n");
			}


			fseek(ifp,-1,SEEK_CUR);//move the file pointer one step back


			if((a == ' ') || (a == '\n')){
				fseek(ifp,1,SEEK_CUR);//move the file pointer one step forward
			}

		}else{

			if(a == EOF){
				int j;
				for(j = 0;line[j] != '*';j++){
					printf("%c",line[j]);
				}
			}else{
				int k;
				for(k = i;line[k] != ' ';k--){}

				line[k+1] = '*';

				int j;
				for(j = 0;line[j] != '*';j++){
					printf("%c",line[j]);
				}

				printf("\n");

				fseek(ifp,-(i-k),SEEK_CUR);//move the file pointer (i-k) step back
			}

		}
	}

	fclose(ifp);

	return 0;
}