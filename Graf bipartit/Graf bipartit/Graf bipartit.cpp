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

bool bipartit(vector<int> G[], int N)
{
	queue<int> C;
	int cul[maxn];
	cul[1] = 1;
	for (int i = 2; i <= N; ++i)
		cul[i] = 0;
	C.push(1);
	while (!C.empty())
	{
		int nod = C.front();
		for (int i = 0; i < G[nod].size(); ++i)
			if (!cul[G[nod][i]]) // nu este colorat, il coloram
			// in culoarea opusa nodului *nod*
			{
				cul[G[nod][i]] = 3 - cul[nod];
				C.push(G[nod][i]);
			}
			else if (cul[G[nod][i]] == cul[nod]) // trebuie schimbata
			// culoarea
				return false;
		C.pop();
	}
	return true;
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
	out << bipartit(G, N);
	out.close();
	return 0;
}