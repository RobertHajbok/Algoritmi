#include<stdio.h>
#include<conio.h>
int main()
{
	int a[24], n, x = 1, y = 1, z, i, j;
	scanf("%d", &n);
	a[1] = x % 10;
	a[2] = y % 10;
	for (i = 3; i <= n * n; i++)
	{
		z = x + y;
		x = y;
		y = z;
		a[i] = z % 10;
	}
	j = 0;
	for (i = 1; i <= n * n; i++)
	{
		printf("%d ", a[i]);
		j++;
		if (j == n)
		{
			printf("\n");
			j = 0;
		}
	}
	getch();
	return 0;
}
