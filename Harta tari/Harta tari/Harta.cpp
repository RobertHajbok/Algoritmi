/* Fiind data o harta cu n tari, se cer toate solutiile de colorare a hartii, utilizand cel mult patru culori, astfel incat doua tari ce au frontiera
comuna sa fie colorate diferit. Este demonstrat faptul ca sunt suficiente numai patru culori pentru ca orice harta sa poata fi colorata.*/

#include<iostream>
#include<conio.h>
using namespace std;
int st[20], n, k, a[20][20];
void init()
{
	st[k] = 0;
}
int succesor()
{
	if (st[k] < 4)
	{
		st[k]++;
		return 1;
	}
	return 0;
}
int valid()
{
	for (int i = 1; i < k; i++)
		if (st[i] == st[k] && a[i][k] == 1)
			return 0;
	return 1;
}
int sol()
{
	return (k == n);
}
void tipar()
{
	for (int i = 1; i <= n; i++)
		cout << "Tara numarul " << i << " culoarea " << st[i] << endl;
	cout << endl;
}
void bkt()
{
	int as; k = 1;
	init();
	while (k > 0)
	{
		do
		{
		} while ((as = succesor()) && !valid());
		if (as)
			if (sol()) tipar();
			else
			{
				k++;
				init();
			}
		else
			k--;
	}
}

void main()
{
	cout << "Numarul de tari=";
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	bkt();
	_getch();
}