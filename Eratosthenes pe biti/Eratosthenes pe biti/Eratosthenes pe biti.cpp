#include<iostream>
#include<conio.h>
using namespace std;
inline void del(unsigned char lista[], int nr)
{
	lista[nr >> 3] &= ~(1 << (nr & 7));
}
inline bool verif(unsigned char lista[], int nr)
{
	return lista[nr >> 3] & (1 << (nr & 7));
}
void eratosthenes(int n)
{
	int dim = n / 8 / 2 + 1;
	unsigned char* lista = new unsigned char[dim];
	for (int i = 0; i < dim; ++i)
		lista[i] = 0xFF;
	for (int i = 1; ((i * i) << 1) + (i << 1) <= n; ++i)
		if (verif(lista, i))				//daca 2i+1 e numar prim
			for (int j = ((i * i) << 1) + (i << 1); (j << 1) + 1 <= n; j += (i << 1) + 1)
				del(lista, j);			//sterg multiplii lui 2i+1
	//afisez numerele prime
	cout << 2 << " ";
	for (int i = 1; (i << 1) + 1 <= n; ++i)
		if (verif(lista, i))
			cout << (i << 1) + 1 << " ";
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