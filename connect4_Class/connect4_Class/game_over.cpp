#include "Connect4.h"

bool Connect4::game_over()
{
	if (column == -1) {
		return false;
	}

	if (Connect4::check_win()) {
		std::cout << " Player " << currentPlayer << " wins!" << std::endl;
		return true;
	}

	for (int i = 0; i < col; i++) {
		if (board[0][i] == 0) {
			return false;
		}
	}

	return true;
}