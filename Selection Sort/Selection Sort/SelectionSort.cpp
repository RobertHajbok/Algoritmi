/* SELECTION SORT
Cazul mediu: O(N^2)
Cazul defavorabil: O(N^2)
Memorie folosita: O(1)
Stabil: DA
Sortare descrescatoare: min<a[i+1]
Sortare crescatoare: min>a[i+1]

Descriere: Acest algoritm selecteaza la fiecare pas i cel mai mic element din vectorul de la pasul i+1 pana la n. Valoarea minima de la pasul i este
		   pusa in vector la pozitia i, facandu-se interschimbarea cu pozitia actuala a minimului. Nu este un algoritm indicat pentru vectorii mari, in
		   majoritatea cazurilor oferind rezultate mai slabe decat insertion sort sau bubble sort. */

#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	int a[100], n;
	int i, min, minat, aux, j;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 0; i < n - 1; i++)
	{
		minat = i;
		min = a[i];
		for (j = i + 1; j < n; j++)		//selectam minimul
		{						//din vectorul ramas (de la i+1 la n)
			if (min > a[j])		//sortare crescatoare
			{
				minat = j;		//pozitia elementului minim
				min = a[j];
			}
		}
		aux = a[i];
		a[i] = a[minat];			//interschimbare
		a[minat] = aux;
	}
	for (i = 0; i < n; i++)
		cout << a[i] << " ";
	getch();
}