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

vector<Punct> Jarvis(const vector<Punct>& P)
{
	int start = 0; // vectorii incep de la 0
	for (int i = 1; i < P.size(); ++i)
		if (P[i].x < P[start].x || (P[i].x == P[start].x && P[i].y > P[start].y))
			start = i;
	vector<Punct> CH;
	CH.push_back(P[start]);
	for (int i = 0; i < CH.size(); ++i)
	{
		Punct nextPct = (CH[i] == P[0]) ? P[1] : P[0];
		for (int j = 0; j < P.size(); ++j)
			if (Orientare(CH[i], P[j], nextPct) > 0)
				nextPct = P[j];
		if (nextPct != CH[0])
			CH.push_back(nextPct);
	}
	return CH;
}

int main()
{
	int N;
	vector<Punct> P;
	Citire(P, N);
	vector<Punct> CH = Jarvis(P);
	cout << endl;
	for (int i = 0; i < CH.size(); ++i)
		cout << CH[i].x << " " << CH[i].y << endl;
	_getch();
	return 0;
}