//Se dau doua siruri de caractere A si B, formate din litere mici ale alfabetului englez. Se cere gasirea unui sir de 
//caractere C de lungime maxima care este subsir atat a lui A cat si a lui B.
//Sirurile A si B se citesc din fisierul sircom.in, fiecare pe cate o linie. In fisierul sircom.out se va afisa pe prima
//linie lungimea celui mai lung subsir comun, iar pe a doua linie sirul gasit.

#include <fstream>
#include <string>
using namespace std;
const int maxn = 101;

void citire(string& A, string& B)
{
	ifstream in("sircom.in");
	in >> A >> B;
	in.close();
}

int cmlsc(string& A, string& B, int L[maxn][maxn])
{
	for (int i = 0; i <= A.length(); ++i)
		L[i][0] = 0;
	for (int i = 0; i <= B.length(); ++i)
		L[0][i] = 0;
	for (int i = 1; i <= A.length(); ++i)
		for (int j = 1; j <= B.length(); ++j)
			if (A[i - 1] == B[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;
			else
			{
				if (L[i - 1][j] > L[i][j - 1])
					L[i][j] = L[i - 1][j];
				else
					L[i][j] = L[i][j - 1];
			}
	return L[A.length()][B.length()];
}

void reconst(int x, int y, string& A, string& B, int L[maxn][maxn], ofstream& out)
{
	if (x < 1 || y < 1)
		return;
	if (A[x - 1] == B[y - 1])
	{
		reconst(x - 1, y - 1, A, B, L, out);
		out << A[x - 1];
	}
	else
	{
		if (L[x - 1][y] > L[x][y - 1])
			reconst(x - 1, y, A, B, L, out);
		else
			reconst(x, y - 1, A, B, L, out);
	}
}

int main()
{
	string A, B;
	int L[maxn][maxn];
	citire(A, B);
	ofstream out("sircom.out");
	out << cmlsc(A, B, L) << '\n';
	reconst(A.length(), B.length(), A, B, L, out);
	out.close();
	return 0;
}