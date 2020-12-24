#include<fstream>
using namespace std;
const int maxN = 20;
void citire(int& N)
{
	ifstream in("part.in");
	in >> N;
	in.close();
}
void part(int K, int N, int Sol[], ofstream& out)
{
	if (!N)
	{
		for (int i = 1; i < K; ++i)
			out << Sol[i] << ' ';
		out << endl;
		return;
	}
	for (int i = Sol[K - 1]; N - i >= 0; ++i)
	{
		Sol[K] = i;
		part(K + 1, N - i, Sol, out);
	}
}
int main()
{
	int N, Sol[maxN];
	citire(N);
	Sol[0] = 1;
	ofstream out("part.out");
	part(1, N, Sol, out);
	out.close();
	return 0;
}