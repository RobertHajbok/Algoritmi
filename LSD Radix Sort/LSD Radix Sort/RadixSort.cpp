/* LSD RADIX SORT
Cazul mediu: O(N*k)
Cazul defavorabil: O(N*k)
Memorie folosita: O(N)
Stabil: DA
Descriere: Deoarece Radix Sort este un algoritm hibrid, ce nu are la baza o tehnica de comparare fiecare element se numeste „cheie”. Valorile sunt gandite
ca siruri de caractere si procesate pe biti. Algoritmul sorteaza cheile dupa urmatoarea regula: cheile de lungime mai mica sunt asezate in fata celor de
lungime mai mare,iar cele de aceeasi lungime sunt asezate in ordine lexicografica. LSD Radix Sort poate sorta un vector cu valori intregi sau de tip
string in ordine lexicografica. Deoarece fiecare numar/cuvant este considerat un sir de caractere, procesarea incepe de la cea mai nesemnificativa dintre
valorile sirului de caractere. Astfel valorile la pasul k sunt comparate,sortate iar cele ce au valori egale sunt lasate in pace pentru a fi evaluate
ulterior la un pas k+i. */
#include<iostream>
#include<conio.h>
using namespace std;
void RadixSort(int* a, int n)
{
	int i, b[100], m = a[0], exp = 1;
	for (i = 0; i < n; i++)
		if (a[i] > m)
			m = a[i];
	while (m / exp > 0)
	{
		int rad[10] = { 0 };
		for (i = 0; i < n; i++)
			rad[a[i] / exp % 10]++;
		for (i = 1; i < 10; i++)
			rad[i] += rad[i - 1];
		for (i = n - 1; i >= 0; i--)
			b[--rad[a[i] / exp % 10]] = a[i];
		for (i = 0; i < n; i++)
			a[i] = b[i];
		exp *= 10;
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
	}
}
int main()
{
	int arr[100], i, n;
	cout << "Introduceti dimensiunea vectorului: ";
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> arr[i];
	RadixSort(&arr[0], n);
	getch();
	return 0;
}