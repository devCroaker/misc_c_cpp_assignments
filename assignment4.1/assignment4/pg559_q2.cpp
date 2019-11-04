#include "Person.h"

int main(int argc, char *argv[]) {
	Person one;
	Person two("Lindahl");
	Person three("Engelbert", "Cassy");

	one.Show();
	std::cout << std::endl;
	one.FormalShow();
	std::cout << std::endl << std::endl;

	two.Show();
	std::cout << std::endl;
	two.FormalShow();
	std::cout << std::endl << std::endl;

	three.Show();
	std::cout << std::endl;
	three.FormalShow();
	std::cout << std::endl << std::endl;

	return 0;
}