//Se dau N – 1 operatori matematici O1, O2, ..., ON – 1 din multimea {+, -, *}, avand semnificatia lor obisnuita si un 
//numar S. Scrieti un program care gaseste un sir de N numere naturale X1, X2, ..., XN din intervalul [1, N], astfel incat
//expresia formata prin alaturarea numerelor gasite cu operatorii dati sa dea, modulo 16381, rezultatul S.
//Datele de intrare se citesc din fisierul expresie.in, iar solutia se scrie in fisierul expresie.out. Fisierul de 
//intrare contine pe prima linie numerele N si S, separate printr-un spatiu, iar pe a doua linie N-1 operatori matematici
//din multimea specificata in enunt. In fisierul de iesire se afiseaza, separate printr-un spatiu, pe prima linie, 
//elementele sirului X.

#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <time.h>
using namespace std;

const int maxN = 1001;
const int maxpop = 400;
const int maxlg = 2 * maxN + 1;
const int maxeli = 50;
const int prob_recomb = (int)((double)0.80 * RAND_MAX);
const int prob_mutatie = (int)((double)0.95 * RAND_MAX);
const int mod = 16381;

struct info
{
	int P[maxlg], fitness;
};

void citire_init(int& N, int& S, info A[])
{
	ifstream in("expresie.in");
	in >> N >> S;
	char x;
	int ops[maxN];
	for (int i = 1; i < N; ++i)
	{
		in >> x;
		if (x == '-')
			ops[i] = -1;
		else
			if (x == '+')
				ops[i] = -2;
			else
				ops[i] = -3;
	}
	ops[N] = -100;
	in.close();
	for (int i = 1; i < maxpop; ++i)
	{
		for (int j = 1, k = 1; j < 2 * N; j += 2, ++k)
		{
			A[i].P[j] = 1 + rand() % N;
			A[i].P[j + 1] = ops[k];
		}
	}
}
// <EVALUARE>

int paran(int& k, int cr, info A[])
{
	return A[cr].P[k++];
}

int inm(int& k, int cr, info A[])
{
	int ret = paran(k, cr, A);
	while (A[cr].P[k] == -3)
	{
		++k;
		ret *= paran(k, cr, A);
		ret %= mod;
	}
	return ret;
}

int eval(int& k, int cr, info A[])
{
	int ret = inm(k, cr, A);
	while (A[cr].P[k] == -1 || A[cr].P[k] == -2)
	{
		if (A[cr].P[k++] == -1)
			ret -= inm(k, cr, A);
		else
			ret += inm(k, cr, A);
		ret %= mod;
		while (ret < 0)
			ret += mod;
	}
	return ret;
}
// </EVALUARE>

void calc_fitness(int N, int S, info A[])
{
	for (int cr = 1; cr < maxpop; ++cr)
	{
		int k = 1;
		A[cr].fitness = abs(eval(k, cr, A) - S);
	}
	sort(A + 1, A + maxpop);
}

void noua_gen(int N, info A[])
{
	for (int i = maxeli + 1; i < maxpop; ++i)
	{
		if (rand() < prob_recomb) // recombinare
		{
			int i1, i2;
			do
			{
				i1 = 1 + rand() % maxeli;
				i2 = 1 + rand() % maxeli;
			} while (i1 == i2);
			int poz;
			do
			{
				poz = 1 + (rand() % (2 * N - 1));
			} while (poz % 2 == 0);
			for (int j = 1; j < poz; j += 2)
				A[i].P[j] = A[i1].P[j];
			for (int j = poz; j < 2 * N; j += 2)
				A[i].P[j] = A[i2].P[j];
		}
		if (rand() < prob_mutatie) // mutatie
		{
			int poz;
			do
			{
				poz = 1 + (rand() % (2 * N - 1));
			} while (poz % 2 == 0);
			A[i].P[poz] = 1 + (rand() % N);
		}
	}
}

bool operator<(const info& x, const info& y)
{
	return x.fitness < y.fitness;
}

void start(int N, int S, info A[])
{
	do
	{
		noua_gen(N, A);
		calc_fitness(N, S, A);
	} while (A[1].fitness != 0);
	ofstream out("expresie.out");
	for (int i = 1; i < 2 * N; i += 2)
	{
		out << A[1].P[i] << " ";
	}
	out << endl;
	out.close();
}

int main()
{
	int N, S;
	info* A = new info[maxpop];
	srand((unsigned)time(0));
	citire_init(N, S, A);
	start(N, S, A);
	delete[] A;
	return 0;
}