#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	int n;
	double x[50], y[50];
	cout << "Introduceti numarul datelor: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "x" << i + 1 << " = ";
		cin >> x[i];
		cout << "y" << i + 1 << " = ";
		cin >> y[i];
	}
	double sx = 0, sxp = 0, sxy = 0, sy = 0;
	for (int i = 0; i < n; i++)
	{
		sxp = sxp + x[i] * x[i];
		sx = sx + x[i];
		sy = sy + y[i];
		sxy = sxy + x[i] * y[i];
	}
	double a = (n * sxy - sx * sy) / (n * sxp - sx * sx);
	double b = (sxp * sy - sxy * sx) / (n * sxp - sx * sx);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	getch();
}