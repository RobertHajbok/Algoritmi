#include<stdio.h>
#include<conio.h>
void ordonare(int v[50], int m)
{
	int aux, j, i;
	for (i = 1; i < m; i++)
		for (j = i + 1; j <= m; j++)
		{
			if (v[i] > v[j])
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
}
int main()
{
	int a[50], i, n;
	FILE* f;
	f = fopen("vector.txt", "r");
	fscanf(f, "%d", &n);
	for (i = 1; i <= n; i++)
		fscanf(f, "%d", &a[i]);
	ordonare(a, n);
	for (i = 1; i <= n; i++)
		printf("%d ", a[i]);
	getch();
	return 0;
}
