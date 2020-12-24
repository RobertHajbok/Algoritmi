#include<iostream>
#include<conio.h>
using namespace std;

double F(double x)
{
	return 1 / (x + 1);
}

double Romberg(double a, double b, double e)
{
	int p = 0;
	double s, n[50], h[50], s2[50], s1[50], i[50];
	h[p] = (b - a) / 2;
	s = F(a) + F(b);
	n[p] = 1;
	s2[p] = 0;
	s1[p] = F(a + h[p]);
	i[p] = (h[p] / 3) * (s + 2 * s2[p] + 4 * s1[p]);
	do
	{
		p = p + 1;
		h[p] = (h[p - 1]) / 2;
		n[p] = 2 * n[p - 1];
		s2[p] = s2[p - 1] + s1[p - 1];
		s1[p] = 0;
		for (int k = 1; k <= n[p]; k++)
			s1[p] += F(a + (2 * k - 1) * h[p]);
		i[p] = (h[p] / 3) * (s + 2 * s2[p] + 4 * s1[p]);
	} while (abs(i[p] - i[p - 1]) >= e);
	return i[p];
}

double Clasic(double a, double b, int n)
{
	double x[21], S, T, M;

	for (int i = 0; i <= n; i++)
		x[i] = a + (i * (b - a)) / n;
	S = 0;
	M = 0;

	for (int i = 1; i <= n; i++)
	{
		S += F(x[i]) + F(x[i - 1]);
		M += F((x[i - 1] + x[i]) / 2);
	}
	T = (double)(b - a) / (6 * n) * (S + 4 * M);
	return T;
}

void main()
{
	cout << "Integrala aproximata prin metoda lui Romberg: " << Romberg(0, 1, 0.00001) << endl;
	cout << "Integrala aproximata prin metoda clasica: " << Clasic(0, 1, 20) << endl;
	_getch();
}