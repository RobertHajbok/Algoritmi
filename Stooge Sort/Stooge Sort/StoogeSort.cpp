/* STOOGE SORT
Cazul mediu: O(N^(log 3/log 1.5))=O(N^2.7095..)
Cazul defavorabil: O(N^(log 3/log 1.5))=O(N^2.7095..)
Memorie folosita: O(N)
Stabil: DA
Sortare descrescatoare: v[j]>v[i]
Sortare crescatoare: v[j]<v[i]

Descriere: Stooge sort este un algoritm recursiv de sortare extrem de incet, chiar mai incet Merge Sort si chiar si decat
		   Bubble Sort. Algoritmul este definit dupa cum urmeaza:
				- daca valoarea de la inceput este mai mare decat valoarea de la sfarsit, atunci se interschimba
				- daca in lista sunt trei sau mai multe elemente, atunci:
						- Stooge Sort primele doua treimi din lista
						- Stooge Sort ultimele doua treimi din lista
						- Stooge Sort primele doua treimi din lista din nou
				- altfel, paraseste procedura */

#include<iostream>
#include<conio.h>
using namespace std;
int v[2000], n;
void stooge(int i = 0, int j = n - 1)
{
	int t, aux;
	if (v[j] < v[i])
	{
		aux = v[i];
		v[i] = v[j];
		v[j] = aux;
	}
	if (j - i + 1 >= 3)
	{
		t = (j - i + 1) / 3;
		stooge(i, j - t);
		stooge(i + t, j);
		stooge(i, j - t);
	}
}
void main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	stooge(0, n - 1);
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
	_getch();
}