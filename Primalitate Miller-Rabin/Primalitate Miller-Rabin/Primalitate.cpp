#include<iostream>
#include<conio.h>
using namespace std;
int exponentiere_log(int a, int b, int n)
{
	if (b == 0)
		return 1;
	if ((b & 1) == 0)					//daca b este numar par
	{
		int temp = exponentiere_log(a, b >> 1, n);
		return (temp * temp) % n;
	}
	return ((a % n) * exponentiere_log(a, b - 1, n)) % n;
}
bool Miller_Rabin(int p)
{
	int a[] = { 2,7,61,0 }, s = 0, d = p - 1;
	while (d % 2 == 0)
	{
		d /= 2;
		++s;
	}
	for (int k = 0; a[k] && a[k] < p; ++k)
	{
		int x = exponentiere_log(a[k], d, p);
		if (x == 1 || x == p - 1)
			continue;				//urmatoarea iteratie a lui k
		bool doi = true;				//verificam daca relatia (2) este adevarata, initial presupunem ca da
		for (int r = 1; r < s; ++r)
		{
			x = (x * x) % p;
			if (x == 1)
				return false;
			else
				if (x == p - 1)
				{
					doi = false;
					break;
				}
		}
		if (doi)
			return false;			//daca (2) este adavarata, atunci p este compus
		return true;				//PROBABIL prim (in practica putem fi SIGURI deoarece p este de tip int)
	}
}
int main()
{
	int nr;
	cout << "Testati numarul: ";
	cin >> nr;
	if (Miller_Rabin(nr) == true)
		cout << "Numarul probabil este prim\n";
	else
		cout << "Numarul nu este prim\n";
	getch();
	return 0;
}
