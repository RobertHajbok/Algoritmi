#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	int a[50], b[50], n1, n2, i, j;
	cin >> n1;
	for (i = 0; i < n1; i++)
		cin >> a[i];
	cin >> n2;
	for (j = 0; j < n2; j++)
		cin >> b[j];
	for (i = 0; i < n1; i++)
		for (j = 0; j < n2; j++)
			if (a[i] == b[j])
				cout << "Cifra comuna: " << a[i] << "\n";
	int min = a[0], ok = 0;
	for (i = 1; i < n1; i++)
		if (a[i] < min)
			min = a[i];
	for (j = 0; j < n2; j++)
		if (b[j] == min)
			ok++;
	cout << ok;
	cout << "\n";
	int nr = 0;
	for (j = 0; j <= n2 - n1; j++)
	{
		int verif = 0;
		i = 0;
		while (b[j] == a[i] && j < n2)
		{
			j++;
			i++;
			verif++;
		}
		if (verif == n1)
			nr++;
	}
	cout << "Primul vector se gaseste in al doilea de " << nr << " ori\n";
	getch();
}