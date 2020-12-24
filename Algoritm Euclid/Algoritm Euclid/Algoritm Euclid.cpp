#include<iostream>
#include<conio.h>
using namespace std;
int euclid_scaderi(int x, int y)
{
	while (x != y)
		if (x > y)
			x -= y;
		else
			y -= x;
	return x;
}
int euclid_rec(int x, int y)
{
	if (!y)
		return x;
	return euclid_rec(y, x % y);
}
int euclid_optim(int x, int y)
{
	while (y)
	{
		int r = x % y;
		x = y;
		y = r;
	}
	return x;
}
void euclid_ref(int x, int y, int& cmmdc)
{
	if (!y)
		cmmdc = x;
	else
		euclid_ref(y, x % y, cmmdc);
}
int main()
{
	int m, n;
	cin >> m;
	cin >> n;
	cout << euclid_optim(m, n) << endl;
	getch();
	return 0;
}