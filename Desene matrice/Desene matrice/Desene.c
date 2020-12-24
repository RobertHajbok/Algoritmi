#include<stdio.h>
#include<conio.h>
void initial(int a[40][40], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			a[i][j] = 0;
}
void afisare(int a[40][40], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	printf("\n");
}
void romb_gol(int a[40][40], int n)
{
	int i;
	for (i = 0; i <= n / 2; i++)
		a[i][n / 2 - i] = a[i][n / 2 + i] = a[n - 1 - i][n / 2 - i] = a[n - 1 - i][n / 2 + i] = 1;
}
void cruce(int a[40][40], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			if (i == n / 2)
				a[i][j] = 1;
			if (j == n / 2)
				a[i][j] = 1;
		}
	afisare(a, n);
}
void patrate(int a[40][40], int n, int niv)
{
	int i;
	for (i = niv; i <= n - niv - 1; i++)
		a[niv][i] = a[i][niv] = a[i][n - 1 - niv] = a[n - 1 - niv][i] = 1;
	if (niv < n / 2)
		patrate(a, n, niv + 2);
}
int main()
{
	int a[40][40], n;
	printf("Numarul de linii/coloane impar: ");
	scanf("%d", &n);
	printf("Romb\n");
	initial(a, n);
	romb_gol(a, n);
	afisare(a, n);
	printf("Cruce\n");
	initial(a, n);
	cruce(a, n);
	printf("Patrate\n");
	initial(a, n);
	patrate(a, n, 1);
	afisare(a, n);
	getch();
	return 0;
}