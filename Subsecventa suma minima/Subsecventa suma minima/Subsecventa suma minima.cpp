//Consideram un numar natural N si un vector A cu N elemente numere intregi. O subsecventa [st, dr] a vectorului A 
//reprezinta secventa de elemente A[st], A[st + 1], ..., A[dr]. Suma unei subsecvente reprezinta suma tuturor elementelor 
//acelei subsecvente. Se cere determinarea unei subsecvente de suma maxima.

#include <fstream>
using namespace std;

const int inf = 1 << 30;
const int maxn = 100;

void citire(int& N, int A[maxn])
{
	ifstream in("subsecv.in");
	in >> N;
	for (int i = 1; i <= N; ++i)
		in >> A[i];
	in.close();
}

//Complexitatea O(N^3)
int subsecv1(int A[], int N)
{
	int max = -inf;
	for (int st = 1; st < N; ++st)
		for (int dr = st; dr <= N; ++dr)
		{
			int temp = 0;
			for (int i = st; i <= dr; ++i)
				temp += A[i];
			if (temp > max)
				max = temp;
		}
	return max;
}

//Complexitatea O(N^2)
int subsecv2(int A[], int N)
{
	int max = -inf;
	for (int st = 1; st < N; ++st)
	{
		int temp = 0;
		for (int dr = st; dr <= N; ++dr)
		{
			temp += A[dr];
			if (temp > max)
				max = temp;
		}
	}
	return max;
}

//Complexitatea O(N) -->paradigma programarii dinamice
int subsecv3(int A[], int N)
{
	int max = -inf;
	int S[maxn];
	S[1] = A[1];
	for (int i = 2; i <= N; ++i)
	{
		S[i] = A[i] + S[i - 1] > A[i] ? A[i] + S[i - 1] : A[i];
		if (S[i] > max)
			max = S[i];
	}
	return max;
}

int main()
{
	int N;
	int A[maxn];
	citire(N, A);
	ofstream out("subsecv.out");
	//out << subsecv1(A, N);
	//out << subsecv2(A, N);
	out << subsecv3(A, N);
	out.close();
	return 0;
}