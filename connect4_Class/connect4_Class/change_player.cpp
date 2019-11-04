#include "Connect4.h"

void Connect4::change_player()
{
	if (currentPlayer == 1) {
		currentPlayer++;
	}
	else {
		currentPlayer = 1;
	}
}