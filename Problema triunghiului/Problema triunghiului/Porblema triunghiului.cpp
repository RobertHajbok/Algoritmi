//Se da un triunghi de numere naturale de latura N pe care se joaca urmatorul joc: se alege numarul din coltul de sus 
//al triunghiului. Dupa aceea, la fiecare pas, ne putem deplasa fie cu o pozitie in jos, fie cu o pozitie in jos si una 
//catre dreapta fata de pozitia ultimului numar ales. Numarul pe care se face deplasarea este ales. Acest lucru se 
//continua pana cand se ajunge pe ultima linie a triunghiului. Ne intereseaza un traseu pentru care suma numerelor alese 
//este maxima.

#include <fstream>
#include <algorithm>
using namespace std;
const int maxN = 101;
const int inf = -2000000000;

//Datele de intrare se citesc din fisierul triunghi.in: pe prima linie N, iar pe fiecare linie i a urmatoarelor linii, 
//cate i numere naturale, reprezentand o linie a triunghiului. In fisierul triunghi.out se va afisa, pe prima linie, suma
//maxima gasita. Pe a doua linie, se vor afisa in ordine numerele alese, separate printr-un spatiu.
void citire(int& N, int A[maxN][maxN])
{
	ifstream in("triunghi.in");
	in >> N;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= i; ++j)
			in >> A[i][j];
	in.close();
}

void init(int N, int B[maxN][maxN])
{
	for (int i = 1; i <= N; ++i)
		B[i][0] = inf;
	for (int i = 1; i < N; ++i)
		B[i][i + 1] = inf;
}

void rez(int N, int A[maxN][maxN], int B[maxN][maxN])
{
	B[1][1] = A[1][1];
	for (int i = 2; i <= N; ++i)
		for (int j = 1; j <= i; ++j)
			B[i][j] = max(B[i - 1][j], B[i - 1][j - 1]) + A[i][j];
}

void reconst(int Xi, int Xj, int A[maxN][maxN], int B[maxN][maxN], ofstream& out)
{
	if (Xi == 1 && Xj == 1)
	{
		out << A[1][1] << ' ';
		return;
	}
	int t1 = B[Xi - 1][Xj];
	int t2 = B[Xi][Xj] - A[Xi][Xj];
	if (t1 == t2)
		reconst(Xi - 1, Xj, A, B, out);
	else
		reconst(Xi - 1, Xj - 1, A, B, out);
	out << A[Xi][Xj] << ' ';
}

int main()
{
	int N, A[maxN][maxN];
	int B[maxN][maxN];
	citire(N, A);
	init(N, B);
	rez(N, A, B);
	ofstream out("triunghi.out");
	int Xj = 1;
	for (int i = 2; i <= N; ++i)
		if (B[N][i] > B[N][Xj])
			Xj = i;
	out << B[N][Xj] << endl;
	reconst(N, Xj, A, B, out);
	out.close();
	return 0;
}