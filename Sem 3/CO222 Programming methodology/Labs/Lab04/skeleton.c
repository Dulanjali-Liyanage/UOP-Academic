#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define RESET		0
#define BRIGHT 		1

#define BLACK 		0
#define RED		1
#define GREEN		2
#define YELLOW		3
#define BLUE		4
#define MAGENTA		5
#define CYAN		6
#define	WHITE		7

void textcolor(int attr, int fg, int bg);

void textcolor(int attr, int fg, int bg)
{	char command[13];

	/* Command is the control command to the terminal */

	/* textcolor(BRIGHT,BLACK,WHITE) will have characters printed in
	black in white background */
	sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
	printf("%s",command);

	
}





int main(int argc, char **argv){


	if(argc < 4){
		puts("Not enough arguments");
		return 0;
	}else if(argc > 4){
		puts("Too many arguments");
		return 0;
	}




	if(strcmp("checker",argv[1]) != 0){
		if(strcmp("donut",argv[1]) != 0){
			puts("Requested figure is not available");
			return 0;
		}
	}

	
	int a,b;

	
	if(strcmp("black",argv[2]) == 0){
		a = 0;
	}else if(strcmp("red",argv[2]) == 0){
		a = 1;
	}else if(strcmp("green",argv[2]) == 0){
		a = 2;
	}else if (strcmp("yellow",argv[2]) == 0){
		a = 3;
	}else if(strcmp("blue",argv[2]) == 0){
		a = 4;
	}else if(strcmp("magenta",argv[2]) == 0){
		a = 5;
	}else if(strcmp("cyan",argv[2]) == 0){
		a = 6;
	}else if(strcmp("white",argv[2]) == 0){
		a = 7;
	}else{
		puts("Background color is not available");
		return 0;
	}




	
	if(strcmp("black",argv[3]) == 0){
		b = 0;
	}else if(strcmp("red",argv[3]) == 0){
		b = 1;
	}else if(strcmp("green",argv[3]) == 0){
		b = 2;
	}else if (strcmp("yellow",argv[3]) == 0){
		b = 3;
	}else if(strcmp("blue",argv[3]) == 0){
		b = 4;
	}else if(strcmp("magenta",argv[3]) == 0){
		b = 5;
	}else if(strcmp("cyan",argv[3]) == 0){
		b = 6;
	}else if(strcmp("white",argv[3]) == 0){
		b = 7;
	}else{
		puts("Foreground color is not available");
		return 0;
	}





	if(strcmp("checker",argv[1]) == 0){
		int i,j,k;

		for(j = 1;j <= 4;j++){
			for(k = 1;k <= 8;k++){
				for(i = 1;i <= 4;i++){
					textcolor(BRIGHT,a,b);
					printf("        ");
					textcolor(BRIGHT,b,a);
					printf("        ");
							
				}
				textcolor(RESET,b,a);
				printf("\n");
			}

			for(k = 1;k <= 8;k++){
				for(i = 1;i <= 4;i++){
					textcolor(BRIGHT,b,a);
					printf("        ");
					textcolor(BRIGHT,a,b);
					printf("        ");
			
				}
				textcolor(RESET,b,a);
				
				printf("\n");
			}
		}
	}else if(strcmp("donut",argv[1]) == 0){

		int x,y;

		float outerDiam,innerDiam;
		scanf("%f",&outerDiam);
		innerDiam = outerDiam/2;

		
		for(x = 1;x <= outerDiam;x++){
			for(y = 1;y <= outerDiam;y++){
				textcolor(BRIGHT,b,a);
				printf(" ");
			}
			
			printf("\n");		
		}

	}

	textcolor(RESET,WHITE, BLACK);
		
	return 0;
	
	
}
