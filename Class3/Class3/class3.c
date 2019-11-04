#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "custFunctions.h"

int main() {

	double a, b;

	printf("Please enter the length of the rectangle\n");
	scanf("%lf", &a);
	printf("Please enter the height of the rectangle\n");
	scanf("%lf", &b);

	double area = area_rectangle(a, b);
	increment(area); //Does nothing
	printf("The area of the rectangle is %.2lf", area);

	getchar(); getchar();
	return 0;

}
