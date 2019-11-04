#include "prototypes.h"

bool check_win(int **b, int c, int r, int p) {

	int count = 0;
	if (p == -1) {
		return false;
	}

	// check horizontal
	for (int i = c; i >= 0; i--) {
		if (b[r][i] == p) {
			count++;
		} else {
			break;
		}
	}

	for (int i = c + 1; i < COL; i++) {
		if (b[r][i] == p) {
			count++;
		} else {
			break;
		}
	}

	if (count >= WIN) {
		return true;
	}

	// check vertical
	count = 0;
	for (int i = r; i < ROW; i++) {
		if (b[i][c] == p) {
			count++;
		} else {
			break;
		}
	}

	if (count >= WIN) {
		return true;
	}

	// Check Diag
	count = 0;
	for (int i = c, j = r; i >= 0; i--, j--) {

		if (j < 0) {
			break;
		}

		if (b[j][i] == p) {
			count++;
		} else {
			break;
		}
	}

	for (int i = c+1, j = r+1; i < ROW; i++, j++) {
		if (j >= COL) {
			break;
		}

		if (b[i][j] == p) {
			count++;
		}
		else {
			break;
		}
	}

	if (count >= WIN) {
		return true;
	}

	// Check anti-Diag
	count = 0;
	for (int i = c, j = r; i < ROW; i++, j--) {

		if (j < 0) {
			break;
		}

		if (b[i][j] == p) {
			count++;
		}
		else {
			break;
		}
	}

	for (int i = c - 1, j = r + 1; i >= 0; i--, j++) {
		if (j >= COL) {
			break;
		}

		if (b[i][j] == p) {
			count++;
		}
		else {
			break;
		}
	}

	if (count >= WIN) {
		return true;
	}

	return false;

}