#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

FILE *fp;

int calculateBMI(void);

int main(void) {

	//BMI lab by alexander lindahl

	fp = fopen("csis.txt", "w");

	for (int i = 1; i <= 4; ++i) {
		calculateBMI();
	}

	fclose(fp);
	return 0;
}

int calculateBMI(void) {

	double w, h;

	printf("Please enter your weight:\n");
	scanf("%lf", &w);
	printf("Please enter your height:\n");
	scanf("%lf", &h);

	fprintf(fp, "The user entered a weight of %.2lf and a height of %.2lf\n", w, h);

	double bmi = (w * 703) / (h * h);
	printf("Your bmi is %.1lf\n", bmi);
	fprintf(fp, "The users bmi is %.1lf\n", bmi);

	if (bmi < 18.5) {
		printf("Your bmi evaluates to be underweight\n\n");
		fprintf(fp, "The users bmi evaluates to be underweight\n\n");
	} else if (bmi >= 18.5 && bmi <= 25) {
		printf("Your bmi evaluates to be normal\n\n");
		fprintf(fp, "The users bmi evaluates to be normal\n\n");
	} else if (bmi > 25 && bmi < 30) {
		printf("Your bmi evaluates to be overweight\n\n");
		fprintf(fp, "The users bmi evaluates to be overweight\n\n");
	} else if (bmi >= 30) {
		printf("Your bmi evaluates to be obese\n\n");
		fprintf(fp, "The users bmi evaluates to be obese\n\n");
	}

	return 0;
}