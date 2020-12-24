#include<iostream>
#include<conio.h>
using namespace std;

struct nod
{
	int info;
	nod* link_;
	nod* _link; // pointer catre nodul anterior
};

void add_beg(nod*& Old, int info)
{
	nod* New = new nod;
	New->info = info;
	New->_link = NULL;
	New->link_ = Old;
	if (Old != NULL)
		Old->_link = New;
	Old = New;
}

void add_end(nod*& Old, int info)
{
	// nu mai este necesar sa ne deplasam
	// pe ultimul nod, deoarece functia
	// va fi intotdeauna apelata cu ultimul nod
	// ca parametru.
	nod* New = new nod;
	New->info = info;
	New->link_ = NULL;
	Old->link_ = New;
	New->_link = Old;
	Old = New;
}

void add_mid(nod*& Old, int info)
{
	if (Old == NULL) // adaugarea primului nod
		add_beg(Old, info);
	else
	{
		// daca valoarea este mai mica sau egala cu a primului nod, se adauga la inceput
		if (info <= Old->info)
			add_beg(Old, info);
		else
		{
			// caut unde trebuie adaugat noul nod
			nod* Temp = Old;
			for (; Temp->link_ != NULL; Temp = Temp->link_)
				if (info <= Temp->link_->info)
					break; // am gasit pozitia pe care trebuie adaugat
			if (Temp->link_ == NULL) // adaugare la sfarsit
				add_end(Temp, info);
			else // adaugare undeva in interior
			{
				nod* New = new nod;
				New->info = info;
				New->link_ = Temp->link_;
				New->_link = Temp;
				Temp->link_->_link = New;
				Temp->link_ = New;
			}
		}
	}
}

void del_beg(nod*& Old)
{
	nod* ToDel = Old;
	Old = Old->link_;
	if (Old != NULL) // altfel nu exista Old->_link
		Old->_link = NULL;
	delete ToDel;
}

void del_mid(nod*& Old, int info)
{
	if (Old->info == info)
		del_beg(Old);
	else
	{
		nod* Temp = Old;
		for (; Temp->link_ != NULL; Temp = Temp->link_)
			if (Temp->link_->info == info)
				break;
		if (Temp->link_ != NULL)
		{
			nod* ToDel = Temp->link_;
			Temp->link_ = Temp->link_->link_;
			if (Temp->link_ != NULL)
				Temp->link_->_link = Temp;
			delete ToDel;
		}
	}
}

void view(nod* L)
{
	for (; L; L = L->link_)
		cout << L->info << ' ';
	cout << endl;
}

int main()
{
	// atentie la initializarea cu NULL!
	nod* LISTA = NULL;
	int N, M, x;
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> x;
		add_mid(LISTA, x);
	}
	view(LISTA);
	for (int i = 0; i < M; ++i)
	{
		cin >> x;
		del_mid(LISTA, x);
		view(LISTA);
	}
	_getch();
	return 0;
}