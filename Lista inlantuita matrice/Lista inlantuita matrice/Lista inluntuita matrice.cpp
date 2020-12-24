#include<iostream>
#include<conio.h>
using namespace std;

struct columns
{
	int info;
	struct columns* link_;
};

struct row
{
	struct columns* columns;
	struct row* link_;
};

void addBeg(struct row*& toAdd, struct columns*& columnToAdd)
{
	struct row* New = new row;
	New->columns = columnToAdd;
	New->link_ = toAdd;
	toAdd = New;
}

void addColumns(struct columns*& toAdd, int m)
{
	for (int i = 0; i < m; i++)
	{
		struct columns* New = new columns;
		New->info = rand() % 10;
		New->link_ = toAdd;
		toAdd = New;
	}
}

void CreateMatrix(struct row*& x, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		struct columns* y = NULL;

		addColumns(y, m);
		addBeg(x, y);
	}
}

void ViewColumns(struct columns* toView)
{
	int i = 0;
	struct columns* t;
	for (t = toView; t != NULL; t = t->link_)
	{
		cout << t->info << " ";
		/*cout<<i;
		i++;*/
	}
}

void ViewMatrix(struct row* toView)
{
	struct row* t;
	for (t = toView; t != NULL; t = t->link_)
	{
		ViewColumns(t->columns);
		cout << endl;
	}
}

void Modify(struct row* x, int i, int j, int k)
{
	struct row* t;
	struct columns* z = NULL;
	int l = 0, c = 0;
	for (t = x; t != NULL && l <= i; t = t->link_)
	{
		if (l == i)
			z = t->columns;
		l++;
	}

	struct columns* q;

	for (q = z; q != NULL && c <= j; q = q->link_)
	{
		if (c == j)
			q->info = k;
		c++;
	}
}

void main()
{
	struct row* x = NULL;

	CreateMatrix(x, 3, 2);

	ViewMatrix(x);
	cout << endl;

	Modify(x, 1, 1, 999);

	ViewMatrix(x);
	cout << endl;

	_getch();
}