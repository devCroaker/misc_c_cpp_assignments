#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

FILE *fin;
FILE *fout;

typedef struct EMP {
	char first[8];
	char initial[2];
	char last[10];
	char street[17];
	char city[12];
	char state[3];
	char zip[6];
	int age;
	char sex[2];
	int tenure;
	double salary;
	struct EMP *next;
} emp;
#define LINEMAX 100

void strsub(char buf[], char sub[], int start, int end);
void readEmps(emp *employees);
void outEmployees(emp *employee);
void outMen(emp *employee);
void outHighFemale(emp *employee);
void outLowMale(emp *employee);
double outAvgSalary(emp *employee);
void outFemaleBelowAvg(emp *employee, double avg);
void outMaleRatio(emp *employee, double avg);
void outWealthyOldTenure(emp *employee);
void outEmpsWithRaise(emp *employee);

int main(void) {

	if (!(fout = fopen("csis.txt", "w"))) {
		printf("Could not open the output file");
		return 0;
	}
	if (!(fin = fopen("payfile.txt", "r"))) {
		printf("Could not open the input file");
		return 0;
	}

	emp *employees;
	employees = (emp *)malloc(sizeof(emp));

	double avg;

	readEmps(employees);
	outEmployees(employees);
	outMen(employees);
	outHighFemale(employees);
	outLowMale(employees);
	avg = outAvgSalary(employees);
	outFemaleBelowAvg(employees, avg);
	outMaleRatio(employees, avg);
	outWealthyOldTenure(employees);
	outEmpsWithRaise(employees);

	fclose(fout);
	fclose(fin);
	getchar();
	return 0;
}

void strsub(char buf[], char sub[], int start, int end) {
	int i, j;

	for (j = 0, i = start; i <= end; i++, j++) {
		sub[j] = buf[i];
	}
	sub[j] = '\0';

}

void readEmps(emp *employees) {

	char buf[LINEMAX], age[3], sal[7], ten[2];
	emp *previous;
	
	while (!feof(fin)) {

		fgets(buf, LINEMAX, fin);
		strsub(buf, employees->first, 0, 6);
		strsub(buf, employees->initial, 8, 8);
		strsub(buf, employees->last, 10, 18);
		strsub(buf, employees->street, 20, 35);
		strsub(buf, employees->city, 37, 47);
		strsub(buf, employees->state, 49, 50);
		strsub(buf, employees->zip, 52, 56);
		strsub(buf, age, 58, 59);
		employees->age = atoi(age);
		strsub(buf, employees->sex, 61, 61);
		strsub(buf, ten, 63, 63);
		employees->tenure = atoi(ten);
		strsub(buf, sal, 65, 70);
		employees->salary = atof(sal);
		previous = employees;
		employees = employees->next = (emp *)malloc(sizeof(emp));
	}
	free(employees);
	previous->next = NULL;

}

void outEmployees(emp *employee) {

	while (employee != NULL) {
		printf("%17s %s %s %s\n", "Read in Employee:", employee->first, employee->initial, employee->last);
		printf("%17s %s %s %s %s\n", "Address:", employee->street, employee->city, employee->state, employee->zip);
		printf("%17s %d\n", "Age:", employee->age);
		printf("%17s %s\n", "Sex:", employee->sex);
		printf("%17s %d\n", "Years of Work:", employee->tenure);
		printf("%17s %.2lf\n\n", "Salary:", employee->salary);

		fprintf(fout, "%17s %s %s %s\n", "Read in Employee:", employee->first, employee->initial, employee->last);
		fprintf(fout, "%17s %s %s %s %s\n", "Address:", employee->street, employee->city, employee->state, employee->zip);
		fprintf(fout, "%17s %d\n", "Age:", employee->age);
		fprintf(fout, "%17s %s\n", "Sex:", employee->sex);
		fprintf(fout, "%17s %d\n", "Years of Work:", employee->tenure);
		fprintf(fout, "%17s %.2lf\n\n", "Salary:", employee->salary);

		employee = employee->next;
	}

}

