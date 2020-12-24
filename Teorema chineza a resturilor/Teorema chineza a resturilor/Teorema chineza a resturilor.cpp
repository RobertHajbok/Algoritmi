#include <fstream>
using namespace std;
const int maxk = 100;

struct congruenta
{
	int a, n;
};

void citire(int& k, congruenta T[])
{
	ifstream in("TCR.in");
	in >> k;
	for (int i = 1; i <= k; ++i)
		in >> T[i].a >> T[i].n;
	in.close();
}

void euclid_ext(int X, int Y, int& a, int& b)
{
	if (X % Y == 0)
	{
		a = 0;
		b = 1;
		return;
	}
	int ta, tb;
	euclid_ext(Y, X % Y, ta, tb);
	a = tb;
	b = ta - tb * (X / Y);
}

int rezolvare(int k, congruenta T[])
{
	int N = 1, P[maxk], Q[maxk];
	for (int i = 1; i <= k; N *= T[i++].n);
	for (int i = 1; i <= k; ++i) P[i] = N / T[i].n;
	int a, b;
	for (int i = 1; i <= k; ++i)
	{
		euclid_ext(P[i], T[i].n, a, b);
		Q[i] = a;
	}
	int X = 0;
	for (int i = 1; i <= k; ++i)
		X += (T[i].a * P[i] * Q[i]) % N;
	return X;
}

int main()
{
	int k;
	congruenta T[maxk];
	citire(k, T);
	ofstream out("TCR.out");
	out << rezolvare(k, T);
	out.close();
	return 0;
}