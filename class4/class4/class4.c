#include <stdio.h>

int factorial(int num);

int main() {

	int result = factorial(5);
	printf("%d", result);

	getchar();
	return 0;
}

int factorial(int num) {

	if (num != 1) {
		return factorial(num - 1) * num;
	}

	return 1;

};