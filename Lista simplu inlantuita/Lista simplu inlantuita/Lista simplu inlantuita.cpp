#include<iostream>
#include<conio.h>
using namespace std;

struct nod
{
	int info;
	nod* link_;
};

void add_beg(nod*& Old)
{
	nod* New = new nod;
	cin >> New->info;
	New->link_ = Old;
	Old = New;
}


nod* add_end(nod* Old)
{
	if (Old == NULL)
		add_beg(Old);

	// constructia nodului de adaugat
	nod* New = new nod;
	New->link_ = NULL;
	cin >> New->info;
	// gasirea adresei ultimului nod
	nod* Temp;
	for (Temp = Old; Temp->link_ != NULL; Temp = Temp->link_);
	// legatura
	Temp->link_ = New;
	// valoarea de returnat
	return Old;
}

nod* add_mid(nod* Old)
{
	if (Old == NULL)
		add_beg(Old); // adaugarea primului nod
	else
	{
		// nodul care trebuie adaugat
		nod* New = new nod;
		cin >> New->info;
		// daca noua valoarea este mai mica sau egala cu cea a primului
		// element, atunci aceasta se adauga la inceput
		if (New->info <= Old->info)
		{
			New->link_ = Old; Old = New;
		}
		else
		{
			// caut unde trebuie adaugat noul nod
			nod* Temp;
			for (Temp = Old; Temp->link_ != NULL; Temp = Temp->link_)
				if (New->info <= Temp->link_->info)
					break; // am gasit pozitia pe care trebuie adaugat nodul
			if (Temp->link_ == NULL) // adaugare la sfarsit
			{
				New->link_ = NULL; Temp->link_ = New;
			}
			else // nodul se adauga undeva in interior
			{
				New->link_ = Temp->link_; Temp->link_ = New;
			}
		}
	}
	return Old;
}

nod* del_beg(nod* Old)
{
	if (Old != NULL)
		return Old->link_;
	else
		return Old;
}

nod* del_end(nod* Old)
{
	if (Old == NULL)
		return NULL;
	else
	{
		if (Old->link_ == NULL)
		{
			nod* ToDel = Old;
			Old = NULL;
			delete ToDel;
		}
		else
		{
			nod* Temp;
			for (Temp = Old; Temp->link_->link_; Temp = Temp->link_);
			nod* ToDel = Temp->link_;
			Temp->link_ = NULL;
			delete ToDel;
		}
	}
	return Old;
}

nod* del_mid(nod* Old, int key)
{
	if (Old->info == key)
		Old = del_beg(Old);
	else
	{
		for (nod* Temp = Old; Temp->link_; Temp = Temp->link_)
			if (Temp->link_->info == key)
			{
				nod* ToDel = Temp->link_;
				Temp->link_ = Temp->link_->link_;
				delete ToDel;
				break;
			}
	}
	return Old;
}

void view(nod* Old)
{
	for (nod* Temp = Old; Temp != NULL; Temp = Temp->link_)
		cout << Temp->info << ' ';
	cout << endl;
}

void main()
{
	struct nod* lista = NULL;

	cout << "Add to begin: " << endl;
	for (int i = 0; i < 5; i++)
		add_beg(lista);
	view(lista);

	cout << "Add to end: ";
	add_end(lista);
	view(lista);

	cout << "Add to mid: ";
	add_mid(lista);
	view(lista);

	cout << "Delete from begin " << endl;
	del_beg(lista);
	view(lista);

	cout << "Delete from end " << endl;
	del_end(lista);
	view(lista);

	cout << "Delete from mid " << endl;
	del_mid(lista, 3);
	view(lista);

	_getch();
}