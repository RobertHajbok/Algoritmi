#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

ifstream f("spectacole.in");

int n, inceput[100], sfarsit[100], nr[100];

//Citeste din fisier n-numarul de spectacole si orele la care incep si se termina spectacolele
void citeste()
{
	int ora, i;
	f >> n;
	for (i = 0; i < n; ++i)
	{
		nr[i] = i + 1;
		f >> ora;
		inceput[i] = ora;
		f >> ora;
		sfarsit[i] = ora;
	}
	f.close();
}

//Sorteaza spectacolele dupa ora de final
void sorteaza()
{
	int aux, schimb, i;
	do
	{
		schimb = 0;
		for (i = 0; i < n - 1; ++i)
			if (sfarsit[nr[i]] > sfarsit[nr[i + 1]])
			{
				aux = nr[i];
				nr[i] = nr[i + 1];
				nr[i + 1] = aux;
				schimb = 1;
			}
	} while (schimb);
}

//Se selecteaza, la fiecare pas, primul spectacol neselectat, care nu se suprapune peste cele deja selectate
void rezolva()
{
	int ultim, i;
	for (ultim = 0, i = 1; i < n; ++i)
		if (inceput[nr[i]] >= sfarsit[nr[ultim]])
		{
			cout << nr[i] + 1 << " ";
			ultim = i;
		}
	cout << endl;
}

int main()
{
	citeste();
	sorteaza();
	rezolva();
	_getch();
	return 0;
}