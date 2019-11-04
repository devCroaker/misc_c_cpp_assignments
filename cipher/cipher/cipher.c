#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<ctype.h>

FILE *fout;
FILE *fin;

#define MAX 1000

void processFile(char input[]);
void shift(int num, char input[], char code[]);
void output(char code[]);

//Cipher Lab by Alexander Lindahl
int main(void) {

	if (!(fout = fopen("csis.txt", "w"))) {
		printf("Could not open the output file");
		return 0;
	}
	if (!(fin = fopen("congress.txt", "r"))) {
		printf("Could not open the input file");
		return 0;
	}

	char input[MAX], code[MAX];

	processFile(input);
	shift(13, input, code);
	output(code);

	fclose(fin);
	fclose(fout);
	getchar();
	return 0;
}

void processFile(char input[]) {
	char c, i = 0;
	printf("The string to cipher is:\n");
	fprintf(fout, "The string to cipher is:\n");
	while ((c = getc(fin)) != EOF) {
		putchar(c);
		fputc(c, fout);
		if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
			*input++ = toupper(c);
		}
	}
	putchar('\n');
	fputc('\n', fout);
}

void shift(int num, char input[], char code[]) {
	char temp;
	while (*input >= 65 && *input <= 90) {
		temp = *input++;
		temp += num;
		if (temp > 90) {
			temp -= 26;
		}
		*code++ = temp;
	}
}

void output(char code[]) {
	int i = 1;
	printf("\nThe ciphered message is:\n");
	fprintf(fout, "\nThe ciphered message is:\n");
	while (*code >= 65 && *code <= 90) {
		putchar(*code);
		fputc(*code++, fout);
		if (i % 50 == 0) {
			putchar('\n');
			fputc('\n', fout);
		}
		else if (i % 5 == 0) {
			putchar('\0');
			fputc('\0', fout);
		}
		i++;
	}
}
