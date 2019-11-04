#include "Connect4.h"

void Connect4::print_board()
{
	for (int i = 0; i < row; i++) {

		for (int j = 0; j < col; j++) {
			std::cout << "-=";
		}

		std::cout << "-" << std::endl;

		for (int j = 0; j < col; j++) {
			std::cout << "|" << board[i][j];
		}

		std::cout << "|" << std::endl;
	}

	for (int j = 0; j < col; j++) {
		std::cout << "-=";
	}

	std::cout << "-" << std::endl;
}