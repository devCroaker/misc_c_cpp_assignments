#include "Plorg.h"

int main(int argc, char *argv[]) {

	Plorg pl1;
	Plorg pl2("Sparky");

	pl1.report();
	pl2.report();

	std::cout << std::endl << "CHANGING CONTAINMENT INDEX" << std::endl << std::endl;
	pl1.updateCIdx(25);
	pl2.updateCIdx(75);

	pl1.report();
	pl2.report();

	return 0;
}