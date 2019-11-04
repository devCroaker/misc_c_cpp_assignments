#include "Connect4.h"

int main(int argc, char *argv[])
{
	char play = 'Y';
	
	do {
		Connect4 newGame;

		newGame.init_board();
		newGame.print_board();

		while (!newGame.game_over()) {

			newGame.change_player();
			newGame.get_move();
			newGame.update();
			newGame.print_board();
		}

		do {

			if (play != 'Y' && play != 'N') {
				std::cout << "Invalid input" << std::endl;
			}

			std::cout << "Play again? (Y/N)" << std::endl;
			std::cin >> play;
		} while (play != 'Y' && play != 'N');

	} while (play == 'Y');

}