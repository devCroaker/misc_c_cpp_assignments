#include <iostream>
#include <string>

template <typename T>
T get_input(std::string str, T b);

double calculate(double a, double b, double f(double a, double b));
double add(double a, double b);
double sub(double a, double b);
double mul(double a, double b);
double div(double a, double b);

int main(int argc, char *argv[]) {

	char quit = 'N';
	std::string type[4] = {
		"addition", "subtraction", "multiplication", "division"
	};

	double (*functions[4])(double, double) = {
		&add, &sub, &mul, &div
	};

	do {
		double a, b, c = 0.00;

		// Get the first input
		a = get_input <double>("Please insert the first double: ", c);

		// Get the second input
		b = get_input <double>("Please insert the second double: ", c);

		// Do the calculations
		for (int i = 0; i < 4; i++) {
			c = calculate(a, b, *(functions[i]));

			std::cout << "Result of " << type[i] << " is equal to " << c << std::endl;
		}
		std::cout << std::endl;

		// Ask if they want to quit
		do {
			if (toupper(quit) != 'N' && toupper(quit) != 'Y') {
				std::cout << "Invalid input" << std::endl;
			}
			quit = get_input <char>("Do you want to calculate again? (Y/N)", quit);
		} while (toupper(quit) != 'N' && toupper(quit) != 'Y');

	} while (toupper(quit) != 'N');


	return 0;
}

template <typename T>
T get_input(std::string str, T b) {
	bool valid = false;
	T input;

	do {
		std::cout << str << std::endl;

		if (!(std::cin >> input)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input" << std::endl;
		}
		else {
			valid = true;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!valid);
	std::cout << std::endl;

	return input;
}

double calculate(double a, double b, double f(double a, double b)) {
	return f(a, b);
}

double add(double a, double b) {
	return a + b;
}

double sub(double a, double b) {
	return a - b;
}

double mul(double a, double b) {
	return a * b;
}

double div(double a, double b) {
	return a / b;
}
