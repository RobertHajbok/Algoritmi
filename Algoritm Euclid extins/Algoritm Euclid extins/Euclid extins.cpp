/* Algoritmul lui Euclid extins este folosit pentru a gasi numerele a si b din ecuatia diofantica aX+bY=cmmdc(X,Y). Algoritmul este folositor
atunci cand avem de determinat un invers multiplicativ modulo Y, deoarece a este inversul multiplicativ al lui X modulo Y. */
#include<iostream>
#include<conio.h>
using namespace std;
int a, b;
void euclid_extins(int x, int y, int& a, int& b)
{
	if (x % y == 0)
	{
		a = 0;
		b = 1;
		return;
	}
	int ta, tb;
	euclid_extins(y, x % y, ta, tb);
	a = tb;
	b = ta - tb * (x / y);
}
int main()
{
	int m, n;
	cin >> m;
	cin >> n;
	euclid_extins(m, n, a, b);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	getch();
	return 0;
}

