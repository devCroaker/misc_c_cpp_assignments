#include <iostream>

void display_time(int hours, int minutes);

int main(int argc, char *argv[]) {

	int hours, minutes;
	
	std::cout << "Please enter the number of hours: ";
	std::cin >> hours;

	std::cout << "Please enter the number of minutes: ";
	std::cin >> minutes;

	display_time(hours, minutes);

	return 0;
}

void display_time(int hours, int minutes) {
	std::cout << "Time: " << hours << ":" << minutes;
}