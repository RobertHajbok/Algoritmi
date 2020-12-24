#include <fstream>
#include <vector>
using namespace std;
const int maxn = 101;

void citire(vector<int> G[], vector<int> GT[], int& N, int& M)
{
	ifstream in("ctc.in");
	in >> N >> M;
	int x, y;
	for (int i = 1; i <= M; ++i)
	{
		in >> x >> y;
		G[x].push_back(y);
		GT[y].push_back(x);
	}
	in.close();
}

void DFS_G(vector<int> G[], int nod, bool V[], vector<int>& postord)
{
	if (V[nod])
		return;
	V[nod] = true;
	for (int i = 0; i < G[nod].size(); ++i)
		DFS_G(G, G[nod][i], V, postord);
	postord.push_back(nod);
}

void DFS_GT(vector<int> GT[], int nod, bool V[], ofstream& out)
{
	if (!V[nod])
		return;
	V[nod] = false;
	out << nod << ' ';
	for (int i = 0; i < GT[nod].size(); ++i)
		DFS_GT(GT, GT[nod][i], V, out);
}

int main()
{
	int N, M;
	vector<int> G[maxn], GT[maxn];
	bool V[maxn];
	citire(G, GT, N, M);
	for (int i = 1; i <= N; ++i)
		V[i] = false;
	vector<int> postord;
	for (int i = 1; i <= N; ++i)
		DFS_G(G, i, V, postord);
	ofstream out("ctc.out");
	for (int i = 1; i <= N; ++i)
		if (V[i])
		{
			DFS_GT(GT, i, V, out);
			out << '\n';
		}
	out.close();
	return 0;
}