/* La o petrecere sunt invitate un numar de perechi, sot si sotie.Ei trebuie asezati in jurul unei mese rotunde astfel incat membrii aceleasi perechi sa
nu fie unul langa altul,dar in acelasi timp fiecare femeie sa aiba vecini doi barbati si fiecare barbat sa aiba vecini doua femei.
Femeile vor avea numere impare iar barbatii numere pare.Perechile vor fi de forma (1,2),(3,4),(5,6) etc */
#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
int st[20], n;
int valid(int p)
{
	int i;
	for (i = 1; i < p; i++)
		if (st[i] == st[p])
			return 0;
	if ((st[p] - st[p - 1]) % 2 == 0)
		return 0;
	if (st[p] % 2 == 0 && st[p] - st[p - 1] == 1)
		return 0;
	if (st[p] % 2 == 1 && st[p] - st[p - 1] == -1)
		return 0;
	if (p == n && st[p] == 2)
		return 0;
	return 1;
}
int sol(int p)
{
	return (p == n);
}
void bkt(int p)
{
	int val, j;
	for (val = 2; val <= n; val++)
	{
		st[p] = val;
		if (valid(p))
			if (sol(p))
			{
				for (j = 1; j <= p; j++)
					cout << st[j] << " ";
				cout << endl;
			}
			else
				bkt(p + 1);
	}
}
void main()
{
	int j;
	st[1] = 1;
	cout << "n=";
	cin >> n;
	for (j = 2; j <= n; j++)
		st[j] = 0;
	bkt(2);
	getch();
}