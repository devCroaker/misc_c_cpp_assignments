#include <iostream>

#define ROW 6
#define COL 7
#define WIN 4

using namespace std;

void init_board(int **b);
void printBoard(int **b);
void get_move(int &c, int **b);
void update(int **b, int c=-1, int p=1);
bool game_over(int **b, int m);
bool check_win(int **b, int m = -1, int r = -1, int p = -1);