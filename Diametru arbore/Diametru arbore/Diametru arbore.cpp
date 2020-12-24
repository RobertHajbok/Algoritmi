#include <fstream>
#include <vector>
using namespace std;
const int maxn = 101;

void citire(vector<int> G[], int& N)
{
	ifstream in("dfs.in");
	in >> N;
	int x, y;
	for (int i = 1; i < N; ++i)
	{
		in >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	in.close();
}

void init(int D[], int N)
{
	for (int i = 1; i <= N; ++i)
		D[i] = -1;
}

void DFS(vector<int> G[], int nod, int dist, int D[])
{
	// putem folosi D ca sa vedem daca un nod a mai fost sau nu vizitat
	if (D[nod] != -1)
		return;
	D[nod] = dist;
	for (int i = 0; i < G[nod].size(); ++i)
		DFS(G, G[nod][i], dist + 1, D);
}

int main()
{
	int N;
	int D[maxn];
	vector<int> G[maxn];
	citire(G, N);
	init(D, N);
	DFS(G, 1, 0, D);
	int X = 1;
	for (int i = 2; i <= N; ++i)
		if (D[i] > D[X])
			X = i;
	init(D, N);
	DFS(G, X, 0, D);
	int max = D[1];
	for (int i = 2; i <= N; ++i)
		if (D[i] > max)
			max = D[i];
	ofstream out("dfs.out");
	out << max;
	out.close();
	return 0;
}