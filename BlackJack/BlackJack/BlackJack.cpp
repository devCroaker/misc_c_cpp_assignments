#include "BlackJack.h"



BlackJack::BlackJack()
{
	currentPlayer = 1;
	deckLocation = 0;
	deck = new int[DECK];
	cards = new int[NPLAYERS];
	bet = new float[NPLAYERS];
	bank = new float[NPLAYERS];
	players = new int*[NPLAYERS];
	for (int i = 0; i < NPLAYERS; i++) {
		players[i] = new int[5];
		bank[i] = AMOUNT;
	}
}


BlackJack::~BlackJack()
{
	delete [] deck;
	delete [] cards;
	delete [] bet;
	delete [] bank;
	for (int i = 0; i < NPLAYERS; i++) {
		delete [] players[i];
	}
	delete [] players;
}

void BlackJack::create_deck()
{
	int numCards = 0;
	srand(time(0));

	int totalCards[14];
	for (int i = 0; i < 14; i++) {
		totalCards[i] = 0;
	}

	int card;
	while (numCards < 52) {
		card = rand() % 13 + 1;
		if (totalCards[card] < 4) {
			deck[numCards] = card;
			totalCards[card]++;
			numCards++;
		}
	}
}

void BlackJack::make_bet()
{
	int amount;
	for (int i = 0; i < NPLAYERS - 1; i++) {
		bet[i] = 0;

		if (bank[i] < 0) {
			std::cout << "You are out of money" << std::endl;
			continue;
		}

		do {
			std::cout << "Please make a bet for player " << i << std::endl;
			std::cout << "Remaining funds: $" << bank[i] << std::endl;
			std::cin >> amount;
			if (amount > bank[i] || amount < 1) {
				std::cout << "invalid bet" << std::endl;
			}
		} while (amount > bank[i] || amount < 1);

		bank[i] -= amount;
		bet[i] = amount;
	}

}

void BlackJack::deal_cards()
{
	deckLocation = 0;
	for (int i = 0; i < NPLAYERS; i++) {
		cards[i] = 2;
	}
	for (int i = 0; i < NPLAYERS; i++) {
		for (int j = 0; j < 5; j++) {
			players[i][j] = 0;
		}
	}

	for (int i = 0; i < NPLAYERS; i++) {
		players[i][0] = deck[deckLocation];
		deckLocation++;
		players[i][1] = deck[deckLocation];
		deckLocation++;
	}
}

void BlackJack::print_hands()
{
	for (int i = 0; i < NPLAYERS; i++) {
		print_hand(i);
	}
}

void BlackJack::print_hand(int i)
{
	if (i != NPLAYERS - 1) {
		std::cout << "Player " << i << "'s hand:" << std::endl;
	}
	else {
		std::cout << "Dealers's hand:" << std::endl;
	}
	for (int j = 0; j < cards[i]; j++) {
		if (i != NPLAYERS - 1 && j == 0) {
			std::cout << "?? ";
		}
		else {
			std::cout << players[i][j] << " ";
		}
	}
	std::cout << std::endl << std::endl;
}

void BlackJack::hit()
{
	char willHit = 'Y';
	for (int i = 0; i < NPLAYERS-1; i++) {
		do {
			std::cout << "Player " << i << "would you like to hit? (Y/N)";
			std::cin >> willHit;
			if (toupper(willHit) == 'Y' && cards[i] < 5) {
				players[i][cards[i]-1] = deck[deckLocation];
				deckLocation++;
				cards[i]++;
				print_hand(i);
			}
		} while (willHit != 'N' && cards[i] < 5);
	}

	// House hit
	int houseTotal = 0;
	bool hasAce = false;
	for (int i = 0; i < cards[NPLAYERS - 1]; i++) {
		if (players[NPLAYERS - 1][i] == 1) {
			hasAce = true;
		}
		if (players[NPLAYERS - 1][i] > 9) {
			houseTotal += 10;
		}
		else {
			houseTotal += players[NPLAYERS - 1][i];
		}
	}

	while (houseTotal < 17 && (hasAce && (houseTotal+10 < 17) || houseTotal < 22) ) {
		players[NPLAYERS - 1][cards[NPLAYERS - 1] - 1] = deck[deckLocation];
		deckLocation++;
		cards[NPLAYERS - 1]++;
		print_hand(NPLAYERS - 1);
	}

}

void BlackJack::check_win()
{

}

void BlackJack::payout(int const player, float const amt)
{

}

bool BlackJack::game_over()
{

}
