#include <iostream>
#include <conio.h>
using namespace std;

void adunare(int A[], int B[], int C[])
{
	int i, transport = 0;
	for (i = 1; i <= A[0] || i <= B[0]; ++i)
	{
		C[i] = A[i] + B[i] + transport;
		transport = C[i] / 10;
		C[i] %= 10;
	}
	if (transport)
		C[i] = transport;
	C[0] = i;

	for (int j = C[0] - 1; j >= 1; j--)
		cout << C[j];
}

void scadere(int A[], int B[], int C[])
{
	int imprumut = 0;
	for (int i = 1; i <= A[0]; ++i)
	{
		C[i] = A[i] - B[i] - imprumut;
		if (C[i] < 0)
		{
			C[i] += 10;
			imprumut = 1;
		}
		else
			imprumut = 0;
	}
	while (C[C[0]] == 0 && C[0] > 1)
		--C[0];

	for (int j = C[0] - 1; j >= 1; j--)
		cout << C[j];
}

void comparare(int A[], int B[])
{
	if (A[0] > B[0])
	{
		cout << "Primul numar este mai mare decat al doilea"; // A > B
		return;
	}
	if (B[0] > A[0])
	{
		cout << "Al doilea numar este mai mare decat primul"; // A < B
		return;
	}
	for (int i = A[0]; i; --i)
		if (A[i] > B[i])
		{
			cout << "Primul numar este mai mare decat al doilea";
			return;
		}
		else
			if (B[i] > A[i])
			{
				cout << "Al doilea numar este mai mare decat primul";
				return;
			}
	cout << "Numerele sunt egale"; // A == B
}

void inm_mic(int A[], int B, int C[])
{
	int transport = 0;
	for (int i = 1; i <= A[0]; ++i)
	{
		C[i] = A[i] * B + transport;
		transport = C[i] / 10;
		C[i] %= 10;
	}
	while (transport)
	{
		C[++C[0]] = transport % 10;
		transport /= 10;
	}
	for (int j = C[0] - 1; j >= 1; j--)
		cout << C[j];
}

void inm_mare(int A[], int B[], int C[]) // Se presupune C initializat cu 0
{
	C[0] = A[0] + B[0] - 1;

	for (int i = 1; i <= C[0]; ++i)
		C[i] = 0;

	for (int i = 1; i <= A[0]; ++i)
		for (int j = 1; j <= B[0]; ++j)
			C[i + j - 1] += A[i] * B[j];
	int s = 0, transport = 0;
	for (int i = 1; i <= C[0]; ++i)
	{
		s = C[i] + transport;
		C[i] = s % 10;
		transport = s / 10;
	}
	if (transport)
		C[++C[0]] = transport;

	for (int j = C[0]; j >= 1; j--)
		cout << C[j];
}

void impartire(int A[], int B) // rezultatul va fi retinut in A
{
	int transport = 0;
	for (int i = A[0]; i > 0; --i)
	{
		transport = transport * 10 + A[i];
		A[i] = transport / B;
		transport %= B;
	}
	while (!A[A[0]] && A[0] > 1)
		--A[0];

	for (int j = A[0]; j >= 1; j--)
		cout << A[j];
}

void modulo(int A[], int B)
{
	int rest = 0;
	for (int i = A[0]; i > 0; --i)
	{
		rest = rest * 10 + A[i];
		rest %= B;
	}
	cout << rest;
}

void main()
{
	const int n = 4;
	int nrMare1[n], nrMare2[n], nrMare3[2 * n];
	nrMare1[0] = n;
	nrMare2[0] = n;
	int aux[n];

	for (int i = n; i > 0; i--)
		nrMare1[i] = rand() % 10;

	for (int i = n; i > 0; i--)
		nrMare2[i] = rand() % 10;

	for (int i = n; i >= 0; i--)
		aux[i] = nrMare1[i];

	cout << "Primul numar mare: " << endl;
	for (int i = n; i > 0; i--)
		cout << nrMare2[i];

	cout << endl << endl << "Al doilea numar mare: " << endl;
	for (int i = n; i > 0; i--)
		cout << nrMare1[i];

	cout << endl << endl << "Suma celor doua numere mari: " << endl;
	adunare(nrMare1, nrMare2, nrMare3);

	cout << endl << endl << "Diferenta celor doua numere mari: " << endl;
	scadere(nrMare2, nrMare1, nrMare3);

	cout << endl << endl << "Compararea celor doua numere mari: " << endl;
	comparare(nrMare2, nrMare1);

	cout << endl << endl << "Inmultirea unui numar mare cu un numar mic - (1740 * 7): " << endl;
	inm_mic(nrMare1, 7, nrMare3);

	cout << endl << endl << "Inmultirea a doua numere mari: " << endl;
	inm_mare(nrMare2, nrMare1, nrMare3);

	cout << endl << endl << "Catul impartirii unui numar mare la un numar mic - (1740 / 7): " << endl;
	impartire(nrMare1, 7);

	cout << endl << endl << "Restul impartirii unui numar mare la un numar mic - (1740 % 7): " << endl;
	modulo(aux, 7);

	_getch();
}