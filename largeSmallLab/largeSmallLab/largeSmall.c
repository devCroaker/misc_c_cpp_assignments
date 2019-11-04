#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

FILE *fp;

int compare(void);

int main(void) {
	int i;

	fp = fopen("csis.txt", "w");
	for (i = 1; i <= 4; ++i) {
		compare();
	}
	fclose(fp);
	return 0;
}

int compare(void) {

	int i, large, small, input;

	printf("Please enter four intigers:\n");
	fprintf(fp, "Asked the user to enter four intigers. They entered:\n");
	for (i = 1; i <= 4; ++i) {
		printf("%d - ", i);
		fprintf(fp, "%d - ", i);

		scanf("%d", &input);
		fprintf(fp, "%d\n", input);

		if (i == 1 || input > large) {
			large = input;
		}
		if (i == 1 || input < small) {
			small = input;
		}
	}

	printf("The largest of the four numbers was: %d\n", large);
	fprintf(fp, "The largest of the four numbers was: %d\n", large);
	printf("The smallest of the four numbers was: %d\n\n", small);
	fprintf(fp, "The smallest of the four numbers was: %d\n\n", small);

	return 0;

}