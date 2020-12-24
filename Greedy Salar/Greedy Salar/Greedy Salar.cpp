#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

int n, m, monede[100], nr[100];

//Sorteaza descrescator valoarea monedelor
void sorteaza()
{
	int aux, schimb, i;
	do
	{
		schimb = 0;
		for (i = 0; i < n - 1; ++i)
			if (monede[i] < monede[i + 1])
			{
				aux = monede[i];
				monede[i] = monede[i + 1];
				monede[i + 1] = aux;
				schimb = 1;
			}
	} while (schimb);
}

int main()
{
	int moneda, i;
	ifstream f("Salar.txt");
	f >> n;
	cout << "Salar: " << n;
	f >> m;		//Numarul de monede
	for (i = 0; i < m; ++i)
	{
		f >> moneda;
		monede[i] = moneda;
	}
	f.close();

	sorteaza();

	for (i = 0; i < m; i++)
	{
		nr[i] = n / monede[i];
		n %= monede[i];
	}

	for (i = 0; i < m; i++)
	{
		cout << endl;
		cout << "Sunt necesare " << nr[i] << " monede cu valoarea " << monede[i];
	}

	_getch();
	return 0;
}