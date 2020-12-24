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

bool DFS(vector<int> G[], int nod, int pred[])
{
	for (int i = 0; i < G[nod].size(); ++i)
		if (pred[G[nod][i]] != nod)
		{
			if (pred[G[nod][i]] != -1)
				return true;
			else
			{
				pred[G[nod][i]] = nod;
				return DFS(G, G[nod][i], pred);
			}
		}
	return false;
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
	out << DFS(G, 1, pred);
	out.close();
	return 0;
}