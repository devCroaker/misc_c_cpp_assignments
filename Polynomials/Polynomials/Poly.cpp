#include "Poly.h"

bool sortbysec(const std::pair<int, int> &a,
	const  std::pair<int, int> &b)
{
	return (a.second > b.second);
}

Poly::Poly()
{
	
}

Poly::Poly(std::pair<float, int> p)
{
	list.push_back(p);
}

Poly::Poly(const Poly&p)
{
	list = p.list;
}

Poly::~Poly()
{
	list.clear();
}

Poly& Poly::operator=(const Poly&p)
{
	list = p.list;

	return *this;
}

Poly Poly::operator +(Poly p)
{
	Poly temp;
	int cont = 0;
	temp.list = list;

	for (int i = 0; i < p.list.size(); i++) {
		cont = 0;
		for (int j = 0; j < temp.list.size(); j++) {
			if (p.list[i].second == temp.list[j].second) {
				temp.list[j].first = temp.list[j].first + p.list[i].first;
				cont = 1;
			}
		}
		if (cont == 0) {
			temp.list.push_back(p.list[i]);
		}
	}

	std::sort(temp.list.begin(), temp.list.end(), sortbysec);

	return temp;
}

std::ostream& operator <<(std::ostream& os, Poly &p)
{
	os << "p(x) = ";
	for (int i = 0; i < p.list.size(); i++) {
		
		if (p.list[i].first > 0 && i != 0) {
			os << "+";
		}
		if (p.list[i].second > 0) {
			os << p.list[i].first << "x^" << p.list[i].second << " ";
		}
		else {
			os << p.list[i].first << " ";
		}
	}

	return os;
}
