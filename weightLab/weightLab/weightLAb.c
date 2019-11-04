#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

FILE *fp;

int main() {
	// Weight Lab by Alexander Lindahl

	fp = fopen("weight_lab.txt", "w");

	double weight;

	printf("Please enter your weight:\n");
	scanf("%lf", &weight);
	fprintf(fp, "The user entered a weight of %lf\n\n", weight);

	printf("%15s | %10s\n", "Planet", "Weight");
	fprintf(fp, "%15s | %10s\n", "Planet", "Weight");
	printf("___________________________\n");
	fprintf(fp, "___________________________\n");

	printf("%15s | %10.1lf\n", "Mercury", weight * 0.378);
	fprintf(fp, "%15s | %10.1lf\n", "Mercury", weight * 0.378);

	printf("%15s | %10.1lf\n", "Earth", weight);
	fprintf(fp, "%15s | %10.1lf\n", "Earth", weight);

	printf("%15s | %10.1lf\n", "Venus", weight * 0.907);
	fprintf(fp, "%15s | %10.1lf\n", "Venus", weight * 0.907);

	printf("%15s | %10.1lf\n", "Mars", weight * 0.377);
	fprintf(fp, "%15s | %10.1lf\n", "Mars", weight * 0.377);

	printf("%15s | %10.1lf\n", "Jupiter", weight * 2.36);
	fprintf(fp, "%15s | %10.1lf\n", "Jupiter", weight * 2.36);

	printf("%15s | %10.1lf\n", "Saturn", weight * 0.916);
	fprintf(fp, "%15s | %10.1lf\n", "Saturn", weight * 0.916);

	printf("%15s | %10.1lf\n", "Uranus", weight * 0.889);
	fprintf(fp, "%15s | %10.1lf\n", "Uranus", weight * 0.889);

	printf("%15s | %10.1lf\n", "Neptune", weight * 1.12);
	fprintf(fp, "%15s | %10.1lf\n", "Neptune", weight * 1.12);


	getchar();
	fclose(fp);
	return 0;
}