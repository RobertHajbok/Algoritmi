//Se dau doua siruri de caractere A si B, formate din litere mici ale alfabetului englez. Asupra sirului A putem face 
//urmatoarele trei operatii:
//			1. Inseram un caracter.
//			2. Stergem un caracter.
//			3. Inlocuim un caracter cu orice alt caracter din alfabetul folosit.
//Se cere determinarea numarului minim de operatii necesare transformarii sirului de caractere A in sirul de caractere B.
//Cele doua siruri de caractere se citesc din fisierul lev.in, iar numarul minim de operatii se va afisa in 
//fisierul lev.out.

#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 101;

void citire(string& A, string& B)
{
	ifstream in("lev.in");
	in >> A >> B;
	in.close();
}

int levenshtein(const string& A, const string& B, int D[maxn][maxn])
{
	for (int i = 0; i <= A.length(); ++i)
		D[i][0] = i;
	for (int i = 0; i <= B.length(); ++i)
		D[0][i] = i;
	for (int i = 1; i <= A.length(); ++i)
		for (int j = 1; j <= B.length(); ++j)
			if (A[i - 1] == B[j - 1])
				D[i][j] = D[i - 1][j - 1];
			else
				D[i][j] = 1 + min(min(D[i - 1][j], D[i][j - 1]), D[i - 1][j - 1]);
	return D[A.length()][B.length()];
}

int main()
{
	string A, B;
	int L[maxn][maxn];
	citire(A, B);
	ofstream out("lev.out");
	out << levenshtein(A, B, L) << '\n';
	out.close();
	return 0;
}