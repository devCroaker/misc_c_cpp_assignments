#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

FILE *fp;

#define PI acos(-1)

double calc_pi(int maxsteps);

int main(void) {

	if (!(fp = fopen("csis.txt", "w"))) {
		printf("Could not open the file");
		return 0;
	}

	double result;
	int i = 1;

	printf("%25s\n", "Step Approximation of Pi\n");
	printf("%25s\n", "-------------------------\n");
	fprintf(fp, "%25s\n", "Step Approximation of Pi\n");
	fprintf(fp, "%25s\n", "-------------------------\n");

	do {
		result = calc_pi(i);
		if (i <= 30) {
			printf("%2d) %15lf\n", i, result);
			fprintf(fp, "%2d) %15lf\n", i, result);
		}
		i++;
	} while (fabs(result - PI) > 0.0001);

	printf("\nIt would take %d steps to approximate pi so that the absolute error is less than 0.0001", i);
	fprintf(fp, "\nIt would take %d steps to approximate pi so that the absolute error is less than 0.0001", i);

	fclose(fp);
	getchar();
	return 0;

}

double calc_pi(int maxsteps) {

	double pi = 0, j = 1;

	for (int i = 0; i < maxsteps; i++, j += 2) {
		if (i%2 == 0) {
			pi += (1 / j);
		}
		else {
			pi -= (1 / j);
		}
	}

	return pi*4;

}