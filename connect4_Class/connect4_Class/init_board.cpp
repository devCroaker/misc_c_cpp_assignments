#include "Connect4.h"

void Connect4::init_board()
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			board[i][j] = 0;
		}
	}
}