#pragma once
#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

class Poly
{
private:
	std::vector<std::pair<float, int>> list;
public:
	Poly();
	Poly(std::pair<float, int>);
	Poly(const Poly&);
	~Poly();

	Poly& operator =(const Poly&);
	Poly operator +(Poly);

	friend std::ostream& operator <<(std::ostream& os, Poly &p);
};

