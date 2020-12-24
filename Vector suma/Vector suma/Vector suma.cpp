#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	int	a[10][10], v[10], i, j, n, m;
	cin >> n;
	cin >> m;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> a[i][j];
	for (i = 0; i < n; i++)
	{
		int s = 0;
		for (j = 0; j < m; j++)
			s = s + a[i][j];
		v[i] = s;
	}
	for (i = 0; i < n; i++)
		cout << v[i] << " ";
	getch();
}