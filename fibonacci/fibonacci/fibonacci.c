#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

FILE *fp;
void fibonacci(int first, int second, int num, int target);

int main(void) {
	//Recursive Fionacci Lab by Alexander Lindahl

	fp = fopen("csis.txt", "w");

	int target = 20;
	printf("The first %d fibonacci numbers are:\n", target);
	fprintf(fp, "The first %d fibonacci numbers are:\n", target);
	fibonacci(0, 1, 0, target);

	getchar();
	fclose(fp);
	return 0;
}

void fibonacci(int first, int second, int num, int target) {

	++num;
	int next = first + second;
	printf(" %d", next);
	fprintf(fp, " %d", next);
	if (num != target) {
		fibonacci(second, next, num, target);
	}

}