//Se da un labirint reprezentat cu ajutorul unei matrici patratice A de ordin N a caror valori pot fi doar 0 si 1. Fiecare
//element al matricii reprezinta o incapere a labirintului. Valoarea 0 reprezinta faptul ca respectiva camera este 
//deschisa, iar valoarea 1 reprezinta o camera inchisa. Dintr-o camera oarecare, putem ajunge in camerele care se 
//invecineaza cu aceasta la sud, nord, est sau vest (daca acestea sunt deschise desigur). Mai mult, putem trece prin 
//fiecare camera cel mult o data!
//Se cere determinarea tuturor posibilitatilor de a ajunge din incaperea (1, 1) in incaperea (N, N) respectand conditiile
//din enunt. Datele de intrare se citesc din fisierul labirint.in, iar modalitatile gasite se scriu in fisierul 
//labirint.out in felul urmator: fiecare linie a fisierului contine, in ordine, cate o pereche i j care descrie o camera 
//a traseului curent. Cand se trece la un nou traseu, se lasa o linie libera.

#include <fstream>
using namespace std;
const int maxn = 100;
const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };

struct stiva
{
	int lin, col;
};

void citire(int& N, bool A[maxn][maxn])
{
	ifstream in("labirint.in");
	in >> N;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			in >> A[i][j];
	in.close();
}

bool valid(int lin, int col, int N, bool A[maxn][maxn])
{
	if (lin > 0 && lin <= N &&
		col > 0 && col <= N)
		if (A[lin][col] == false)
			return true;
	return false;
}

void back(int k, int lin, int col, int N, bool A[maxn][maxn], stiva st[], ofstream& out)
{
	st[k].lin = lin;
	st[k].col = col;
	if (lin == N && col == N)
	{
		for (int i = 1; i <= k; ++i)
			out << st[i].lin << ' ' << st[i].col << '\n';
		out << '\n';
		return;
	}
	for (int i = 0; i < 4; ++i)
	{
		int n_lin = lin + dx[i];
		int n_col = col + dy[i];
		if (valid(n_lin, n_col, N, A))
		{
			A[lin][col] = true;
			back(k + 1, n_lin, n_col, N, A, st, out);
			A[lin][col] = false;
		}
	}
}

int main()
{
	int N;
	bool A[maxn][maxn];
	stiva st[maxn * maxn];
	citire(N, A);
	ofstream out("labirint.out");
	back(1, 1, 1, N, A, st, out);
	out.close();
	return 0;
}