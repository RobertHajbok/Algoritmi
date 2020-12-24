#include <fstream>
#include <queue>
using namespace std;
const int maxn = 101;

void citire(vector<int> G[], int& N, int& M)
{
	ifstream in("bfs.in");
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

void BFS(vector<int> G[])
{
	queue<int> C;
	bool V[maxn];
	ofstream out("bfs.out");
	memset(V, 0, maxn * sizeof(bool));
	V[1] = true;
	C.push(1);
	while (!C.empty())
	{
		int nod = C.front();
		out << nod << ' ';
		for (int i = 0; i < G[nod].size(); ++i)
			if (!V[G[nod][i]])
			{
				C.push(G[nod][i]);
				V[G[nod][i]] = true;
			}
		C.pop();
	}
	out.close();
}

int main()
{
	int N, M;
	bool V[maxn];
	vector<int> G[maxn];
	citire(G, N, M);
	for (int i = 1; i <= N; ++i)
		V[i] = false;
	ofstream out("bfs.out");
	BFS(G);
	out.close();
	return 0;
}