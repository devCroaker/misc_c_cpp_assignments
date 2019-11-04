#include "Connect4.h"

Connect4::Connect4()
{
	row = 6;
	col = 7;
	win = 4;
	currentPlayer = -1;
	column = -1;

	board = new int *[row];

	for (int i = 0; i < row; i++) {
		board[i] = new int[col];
	}

	std::cout << "Constructor called";
}

Connect4::Connect4(int r, int c, int w)
{
	row = r;
	col = c;
	win = w;
	currentPlayer = -1;
	column = -1;

	board = new int *[row];

	for (int i = 0; i < row; i++) {
		board[i] = new int[col];
	}
}

Connect4::~Connect4()
{
	for (int i = 0; i < row; i++) {
		delete[] board[i];
	}
	delete[] board;

	std::cout << "Destructor called";
}
