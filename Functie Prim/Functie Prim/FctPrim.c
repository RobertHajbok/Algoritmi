#include<stdio.h>
#include<conio.h>
int prim(int n)
{
	int d;
	if (n == 2)
		return 1;
	if (n % 2 == 0)
		return 0;
	for (d = 3; d * d <= n; d += 2)
		if (n % d == 0)
			return 0;
	return 1;
}
int main()
{
	int n, x = 2, i = 1;
	scanf("%d", &n);
	while (i <= n)
	{
		if (prim(x) == 1)
		{
			printf("%d ", x);
			i++;
		}
		x++;
	}
	getch();
}
