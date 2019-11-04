#include <stdio.h>

int x = 10;

void outx(void);

int main() {
	
	int x = 40;
	{
		int x = 20; //local 1
		printf("x local1 = %d\n", x);
	}
	{
		int x = 30; //Local 2
		printf("x local2 = %d\n", x);
	}
	{
		extern int x; //global
		printf("x global = %d\n", x);
	}
	printf("x main=%d\n",x);
	outx();

	return 0;
}

void outx(void) {
	
	printf("x func=%d\n", x); //global
	return;
}