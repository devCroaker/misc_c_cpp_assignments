#include "Plorg.h"

Plorg::Plorg(const char * nm)
{
	strcpy(name, nm);
	cIdx = 50;
}

void Plorg::updateCIdx(int newIdx)
{
	cIdx = newIdx;
}

void Plorg::report()
{
	std::cout << "Plorg, " << name << ", has a containment index of " << cIdx << std::endl;
}
