/* Se citeste o matrice patratica. Diagonala principala si secundara impart matricea in 4 zone (N,V,S,E). Sa se afiseze matricea dupa ce asupra ei au fost
facute urmatoarele modificari: a)Elementele de pe cele 2 diagonale si care se gasesc pe aceeasi linie se inlocuiesc cu media lor aritmetica
							   b)Se calculeaza suma elementelor din zona N
							   c)Se determina numarul de elemente negative din zona E
							   d)Se determina numarul de elemente nule din zona S
							   e)Se determina produsul elementlor din zona V
Prelucrarile de la b), c), d), e) se fac in aceeasi parcurgere */

#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	int a[25][25], i, j, n;
	int s, nrNul, p, nrNeg;
	cin >> n;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			cin >> a[i][j];
	for (i = 0; i < n; i++)
	{
		a[i][i] = (a[i][i] + a[i][n - i - 1]) / 2;
		a[i][n - i - 1] = a[i][i];
	}
	s = 0;
	nrNul = 0;
	p = 1;
	nrNeg = 0;
	for (i = 0; i < (n + 1) / 2; i++)
		for (j = i + 1; j < n - 1 - i; j++)
		{
			s = s + a[i][j];
			if (a[n - 1 - j][j] == 0)
				nrNul = nrNul + 1;
			p = p * a[j][i];
			if (a[j][n - 1 - i] < 0)
				nrNeg = nrNeg + 1;
		}
	cout << s << endl;
	cout << nrNul << endl;
	cout << p << endl;
	cout << nrNeg << endl;
	getch();
}
