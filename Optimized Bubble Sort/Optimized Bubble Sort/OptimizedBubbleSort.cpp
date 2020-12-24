#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	int a[50], i, n, k, aux;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	int ok = 0;
	for (k = n - 1; k > 0 && ok == 0; k--)
	{
		ok = 1;
		for (i = 0; i < k; i++)
			if (a[i] > a[i + 1])
			{
				aux = a[i];
				a[i] = a[i + 1];
				a[i + 1] = aux;
				ok = 0;
			}
	}
	for (i = 0; i < n; i++)
		cout << a[i] << " ";
	getch();
}