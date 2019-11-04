#include "prototypes.h"

void printBoard(int **b) {

	for (int i = 0; i < ROW; i++) {

		for (int j = 0; j < COL; j++)
			cout << "-=";
		cout << "-" << endl;

		for (int j = 0; j < COL; j++) 
			cout << "|" << b[i][j];
		
		cout << "|" << endl;

	}

	for (int j = 0; j < COL; j++)
		cout << "-=";
	cout << "-" << endl;


}