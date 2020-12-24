#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	int a[10][10], n, i, j, k = 0;
	cin >> n;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			cin >> a[i][j];
	for (k = 0; k < n / 2; k++)
	{
		for (j = k; j < n - k; j++)
			cout << a[k][j] << " ";
		for (i = k + 1; i < n - k; i++)
			cout << a[i][n - k - 1] << " ";
		for (j = n - k - 2; j >= k; j--)
			cout << a[n - k - 1][j] << " ";
		for (i = n - k - 2; i > k; i--)
			cout << a[i][k] << " ";
	}
	if (n % 2 == 1)
		cout << a[n / 2][n / 2];
	getch();
}