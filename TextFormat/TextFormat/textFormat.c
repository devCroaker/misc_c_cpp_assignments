#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

FILE *fin;
FILE *fout;

void output(char wbuf[]);

int main(void) {

	if (!(fout = fopen("csis1.txt", "w"))) {
		printf("Could not open the output file");
		return 0;
	}
	if (!(fin = fopen("getty.txt", "r"))) {
		printf("Could not open the input file");
		return 0;
	}

	unsigned int i = 0;
	char c, *wbuf;

	wbuf = (char *)malloc((i + 1) * (sizeof(char)));
	while (!feof(fin)) {
		if (!isspace(c = fgetc(fin))) {
			wbuf = (char *)realloc(wbuf, (i + 1) * (sizeof(char)));
			wbuf[i] = c;
			i++;
		}
		else {

			wbuf = (char *)realloc(wbuf, (i + 1) * (sizeof(char)));
			wbuf[i] = '\0';

			if (strlen(wbuf) > 0) {
				output(wbuf);

				i = 0;
				free(wbuf);
				wbuf = (char *)malloc((i + 1) * (sizeof(char)));
			}
		}
	}

	wbuf[--i] = '\0';
	output(wbuf);

	fclose(fout);
	fclose(fin);
	getchar();
	return 0;
}

void output(char wbuf[]) {
	unsigned int j;
	putchar('+');
	putc('+', fout);
	for (j = 0; j < strlen(wbuf); j++) {
		putchar(wbuf[j]);
		putc(wbuf[j], fout);
	}
	putchar('+');
	putc('+', fout);
	putchar('\n');
	putc('\n', fout);
}