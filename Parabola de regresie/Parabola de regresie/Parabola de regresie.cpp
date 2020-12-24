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
	double sx = 0, sx2 = 0, sx3 = 0, sx4 = 0, sxy = 0, sy = 0, sx2y = 0;
	for (int i = 0; i < n; i++)
	{
		sx = sx + x[i];
		sx2 = sx2 + x[i] * x[i];
		sx3 = sx3 + x[i] * x[i] * x[i];
		sx4 = sx4 + x[i] * x[i] * x[i] * x[i];
		sxy = sxy + x[i] * y[i];
		sy = sy + y[i];
		sx2y = sx2y + x[i] * x[i] * y[i];
	}
	double d = n * sx2 * sx4 + 2 * sx * sx2 * sx3 - (sx2 * sx2 * sx2) - (sx * sx) * sx4 - n * (sx3 * sx3);
	double d1 = n * sx2 * sx2y + sx * sx2 * sxy + sx3 * sx * sy - (sx2 * sx2) * sy - (sx * sx) * sx2y - n * sx3 * sxy;
	double d2 = n * sxy * sx4 + sx2 * sx3 * sy + sx * sx2 * sx2y - (sx2 * sx2) * sxy - sx4 * sx * sy - n * sx2y * sx3;
	double d3 = sx4 * sx2 * sy + sx * sx2y * sx3 + sx2 * sx3 * sxy - (sx2 * sx2) * sx2y - sx * sxy * sx4 - (sx3 * sx3) * sy;
	cout << "a = " << d1 / d << endl;
	cout << "b = " << d2 / d << endl;
	cout << "c = " << d3 / d << endl;
	getch();
}