#include<stdio.h>
#include<conio.h>
int main()
{
	int a[24][24], i, j, x = 0, y = 1, n;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			a[i][j] = x + y;
			if (i == 1 && j == 1)
				x = 0;
			else x = y;
			y = a[i][j];
			printf("%d ", a[i][j] % 10);
		}
		printf("\n");
	}
	getch();
	return 0;
}
