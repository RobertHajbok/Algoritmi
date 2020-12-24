//Se da o matrice patratica de dimensiune N, cu valori de 0 sau de 1, codificand un labirint. Valoarea 0 reprezinta o 
//camera deschisa, iar valoarea zero o camera inchisa. Se cere cel mai scurt drum de la pozitia (1, 1) la pozitia (N, N), 
//mergand doar prin camere deschise si doar la stanga, dreapta, in jos sau in sus. Nu se poate trece de doua ori prin 
//acelasi loc. Lungimea unui drum este data de numarul de pasi necesari parcurgerii drumului.
//Vom citi datele de intrare din fisierul lee.in, iar in fisierul de iesire lee.out vom afisa pe prima linia lungimea 
//drumului minim, iar pe urmatoarele linii coordonatele care descriu un drum de lungime minima.

#include <fstream>
#include <queue>
using namespace std;
const int maxn = 101;
const int inf = 1 << 30;
const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };

void citire(bool A[maxn][maxn], int& N)
{
	ifstream in("lee.in");
	in >> N;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			in >> A[i][j];
	in.close();
}

bool valid(int N, int x, int y)
{
	return x >= 1 && y >= 1 && x <= N && y <= N;
}

void Lee(bool A[maxn][maxn], int N, int D[maxn][maxn])
{
	queue<pair<int, int> > Q;
	Q.push(make_pair(1, 1));
	while (!Q.empty())
	{
		pair<int, int> poz = Q.front(); // extragerea primului element
		Q.pop(); // stergerea efectiva a primului element
		for (int i = 0; i < 4; ++i)
		{
			int newx = poz.first + dx[i];
			int newy = poz.second + dy[i];
			if (valid(N, newx, newy))
				if (!A[newx][newy] && D[newx][newy] > D[poz.first][poz.second] + 1)
				{
					D[newx][newy] = D[poz.first][poz.second] + 1;
					Q.push(make_pair(newx, newy)); // adaugarea in coada
				}
		}
	}
}

void drum(int D[maxn][maxn], int N, int x, int y, ofstream& out)
{
	if (D[x][y] == 0)
	{
		out << 1 << ' ' << 1 << '\n';
		return;
	}
	for (int i = 0; i < 4; ++i)
	{
		int newx = x + dx[i];
		int newy = y + dy[i];
		if (valid(N, newx, newy))
			if (D[newx][newy] == D[x][y] - 1)
			{
				drum(D, N, newx, newy, out);
				break;
			}
	}
	out << x << ' ' << y << '\n';
}

void init(int D[maxn][maxn], int N)
{
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			D[i][j] = inf;
	D[1][1] = 0;
}

int main()
{
	int N;
	bool A[maxn][maxn];
	int D[maxn][maxn];
	citire(A, N);
	init(D, N);
	Lee(A, N, D);
	ofstream out("lee.out");
	out << D[N][N] << '\n';
	drum(D, N, N, N, out);
	out.close();
	return 0;
}