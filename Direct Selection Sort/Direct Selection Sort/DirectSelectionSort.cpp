/* DIRECT SELECTION SORT
Algoritmul de sortare prin selectie directa consta in urmatoarea idee: comparam primul element cu toate elementele care urmeaza dupa el. Daca gasim un
element mai mic decat primul atunci le interschimbam pe cele doua. Apoi continuam cu al doilea element al sirului, pe care, de asemenea îl comparam cu
toate elementele care urmeaza dupa el si in caz de inversiune interschimbam cele doua elemente. Apoi procedam la fel cu al treilea element al sirului
iar procesul continua astfel pana la penultimul element al sirului care va fi comparat cu ultimul element din sir. */
#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	int a[50], n, i, k, aux;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (k = 0; k < n - 1; k++)
		for (i = k + 1; i < n; i++)
			if (a[k] > a[i])
			{
				aux = a[i];
				a[i] = a[k];
				a[k] = aux;
			}
	for (i = 0; i < n; i++)
		cout << a[i] << " ";
	getch();
}