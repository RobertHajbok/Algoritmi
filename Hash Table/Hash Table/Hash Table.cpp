#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include <conio.h>
using namespace std;
const int maxH = 1 << 20; // 2 la 20
int h(int x) // functia de dispersie e h(x) = x % (2 la 20)
{
	return x & (maxH - 1);
}

void Insert(int x, list<int> H[])
{
	H[h(x)].push_front(x);
}

bool Search(int x, list<int> H[])
{
	// pentru cautare se parcurge secvential lista
	int hash = h(x);
	list<int>::iterator i;
	for (i = H[hash].begin();
		i != H[hash].end(); ++i)
		if (*i == x)
			return true;
	return false;
}

void Remove(int x, list<int> H[])
{
	H[h(x)].remove(x);
}

int main()
{
	// 2 la 20 poate fi prea mult pentru un tablou local
	list<int>* H = new list<int>[maxH];
	srand((unsigned)time(0));
	for (int i = 1; i <= 2010; ++i)
		Insert(rand() * rand(), H);
	for (int i = 1; i <= 2010; ++i)
		cout << Search(rand() * rand(), H) << '\n';
	_getch();
	return 0;
}