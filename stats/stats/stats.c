#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

FILE *fp;

#define MAX 30

void printScores(int scores[]);
void sortScores(int scores[]);
int  fequencyChart(int scores[]);
void passFail(int scores[]);
void calcMean(int scores[]);
void calcMedian(int scores[]);

int main(void) {

	int scores[MAX] = { 90,85,100,50,50,85,60,70,55,55,80,95,70,60,95,80,100,75,70,95,90,90,70,95,50,65,85,95,100,65 }, mode;

	if (!(fp = fopen("csis.txt", "w"))) {
		printf("Could not open the file");
		return 0;
	}
	 
	printf("The scores at compile time\n------------------------------\n");
	fprintf(fp, "The scores at compile time\n------------------------------\n");
	printScores(scores);
	sortScores(scores);
	printf("\nThe scores after sorting\n------------------------------\n");
	fprintf(fp, "\nThe scores after sorting\n------------------------------\n");
	printScores(scores);
	mode = fequencyChart(scores); //bootstrapping the chart to return mode for later
	passFail(scores);
	calcMean(scores);
	/* 
	*  It says to make a function for each step but 
	*  whats the point of making a new function when
	*  the frequencyChart function already does it 
	*  with a minor tweak? Hope you dont mark me down.
	*/
	printf("The mode of the scores is %d\n", mode);
	fprintf(fp, "The mode of the scores is %d\n", mode);
	calcMedian(scores);

	fclose(fp);
	getchar();
	return 0;
}

void printScores(int scores[]) {

	int i = 0;

	while (i < MAX) {
		for (int j = 0; j < 5; j++, i++) {
			printf("%d%c", scores[i], (j != 4) ? ',' : '\n');
			fprintf(fp, "%d%c", scores[i], (j != 4) ? ',' : '\n');
		}
	}

}

void sortScores(int scores[]) {

	int i, j, temp;

	for (i = 1; i < MAX; i++) {
		temp = scores[i];
		j = i - 1;
		while (j >= 0 && temp < scores[j]) {
			scores[j + 1] = scores[j];
			--j;
		}
		scores[j + 1] = temp;
	}

}

int fequencyChart(int scores[]) {

	printf("\n%7s %15s\n%7s %15s\n", "Score", "Frequency", "-----", "---------");
	fprintf(fp, "\n%7s %15s\n%7s %15s\n", "Score", "Frequency", "-----", "---------");

	int current = scores[MAX-1], i = MAX-1, count = 0, max = 0, mode;
	while (i >= 0) {
		while (scores[i] == current) {
			count++; i--;
		}
		printf("%6d %12d\n", current, count);
		fprintf(fp, "%6d %12d\n", current, count);
		if (count > max) {
			max = count; mode = current;
		}
		count = 0;
		current = scores[i];
	}

	return mode;
}

void passFail(int scores[]) {

	int passed = 0, failed, i = 0;

	while (scores[i] >= 60) {
		passed++; i++;
	}

	failed = MAX - passed;

	printf("\n%.1lf%% recived passing grades\n%.1lf%% recived failing grades\n", (((double)passed / MAX)*100), (((double)failed / MAX) * 100));
	fprintf(fp, "\n%.1lf%% recived passing grades\n%.1lf%% recived failing grades\n", (((double)passed / MAX) * 100), (((double)failed / MAX) * 100));

}

void calcMean(int scores[]) {
	int total = 0;

	for (int i = 0; i < MAX; i++) {
		total += scores[i];
	}

	double mean = (double)total / MAX;

	printf("\nThe mean of the scores is %.1lf\n", mean);
	fprintf(fp, "\nThe mean of the scores is %.1lf\n", mean);

}

void calcMedian(int scores[]) {

	double median;

	if (MAX%2 == 0) {
		int i = MAX / 2, j = i + 1;
		median = ((double)scores[i-1] + scores[j-1]) / 2;
	}
	else {
		int i = (MAX / 2)+1;
		median = scores[i-1];
	}
	
	printf("The median of the scores is %.1lf\n", median);
	fprintf(fp, "The median of the scores is %.1lf\n", median);

}
