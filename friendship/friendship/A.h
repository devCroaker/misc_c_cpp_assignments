#pragma once
#include <iostream>

class A
{
friend class B;
private:
	int x;
public:
	A();
	~A();
	void test_x();
};

