//Consideram un sir de 2*N numere intregi si doua persoane A si B care joaca alternativ urmatorul joc: fiecare persoana,
//incepand cu persoana A, scoate fie primul fie ultimul element din sir, care se aduna la numerele deja alese de acea 
//persoana. Ne intereseaza suma maxima pe care o poate obtine persoana A daca ambele persoane joaca optim.
//Prima linie a fisierului de intrare joc.in contine pe prima linie numarul N, iar pe urmatoarea linie 2*N numere 
//intregi reprezentand sirul pe care se joaca. In fisierul joc.out se va afisa suma maxima pe care o poate obtine
//persoana A, in conditiile in care ambii jucatori joaca optim.

#include <fstream>
#include <algorithm>
using namespace std;
const int maxn = 101;

void citire(int V[], int& N)
{
	ifstream in("joc.in");
	in >> N;
	N *= 2; // mai simplu decat sa lucram cu 2*N
	for (int i = 1; i <= N; ++i)
		in >> V[i];
	in.close();
}

int joc(int V[], int N, int S[maxn][maxn])
{
	S[N][N] = V[N];
	for (int i = 1; i < N; ++i)
	{
		S[i][i] = V[i];
		S[i][i + 1] = max(V[i], V[i + 1]);
	}
	for (int i = N - 2; i; --i)
		for (int j = i + 2; j <= N; ++j)
		{
			int C1 = V[i] + min(S[i + 2][j], S[i + 1][j - 1]);
			int C2 = V[j] + min(S[i][j - 2], S[i + 1][j - 1]);
			S[i][j] = max(C1, C2);
		}
	return S[1][N];
}

int main()
{
	int N, V[maxn], S[maxn][maxn];
	citire(V, N);
	ofstream out("joc.out");
	out << joc(V, N, S);
	out.close();
	return 0;
}