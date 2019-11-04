#include "Person.h"

Person::Person()
{
	lname = "";
	fname[0] = '\0';
}

Person::Person(const std::string & ln, const char * fn)
{
	lname = ln;
	strcpy(fname, fn);
}

void Person::Show() const
{
	std::cout << fname << " " << lname;
}
void Person::FormalShow() const
{
	std::cout << lname << ", " << fname;
}
