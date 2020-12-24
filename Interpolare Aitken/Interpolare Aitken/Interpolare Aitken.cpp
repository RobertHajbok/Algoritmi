#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	int m;
	double d[50][50], a[50];
	cout << "Introduceti gradul maxim al polinomului de interpolare: ";
	cin >> m;
	double e, l;
	cout << "Introduceti eroarea absoluta maxima admisibila: ";
	cin >> e;
	cout << "Introduceti punctul in care se aproximeaza functia f: ";
	cin >> l;
	for (int i = 0; i < m; i++)
	{
		double x, fx;
		cout << "x" << i + 1 << " = ";
		cin >> x;
		a[i] = x;
		cout << "fx" << i + 1 << " = ";
		cin >> fx;
		d[i][0] = fx;
	}
	for (int i = 1; i <= m; i++)
		for (int j = i + 1; j <= m; j++)
			if (abs(a[i] - e) > abs(a[j] - e))
			{
				double aux = d[i][0];
				d[i][0] = d[j][0];
				d[j][0] = aux;
			}
	bool gasit = false;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j <= i - 1; j++)
			d[i][j + 1] = 1 / (a[i] - a[j]) * (d[j][j] * (a[i] - l) - d[i][j] * (a[j] - l));
		if (abs(d[i][i] - d[i - 1][i - 1]) < e)
		{
			cout << "\nRezultatul aproximarii: " << d[i][i];
			gasit = true;
			break;
		}
	}
	if (!gasit)
		cout << "Nu s-a putut calcula o aproximatie cu precizia dorita";
	_getch();
}