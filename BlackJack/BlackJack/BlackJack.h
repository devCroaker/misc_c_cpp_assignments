#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>

#define DECK 52
#define NPLAYERS 2
#define AMOUNT 10000

class BlackJack
{
private:
	int *deck;
	int *cards;
	int **players;
	float *bet;
	float *bank;
	int currentPlayer;
	int deckLocation;
public:
	BlackJack();
	~BlackJack();
	void create_deck();
	void make_bet();
	void deal_cards();
	void print_hands();
	void print_hand(int);
	void hit();
	void check_win();
	void payout(int const player, float const amt);
	bool game_over();

};

