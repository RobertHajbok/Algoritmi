/* COMB SORT
Cazul mediu: O((N^2)/(2^p)) unde p este numarul de incrementari
Cazul defavorabil: O(N^2)
Memorie folosita: O(1)
Stabil: DA
Sortare descrescatoare: a[i]<a[i+gap]
Sortare crescatoare: a[i]>a[i+gap]

Descriere: Comb Sort este un algoritm imbunatatit al metodei bulelor. Ideea principala este de a elimina
		   numerele mari de la inceput, deoarece in Bubble Sort acestea incetinesc sortarea. La fel se procedeaza si
		   pentru numerele mici de la sfarsitul listei. In Bubble Sort, cand oricare doua elemente sunt comparate, distanta dintre
		   ele este intotdeauna 1. Ideea de baza a Comb Sort-ului este ca aceasta distanta poate fi mai mare decat 1 (Shell Sort
		   este de asemenea bazat pe aceasta idee, dar este mai degraba o modificare a sortarii prin insertie decat a sortarii
		   prin metoda bulelor).*/

#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	int a[100], n;
	int i, schimbat, aux, gap;
	cin >> n;
	gap = n;
	double shrink = 1.3;
	for (i = 0; i < n; i++)
		cin >> a[i];
	while ((gap > 1) || schimbat)
	{
		if (gap > 1)
			gap = (int)((double)gap / shrink);
		schimbat = 0;
		for (i = 0; gap + i < n; ++i)
		{
			if (a[i] - a[i + gap] > 0)
			{
				aux = a[i];
				a[i] = a[i + gap];
				a[i + gap] = aux;
				schimbat = 1;
			}
		}
	}
	for (i = 0; i < n; i++)
		cout << a[i] << " ";
	_getch();
}