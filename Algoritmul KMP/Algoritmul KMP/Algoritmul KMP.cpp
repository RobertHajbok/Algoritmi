//Se dau doua siruri de caractere S1 si S2, de dimensiune N respectiv M. Sa se determine de cate ori sirul S2 apare ca 
//subsecventa in sirul S1.

#include <fstream>
#include <cstring>
using namespace std;
const int maxn = 100001;

void KMP_prefix(char S2[], int pi[])
{
	pi[1] = 0;
	int k = 0;
	for (int i = 2; S2[i]; ++i)
	{
		while (k > 0 && S2[k + 1] != S2[i])
			k = pi[k];
		if (S2[k + 1] == S2[i])
			++k;
		pi[i] = k;
	}
}

void KMP_potrivire(char S1[], char S2[], int pi[])
{
	KMP_prefix(S2, pi);
	ofstream out("kmp.out");
	int lgS2 = strlen(S2 + 1);
	int nr = 0, k = 0;
	for (int i = 1; S1[i]; ++i)
	{
		while (k > 0 && S2[k + 1] != S1[i])
			k = pi[k];
		if (S2[k + 1] == S1[i])
			++k;
		if (k == lgS2)
			++nr;
	}
	out << nr;
	out.close();
}

int main()
{
	char S1[maxn + 1], S2[maxn + 1];
	int pi[maxn];
	ifstream in("kmp.in");
	in.getline(S1 + 1, maxn - 1);
	in.getline(S2 + 1, maxn - 1);
	in.close();
	KMP_potrivire(S1, S2, pi);
	return 0;
}