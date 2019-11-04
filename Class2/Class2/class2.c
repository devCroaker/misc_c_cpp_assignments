#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

FILE *fp;

int main() {

	fp = fopen("quadraticrun.txt", "w");

	double a, b, c, x1, x2, temp;

	printf("Enter value for a:\n");
	scanf("%lf", &a);
	fprintf(fp, "User entered %lf for a\n", a);
	printf("Enter value for b:\n");
	scanf("%lf", &b);
	fprintf(fp, "User entered %lf for b\n", b);
	printf("Enter value for c:\n");
	scanf("%lf", &c);
	fprintf(fp, "User entered %lf for c\n", c);

	temp = b * b - 4 * a * c;

	if (temp < 0) {
		printf("Only complex solution exists\n");
		fprintf(fp, "Only complex solution exists\n");
		getchar();
		return -1;
	}

	x1 = (-b + sqrt(temp)) / (2 * a);
	x2 = (-b - sqrt(temp)) / (2 * a);

	printf("The value of x1 is %lf\nThe value of x2 is %lf", x1, x2);
	fprintf(fp, "The value of x1 is %lf\nThe value of x2 is %lf", x1, x2);

	getchar();
	fclose(fp);
	return 0;

}