#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	int a[10][10], n, m, i, j;
	cin >> n;
	cin >> m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			cin >> a[i][j];
	int sus = 1, stanga = 1, jos = n, dreapta = m, q = 1;
	while (q <= m * n)
	{
		for (i = stanga; i <= dreapta; i++)
		{
			cout << a[stanga][i] << " ";
			q++;
		}
		sus++;
		for (i = sus; i <= jos; i++)
		{
			cout << a[i][dreapta] << " ";
			q++;
		}
		dreapta--;
		if (q <= m * n)
			for (i = dreapta; i >= stanga; i--)
			{
				cout << a[jos][i] << " ";
				q++;
			}
		jos--;
		if (q <= m * n)
			for (i = jos; i >= sus; i--)
			{
				cout << a[i][stanga] << " ";
				q++;
			}
		stanga++;
	}
	getch();
}