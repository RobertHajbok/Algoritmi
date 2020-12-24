#include<iostream>
#include<conio.h>
using namespace std;

double F(double x)
{
	return (pow(x, 5) - 5 * x + 1);
}

double DF(double x)
{
	return (5 * pow(x, 4) - 5);
}

double D2F(double x)
{
	return (20 * pow(x, 3));
}

double Contractia(double x)
{
	return (1 / 5.0) * (pow(x, 5) + 1);
}

double MetodaInjumatatirii(double a, double b, double eps)
{
	double c;
	if (b - a < eps)
		return (a + b) / 2;
	else
	{
		c = (a + b) / 2.0;
		if (F(a) * F(c) < 0)
			return MetodaInjumatatirii(a, c, eps);
		else
			return MetodaInjumatatirii(c, b, eps);
	}
}

double MetodaAproxSuccesive(double a, double b, double eps, double itInit)
{
	double x[100], solutie = 0;
	int n = 1;
	x[0] = itInit;
	x[1] = Contractia(itInit);
	while (fabs((x[n] - x[n - 1])) >= eps)
	{
		n++;
		x[n] = Contractia(x[n - 1]);
	}
	if (fabs((x[n] - x[n - 1])) < eps)
		solutie = x[n];
	return solutie;
}

double MetodaTangentei(double a, double b, double eps)
{
	double x[50];
	if (F(a) * D2F(a) > 0)
		x[0] = a;
	else
		x[0] = b;
	int n = 0;
	do
	{
		n++;
		x[n] = x[n - 1] - F(x[n - 1]) / DF(x[n - 1]);
	} while (fabs(x[n] - x[n - 1]) >= eps);
	return x[n];
}

double MetodaCoardei(double a, double b, double eps)
{
	double x[6000];
	int n = 0;
	if (F(a) * D2F(a) < 0)
		x[0] = a;
	else
		x[0] = b;
	do
	{
		n++;
		if (x[0] == a)
			x[n] = x[n - 1] - F(x[n - 1]) / (F(b) - F(x[n - 1])) * (b - x[n - 1]);
		else
			x[n] = x[n - 1] - F(x[n - 1]) / (F(a) - F(x[n - 1])) * (a - x[n - 1]);
	} while (fabs(x[n] - x[n - 1]) >= eps);
	return x[n];
}

double MetodaCombinata(double a, double b, double eps)
{
	int n = 0;
	double xs[50], xt[50];
	if (F(a) * D2F(a) < 0)
	{
		xs[0] = a;
		xt[0] = b;
	}
	else
	{
		xs[0] = b;
		xt[0] = a;
	}
	do
	{
		xt[n + 1] = xt[n] - F(xt[n]) / DF(xt[n]);
		xs[n + 1] = xs[n] - (F(xs[n]) / (F(xt[n]) - F(xs[n]))) * (xt[n] - xs[n]);
		n++;
	} while (fabs(xt[n] - xs[n]) > eps);
	return xt[n];
}

void main()
{
	int x = 0;
	cout << "Solutia calculata prin metoda injumatatirii: " << MetodaInjumatatirii(-1, 1, 0.000001) << endl;
	cout << "Solutia calculata prin metoda aproximatiilor succesive: " << MetodaAproxSuccesive(-1, 0, 0.00001, 0.8) << endl;
	cout << "Solutia calculata prin metoda tangentei: " << MetodaTangentei(-1, 0, 0.000001) << endl;
	cout << "Solutia calculata prin metoda coardei: " << MetodaCoardei(-1, 0, 0.000001) << endl;
	cout << "Solutia calculata prin metoda combinata secanta-tangenta: " << MetodaCombinata(-1, 0, 0.000001);
	_getch();
}