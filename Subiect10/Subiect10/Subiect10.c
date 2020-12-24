#include <stdio.h>
FILE* f, * g;
void afisare(int a[20][20], int n, int m, int c)
{
	int ok = 0, i;
	g = fopen("atestat.out", "w");
	for (i = 1; i <= n; i++)
		if (a[i][c] % 2 == 1)
		{
			fprintf(g, "%d ", a[i][c]);
			ok = 1;
		}
	if (ok == 0)
		fprintf(g, "NU EXISTA");
}
int main()
{
	int n, m, i, j, a[20][20], z, c, k, ok = 0;
	f = fopen("atestat.in", "r");
	fscanf(f, "%d", &n);
	fscanf(f, "%d", &m);
	printf("%d", n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			fscanf(f, "%d", &a[i][j]);
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	fscanf(f, "%d", &k);
	for (i = 1; i <= n; i++)
	{
		z = 0;
		for (j = 1; j <= m; j++)
		{
			if (a[i][j] == 0)
				z = z + 1;
		}
		if (z == k)
		{
			printf("%d ", i);
			ok = 1;
		}
	}
	if (ok == 0)
		printf("nu exista");
	printf("\n");
	printf("c=");
	scanf("%d", &c);
	afisare(a, n, m, c);
	return 0;
}