#include<iostream>
#include<conio.h>
using namespace std;
void Hanoi4tije(int nDiscuri, char tSursa, char tInter1, char tInter2, char tDest)
{
	if (nDiscuri == 1)
		cout << tSursa << "->" << tDest << endl;
	else
		if (nDiscuri == 2)
		{
			cout << tSursa << "->" << tInter1 << endl;
			cout << tSursa << "->" << tDest << endl;
			cout << tInter1 << "->" << tDest << endl;
		}
		else
		{
			Hanoi4tije(nDiscuri - 2, tSursa, tInter2, tDest, tInter1);
			cout << tSursa << "->" << tInter2 << endl;
			cout << tSursa << "->" << tDest << endl;
			cout << tInter2 << "->" << tDest << endl;
			Hanoi4tije(nDiscuri - 2, tInter1, tSursa, tInter2, tDest);
		}
}
int main()
{
	Hanoi4tije(5, 'A', 'B', 'C', 'D');
	getch();
	return 0;
}