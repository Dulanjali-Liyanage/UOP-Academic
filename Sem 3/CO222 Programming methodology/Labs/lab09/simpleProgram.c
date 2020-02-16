
// Stepping through the debugger and break points

#include <stdio.h>

int test1()
{
	printf("Inside sub function\n");
}



int main()
{
	int var1=0;
	int var2=5;
	for(var1 = 0; var1< 5; var1++)
	{
		printf("main function\n");
		test1();
	}
	return 0;
}

