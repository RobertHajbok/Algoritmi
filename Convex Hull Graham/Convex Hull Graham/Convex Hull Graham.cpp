#include <algorithm>
#include <conio.h>
#include <iostream>
#include <vector>
using namespace std;

struct Punct
{
	double x, y;
	Punct(double abscisa, double ordonata) : x(abscisa), y(ordonata) {}
	Punct() {}
	// se vor compara puncte, deci trebuie sa supraincarcam operatorii de egalitate
	bool operator ==(const Punct& other)
	{
		return x == other.x && y == other.y;
	}
	bool operator !=(const Punct& other)
	{
		return x != other.x || y != other.y;
	}
};

int Orientare(const Punct& A, const Punct& B, const Punct& C)
{
	double temp = (B.y - A.y) * (C.x - A.x) - (C.y - A.y) * (B.x - A.x);
	if (temp < 0)
		return -1;
	else
		if (temp == 0)
			return 0;
		else
			return 1;
}

struct Sorter // o structura care nu poate fi initializata, folosita pentru a sorta in functie de un element al vectorului
{
private: static Punct st;
	   static bool cmp(const Punct& A, const Punct& B)
	   {
		   return (A.y - st.y) * (B.x - st.x) < (B.y - st.y) * (A.x - st.x);
	   }
	   Sorter() {}
public: static void Sort(vector<Punct>& P, int start)
{
	st = P[start];
	Punct t = P[0];
	P[0] = P[start];
	P[start] = t;
	sort(P.begin() + 1, P.end(), Sorter::cmp);
}
};
Punct Sorter::st = Punct();

vector<Punct> Graham(vector<Punct> P)
{
	int start = 0; // vectorii incep de la 0
	for (int i = 1; i < P.size(); ++i)
		if (P[i].x < P[start].x || (P[i].x == P[start].x && P[i].y > P[start].y))
			start = i;
	Sorter::Sort(P, start);
	P.insert(P.begin(), P[P.size() - 1]);
	int nrH = 2;
	for (int i = 3; i < P.size(); ++i)
	{
		while (nrH > 1 && Orientare(P[nrH - 1], P[nrH], P[i]) > 0)
			--nrH;
		++nrH;
		swap(P[nrH], P[i]);
	}
	return vector<Punct>(P.begin(), P.begin() + nrH);
}

void Citire(vector<Punct>& P, int& N)
{
	cin >> N;
	double x, y;
	for (int i = 1; i <= N; ++i)
	{
		cin >> x >> y;
		P.push_back(Punct(x, y));
	}
}

int main()
{
	int N;
	vector<Punct> P;
	Citire(P, N);
	vector<Punct> CH = Graham(P);
	cout << endl;
	for (int i = 0; i < CH.size(); ++i)
		cout << CH[i].x << " " << CH[i].y << endl;
	_getch();
	return 0;
}