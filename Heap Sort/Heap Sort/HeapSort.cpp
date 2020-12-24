/* HEAP SORT
Cazul mediu: O(N log N)
Cazul defavorabil: O(N log N)
Memorie folosita: O(1)
Stabil: NU
Sortare descrescatoare: if(a[w+1]<a[w])
								w++;
						if(a[v]<=a[w])
							return;
Sortare crescatoare : if(a[w+1]>a[w])
							w++;
					  if(a[v]>=a[w])
							return;
Descriere: Algoritmul Heap Sort este cel mai slab algoritm de clasa O(N log2N). Este mai slab (dar nu cu mult) decat algoritmii din familia QuickSort, dar
are marele avantaj fata de acestia ca nu este recursiv. Algoritmii recursivi ruleaza rapid, dar consuma o mare cantitate de memorie, ceea ce nu le permite
sa sorteze tablouri de dimensiuni oricat de mari HeapSort este un algoritm care "impaca" viteza cu consumul relativ mic de memorie. */
#include<iostream>
#include<conio.h>
using namespace std;
void Swap(int a[], int i, int j)
{
	int aux = a[i];
	a[i] = a[j];
	a[j] = aux;
}
void DownHeap(int a[], int v, int n)
{
	int w = 2 * v + 1;							//primul descendent al lui v
	while (w < n)
	{
		if (w + 1 < n)							// mai exista unul?
			if (a[w + 1] > a[w])
				w++;						//crescator
											// w este decendentul lui v
		if (a[v] >= a[w])
			return;
		Swap(a, v, w);						// interschimbam v cu w
		v = w;								// continuam
		w = 2 * v + 1;
	}
}
void HeapSort(int a[], int n)
{
	for (int v = n / 2 - 1; v >= 0; v--)		//creem heap`ul
		DownHeap(a, v, n);
	while (n > 1)
	{
		n--;
		Swap(a, 0, n);
		DownHeap(a, 0, n);
	}
}
void main()
{
	int a[100], n, i;
	cout << "Dati dimensiunea vectorului:";
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	HeapSort(a, n);
	for (i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	getch();
}