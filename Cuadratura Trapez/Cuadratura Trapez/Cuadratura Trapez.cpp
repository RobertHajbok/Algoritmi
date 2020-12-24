#include<iostream>
#include<conio.h>
using namespace std;

double F(double x)
{
	return 1 / (x + 1);
}

double Fderiv(double x)
{
	return -1 / ((x + 1) * (x + 1));
}

double CuadraturaPerturbata(double a, double b, double n)
{
	double x[101], T = 0;
	for (int i = 0; i <= n; i++)
		x[i] = a + i * (b - a) / n;
	for (int i = 1; i <= n; i++)
		T += F(x[i - 1]) + F(x[i]);
	double S = (b - a) / (2 * n) * T - ((b - a) * (b - a)) / (12 * n * n) * (Fderiv(b) - Fderiv(a));
	return S;
}

double Romberg(double a, double b, double e)
{
	int p = 0;
	double s[50], n[50], h[50];
	h[p] = b - a;
	s[p] = (h[p] / 2) * (F(a) + F(b));
	n[p] = 1;
	do
	{
		p = p + 1;
		h[p] = (h[p - 1]) / 2;
		double sum = 0;
		for (int i = 1; i <= n[p - 1]; i++)
			sum += F(a + (2 * i - 1) * h[p]);
		sum = h[p] * sum;
		s[p] = s[p - 1] / 2 + sum;
		n[p] = 2 * n[p - 1];
	} while (abs(s[p] - (s[p - 1])) >= e);
	return s[p];
}

double Clasic(double a, double b, int n)
{
	double x[101], S, T;

	for (int i = 0; i <= n; i++)
		x[i] = a + (i * (b - a)) / n;
	S = 0;

	for (int i = 1; i <= n; i++)
		S = S + (F(x[i]) + F(x[i - 1]));
	T = (double)(b - a) / (2 * n) * S;
	return T;
}

void main()
{
	cout << "Integrala aproximata prin metoda cuadraturii perturbate: " << CuadraturaPerturbata(0, 1, 100) << endl;
	cout << "Integrala aproximata prin metoda lui Romberg: " << Romberg(0, 1, 0.00001) << endl;
	cout << "Integrala aproximata prin metoda clasica: " << Clasic(0, 1, 100) << endl;
	getch();
}