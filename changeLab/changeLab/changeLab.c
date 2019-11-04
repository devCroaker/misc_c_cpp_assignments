#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
FILE *fp;

#define TWENTY 2000
#define TEN 1000
#define FIVE 500
#define ONE 100
#define QUARTER 25
#define DIME 10
#define NICKLE 5
#define PENNY 1
#define AMOUNT 10000
#define COST 2117

int main() {

	// Change lab by Alexander Lindahl

	fp = fopen("change_output.txt", "w");

	int twenties, tens, fives, ones, quarters, dimes, nickles, pennies, change;
	
	change = AMOUNT - COST;

	twenties = change / TWENTY;
	change = change % TWENTY;
	tens = change / TEN;
	change = change % TEN;
	fives = change / FIVE;
	change = change % FIVE;
	ones = change / ONE;
	change = change % ONE;
	quarters = change / QUARTER;
	change = change % QUARTER;
	dimes = change / DIME;
	change = change % DIME;
	nickles = change / NICKLE;
	change = change % NICKLE;
	pennies = change;

	printf("The change is %i twenties\n", twenties);
	fprintf(fp, "The change is %i twenties\n", twenties);
	printf("The change is %i tens\n", tens);
	fprintf(fp, "The change is %i tens\n", tens);
	printf("The change is %i fives\n", fives);
	fprintf(fp, "The change is %i fives\n", fives);
	printf("The change is %i ones\n", ones);
	fprintf(fp, "The change is %i ones\n", ones);
	printf("The change is %i quarters\n", quarters);
	fprintf(fp, "The change is %i quarters\n", quarters);
	printf("The change is %i dimes\n", dimes);
	fprintf(fp, "The change is %i dimes\n", dimes);
	printf("The change is %i nickles\n", nickles);
	fprintf(fp, "The change is %i nickles\n", nickles);
	printf("The change is %i pennies\n", pennies);
	fprintf(fp, "The change is %i pennies\n", pennies);

	getchar();
	fclose(fp);
	return 0;

}