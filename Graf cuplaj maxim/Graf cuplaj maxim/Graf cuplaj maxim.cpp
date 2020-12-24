#include <fstream>
#include <vector>
using namespace std;
const int maxn = 101;

void citire(vector<int> G[], int& N, int& M)
{
	int E;
	ifstream in("cuplaj.in");
	in >> N >> M >> E;
	int x, y;
	for (int i = 1; i <= E; ++i)
	{
		in >> x >> y;
		G[x].push_back(y);
	}
	in.close();
}

bool Cuplare(vector<int> G[], int i, int st[], int dr[], bool V[])
{
	if (V[i])
		return false;
	V[i] = true;
	vector<int>::iterator v;
	for (v = G[i].begin();
		v != G[i].end(); ++v)
		if (!st[*v])
		{
			st[*v] = i;
			dr[i] = *v;
			return true;
		}
	for (v = G[i].begin();
		v != G[i].end(); ++v)
		if (Cuplare(G, st[*v], st, dr, V))
		{
			st[*v] = i;
			dr[i] = *v;
			return true;
		}
	return false;
}

void HopcroftKarp(vector<int> G[], int N)
{
	int st[maxn], dr[maxn];
	bool V[maxn], ok = true;
	for (int i = 1; i < maxn; ++i)
		st[i] = dr[i] = 0;
	do
	{
		ok = false;
		for (int i = 1; i <= N; ++i)
			V[i] = false;
		for (int i = 1; i <= N; ++i)
			if (!dr[i])
				ok |= Cuplare(G, i, st, dr, V);
	} while (ok);
	ofstream out("cuplaj.out");
	for (int i = 1; i <= N; ++i)
		if (dr[i])
			out << i << ' ' << dr[i] << '\n';
	out.close();
}

int main()
{
	int N, M;
	vector<int> G[maxn];
	citire(G, N, M);
	HopcroftKarp(G, N);
	return 0;
}