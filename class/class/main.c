#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SECONDS 60
#define MINUTES 60
#define HOURS 24
//#define DAYS 7
#define DAYS 365
//#define WEEKS 52
#define YEARS 50

FILE *fp;

int main()
{

	//fp = fopen("output.txt", "w");
	
	//int beats;
	//beats = SECONDS * MINUTES * HOURS * DAYS * YEARS;
	char num = '5';
	printf("%d",num);
	//fprintf(fp, "Your heart beats aproximatly %i times in %i years.", beats, YEARS);

	//fclose(fp);
	getchar();
	return 0;
}

//Alex Lindahl