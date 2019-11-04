#include "prototypes.h"

bool game_over(int **b, int m) {

	int player = -1, row = -1;

	if (m == -1) {
		return false;
	}

	for (int i = 0; i < ROW; i++) {
		if (b[i][m] != 0) {
			player = b[i][m];
			row = i;
			break;
		}
	}

	if (check_win(b,m,row,player)) {
		cout << " Player " << player << " wins!" << endl;
		return true;
	}

	for (int i = 0; i < COL; i++) {
		if (b[0][i] == 0) {
			return false;
		}
	}

	return true;
}