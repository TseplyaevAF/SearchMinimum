#include "methods.h"

float f(float x) {
	return (5 * x * x + 7) / (x * x + 2);
}

void Sven(float &a, float &b, float x0, float d) {
	float xC = x0;
	float xL = x0 - d;
	float xR = x0 + d;
	float xN;
	
	while (!(f(xL) > f(xC)) && (f(xR) > f(xC))) {
		if ((f(xL) > f(xC)) && (f(xC) > f(xR))) {
			xN = xR + 2 * d;
			xL = xC;
			xC = xR;
			xR = xN;
		}
		else
			if ((f(xL) < f(xC)) && (f(xC) < f(xR))) {
				xN = xL - 2 * d;
				xR = xC;
				xC = xL;
				xL = xN;
			}
		d = 2 * d;
	}
	a = xL;
	b = xR;
}

float Halving(float a, float b) {
	const float E = 0.001;
	float x1, x2, x3, x = 0;

	while (b - a < 2 * E) {
		x1 = (3 * a + b) / 4;
		x2 = (a + b) / 4;
		x3 = (a + 3 * b) / 4;
		if ((f(x1) < f(x2)) && (f(x2) < f(x3)))
			b = x2;
		else
			if ((f(x1) > f(x2)) && (f(x2) > f(x3)))
				a = x2;
			else
			{
				a = x1;
				b = x3;
			}
		x = (a + b) / 2;
	}
	return x;
}

float Golden(float a, float b) {
	float E = 0.001;
	float phi = (sqrt(5) - 1) / 2,
		x1, x2, x_min = 0;
	while (b - a < 2 * E) {
		x1 = phi * a + (1 - phi) * b;
		x2 = (1 - phi) * a + phi * b;
		if (f(x1) < f(x2))
			b = x2;
		else
			if (f(x1) > f(x2))
				a = x1;
		x_min = (a + b) / 2;
	}
	return x_min;
}

float Passive(float a, float b) {
	float E = 0.001, k = 1, xK, min, n;

	n = ((b - a) / E) - 1;
	xK = a + k * ((b - a) / (n + 1));
	min = f(a);

	while (f(xK) < min) {
		min = f(xK);
		k++;
		xK = a + k * ((b - a) / (n + 1));
	}
	return xK;
}