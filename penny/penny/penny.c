#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

FILE *fp;

void tableHeaders(void);
int calcDays(double amount);

int main(void) {
	// Penny Lab by Alex Lindahl

	fp = fopen("csis.txt", "w");

	double amount;
	printf("Please enter the amount of money you want to accumulate: ");
	scanf("%lf", &amount);
	fprintf(fp, "The user wants to accumulate %.2lf dolars", amount);

	tableHeaders();
	int days = calcDays(amount);

	printf("\nIt took %d days to accumulate at least $%.2lf.", days, amount);
	fprintf(fp, "\nIt took %d days to accumulate at least $%.2lf.", days, amount);

	getchar();
	fclose(fp);
	return 0;
}

void tableHeaders(void) {

	printf("\n\n%10s%20s%20s\n", "DAY", "DEPOSIT", "BALANCE");
	fprintf(fp, "\n\n%10s%20s%20s\n", "DAY", "DEPOSIT", "BALANCE");
	printf("%10s%20s%20s\n", "---", "-------", "-------");
	fprintf(fp, "%10s%20s%20s\n", "---", "-------", "-------");

}

int calcDays(double amount) {

	int days;
	double deposit, balance;

	for (days = 1, deposit = 0.01, balance = 0.00; balance < amount; days++, deposit *= 2) {
		balance += deposit;
		printf("%10d%20.2lf%20.2lf\n", days, deposit, balance);
		fprintf(fp, "%10d%20.2lf%20.2lf\n", days, deposit, balance);
	}

	return --days;
}