void outMen(emp *employee) {

	printf("\nThe male employees are:\n");
	fprintf(fout, "\nThe male employees are:\n");
	while (employee != NULL) {
		if (employee->sex[0] == 'M') {
			printf("%s %s\n", employee->first, employee->last);
			fprintf(fout, "%s %s\n", employee->first, employee->last);
		}
		employee = employee->next;
	}

}

void outHighFemale(emp *employee) {

	double highest = 0.00;
	emp *highFemale = NULL;

	printf("\nThe highest paid female is: ");
	fprintf(fout, "\nThe highest paid female is: ");
	while (employee != NULL) {
		if (employee->sex[0] == 'F' && employee->salary > highest) {
			highest = employee->salary;
			highFemale = employee;
		}
		employee = employee->next;
	}

	printf("%s %s\n", highFemale->first, highFemale->last);
	fprintf(fout, "%s %s\n", highFemale->first, highFemale->last);

}

void outLowMale(emp *employee) {

	double lowest = 0.00;
	emp *lowMale = NULL;

	printf("\nThe lowest paid male is: ");
	fprintf(fout, "\nThe lowest paid male is: ");
	while (employee != NULL) {
		if (employee->sex[0] == 'M' && (employee->salary < lowest || lowest == 0.00)) {
			lowest = employee->salary;
			lowMale = employee;
		}
		employee = employee->next;
	}

	printf("%s %s\n", lowMale->first, lowMale->last);
	fprintf(fout, "%s %s\n", lowMale->first, lowMale->last);

}

double outAvgSalary(emp *employee) {

	double total = 0.00, avg;
	int num = 0;

	printf("\nThe average salary is: ");
	fprintf(fout, "\nThe average salary is: ");
	while (employee != NULL) {
		total += employee->salary;
		num++;
		employee = employee->next;
	}

	avg = (total / num);

	printf("%.2lf\n", avg);
	fprintf(fout, "%.2lf\n", avg);

	return avg;

}

void outFemaleBelowAvg(emp *employee, double avg) {

	printf("\nThe women making less than the average salary are:\n");
	fprintf(fout, "\nThe women making less than the average salary are:\n");
	while (employee != NULL) {
		if (employee->sex[0] == 'F' && employee->salary < avg) {
			printf("%s %s\n", employee->first, employee->last);
			fprintf(fout, "%s %s\n", employee->first, employee->last);
		}
		employee = employee->next;
	}

}

void outMaleRatio(emp *employee, double avg) {
	
	double above = 0, below = 0;

	printf("\nThe ratio of men above average salary to those below is: ");
	fprintf(fout, "\nThe ratio of men above average salary to those below is: ");
	while (employee != NULL) {
		if (employee->sex[0] == 'M') {
			if (employee->salary < avg) {
				below++;
			} else {
				above++;
			}
		}
		employee = employee->next;
	}

	printf("%.3lf\n", (above / below));
	fprintf(fout, "%.3lf\n", (above / below));

}

void outWealthyOldTenure(emp *employee) {

	printf("\nThe employees over 30 making $35K+, who have been with the company 5+ years are:\n");
	fprintf(fout, "\nThe employees over 30 making $35K+, who have been with the company 5+ years are:\n");
	while (employee != NULL) {
		if (employee->age >= 30 && employee->tenure >= 5 && (employee->salary * 52) >= 35000) {
			printf("%s %s\n", employee->first, employee->last);
			fprintf(fout, "%s %s\n", employee->first, employee->last);
		}
		employee = employee->next;
	}

}

void outEmpsWithRaise(emp *employee) {

	printf("\nThe employees given a 10%% raise for making less than 350 are:\n");
	fprintf(fout, "\nThe employees given a 10%% raise for making less than 350 are:\n");
	while (employee != NULL) {
		if (employee->salary < 350) {
			employee->salary *= 1.10;
			printf("%s %s salary increased to %.2lf\n", employee->first, employee->last, employee->salary);
			fprintf(fout, "%s %s salary increased to %.2lf\n", employee->first, employee->last, employee->salary);
		}
		employee = employee->next;
	}

}
