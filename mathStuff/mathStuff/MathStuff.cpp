#include "MathStuff.h"

MathStuff::MathStuff() {
	result = 0;
}

MathStuff::~MathStuff() {

}

void MathStuff::setInterval(float const x, float const y) {
	a = x, b = y;
	setDelta();
}

void MathStuff::setDelta() {
	delta = (b - a) / 1000;
}

void MathStuff::integrate(float(*f)(float x)) {
	for (int i = 0; i < 1000; i++) {
		result += 0.5*(f(a + delta * i) + f(a + delta * (i + 1)))*delta;
	}
}