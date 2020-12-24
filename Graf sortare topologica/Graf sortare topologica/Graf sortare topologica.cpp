#include <fstream>
#include <queue>
using namespace std;
const int maxn = 101;

void citire(vector<int> G[], int& N, int& M)
{
	ifstream in("dfs.in");
	in >> N >> M;
	int x, y;
	for (int i = 1; i <= M; ++i)
	{
		in >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	in.close();
}

void topo(vector<int> G[], int N, ofstream& out)
{
	int gr[maxn]; // gr[i] = gradul interior al lui i
	memset(gr, 0, maxn * sizeof(int));
	for (int i = 1; i <= N; ++i)
		for (int j = 0; j < G[i].size(); ++j)
			++gr[G[i][j]];
	queue<int> C;
	for (int i = 1; i <= N; ++i)
		if (gr[i] == 0)
			C.push(i);
	while (!C.empty())
	{
		int nod = C.front();
		out << nod << ' ';
		for (int i = 0; i < G[nod].size(); ++i)
		{
			--gr[G[nod][i]];
			if (gr[G[nod][i]] == 0)
				C.push(G[nod][i]);
		}
		C.pop();
	}
}

int main()
{
	int N, M;
	int pred[maxn];
	vector<int> G[maxn];
	citire(G, N, M);
	for (int i = 1; i <= N; ++i)
		pred[i] = -1;
	ofstream out("dfs.out");
	topo(G, 1, out);
	out.close();
	return 0;
}