#include<stdio.h>
int main()
{
	int a[20][20], i, j, n;
	FILE* f, * g;
	f = fopen("date.in", "r");
	g = fopen("date.out", "w");
	fscanf(f, "%d", &n);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			fscanf(f, "%d ", &a[i][j]);
	for (j = 1; j <= n; j++)
		fprintf(g, "%d ", a[1][j]);
	for (i = 2; i <= n; i++)
		fprintf(g, "%d ", a[i][n]);
	for (j = n - 1; j >= 1; j--)
		fprintf(g, "%d ", a[n][j]);
	for (i = n - 1; i >= 1; i--)
		fprintf(g, "%d ", a[i][1]);
	return 0;
}
