#include <iostream>

int main(int argc, char *argv[]) {
	int age;
	std::cout << "Enter your age: ";
	std::cin >> age;

	std::cout << "Your age in months is " << (age * 12);

	return 0;
}