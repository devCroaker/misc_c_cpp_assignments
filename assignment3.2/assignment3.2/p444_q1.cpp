#include <iostream>
#include <string>

template <typename T>
T get_input(std::string str, T b);

void outString(std::string);
void outString(std::string, int);

int repeat = 0;

int main(int argc, char *argv[]) {

	char repeatFlag = 'N', quit = 'N';
	std::string text;

	do {
		std::cout << "Enter something: " << std::endl;
		std::getline(std::cin, text);

		do {
			if (toupper(repeatFlag) != 'Y' && toupper(repeatFlag) != 'N') {
				std::cout << "Invalid input" << std::endl;
			}
			repeatFlag = get_input("Do you wish to print this multiple times (Y/N):", repeatFlag);

		} while (toupper(repeatFlag) != 'Y' && toupper(repeatFlag) != 'N');

		if (repeatFlag == 'Y') {
			outString(text, 0);
		}
		else {
			outString(text);
		}

		do {
			if (toupper(quit) != 'Y' && toupper(quit) != 'N') {
				std::cout << "Invalid input" << std::endl;
			}
			quit = get_input("Do you wish to enter text again (Y/N): ", quit);

		} while (toupper(quit) != 'Y' && toupper(quit) != 'N');

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

void outString(std::string str) {

	std::cout << str << std::endl;
	repeat++;
}

void outString(std::string str, int i) {

	repeat++;
	for (int j = 0; j < repeat; j++) {
		outString(str);
		repeat--;
	}
}