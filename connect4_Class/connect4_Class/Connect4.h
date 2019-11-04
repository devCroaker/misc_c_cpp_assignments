#pragma once
#include <iostream>

class Connect4
{
private:
	int row;
	int col;
	int win;
	int **board;
	int currentPlayer;
	int column;

public:
	Connect4();
	Connect4(int r, int c, int w);
	~Connect4();
	void init_board();
	void print_board();
	void get_move();
	void update();
	void change_player();
	bool game_over();
	bool check_win();
};

