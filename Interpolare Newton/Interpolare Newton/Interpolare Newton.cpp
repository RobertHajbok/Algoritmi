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
		d[0][i] = fx;
	}
	for (int i = 0; i < m; i++)
		for (int j = i + 1; j < m; j++)
			if (abs(a[i] - l) > abs(a[j] - l))
			{
				double aux = d[0][i];
				d[0][i] = d[0][j];
				d[0][j] = aux;
				aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			}
	//Diferente divizate
	for (int i = 1; i < m; i++)
		for (int j = 0; j < m - i; j++)
			d[i][j] = (d[i - 1][j + 1] - d[i - 1][j]) / (a[j + i] - a[j]);
	bool gasit = false;
	double n[50];
	n[0] = d[0][0];
	for (int i = 1; i < m; i++)
	{
		double produs = 1;
		for (int j = 0; j <= i - 1; j++)
			produs = produs * (l - a[j]);
		n[i] = n[i - 1] + produs * d[0][i];
		if (abs(n[i] - n[i - 1]) < e)
		{
			cout << "\nRezultatul aproximarii: " << n[i];
			gasit = true;
			break;
		}
	}
	if (!gasit)
		cout << "Nu s-a putut calcula o aproximatie cu precizia dorita";
	getch();
}