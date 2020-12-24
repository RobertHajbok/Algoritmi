/* Un comis voiajor trebuie sa viziteze un numar n de orase. Initial, el se afla într-unul dintre ele, notat 1. Comis voiajorul doreste sa nu treaca de
   doua ori prin acelasi oras, iar la întoarcere sa revina în orasul din care a plecat. Cunoscând legaturile existente între orase, se cere sa se
   tipareasca toate drumurile posibile pe care le poate efectua comis voiajorul.Drumurile dintre orase sunt date sub forma unei matrici a[i][j]=1 daca
   intre orasul i si j exista drum si a[i][j]=0 daca nu exista drum intre orasul i si orasul j. */



#include<iostream>
#include<conio.h>
using namespace std;
int st[20], n, k, a[10][10];
void init()
{
	st[k] = 1;
}
int succesor()
{
	if (st[k] < n)
	{
		st[k]++;
		return 1;
	}
	return 0;
}
int valid()
{
	if (a[st[k - 1]][st[k]] == 0)
		return 0;
	for (int i = 1; i < k; i++)
		if (st[i] == st[k])
			return 0;
	if ((k == n) && (a[1][st[k]] == 0))
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
		cout << st[i] << " ";
	cout << endl;
}
void bkt()
{
	int as;
	k = 2;
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
	cout << "Numarul de orase=";
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	st[1] = 1;
	bkt();
	getch();
}