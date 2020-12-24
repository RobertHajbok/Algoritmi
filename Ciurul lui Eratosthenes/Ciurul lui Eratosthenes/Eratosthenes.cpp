/* Ciurul lui Eratosthenes este un algoritm care gaseste toate numerele prime mai mici sau egale cu un numar N. Algoritmul ii este atribuit lui
Eratosthenes, un matematician al Greciei antice si functioneaza in felul urmator:
					- Se creeaza o lista cu toate numerele naturale de la 2 pana la N.
					- Fie i un numar care reprezinta la fiecare pas un numar prim determinat de catre algoritm. Initial i=2.
					- Cat timp i*i<=N executa: - se elimina toti multiplii lui i mai mici sau egali cu N din lista, incepand, eventual, de la i*i,
												 deoarece restul multiplilor au fost deja eliminati.
											   - i devine urmatorul numar din lista.
	La sfarsitul algoritmului, toate numerele ramase in lista sunt prime. */

#include<iostream>
#include<conio.h>
using namespace std;
void eratosthenes(int n)
{
	bool* lista = new bool[n + 1];
	//lista[i]=true daca numarul i este prim si false in caz contrar;
	//vom folosi si aici optimizarea de a nu lua in considerare numerele pare;
	lista[2] = true;
	for (int i = 3; i * i <= n; i += 2)
		lista[i] = true;
	for (int i = 3; i * i <= n; i += 2)
		if (lista[i])					//daca i nu a fost sters
			for (int j = i * i; j <= n; j += i)
				lista[j] = false;			//stergem multiplii lui
	//afiseaza numerele prime
	cout << 2 << " ";
	for (int i = 3; i <= n; i += 2)
		if (lista[i])
			cout << i << " ";
	delete[]lista;
}
int main()
{
	int x;
	cin >> x;
	eratosthenes(x);
	getch();
	return 0;
}
