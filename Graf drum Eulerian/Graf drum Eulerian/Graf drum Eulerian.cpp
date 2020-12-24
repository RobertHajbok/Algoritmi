#include <fstream>
#include <vector>
using namespace std;
const int maxn = 101;

void citire(vector<int> G[], int& N, int& M)
{
	ifstream in("euler.in");
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

void euler(vector<int> G[], int nod, vector<int>& st)
{
	for (int i = 0; i < G[nod].size(); ++i)
	{
		// trebuie sters G[nod][i] din lista lui nod si nod din lista lui G[nod][i]
		int temp = G[nod][i];
		G[nod].erase(G[nod].begin() + i);
		for (int j = 0; j < G[temp].size(); ++j)
			if (G[temp][j] == nod)
			{
				G[temp].erase(G[temp].begin() + j);
				break;
			}
		euler(G, temp, st);
	}
	st.push_back(nod);
}

int main()
{
	int N, M;
	vector<int> G[maxn], st;
	citire(G, N, M);
	euler(G, 1, st);
	ofstream out("euler.out");
	for (int i = st.size() - 1; i >= 0; --i)
		out << st[i] << ' ';
	out.close();
	return 0;
}