#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string>

class Person
{
private:
	static const int LIMIT = 25;
	std::string lname; // Person’s last name
	char fname[LIMIT]; // Person’s first name
public:
	Person();
	Person(const std::string & ln, const char * fn = "Heyyou"); 
	void Show() const; // firstname lastname format
	void FormalShow() const; // lastname, firstname format
};

