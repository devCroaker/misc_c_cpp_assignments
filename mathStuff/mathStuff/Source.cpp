#include "MathStuff.h"

int main(int argc, char *argv[]) {
	MathStuff m;
	float x, y;

	std::cout << "Please input a x value: " << std::endl;
	std::cin >> x;

	std::cout << "Please input a y value: " << std::endl;
	std::cin >> y;

	m.setInterval(x, y);

	m.integrate(sin);

	return 0;
}