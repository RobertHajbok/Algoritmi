/*
Cazul mediu : O(N log N)
Cazul defavorabil : O(N log N)
Memorie folosita : O(N)
Stabil : DA
Sortare descrescatoare : b[i] >= a[j]
Sortare crescatoare : b[i] <= a[j]

Descriere : In cazul sortarii prin interclasare vectorii care se interclaseaza sunt doua secvente ordonate din acelasi vector. Sortarea prin
			interclasare utilizeaza metoda Divide et Impera:
						- se imparte vectorul in secvente din ce in ce mai mici., astfel incat fiecare secventa sa fie ordonata la un moment dat
						si interclasata cu o alta secventa din vector corespunzatoare.
						- practic interclasarea va incepe cand se ajunge la o secventa formata din doua elemente.
			Aceasta odata ordonata se va interclasa cu o alta corespunzatoare. Cele doua secvente vor
			alcatui in subsir ordonat din vector mai mare care la randul lui se va interclasa cu subsirul
			corespunzator s.a.m.d. */

#include<iostream>
#include<conio.h>
using namespace std;
void Interclasare(int a[], int st, int m, int dr)
{
	int* B = new int[dr - st + 2];
	int i = st, j = m + 1, k = 0;
	while (i <= m && j <= dr)
		if (a[i] <= a[j])
			B[++k] = a[i++];
		else
			B[++k] = a[j++];
	//copiaza ce a mai ramas
	while (i <= m)
		B[++k] = a[i++];
	while (j <= dr)
		B[++k] = a[j++];
	//copiaza la loc secventa sortata
	for (i = 1; i <= k; ++i)
		a[st + i - 1] = B[i];
	//sterge memoria auxiliara folosita
	delete[]B;
}
void MergeSort(int a[], int st, int dr)
{
	if (st < dr)
	{
		int m = (st + dr) / 2;
		MergeSort(a, st, m);
		MergeSort(a, m + 1, dr);
		Interclasare(a, st, m, dr);
	}
}
void main()
{
	int v[50], dim;
	cout << "Dati dimensiunea vectorului: ";
	cin >> dim;
	for (int i = 1; i <= dim; i++)
		cin >> v[i];
	MergeSort(v, 1, dim - 1);
	cout << "Vectorul sortat este: ";
	for (int i = 1; i <= dim; i++)
		cout << v[i] << " ";
	getch();
}
