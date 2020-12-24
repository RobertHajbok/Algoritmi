#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	int a[20][20], b[20][20], i, j, l, c, n1, m1, n2, m2;
	cin >> n1;
	cin >> m1;
	for (i = 0; i < n1; i++)
		for (j = 0; j < m1; j++)
			cin >> a[i][j];
	cin >> n2;
	cin >> m2;
	for (l = 0; l < n2; l++)
		for (c = 0; c < m2; c++)
			cin >> b[l][c];
	int ok;
	for (i = 0; i <= n1 - n2; i++)
		for (j = 0; j <= m1 - m2; j++)
		{
			ok = 1;
			for (l = 0; l < n2 && ok == 1; l++)
				for (c = 0; c < m2; c++)
					if (a[l + i][c + j] != b[l][c])
						ok = 0;
			if (ok == 1)
				printf("A doua matrice se gaseste in prima incepand de la pozitia a[%d][%d]\n", i, j);
		}
	getch();
}