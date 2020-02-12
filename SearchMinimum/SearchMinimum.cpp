#include <iostream>
#include "methods.h"
#include <math.h>


using namespace std;

int main()
{
	setlocale(0, "RUS");

	float a = 0, b = 0,
		x0 = 8, d = 0.9;

	Sven(a, b, x0, d);
	cout << a << " " << b << endl;
	cout << "Метод деления пополам:\n" << "x_min = " << Halving(a, b) << endl;
	cout << "Метод золотого сечения:\n" << "x_min = " << Golden(a, b) << endl;
	cout << "Пассивный поиск:\n" << "x_min = " << Passive(a, b) << endl;

	return 0;
}
