//Se da un sir A de N numere intregi. Ne intereseaza raspunsul la T intrebari de genul: „dandu-se x si y care este cel mai
//mic numar din secventa A[x, y]?”.
//Prima linie a fisierului de intrare rmq.in va contine N si T, urmatoarea linie va contine elementele sirului A, iar 
//urmatoarele T linii vor contine numerele x y cu semnificatia din enunt. In fisierul rmq.out se vor afisa T linii, 
//fiecare continand raspunsul la intrebarea corespunzatoare.
//O solutie in care parcurgem fiecare secventa data si determinam minimul se dovedeste a fi foarte ineficienta, avand
//complexitatea O(N*T) in cel mai rau caz.
//Problema prezentata este cunoscuta sub numele de problema Range Minimum Query (traducere: problema interogarilor de 
//minim pe intervale). Aceasta problema poate fi rezolvata in timp O(N*log N + T) si folosind memorie O(N*log N) 
//calculand o matrice pe care o vom folosi apoi pentru a raspunde la fiecare intrebare in timp O(1).

#include <fstream>
#include <algorithm>
using namespace std;
const int maxn = 101;
const int maxlog = 7;

void citire(int M[][maxn], int& N, int& T, ifstream& in)
{
	in >> N >> T;
	for (int i = 1; i <= N; ++i)
		in >> M[0][i];
}

void preproc(int N, int M[][maxn], int log2[])
{
	log2[0] = log2[1] = 0;
	for (int i = 2; i <= N; ++i)
		log2[i] = log2[i >> 1] + 1;
	for (int i = 1; i <= log2[N]; ++i)
		for (int j = 1; j + (1 << (i - 1)) <= N; ++j)
			M[i][j] = min(M[i - 1][j], M[i - 1][j + (1 << (i - 1))]);
}

int main()
{
	int N, T, log2[maxn], M[maxlog][maxn];
	ifstream in("rmq.in");
	citire(M, N, T, in);
	preproc(N, M, log2);
	ofstream out("rmq.out");
	int x, y;
	while (T--)
	{
		in >> x >> y;
		int L = log2[y - x + 1];
		out << min(M[L][x], M[L][y - (1 << L) + 1]) << '\n';
	}
	in.close();
	out.close();
	return 0;
}