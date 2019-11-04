#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

FILE *fpIn;
FILE *fpOut;

void outputHeaders(void);
void initialBalance(double amount, double *balance, double *service, double *openBalance);
void deposit(double amount, double *balance, double *service, int *numDeposit, double *amtDeposit);
void check(double amount, double *balance, double *service, int *numCheck, double *amtCheck);
void outputSummary(int numDeposit, double amtDeposit, int numCheck, double amtCheck, double openBalance, double service, double closeBalance);

int main(void) {
	//Checking lab by Alex Lindahl
	char code;
	double amount, service, balance;
	double amtCheck, amtDeposit, openBalance, closeBalance;
	int numCheck, numDeposit;

	if (!(fpIn = fopen("account.txt", "r"))) {
		printf("account.txt could not be opened for input.");
		return 0;
	}
	if (!(fpOut = fopen("csis.txt", "w"))) {
		printf("csis.txt could not be opened for output.");
		return 0;
	}

	amount       = 0.0;
	service      = 0.0;
	balance      = 0.0;
	amtCheck     = 0.0;
	amtDeposit   = 0.0;
	openBalance  = 0.0;
	closeBalance = 0.0;
	numCheck     = 0;
	numDeposit   = 0;

	outputHeaders();

	while (!feof(fpIn)) {
		fscanf(fpIn, "%c %lf\n", &code, &amount);
		if (code == 'I') {
			initialBalance(amount, &balance, &service, &openBalance);
		}
		else if (code == 'D') {
			deposit(amount, &balance, &service, &numDeposit, &amtDeposit);
		}
		else {
			check(amount, &balance, &service, &numCheck, &amtCheck);
		}
	}

	closeBalance = balance - service;
	outputSummary(numDeposit, amtDeposit, numCheck, amtCheck, openBalance, service, closeBalance);

	fclose(fpIn);
	fclose(fpOut);
	return 0;
}

void outputHeaders(void) {
	printf("%-15s%10s%10s%10s\n", "Transaction", "Deposit", "Check", "Balance");
	fprintf(fpOut, "%-15s%10s%10s%10s\n", "Transaction", "Deposit", "Check", "Balance");
	printf("%-15s%10s%10s%10s\n", "-----------", "-------", "-----", "-------");
	fprintf(fpOut, "%-15s%10s%10s%10s\n", "-----------", "-------", "-----", "-------");
}

void initialBalance(double amount, double *balance, double *service, double *openBalance) {
	*balance = *openBalance = amount;
	*service += 5.00;
	printf("%-15s%10s%10s%10.2lf\n", "Initial Balance", "", "", *balance);
	fprintf(fpOut, "%-15s%10s%10s%10.2lf\n", "Initial Balance", "", "", *balance);
}

void deposit(double amount, double *balance, double *service, int *numDeposit, double *amtDeposit) {
	*balance += amount;
	*service += 0.03;
	++*numDeposit;
	*amtDeposit += amount;
	printf("%-15s%10.2lf%10s%10.2lf\n", "Deposit", amount, "", *balance);
	fprintf(fpOut, "%-15s%10.2lf%10s%10.2lf\n", "Deposit", amount, "", *balance);
}

void check(double amount, double *balance, double *service, int *numCheck, double *amtCheck) {
	*balance -= amount;
	*service += 0.06;
	++*numCheck;
	*amtCheck += amount;
	*service += (*balance < 0) ? 5.00 : 0.00;
	printf("%-15s%10s%10.2lf%10.2lf\n", "Check", "", amount, *balance);
	fprintf(fpOut, "%-15s%10s%10.2lf%10.2lf\n", "Check", "", amount, *balance);
}

void outputSummary(int numDeposit, double amtDeposit, int numCheck, double amtCheck, double openBalance, double service, double closeBalance) {
	printf("\n%24s %d\n", "Total number of deposits:", numDeposit);
	fprintf(fpOut, "\n%24s %d\n", "Total number of deposits:", numDeposit);
	printf("%24s %.2lf\n\n", "Total amount of deposits:", amtDeposit);
	fprintf(fpOut, "%24s %.2lf\n\n", "Total amount of deposits:", amtDeposit);

	printf("%24s %d\n", "Total number of checks:", numCheck);
	fprintf(fpOut, "%24s %d\n", "Total number of checks:", numCheck);
	printf("%24s %.2lf\n\n", "Total amount of checks:", amtCheck);
	fprintf(fpOut, "%24s %.2lf\n\n", "Total amount of checks:", amtCheck);

	printf("%24s %.2lf\n\n", "Total service charge:", service);
	fprintf(fpOut, "%24s %.2lf\n\n", "Total service charge:", service);

	printf("%24s %.2lf\n", "Opening balance:", openBalance);
	fprintf(fpOut, "%24s %.2lf\n", "Opening balance:", openBalance);
	printf("%24s %.2lf\n\n", "Closing balance:", closeBalance);
	fprintf(fpOut, "%24s %.2lf\n\n", "Closing balance:", closeBalance);
}