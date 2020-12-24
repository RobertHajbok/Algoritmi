/* COUNTING SORT
Aceasta metoda necesita spatiu suplimentar de memorie. Ea foloseste urmatorii vectori: - vectorul sursa (vectorul nesortat) a;
																					   - vectorul destinatie (vectorul sortat) b;
																					   - vectorul numarator (vectorul de contoare) k.
Elementele vectorului sursa a[i] se copiaza in vectorul destinatie prin inserarea in pozitia corespunzatoare, astfel incat, in vectorul destinatie sa
fie respectata relatia de ordine. Pentru a se cunoaste pozitia in care se va insera fiecare element, se parcurge vectorul sursa si se numara in vectorul
k, pentru fiecare element a[i], câte elemente au valoarea mai mica decât a lui. Fiecare element al vectorului k este un contor pentru elementul a[i].
Valoarea contorului k[i] pentru elementul a[i] arata cate elemente sunt mai mici decat el si deci pozitia in care trebuie copiat in vectorul b. */
#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	int i, j, n, a[50], b[50], k[50] = { 0 };
	cout << "Introduceti dimensiunea vectorului : ";
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (a[i] > a[j])
				k[i]++;
			else
				k[j]++;
	for (i = 0; i < n; i++)
		b[k[i]] = a[i];
	cout << "Vectorul ordonat este : ";
	for (i = 0; i < n; i++)
		cout << b[i] << " ";
	cout << endl;
	getch();
}