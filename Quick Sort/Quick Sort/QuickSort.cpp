/* QUICK SORT
Cazul mediu: O(N log N)
Cazul defavorabil: O(N^2)
Memorie folosita: O(log N)
Stabil: DA
Sortare descrescatoare: while(vector[min] > mijl) min++;
						while(vector[max] < mijl) max--;
Sortare crescatoare: while(vector[min] < mijl) min++;
					 while(vector[max] > mijl) max--;

Descriere: Sortarea prin metoda Quick Sort are la baza urmatorul principiu: practic tabloul este ordonat cand pentru fiecare element din tablou v[poz],
		   elementele situate la stanga sunt mai mici decat v[poz], iar cele din dreapta sunt mai mari sau egale decat v[poz]. Sortarea tabloului decurge
		   astfel: - la un moment dat se prelucreaza o secventa din vector cu indecsi cuprinsi intre p si u
				   - se ia una din aceste componente, fie ea piv=v[p], care se considera element pivot
				   - se fac in tablou interschimbari de componente, astfel incat toate cele mai mici decat valoarea pivot sa treaca in stanga acesteia,
					 iar elementele cu valoare mai mare decat pivot sa treaca in dreapta; prin aceasta operatie se va deplasa si valoarea pivot, astfel ca
					 ea nu se va mai gasi pe pozitia initiala ci pe o pozitie corespunzatoare relatiei de ordine
				   - se continua setul de operatii similare, aplicand recursiv metoda pentru zona de tablou situata in stanga componentei pivot si pentru
					 cea din dreapta acesteia
				   - oprirea recursiei se face cand lungimea zonei de tablou care trebuie sortata devine egala cu 1 */

#include<iostream>
#include<conio.h>
using namespace std;
int v[2000], n;
int poz(int p, int u)
{
	int piv, aux, k;
	piv = v[p];
	while (p < u)
	{
		if (v[p] > v[u])
		{
			aux = v[p];
			v[p] = v[u];
			v[u] = aux;
		}
		if (v[p] == piv)
			u--;
		else
			p++;
	}
	k = p;
	return k;
}
void quick(int p, int u)
{
	int k;
	if (p < u)
	{
		k = poz(p, u);
		quick(p, k - 1);
		quick(k + 1, u);
	}
}
void main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	quick(1, n);
	for (int i = 1; i <= n; i++)
		cout << v[i] << " ";
	getch();
}