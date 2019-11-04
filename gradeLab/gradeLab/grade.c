#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

FILE *fp;

int calculateAverage(void);

int main(void) {
	int i;
	
	fp = fopen("csis.txt", "w");
	for (i = 1; i <= 4; ++i) {
		calculateAverage();
	}
	fclose(fp);
	return 0;
}

int calculateAverage(void) {

	int input, sum = 0, total = 0;

	printf("Please enter a list of grades terminated by a -1:\n");

	do {
		scanf("%d", &input);

		if (input != -1) {
			fprintf(fp, "The user entered the following grade: %d\n", input);
			total++;
			sum += input;
		}
		else {
			fprintf(fp, "The user entered the sentinal value: %d\n", input);
		}
	} while (input != -1);

	if (sum == 0) {
		printf("You did not enter any valid grades\n\n");
		fprintf(fp, "The user did not enter any valid grades\n\n");
		return 0;
	}

	printf("The average of your %d grades is %.2lf\n\n", total, ((double)sum/total));
	fprintf(fp, "The average of your %d grades is %.2lf\n\n", total, ((double)sum/total));
	getchar();

	return 0;

}