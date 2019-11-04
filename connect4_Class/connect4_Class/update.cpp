#include "Connect4.h"

void Connect4::update() 
{
	if (column == -1) {
		return;
	}

	for (int i = row - 1; i >= 0; i--) {
		if (board[i][column] == 0) {
			board[i][column] = currentPlayer;
			break;
		}
	}
}