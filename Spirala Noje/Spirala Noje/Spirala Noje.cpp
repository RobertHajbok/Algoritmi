#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	int m, n, i, j, a[15][15], s;
	cin >> n;
	cin >> m;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> a[i][j];
	for (s = 0; s < (n + 1) / 2; s++)
	{
		for (j = s; j <= m - 1 - s; j++)
			cout << a[s][j] << " ";
		for (i = s + 1; i <= n - 2 - s; i++)
			cout << a[i][m - 1 - s] << " ";
		if (n - 1 - s > s)
			for (j = m - 1 - s; j >= s; j--)
				cout << a[n - 1 - s][j] << " ";
		if (m - 1 - s > s)
			for (i = n - 2 - s; i >= s + 1; i--)
				cout << a[i][s] << " ";
	}
	getch();
}
