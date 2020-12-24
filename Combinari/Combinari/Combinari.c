#include<stdio.h>
#include<conio.h>
int st[20], n, k;
void init()
{
	int i;
	printf("n=");
	scanf("%d", &n);
	printf("k=");
	scanf("%d", &k);
	st[0] = 0;
}
void tipar(int p)
{
	int j;
	for (j = 1; j <= p; j++)
		printf("%d ", st[j]);
	printf("\n");
}
int solutie(int p)
{
	return (p == k);
}
void bkt(int p)
{
	int val;
	for (val = st[p - 1] + 1; val <= n; val++)
	{
		st[p] = val;
		if (solutie(p))
			tipar(p);
		else
			bkt(p + 1);
	}
}
void main()
{
	init();
	bkt(1);
	getch();
}