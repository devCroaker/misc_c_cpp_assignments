#include "Connect4.h"

void Connect4::get_move() {

	do {
		std::cout << "Please select a column between 1 and " << col << std::endl;
		std::cin >> column;
		column--;

		if (column < 0 || column > col - 1) {
			std::cout << "Invalid Input" << std::endl;
		}

		if ((column > -1 && column < col) && board[0][column] != 0) {
			std::cout << "Column is full" << std::endl;
			column = -1;
		}

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

	} while (column < 0 || column > col - 1);

}