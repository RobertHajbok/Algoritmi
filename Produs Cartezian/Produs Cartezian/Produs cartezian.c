#include<stdio.h>
#include<conio.h>
int k, n, sol[20];
int e_valid(int k)
{
	return 1;
}
void tipar(int k)
{
	int i;
	for (i = 1; i <= k; i++)
		printf("%d ", sol[i]);
	printf("\n");
}
void backr(int k)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		sol[k] = i;
		if (e_valid(k))
			if (k == n)
				tipar(k);
			else
				backr(k + 1);
	}
}
int main()
{
	printf("n=");
	scanf("%d", &n);
	backr(1);
	getch();
	return 0;
}