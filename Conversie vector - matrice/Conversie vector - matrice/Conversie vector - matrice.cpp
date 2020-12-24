#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	int v[100], a[10][10], i, j, n, m;
	cin >> n;
	cin >> m;
	for (i = 0; i < n * m; i++)
		cin >> v[i];
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			a[i][j] = v[i * m + j];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			cout << a[i][j] << " ";
		cout << "\n";
	}
	getch();
}