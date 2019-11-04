#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

FILE *fp;

int displayMenu(void);
void toJulian(void);
void toCalendar(void);
void daysBetweenDates(void);
void getCalendarDate(int date[]);
void getJulianDate(int date[]);
int isLeapYear(int year);
int since1900(int date[]);
int getJulianDays(int date[]);

int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int main(void) {

	int selection;
	if (!(fp = fopen("csis.txt", "w"))) {
		printf("Could not open the file");
		return 0;
	}

	do {

		selection = displayMenu();
		if (selection == 1) {
			toJulian();
			fprintf(fp, "------------------------------\n");
		} 
		else if (selection == 2) {
			toCalendar();
			fprintf(fp, "------------------------------\n");
		}
		else if (selection == 3) {
			daysBetweenDates();
			fprintf(fp, "------------------------------\n");
		}
		else if (selection != 4) {
			printf("Please enter a valid selection\n\n");
			continue;
		}

	} while (selection != 4);

	getchar();
	fclose(fp);
	return 0;
}

// Shows the program menu and takes in user selection
int displayMenu(void) {

	int selection;

	printf("DATE SELECTION MENU\n\n");
	printf("1) Convert calendar date into Julian date\n");
	printf("2) Convert Julian date into calendar date\n");
	printf("3) Compute days between two calendar dates\n");
	printf("4) Exit program\n\n");
	printf("ENTER SELECTION (1 - 4):\n");
	scanf("%d", &selection);
	fprintf(fp, "The user has chosen option %d\n\n", selection);

	return selection;
}

// Converts user input calendar date to julian date
void toJulian(void) {

	int date[3], days = 0;
	getCalendarDate(date);

	days = getJulianDays(date);

	printf("\nThe julian date for the date %d/%d/%d is %d, %d\n\n", date[0], date[1], date[2], days, date[2]);
	fprintf(fp, "The julian date for the date %d/%d/%d is %d, %d\n\n", date[0], date[1], date[2], days, date[2]);
}

// Converts user input julian date to calendar date
void toCalendar(void) {

	int jDate[2], cDate[3], i = 0, days;
	getJulianDate(jDate);

	days = jDate[0];
	while (days > months[i]) {
		days -= months[i];
		if (i == 0 && isLeapYear(jDate[1])) {
			// Subtract an extra day off in January to account for 29 days in FEB on leap year
			// Lets the While evaluate correctly for FEB on my global months array without changing it
			--days;
		}
		++i;
	}
	if (i == 1 && isLeapYear(jDate[1])) {
		// If the month is February and it is leap year give the extra day I pulled off in January back
		++days;
	}

	cDate[0] = i + 1;
	cDate[1] = days;
	cDate[2] = jDate[1];

	printf("\nThe calendar date for the date %d, %d is %d/%d/%d\n\n", jDate[0], jDate[1], cDate[0], cDate[1], cDate[2]);
	fprintf(fp, "The calendar date for the date %d, %d is %d/%d/%d\n\n", jDate[0], jDate[1], cDate[0], cDate[1], cDate[2]);
}

// Determines the number of days between two dates greater than 1900
void daysBetweenDates(void) {

	int dates[2][3], daysOne, daysTwo, solution;
	getCalendarDate(dates[0]);
	getCalendarDate(dates[1]);

	daysOne = since1900(dates[0]);
	daysTwo = since1900(dates[1]);

	if (daysOne > daysTwo) {
		solution = daysOne - daysTwo;
	}
	else {
		solution = daysTwo - daysOne;
	}

	printf("\nThe difference between calendar date %d/%d/%d and calendare date %d/%d/%d is %d days\n\n", dates[0][0], dates[0][1], dates[0][2], dates[1][0], dates[1][1], dates[1][2], solution);
	fprintf(fp, "The difference between calendar date %d/%d/%d and calendare date %d/%d/%d is %d days\n\n", dates[0][0], dates[0][1], dates[0][2], dates[1][0], dates[1][1], dates[1][2], solution);

}

// takes in user input for calendar date and sets it to referenced array
void getCalendarDate(int date[]) {

	printf("\nPlease enter a calendar date in the following format MM/DD/YYYY\n");
	scanf("%d/%d/%d", &date[0], &date[1], &date[2]);
	fprintf(fp, "The user has entered the calendar date %d/%d/%d\n\n", date[0], date[1], date[2]);

}

// takes in user input for julian date and sets it to referenced array
void getJulianDate(int date[]) {

	printf("\nPlease enter a julian date in the following format DDD, YYYY\n");
	scanf("%d, %d", &date[0], &date[1]);
	fprintf(fp, "The user has entered the julian date %d, %d\n\n", date[0], date[1]);

}

// returns true if year is a leap year
int isLeapYear(int year) {
	return ((!(year % 4) && year % 100) || !(year % 400));
}

// returns number of days since 1/1/1900
int since1900(int date[]) {

	int days = 0, currentYear = date[2];

	while (currentYear != 1900) {
		days += 365;
		if (isLeapYear(currentYear)) {
			++days;
		}
		--currentYear;
	}

	return days + getJulianDays(date);

}

// returns the number of days since 1/1/date[2]
int getJulianDays(int date[]) {

	int days = 0;

	for (int i = 0; i < date[0] - 1; ++i) {
		days += months[i];
		if (i == 2 && isLeapYear(date[2])) {
			++days;
		}
	}
	days += date[1];

	return days;
}
