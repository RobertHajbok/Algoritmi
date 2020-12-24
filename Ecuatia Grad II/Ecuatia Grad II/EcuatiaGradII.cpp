#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	float a, b, c;
	float d, x;
	cin >> a;
	cin >> b;
	cin >> c;
	if (a != 0)
	{
		d = b * b - 4 * a * c;
		if (d >= 0)
		{
			float x1 = (-b + sqrt(d)) / (2 * a);
			float x2 = (-b - sqrt(d)) / (2 * a);
			cout << x1;
			cout << x2;
		}
		else
			cout << "ecuatia nu are solutii reale";
	}
	else
		if (b == 0)
			if (c == 0)
				cout << "ecuatia are o infinitate de solutii";
			else
				cout << "x apartine R";
		else
		{
			x = -c / b;
			cout << x;
		}
	getch();
}

