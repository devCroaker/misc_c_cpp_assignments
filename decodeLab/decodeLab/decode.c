#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

FILE *msgfp;
FILE *codefp;
FILE *fp;

#define MAX 26

void getCodeString(char codeArray[]);
void getMessage(int msgValue[], int msgChar[]);
void sortArrays(int array[], int mirror[]);
void printMsg(int array[], char codeArray[]);

int main(void) {

	// Check all the file openings
	if (!(fp = fopen("csis.txt", "w"))) {
		printf("Could not open the output");
		return 0;
	}
	if (!(msgfp = fopen("msgfile.txt", "r"))) {
		printf("Could not open the message file");
		return 0;
	}
	if (!(codefp = fopen("codefile.txt", "r"))) {
		printf("Could not open the code file");
		return 0;
	}

	char codeArray[52];
	getCodeString(codeArray);

	int msgValue[MAX], msgChar[MAX];
	getMessage(msgValue, msgChar);
	sortArrays(msgValue, msgChar);
	printMsg(msgChar, codeArray);

	getchar();
	fclose(fp);
	return 0;
}

void getCodeString(char codeArray[]) {

	int c, i = 0;
	printf("The code string is:\n");
	fprintf(fp, "The code string is:\n");
	while ((c = getc(codefp)) != EOF) {
		putchar(c);
		fputc(c, fp);
		codeArray[i] = c;
		i++;
	}

}

void getMessage(int msgValue[], int msgChar[]) {

	printf("\n\nThe message values are:\n");
	fprintf(fp, "\n\nThe message values are:\n");
	for (int i = 0; i < MAX; i++) {
		fscanf(msgfp, "%3d%2d", &msgValue[i], &msgChar[i]);
		printf("%d%02d\n", msgValue[i], msgChar[i]);
		fprintf(fp, "%d%02d\n", msgValue[i], msgChar[i]);
	}

}

void sortArrays(int array[], int mirror[]) {

	int i, j, temp, temp2;

	for (i = 1; i < MAX; i++) {
		temp = array[i]; temp2 = mirror[i];
		j = i - 1;
		while (j >= 0 && temp < array[j]) {
			array[j + 1] = array[j];
			mirror[j + 1] = mirror[j];
			--j;
		}
		array[j + 1] = temp;
		mirror[j + 1] = temp2;
	}

}

void printMsg(int array[], char codeArray[]) {

	printf("\nThe code is:\n");
	fprintf(fp, "\nThe code is:\n");

	for (int i = 0; i < MAX; i++) {
		putchar(codeArray[array[i]]);
		fputc(codeArray[array[i]], fp);
	}

}
