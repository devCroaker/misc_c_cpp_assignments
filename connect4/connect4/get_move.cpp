#include "prototypes.h"

void get_move(int &c, int **b) {

	do {
		cout << "Please select a column between 1 and " << COL << endl;
		cin >> c;
		c--;

		if (c < 0 || c > COL - 1) {
			cout << "Invalid Input" << endl;
		} 
		
		if ((c > -1 && c < COL) && b[0][c] != 0) {
			cout << "Column is full" << endl;
			c = -1;
		}

		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

	} while (c < 0 || c > COL - 1);

}