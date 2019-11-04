#include "Connect4.h"

bool Connect4::check_win()
{
	int last_row, count = 0;

	for (int i = 0; i < row; i++) {
		if (board[i][column] != 0) {
			last_row = i;
			break;
		}
	}

	if (currentPlayer == -1) {
		return false;
	}

	// check horizontal
	for (int i = column; i >= 0; i--) {
		if (board[last_row][i] == currentPlayer) {
			count++;
		}
		else {
			break;
		}
	}

	for (int i = column + 1; i < col; i++) {
		if (board[last_row][i] == currentPlayer) {
			count++;
		}
		else {
			break;
		}
	}

	if (count >= win) {
		return true;
	}

	// check vertical
	count = 0;
	for (int i = last_row; i < row; i++) {
		if (board[i][column] == currentPlayer) {
			count++;
		}
		else {
			break;
		}
	}

	if (count >= win) {
		return true;
	}

	// Check Diag
	count = 0;
	for (int i = column, j = last_row; i >= 0; i--, j--) {

		if (j < 0) {
			break;
		}

		if (board[j][i] == currentPlayer) {
			count++;
		}
		else {
			break;
		}
	}

	for (int i = column + 1, j = last_row + 1; i < row; i++, j++) {
		if (j >= col) {
			break;
		}

		if (board[i][j] == currentPlayer) {
			count++;
		}
		else {
			break;
		}
	}

	if (count >= win) {
		return true;
	}

	// Check anti-Diag
	count = 0;
	for (int i = column, j = last_row; i < row; i++, j--) {

		if (j < 0) {
			break;
		}

		if (board[i][j] == currentPlayer) {
			count++;
		}
		else {
			break;
		}
	}

	for (int i = column - 1, j = last_row + 1; i >= 0; i--, j++) {
		if (j >= col) {
			break;
		}

		if (board[i][j] == currentPlayer) {
			count++;
		}
		else {
			break;
		}
	}

	if (count >= win) {
		return true;
	}

	return false;
}