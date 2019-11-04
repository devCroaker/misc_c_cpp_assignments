#include "Poly.h"

int main(int argc, char argv[]) {

	Poly p1(std::pair<float, int>(5.5,5));
	Poly p2(std::pair<float, int>(7.1, 10));

	p1 = p1 + Poly(std::pair<float, int>(4, 3)) + Poly(std::pair<float, int>(2, 0));
	p2 = p2 + Poly(std::pair<float, int>(4, 7)) + Poly(std::pair<float, int>(-2, 5)) + Poly(std::pair<float, int>(2, 3)) + Poly(std::pair<float, int>(-1, 1)) + Poly(std::pair<float, int>(-1, 0));

	Poly p3 = p1 + p2;
	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;
	std::cout << p3;
	return 0;
}