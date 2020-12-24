/* BUBBLE SORT
Cazul mediu: O(N^2)
Cazul defavorabil: O(N^2)
Memorie folosita: O(1)
Stabil: DA
Sortare descrescatoare: a[i]<a[i+1]
Sortare crescatoare: a[i]>a[i+1]

Descriere: Sortarea prin metoda bulelor se considera drept una din cele mai putin eficiente metode de sortare dar cu un algoritm mai putin complicat.
		   Ideea de baza a sortarii prin metoda bulelor este in a parcurge tabloul de la stanga spre dreapta, fiind comparate elementele alaturate a[i]
		   si a[i+1]. Daca vor fi gasite 2 elemente neordonate valorile lor vor fi interschimbate.
		   Parcurgerea tabloului de la stanga spre dreapta se va repeta atat timp cat nu vor fi intalnite elemente neordonate. */

#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	int a[100], n;
	int i, schimbat, aux;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	do
	{
		schimbat = 0;
		for (i = 0; i < n - 1; i++)			//parcurgem vectorul
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
	getch();
}