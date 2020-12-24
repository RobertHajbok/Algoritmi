#include<stdio.h>
#include<conio.h>
FILE* f, * g;
void min(int v[20][20], int n, int k)
{
	int min = 9999, i;
	for (i = 1; i <= n; i++)
		if (v[k][i] < min)
			min = v[k][i];
	fprintf(g, "minimul de pe linia %d este %d ", k, min);
	fprintf(g, "\n");
}
int main()
{
	int n, i, s = 0, j, v[20][20];
	f = fopen("atestat.in", "r");
	g = fopen("atestat.out", "w");
	fscanf(f, "%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			fscanf(f, "%d", &v[i][j]);
			printf("%d ", v[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (j == n - i + 1)
				s = s + v[i][j];
	printf("%d ", s);
	for (i = 1; i <= n; i++)
		min(v, n, i);
	getch();
	return 0;
}
