#include "prototypes.h"

void init_board(int **b) {

	for (int i = 0; i < ROW; i++) 
		for (int j = 0; j < COL; j++) 
			b[i][j] = 0;

}