#include <fstream>
#include <vector>
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

void DFSpreordine(vector<int> G[], int nod, bool V[], ofstream& out)
{
	if (V[nod])
		return;
	V[nod] = true;
	out << nod << ' ';
	for (int i = 0; i < G[nod].size(); ++i)
		DFSpreordine(G, G[nod][i], V, out);
}

void DFSpostordine(vector<int> G[], int nod, bool V[], ofstream& out)
{
	if (V[nod])
		return;
	V[nod] = true;
	for (int i = 0; i < G[nod].size(); ++i)
		DFSpostordine(G, G[nod][i], V, out);
	out << nod << ' ';
}

int main()
{
	int N, M;
	bool V[maxn];
	vector<int> G[maxn];
	citire(G, N, M);
	for (int i = 1; i <= N; ++i)
		V[i] = false;
	ofstream out("dfs.out");
	DFSpreordine(G, 1, V, out);
	//DFSpostordine(G, 1, V, out);
	out.close();
	return 0;
}