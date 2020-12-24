#include<stdio.h>
#include<conio.h>
int main()
{
	int a[40][40], i, j, n, k;
	printf("Numarul de linii/coloane impar: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			a[i][j] = 1;
	for (i = 0; i < n / 2; i++)
		for (j = 0; j < n / 2 - i; j++)
			a[i][j] = 0;
	for (i = 0; i < n / 2; i++)
		for (j = n / 2 + i + 1; j < n; j++)
			a[i][j] = 0;
	for (i = n / 2 + 1; i < n; i++)
		for (j = 0; j < i - n / 2; j++)
			a[i][j] = 0;
	k = 0;
	for (i = n / 2 + 1; i < n; i++)
	{
		k++;
		for (j = n - k; j < n; j++)
			a[i][j] = 0;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	getch();
	return 0;
}