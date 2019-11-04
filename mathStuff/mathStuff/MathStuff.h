#pragma once
#include <iostream>
#include <math.h>

class MathStuff
{
private:
	float a, b;
	float result;
	float delta;

public:
	MathStuff();
	~MathStuff();
	void setInterval(float const x, float const y);
	void setDelta();
	void integrate(float(*f)(float x));

};