#include "prototypes.h"

int main(int argc, char *argv[]) {

	char play = 'Y';

	int **board;
	// int **board = new int[ROW][COL]; Same as the decleration and for loop belown but quicker
	int column, currentPlayer;

	board = new int *[ROW];

	for (int i = 0; i < ROW; i++) {
		board[i] = new int[COL];
	}

	do {

		column = -1;
		currentPlayer = 1;

		init_board(board);
		printBoard(board);


		while (!game_over(board, column)) {

			get_move(column, board);

			update(board, column, currentPlayer);

			if (currentPlayer == 1)
				currentPlayer++;
			else
				currentPlayer--;

			printBoard(board);

		}

		do {

			if (play != 'Y' && play != 'N') {
				cout << "Invalid input" << endl;
			}

			cout << "Play again? (Y/N)" << endl;
			cin >> play;
		} while (play != 'Y' && play != 'N');

	} while (play == 'Y');

	for (int i = 0; i < ROW; i++) {
		delete[] board[i];
	}
	delete[] board;

	return 0;
}