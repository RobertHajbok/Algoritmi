/* INSERTION SORT
Cazul mediu: O(N^2)
Cazul defavorabil: O(N^2)
Memorie folosita: O(1)
Stabil: DA
Sortare descrescatoare: j>0 && a[j-1]<a[j]
Sortare crescatoare: j>0 && a[j-1]>a[j]

Descriere: Spre deosebire de alti algoritmi de sortare, sortarea prin insertie este folosita destul de des pentru sortarea tablourilor cu numar mic
		   de elemente. De exemplu, poate fi folosit pentru a imbunatati rutina de sortare rapida.
		   Sortarea prin insertie seamana oarecum cu sortarea prin selectie. Tabloul este impartit imaginar in doua parti - o parte sortata si o parte
		   nesortata. La inceput, partea sortata contine primul element al tabloului si partea nesortata contine restul tabloului. La fiecare pas,
		   algoritmul ia primul element din partea nesortata si il insereaza in locul potrivit al partii sortate.
		   Cand partea nesortata nu mai are nici un element, algoritmul se opreste. */

#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	int a[100], n;
	int i, j, aux;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 1; i < n; i++)
	{
		j = i;
		while (j > 0 && a[j - 1] > a[j])
		{
			aux = a[j];
			a[j] = a[j - 1];
			a[j - 1] = aux;
			j--;
		}
	}
	for (i = 0; i < n; i++)
		cout << a[i] << " ";
	getch();
}