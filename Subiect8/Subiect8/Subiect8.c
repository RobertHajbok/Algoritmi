#include<stdio.h>
#include<conio.h>
int suma(int v[30], int n)
{
	int i, s = 0;
	for (i = 1; i <= n; i++)
		if (v[i] > 0)
			s = s + v[i];
	return s;
}
int main()
{
	int n, v[30], i, x, ok = 0;
	FILE* f, * g;
	f = fopen("atestat.in", "r");
	g = fopen("atestat.out", "w");
	scanf("%d", &x);
	fscanf(f, "%d", &n);
	for (i = 1; i <= n; i++)
		fscanf(f, "%d", &v[i]);
	for (i = n; i >= 1; i--)
		printf("%d ", v[i]);
	printf("\n");
	for (i = 1; i <= n; i++)
		if (v[i] == x)
			ok = 1;
	if (ok == 1)
		printf("da");
	else
		printf("nu");
	fprintf(g, "%d", suma(v, n));
	getch();
	return 0;
}
