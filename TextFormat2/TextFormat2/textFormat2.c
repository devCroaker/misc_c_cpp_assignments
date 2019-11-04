#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

FILE *fin;
FILE *fout;

void output(char lbuf[]);

int main(void) {

	if (!(fout = fopen("csis2.txt", "w"))) {
		printf("Could not open the output file");
		return 0;
	}
	if (!(fin = fopen("getty.txt", "r"))) {
		printf("Could not open the input file");
		return 0;
	}

	unsigned int i = 0, j = 0, k;
	char c, *wbuf, *lbuf;

	wbuf = (char *)malloc((i + 1) * (sizeof(char)));
	lbuf = (char *)malloc((j + 1) * (sizeof(char)));
	while ((c = fgetc(fin)) != EOF) {

		if (!isspace(c)) {

			wbuf = (char *)realloc(wbuf, (i + 1) * (sizeof(char)));
			wbuf[i++] = c;
		}
		else {

			wbuf = (char *)realloc(wbuf, (i + 1) * (sizeof(char)));
			wbuf[i] = '\0';

			if (strlen(wbuf) > 0) {

				if ((j + strlen(wbuf)) > 62) {

					lbuf = (char *)realloc(lbuf, (j + 1) * (sizeof(char)));
					lbuf[j] = '\0';
					output(lbuf);
					j = 0;
					free(lbuf);
					lbuf = (char *)malloc((j + 1) * (sizeof(char)));
				}

				for (k = 0; k < strlen(wbuf); k++) {

					lbuf = (char *)realloc(lbuf, (j + 1) * (sizeof(char)));
					lbuf[j++] = wbuf[k];
				}
				lbuf = (char *)realloc(lbuf, (j + 1) * (sizeof(char)));
				lbuf[j++] = ' ';

				i = 0;
				free(wbuf);
				wbuf = (char *)malloc((i + 1) * (sizeof(char)));
			}
		}

	}

	wbuf[i] = '\0';
	for (k = 0; k < strlen(wbuf); k++) {

		lbuf = (char *)realloc(lbuf, (j + 1) * (sizeof(char)));
		lbuf[j++] = wbuf[k];
	}
	lbuf[j] = '\0';
	output(lbuf);

	fclose(fout);
	fclose(fin);
	getchar();
	return 0;
}

void output(char lbuf[]) {

	unsigned int j;

	for (j = 0; j < strlen(lbuf); j++) {
		putchar(lbuf[j]);
		putc(lbuf[j], fout);
	}
	putchar('\n');
	putc('\n', fout);

}