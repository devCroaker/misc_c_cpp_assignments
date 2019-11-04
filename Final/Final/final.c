#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

FILE *fin;
FILE *fout;

void read_line(FILE *fp, char *line);
void line_reverse(char *strf, char *strr);

int main(void) {

	if (!(fout = fopen("csis.txt", "w"))) {
		printf("Could not open the output file");
		return 0;
	}
	if (!(fin = fopen("testfile.txt", "r"))) {
		printf("Could not open the input file");
		return 0;
	}

	char buff[MAX], *rev;
	int i = 0;

	while (!feof(fin)) {

		read_line(fin, buff);
		if (i%2 == 1) {
			rev = (char*)malloc(sizeof(buff));
			line_reverse(buff, rev);
			strcpy(buff, rev);
			free(rev);
		}
		printf("%s\n", buff);
		fprintf(fout, "%s\n", buff);
		i++;
	}

	fclose(fin);
	fclose(fout);
	getchar();
	return 0;

}

void read_line(FILE *fp, char *line) {

	char c;
	int i = 0;

	while ((c = fgetc(fp)) != '\n' && c != EOF) {
		line[i++] = c;
	}

	line[i] = '\0';

}

void line_reverse(char *strf, char *strr) {
	
	int i = (strlen(strf)-1), j = 0;
	for (i, j; i >= 0; i--, j++) {
		strr[j] = strf[i];
	}
	strr[j] = '\0';

}
