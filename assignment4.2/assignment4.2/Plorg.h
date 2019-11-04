#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>

class Plorg
{
private:
	static const int LIMIT = 20;
	char name[LIMIT];
	int cIdx;

public:
	Plorg(const char * nm = "Plorga");
	void updateCIdx(int);
	void report();
};

