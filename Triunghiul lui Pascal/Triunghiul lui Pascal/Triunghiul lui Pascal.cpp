//Se dau mai multe perechi de numere (N, K), cu 1 <= K <= N <= 12. Se cere calcularea valorii Combinari de N luate cate K
//pentru fiecare pereche data. O prima idee de rezolvare consta in calcularea combinarilor folosind formula pentru numarul 
//acestora. Acesta solutie nu este insa foarte eficienta.
//Deoarece numerele date sunt cel mult 12, putem calcula triunghiul lui Pascal pana la linia 12. Al j-lea numar de pe 
//linia i a triunghiului lui Pascal (numerotarea incepe de la zero) reprezinta Combinari de i luate cate j. Astfel, avand 
//calculat triunghiul, putem afisa in O(1) raspunsul pentru fiecare intrebare.
//Triunghiul lui Pascal se construieste dupa urmatoarele reguli:
//		->Prima linie (linia 0) contine numarul 1.
//		->Linia i contine i + 1 numere.
//		->Primul si ultimul numar de pe fiecare linie este numarul 1.
//		->Fiecare numar, in afara de primul si ultimul, de pe o linie este suma celor doua numere de deasupra sa.

#include <fstream>
using namespace std;
const int maxN = 13;

void preprocesare(int A[maxN][maxN])
{
	for (int i = 0; i < maxN - 1; ++i)
		A[i][0] = 1, A[i][i + 1] = 0;
	A[0][0] = 1;
	for (int i = 1; i < maxN; ++i)
		for (int j = 1; j <= i; ++j)
			A[i][j] = A[i - 1][j] + A[i - 1][j - 1];
}

int main()
{
	int N, K, A[maxN][maxN];
	preprocesare(A);
	ifstream in("pascal.in");
	ofstream out("pascal.out");
	while (in >> N >> K)
		out << A[N][K] << endl;
	in.close();
	out.close();
	return 0;
}