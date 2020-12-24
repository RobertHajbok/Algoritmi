/* COCKTAIL SORT
Cazul mediu: O(N^2)
Cazul defavorabil: O(N^2)
Memorie folosita: O(1)
Stabil: DA
Sortare descrescatoare: a[i]<a[i+1]
Sortare crescatoare: a[i]>a[i+1]

Descriere: Sortarea Cocktail, cunoscuta si ca Bubble Sort bidirectional, este un algoritm asemanator Bubble Sort-ului,
		   cu singura diferenta ca aceasta sorteaza lista parcurgand-o in ambele directii. Acest algoritm nu este mult mai complicat
		   de implementat decat Bubble Sort, si ofera performante cu foarte putin mai bune. Din acest motiv,
		   nu se foloseste in practica, avand doar scop didactic.*/

#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	int a[100], n;
	int i, aux, incep = -1, sfarsit, schimbat;
	cin >> n;
	sfarsit = n - 1;
	for (i = 0; i < n; i++)
		cin >> a[i];
	do
	{
		schimbat = 0;
		// creste 'incep' deoarece elementele dinaintea lui sunt pe pozitia corecta
		incep++;
		for (i = incep; i < sfarsit; i++)			//parcurgem vectorul
			if (a[i] > a[i + 1])			//daca valoarea i din vectorul a este
			{						//mai mica decat cea de pe pozitia i+1
				aux = a[i];			//interschimbare
				a[i] = a[i + 1];
				a[i + 1] = aux;
				schimbat = 1;
			}
		if (!schimbat)
			break;
		schimbat = 0;
		// descreste 'sfarsit' deoarece elementele dupa el sunt pe pozitia corecta
		sfarsit--;
		for (i = sfarsit; i >= incep; i--)			//parcurgem vectorul invers
			if (a[i] > a[i + 1])			//daca valoarea i din vectorul a este
			{						//mai mica decat cea de pe pozitia i+1
				aux = a[i];			//interschimbare
				a[i] = a[i + 1];
				a[i + 1] = aux;
				schimbat = 1;
			}
	} while (schimbat);
	for (i = 0; i < n; i++)
		cout << a[i] << " ";
	_getch();
}