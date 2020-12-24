/* GNOME SORT
Cazul mediu: O(N^2)
Cazul defavorabil: O(N^2)
Memorie folosita: O(1)
Stabil: DA
Sortare descrescatoare: a[pos-1]<a[pos]
Sortare crescatoare: a[pos-1]>a[pos]

Descriere: Gnome Sort (cunoscut si sub numele de sortarea stupida) este un algoritm similar cu sortarea
		   prin insertie, cu exceptia faptului ca mutarea elementelor pe pozitiile lor corecte se fac printr-o serie
		   de interschimbari, la fel ca la sortarea prin metoda bulelor. Algoritmul gaseste intotdeauna primele doua elemente
		   adiacente care nu sunt in ordinea corecta, si le interschimba. Algoritmul se foloseste de faptul ca aceasta
		   interschimbare poate aduce un element care nu este la locul lui, exact inainte de pozitia din care a fost
		   interschimbat initial sau exact dupa.*/

#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	int a[100], n;
	int i, pos = 1, last = 0, aux;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	while (pos < n)
	{
		if (a[pos] >= a[pos - 1])
		{
			if (last != 0)
			{
				pos = last;
				last = 0;
			}
			pos++;
		}
		else
		{
			aux = a[pos];
			a[pos] = a[pos - 1];
			a[pos - 1] = aux;
			if (pos > 1)
			{
				if (last == 0)
					last = pos;
				pos--;
			}
			else
				pos++;
		}
	}
	for (i = 0; i < n; i++)
		cout << a[i] << " ";
	_getch();
}