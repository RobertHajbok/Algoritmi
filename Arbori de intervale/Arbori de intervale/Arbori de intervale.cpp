#include <fstream>
#include <algorithm>
using namespace std;
const int maxN = 101;
const int maxArb = 1 << 8;
const int inf = 1 << 30;

void citire(int& N, int& T, int A[], ifstream& in)
{
	in >> N >> T;
	for (int i = 1; i <= N; ++i)
		in >> A[i];
}

void build(int Arb[], int A[], int nod, int st, int dr)
{
	if (st == dr)
	{
		Arb[nod] = A[st];
		return;
	}
	int m = (st + dr) / 2, fiu = 2 * nod;
	build(Arb, A, fiu, st, m);
	build(Arb, A, fiu + 1, m + 1, dr);
	Arb[nod] = min(Arb[fiu], Arb[fiu + 1]);
}

int query(int Arb[], int nod, int st, int dr, int x, int y)
{
	if (st > y || dr < x) // interval invalid
		return INT_MAX;
	if (x <= st && dr <= y) // solutie
		return Arb[nod];
	int m = (st + dr) / 2, fiu = 2 * nod;
	return min(query(Arb, fiu, st, m, x, y), query(Arb, fiu + 1, m + 1, dr, x, y));
}

void update(int Arb[], int nod, int st, int dr, int x, int y)
{
	if (st > x || dr < x)
		return;
	if (st == dr)
	{
		Arb[nod] = y;
		return;
	}
	int m = (st + dr) / 2, fiu = 2 * nod;
	update(Arb, fiu, st, m, x, y);
	update(Arb, fiu + 1, m + 1, dr, x, y);
	Arb[nod] = min(Arb[fiu], Arb[fiu + 1]);
}

int main()
{
	int N, T;
	int A[maxN], Arb[maxArb];
	ifstream in("RMQ2.in");
	citire(N, T, A, in);
	ofstream out("RMQ2.out");
	build(Arb, A, 1, 1, N);
	while (T--)
	{
		int op, x, y;
		in >> op >> x >> y;
		if (op == 1)
			out << query(Arb, 1, 1, N, x, y) << '\n';
		else
			update(Arb, 1, 1, N, x, y);
	}
	in.close();
	out.close();
	return 0;
}