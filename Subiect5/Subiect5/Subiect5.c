#include<stdio.h>
#include<conio.h>
int impar(int n)
{
	int c = 0;
	while (n != 0)
	{
		c = n % 10;
		if (c % 2 == 0)
			return 0;
		n = n / 10;
	}
	return 1;
}
int prim(int n)
{
	int d = 2, x = 0;
	while (n != 1)
	{
		if (n % d == 0)
		{
			x++;
			while (n % d == 0)
				n = n / d;
		}
		d++;
	}
	return x;
}
int main()
{
	int k, v[30], i, ok = 0, n;
	FILE* f, * g;
	f = fopen("atestat.in", "r");
	g = fopen("atestat.out", "w");
	fscanf(f, "%d", &n);
	scanf("%d", &k);
	for (i = 1; i <= n; i++)
	{
		fscanf(f, "%d", &v[i]);
		if (v[i] % 2 == 0)
		{
			printf("%d ", v[i]);
			printf("\n");
		}
	}
	for (i = 1; i <= n; i++)
		if (impar(v[i]) == 1)
		{
			printf("%d ", v[i]);
			ok = 1;
		}
	if (ok == 0)
		printf("nu exista");
	for (i = 1; i <= n; i++)
		if (prim(v[i]) == k)
			fprintf(g, "%d ", v[i]);
	getch();
	return 0;
}
