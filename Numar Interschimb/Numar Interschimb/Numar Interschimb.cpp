#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	int a[50], i, j, n, aux, ok, b[50], c[50];
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i] = c[i] = a[i];
	}
	int nr1 = 0;
	do
	{
		ok = 0;
		for (i = 0; i < n - 1; i++)
			if (a[i] > a[i + 1])
			{
				aux = a[i];
				a[i] = a[i + 1];
				a[i + 1] = aux;
				nr1++;
				ok = 1;
			}
	} while (ok == 1);
	cout << "Bubble sort a realizat " << nr1 << " interschimbari\n";
	int nr2 = 0;
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < i; j++)
			if (b[j] >= b[i])
				break;
		if (j < i)
		{
			aux = b[i];
			for (int k = i; k > j; k--)
			{
				b[k] = b[k - 1];
			}
			b[j] = aux;
			nr2++;
		}
	}
	cout << "Insertion sort a realizat " << nr2 << " interschimbari\n";
	int nr3 = 0;
	for (int k = 0; k < n - 1; k++)
	{
		j = k;
		int min = c[j];
		for (i = j + 1; i < n; i++)
			if (c[i] < min)
			{
				j = i;
				min = c[i];
			}
		c[j] = c[k];
		c[k] = min;
		nr3++;
	}
	cout << "Selection sort a realizat " << nr3 << " interschimbari\n";
	getch();
}