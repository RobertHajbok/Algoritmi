#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	int a[10][10], v[100], i, j, n, m;
	cin >> n;
	cin >> m;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> a[i][j];
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			v[i * m + j] = a[i][j];
	for (i = 0; i < n * m; i++)
		cout << v[i] << " ";
	getch();
}