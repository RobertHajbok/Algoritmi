/* Testul de primalitate a lui Fermat foloseste urmatoarea teorema: daca p este un numar prim si 1<a<p atunci a^(p-1) congruent 1 mod p. Algoritmul
presupune generarea aleatoare a mai multor valori pentru a si testarea congruentei. Daca aceasta se verifica pentru mai multe valori ale lui a, atunci
p este probabil prim (sau pseudoprim). Daca, in schimb, gasim un a care nu verifica ecuatia, atunci p sigur nu e prim */
#include<iostream>
#include<conio.h>
using namespace std;
int exponentiere_log(int a, int b, int n)
{
	if (b == 0)
		return 1;
	if ((b & 1) == 0)					//daca b este numar par
	{
		int temp = exponentiere_log(a, b >> 1, n);
		return (temp * temp) % n;
	}
	return ((a % n) * exponentiere_log(a, b - 1, n)) % n;
}
int Fermat(int p, int k)
{
	for (int i = 1; i <= k; ++i)
	{
		int a = 2 + rand() % (p - 2);
		if (exponentiere_log(a, p - 1, p) != 1)
			return 0;			//SIGUR nu e prim
	}
	return 1;					//PROBABIL e prim
}
int main()
{
	int nr;
	cout << "Test pentru numarul: ";
	cin >> nr;
	if (Fermat(nr, 1000) == 1)
		cout << "Numarul probabil este prim\n";
	else
		cout << "Numarul nu este prim\n";
	getch();
	return 0;
}

