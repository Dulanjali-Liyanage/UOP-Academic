// digitalRoot()
#include<stdio.h>

unsigned short digitalRoot(unsigned long n){
	if (n < 10)
		return n;
	else
		return digitalRoot(n / 10 + n % 10);
}

int main(){
	unsigned long n = 0x9999999999999999;
	printf("Digital Root of %lu is %u\n", n, digitalRoot(n));
	return 0;	
}
