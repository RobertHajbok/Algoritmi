//Consideram N obiecte caracterizate prin doua marimi: greutate (in kg) si valoare. Consideram un rucscac de capacitate 
//C kg. Ne intereseaza alegerea unei submultimi de obiecte a caror greutate totala sa fie cel mult C si a caror valoare 
//sa fie maxima.
//Datele de intrare se citesc din fisierul rucsac.in: pe prima linie valorile N si C, iar pe urmatoarele N linii cate doua
//valori Gi Vi reprezentand greutatea respectiv valoarea obiectului i. In fisierul de iesire rucsac1.out se va afisa pe 
//prima linie valoarea maxima a obiectelor alese, iar pe urmatoarea linie se vor afisa indicii obiectelor alese, in 
//orice ordine. Consideram ca exista intotdeauna solutie.

#include <fstream>
using namespace std;
const int maxn = 101;
const int maxc = 101;

struct obiect
{
	int G, V;
};

void citire(obiect A[], int& N, int& C)
{
	ifstream in("rucsac.in");
	in >> N >> C;
	for (int i = 1; i <= N; ++i)
		in >> A[i].G >> A[i].V;
	in.close();
}

void rezolvare(obiect A[], int N, int C, int F[], int P[])
{
	for (int i = 0; i <= C; ++i)
		F[i] = P[i] = 0;
	for (int i = 1; i <= N; ++i)
		for (int j = C; j >= A[i].G; --j)
			if (F[j] < F[j - A[i].G] + A[i].V)
			{
				F[j] = F[j - A[i].G] + A[i].V;
				P[j] = i;
			}
}

void reconst(obiect A[], int F[], int P[], int C, ofstream& out)
{
	int max = F[C];
	while (F[C] == max)
		--C;
	++C;
	while (P[C])
	{
		out << P[C] << ' ';
		C -= A[P[C]].G;
	}
}

int main()
{
	int N, C;
	obiect A[maxn];
	citire(A, N, C);
	int F[maxc], P[maxc];
	ofstream out("rucsac.out");
	rezolvare(A, N, C, F, P);
	out << F[C] << '\n';
	reconst(A, F, P, C, out);
	out.close();
	return 0;
}