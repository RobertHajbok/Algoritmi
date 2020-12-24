#include<iostream>
#include<conio.h>
using namespace std;
int phi(int y)
{
	int r = y, yt = y;
	for (int i = 2; i * i <= y; ++i)
		if (yt % i == 0)
		{
			r /= i;
			r *= i - 1;
			while (yt % i == 0)
				yt /= i;
		}
	if (yt > 1)
	{
		r /= yt;
		r *= yt - 1;
	}
	return r;
}
int main()
{
	int nr;
	cout << "Numarul: ";
	cin >> nr;
	cout << "Indicatorul lui Euler pentru numarul " << nr << " este " << phi(nr) << endl;
	getch();
	return 0;
}
