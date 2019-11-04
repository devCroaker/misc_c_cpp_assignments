#include "prototypes.h"

void update(int **b, int c, int p) {

	if (c == -1) {
		return;
	}

	for (int i = ROW-1; i >= 0; i--) {
		if (b[i][c] == 0) {
			b[i][c] = p;
			break;
		}
	}

}