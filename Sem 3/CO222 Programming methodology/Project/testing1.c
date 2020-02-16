#include <stdio.h>

int main(){
	FILE *ifp;
	char a;

	ifp = fopen("grid.txt","r");

	while(a != EOF){
		a = fgetc(ifp);
		printf("%c",a);
	}


	return 0;
}