//Se dau N matrice, considerate cu elemente numere reale, identificate printr-un vector de dimensiuni D. Astfel, matricea
//1 <= i ,= N are dimensiunea (D[i – 1], D[i]). Se cere gasirea numarului minim de inmultiri scalare necesare pentru 
//calcularea produsului celor N matrice.
//Fisierul de intrare inmopt.in contine pe prima linie numarul N al matricelor, iar pe linia urmatoare N + 1 valori ce
//reprezinta vectorul de dimensiuni. Numarul minim de inmultiri scalare se va afisa in fisierul inmopt.out.

#include <fstream>
#include <algorithm>
using namespace std;
const int maxn = 101;
const int inf = 1 << 30;

void citire(int D[], int& N)
{
	ifstream in("inmopt.in");
	in >> N;
	for (int i = 0; i <= N; ++i)
		in >> D[i];
	in.close();
}

int rezolvare(int D[], int N)
{
	int M[maxn][maxn];
	for (int i = 1; i <= N; ++i)
		M[i][i] = 0;
	for (int i = N - 1; i; --i)
		for (int j = i + 1; j <= N; ++j)
		{
			M[i][j] = inf;
			for (int k = i; k < j; ++k)
			{
				int t = M[i][k] + M[k + 1][j] +
					D[i - 1] * D[k] * D[j];
				M[i][j] = min(M[i][j], t);
			}
		}
	return M[1][N];
}

int main()
{
	int N, D[maxn];
	citire(D, N);
	ofstream out("inmopt.out");
	out << rezolvare(D, N);
	out.close();
	return 0;
}