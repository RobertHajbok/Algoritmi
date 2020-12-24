/* SHELL SORT
Cazul mediu: -
Cazul defavorabil: O(N*log^2 N)
Memorie folosita: O(1)
Stabil: NU
Sortare descrescatoare: j>=h && a[j-h]<v
Sortare crescatoare: j>=h && a[j-h]>v

Descriere: Algoritmul Shell Sort este o generalizare a algoritmului Insertion Sort. La algoritmul Insertion Sort, pentru a insera un nou element in
		   lista de elemente deja sortate, se deplaseaza fiecare element cu cate o pozitie spre dreapta atat timp cat avem elemente mai mari decat el.
		   Practic fiecare element inainteaza spre pozitia sa finala cu cate un element.
		   Algoritmul Shell Sort lucreaza similar, doar ca deplaseaza elementele spre pozitia finala cu mai mult de o pozitie. Se lucreaza in iteratii.
		   In prima iteratie se aplica un insertion sort cu salt s1 mai mare decat 1. Asta inseamna ca fiecare element din sirul initial este deplasat
		   spre stanga cu cate s1 pozitii atat timp cat intalneste elemente mai mari decat el.
		   Se repeta asemenea iteratii cu salturi din ce in ce mai mic s2, s3, s4 etc. Ultima iteratie se face cu saltul 1. Aceasta ultima iteratie
		   este practic un Insertion Sort clasic.
		   Principiul este ca dupa fiecare iteratie sirul devine din ce in ce "mai sortat". Iar cum algoritmul Insertion Sort functioneaza cu atat mai
		   repede cu cat sirul este mai sortat, per ansamblu vom obtine o imbunatatire de viteza. */

#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	long a[100], n;
	long i, j, k, h, v;
	long cols[] = { 1391376, 463792, 198768, 86961, 33936, 13776, 4592, 1968, 861, 336, 112, 48, 21, 7, 3, 1 };
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (k = 0; k < 16; k++)		//parcurgem fiecare limita
	{
		h = cols[k];
		for (i = h; i < n; i++)
		{
			v = a[i];
			j = i;
			while (j >= h && a[j - h] > v)		//insertion sort
			{
				a[j] = a[j - h];
				j = j - h;
			}
			a[j] = v;
		}
	}
	for (i = 0; i < n; i++)
		cout << a[i] << " ";
	getch();
}