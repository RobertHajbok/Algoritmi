#include <fstream>
using namespace std;
const int maxN = 101;

void Actual(int, int, int, int[]);
void citire(int& N, int& T, int A[], int S[], ifstream& in)
{
	in >> N >> T;
	// S trebuie initializat cu 0 se poate folosi si memset
	for (int i = 1; i <= N; ++i)
		S[i] = 0;
	for (int i = 1; i <= N; ++i)
	{
		in >> A[i];
		Actual(N, i, A[i], S);
	}
}

int Suma(int i, int S[]) // query
{
	int rez = 0;
	for (; i > 0; i -= i ^ (i & (i - 1)))
		rez += S[i];
	return rez;
}

// update
void Actual(int N, int i, int v, int S[])
{
	for (; i <= N; i += i ^ (i & (i - 1)))
		S[i] += v;
}

int main()
{
	int N, T, A[maxN], S[maxN];
	ifstream in("sume.in");
	citire(N, T, A, S, in);
	ofstream out("sume.out");
	while (T--)
	{
		int op, x, y;
		in >> op >> x >> y;
		if (op == 1)
			out << Suma(y, S) - Suma(x - 1, S) << '\n';
		else
			Actual(N, x, y, S);
	}
	in.close();
	out.close();
	return 0;
}