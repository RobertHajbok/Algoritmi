#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<conio.h>
using namespace std;

FILE* f;

struct INTL
{
	int dig;
	struct INTL* link_;
};

void view(struct INTL* toView)
{
	struct INTL* t;
	for (t = toView; t != NULL; t = t->link_)
	{
		cout << t->dig << " ";
	}
}

void addBeg(struct INTL*& toAdd, int n)
{
	struct INTL* New = new INTL;
	New->dig = n;
	New->link_ = toAdd;
	toAdd = New;
}

void addBeg(struct INTL*& toAdd)
{
	struct INTL* New = new INTL;
	New->dig = rand() % 10;
	New->link_ = toAdd;
	toAdd = New;
}

void load(char* p)
{
	ifstream myReadFile;
	myReadFile.open(p);
	struct INTL* New = NULL;
	if (myReadFile.is_open())
	{
		while (!myReadFile.eof())
		{
			int x;
			myReadFile >> x;
			addBeg(New, x);
		}
	}
	view(New);
	myReadFile.close();
}

void save(char* p, struct INTL* toSave)
{
	ofstream outputFile;
	outputFile.open(p);

	struct INTL* t;
	for (t = toSave; t != NULL; t = t->link_)
	{
		outputFile << t->dig << " ";
	}

	outputFile.close();
}

void addEnd(struct INTL*& toAdd, int n)
{
	struct INTL* New = new INTL;
	New->dig = n;
	New->link_ = NULL;

	struct INTL* t = toAdd;
	for (; t->link_ != NULL; t = t->link_);
	t->link_ = New;
}

void MIO(struct INTL*& toM)
{
	addEnd(toM, 0);
}

void INV(struct INTL*& toInv)
{
	struct INTL* toR = NULL;
	for (struct INTL* t = toInv; t != NULL; t = t->link_)
		addBeg(toR, t->dig);
	toInv = toR;
}

void INC(struct INTL*& toInc)
{
	INV(toInc);

	struct INTL* t = toInc;
	int value;
	do
	{
		value = t->dig + 1;
		t->dig = value % 10;
		value /= 10;
		t = t->link_;
	} while (value != 0 && t != NULL);
	if (value == 1)
		addEnd(toInc, 1);

	INV(toInc);
}

void getRND(struct INTL*& toGet, int n)
{
	for (int i = 0; i < n; i++)
	{
		addBeg(toGet);
	}
}

struct INTL* SUM(struct INTL* X, struct INTL* Y)
{
	struct INTL* toR = NULL;
	int p = 0;
	struct INTL* t1 = X;
	struct INTL* t2 = Y;
	INV(t1);
	INV(t2);

	do
	{
		int value = t1->dig + t2->dig + p;
		addBeg(toR, value % 10);
		p = value / 10;
		t1 = t1->link_;
		t2 = t2->link_;
	} while (t1 != NULL && t2 != NULL);
	while (t1 != NULL)
	{
		int value = t1->dig + p;
		addBeg(toR, value % 10);
		p = value / 10;
		t1 = t1->link_;
	}
	while (t2 != NULL)
	{
		int value = t2->dig + p;
		addBeg(toR, value % 10);
		p = value / 10;
		t2 = t2->link_;
	}
	if (p != 0)
		addBeg(toR, p);

	return toR;
}

struct INTL* DIF(struct INTL* X, struct INTL* Y)
{
	struct INTL* toR = NULL;
	int p = 0;
	struct INTL* t1 = X;
	struct INTL* t2 = Y;
	INV(t1);
	INV(t2);

	do
	{
		int value = t1->dig - t2->dig - p;
		p = 0;
		if (value < 0)
		{
			value += 10;
			p = 1;
		}
		addBeg(toR, value % 10);
		t1 = t1->link_;
		t2 = t2->link_;
	} while (t1 != NULL && t2 != NULL);
	while (t1 != NULL)
	{
		int value = t1->dig - p;
		addBeg(toR, value % 10);
		p = value / 10;
		t1 = t1->link_;
	}
	if (p != 0)
		addBeg(toR, p);

	return toR;
}

struct INTL* PRODScalar(struct INTL* X, int n)
{
	struct INTL* toR = NULL;
	int p = 0;
	struct INTL* t1 = X;
	INV(t1);

	do
	{
		int value = t1->dig * n + p;
		addBeg(toR, value % 10);
		p = value / 10;
		t1 = t1->link_;
	} while (t1 != NULL);

	if (p != 0)
		addBeg(toR, p);

	return toR;
}

struct INTL* PROD(struct INTL* X, struct INTL* Y)
{
	struct INTL* toR = NULL;
	struct INTL* t1 = X;
	struct INTL* t2 = Y;
	INV(t2);
	addBeg(toR, 0);

	int i = 0;

	do
	{
		struct INTL* temp = PRODScalar(t1, t2->dig);
		toR = SUM(toR, PRODScalar(temp, pow(10, i)));
		i++;
		t2 = t2->link_;
	} while (t2 != NULL);

	return toR;
}

void main()
{
	struct INTL* x = NULL;
	cout << "Genereaza o lista random " << endl;
	getRND(x, 10);
	view(x);
	cout << endl;

	//Inmultirea cu 10 (adauga inca un 0 la sfarsit)
	cout << endl << "Inmultirea cu 10 " << endl;
	MIO(x);
	view(x);
	cout << endl;

	//Incrementare
	cout << endl << "Incrementare " << endl;
	INC(x);
	view(x);
	cout << endl;

	//Test incrementare pentru 999999
	cout << endl << "Testeaza incrementarea pentru 999999 " << endl;
	struct INTL* y = NULL;
	for (int i = 0; i < 6; i++)
		addBeg(y, 9);
	view(y);
	cout << endl;
	INC(y);
	view(y);
	cout << endl;

	//Salveaza x in fisier
	save("Lista.out", y);

	//Citeste lista inlantuita din fisier
	cout << endl << "Citeste lista din fisier " << endl;
	load("Lista.in");
	cout << endl;

	//Testeaza suma
	cout << endl << "Testeaza suma " << endl;
	struct INTL* suma1 = NULL;
	getRND(suma1, 10);
	view(suma1);
	cout << endl;
	struct INTL* suma2 = NULL;
	getRND(suma2, 10);
	view(suma2);
	cout << endl;
	view(SUM(suma1, suma2));
	cout << endl;

	//Testeaza diferenta
	cout << endl << "Testeaza diferenta (a > b)" << endl;
	struct INTL* dif1 = NULL;
	getRND(dif1, 10);
	view(dif1);
	cout << endl;
	struct INTL* dif2 = NULL;
	getRND(dif2, 7);
	view(dif2);
	cout << endl;
	view(DIF(dif1, dif2));
	cout << endl;

	//Inmultirea cu un scalar
	cout << endl << "Inmultirea cu un scalar " << endl;
	struct INTL* prodscalar = NULL;
	getRND(prodscalar, 10);
	view(prodscalar);
	int scalar = 5;
	cout << endl << scalar << endl;
	view(PRODScalar(prodscalar, scalar));
	cout << endl;

	//Testeaza produsul
	cout << endl << "Testeaza produsul " << endl;
	struct INTL* prod1 = NULL;
	getRND(prod1, 2);
	view(prod1);
	cout << endl;
	struct INTL* prod2 = NULL;
	getRND(prod2, 3);
	view(prod2);
	cout << endl;
	view(PROD(prod1, prod2));
	cout << endl;

	_getch();
}