#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	float a, b, x;
	cin >> a;
	cin >> b;
	if (a == 0)
		if (b == 0)
			cout << "x apartine R";
		else
			cout << "nu exista solutie";
	else
	{
		x = -b / a;
		cout << x;
	}
	getch();
}
