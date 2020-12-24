//Consideram un vector A cu N elemente numere intregi. Un subsir a lui A este o secventa de elemente nu neaparat 
//consecutive ale lui A, dar a caror ordine relativa in A este pastrata. Un subsir crescator a lui A este un subsir a 
//lui A a carui elemente sunt ordonate crescator. Un subsir crescator maximal este un subsir crescator la care nu se 
//mai pot adauga elemente fara a strica proprietatea de subsir crescator. Se cere determinarea celui mai lung subsir 
//crescator maximal al vectorului A.
//Datele de intrare se citesc din fisierul subsir.in. in fisierul subsir.out se va afisa pe prima linie lungimea 
//lg a celui mai lung subsir crescator maximal gasit, iar pe urmatoarea linie se vor afisa valorile (in numar de lg) 
//care constituie un astfel de subsir. Se poate afisa orice solutie daca exista mai multe.

#include <fstream>
using namespace std;
const int maxn = 101;
const int inf = 1 << 30;

void citire(int A[], int& N)
{
	ifstream in("subsir.in");
	in >> N;
	for (int i = 1; i <= N; ++i)
		in >> A[i];
	in.close();
}

int cbin(int st, int dr, int val, int L[])
{
	while (st < dr)
	{
		int m = (st + dr) / 2;
		if (L[m] < val)
			st = m + 1;
		else
			dr = m;
	}
	return st;
}

void reconst(int N, int A[], int P[], int val, ofstream& out)
{
	for (int i = N; i; --i)
		if (P[i] == val)
		{
			reconst(i - 1, A, P, val - 1, out);
			out << A[i] << ' ';
			break;
		}
}

int cmlscm(int A[], int N, int L[], int P[])
{
	int lg = 0;
	for (int i = 1; i <= N; ++i)
	{
		L[i] = inf;
		int k = cbin(1, lg + 1, A[i], L);
		// creste lungimea celui mai lung subsir?
		if (L[k] == inf)
			++lg;
		L[k] = A[i];
		P[i] = k;
	}
	return lg;
}

int main()
{
	int N, A[maxn], L[maxn], P[maxn];
	citire(A, N);
	ofstream out("subsir.out");
	int sol = cmlscm(A, N, L, P);
	out << sol << '\n';
	reconst(N, A, P, sol, out);
	out.close();
	return 0;
}