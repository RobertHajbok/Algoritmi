#include <fstream>
#include <vector>
using namespace std;
const int maxn = 101;

void citire(int G[maxn][maxn], int& N, int& M, int& x)
{
	ifstream in("hamilton.in");
	in >> N >> M >> x;
	int p, q, c;
	for (int i = 1; i <= M; ++i)
	{
		in >> p >> q >> c;
		G[p][q] = G[q][p] = c;
	}
	in.close();
}

void hamilton(int G[maxn][maxn], int N, int nod, int nr, int c, int& cmin, bool V[], int st[], int sol[])
{
	if (c > cmin || V[nod] == true)
		return;
	st[nr] = nod;
	if (nr == N && c < cmin)
	{
		cmin = c;
		for (int i = 1; i <= N; ++i)
			sol[i] = st[i];
		return;
	}
	V[nod] = true;
	for (int i = 1; i <= N; ++i)
		if (G[nod][i])
			hamilton(G, N, i, nr + 1, c + G[nod][i], cmin, V, st, sol);
	V[nod] = false;
}

int main()
{
	int G[maxn][maxn], N, M, x;
	bool V[maxn];
	citire(G, N, M, x);
	for (int i = 1; i <= N; ++i)
		V[i] = false;
	int st[maxn], sol[maxn];
	int cmin = 1 << 30;
	hamilton(G, N, x, 1, 0, cmin, V, st, sol);
	ofstream out("hamilton.out");
	//out << cmin << '\n';
	for (int i = 1; i <= N; ++i)
		out << sol[i] << ' ';
	out.close();
	return 0;
}