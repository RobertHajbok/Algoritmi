#include<iostream>
#include<conio.h>
using namespace std;

double F(double x)
{
	return 1 / (x + 1);
}

double Newton(double a, double b, int n)
{
	double x[21], y[21], z[21], S, T, U, V;

	for (int i = 0; i <= n; i++)
		x[i] = a + (i * (b - a)) / n;

	for (int i = 1; i <= n; i++)
	{
		y[i] = x[i - 1] + (x[i] - x[i - 1]) / 3;
		z[i] = x[i - 1] + (2 * (x[i] - x[i - 1])) / 3;
	}
	S = 0;
	U = 0;
	V = 0;

	for (int i = 1; i <= n; i++)
	{
		S += F(x[i]) + F(x[i - 1]);
		U += F(y[i]);
		V += F(z[i]);
	}
	T = (double)(b - a) / (8 * n) * (S + 3 * U + 3 * V);
	return T;
}

void main()
{
	// ln 2 = 0.69314718055994530941723212145818
	cout << "Integrala aproximata prin metoda lui Newton: " << Newton(0, 1, 20) << endl;
	_getch();
}