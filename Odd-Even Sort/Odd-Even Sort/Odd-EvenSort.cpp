/* ODD-EVEN SORT
Cazul mediu: O(N^2)
Cazul defavorabil: O(N^2)
Memorie folosita: O(1)
Stabil: DA
Sortare descrescatoare: a[i]<a[i+1]
Sortare crescatoare: a[i]>a[i+1]

Descriere: In programare, sortarea par-impar este un algoritm de sortare simplu, foarte asemanator cu
		   Bubble Sort. Ideea algoritmului este de a compara toate elementele adiacente de pe pozitii pare si impare
		   si, daca doua elemente sunt in ordinea gresita, ele sunt interschimbate. Acest procedeu se repeta
		   pana cand lista este complet sortata.*/

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
		for (i = 0; i < n - 1; i += 2)			//parcurgem vectorul pe pozitiile pare
			if (a[i] > a[i + 1])			//daca valoarea i din vectorul a este
			{						//mai mica decat cea de pe pozitia i+1
				aux = a[i];			//interschimbare
				a[i] = a[i + 1];
				a[i + 1] = aux;
				schimbat = 1;
			}
		for (i = 1; i < n - 1; i += 2)			//parcurgem vectorul pe pozitiile impare
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