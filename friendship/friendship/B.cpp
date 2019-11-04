#include "B.h"

B::B()
{
	y = 1;
}

B::~B()
{
}

void B::test_y()
{
	A a;

	a.test_x();
	a.x = 2;
	a.test_x();

	std::cout << y << std::endl;
}
