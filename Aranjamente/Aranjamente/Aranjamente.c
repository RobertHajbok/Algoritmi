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
	for (i = 1; i <= n; i++)
		st[i] = 0;
}
void tipar(int p)
{
	int j;
	for (j = 1; j <= p; j++)
		printf("%d ", st[j]);
	printf("\n");
}
int valid(int p)
{
	int i, ok;
	ok = 1;
	for (i = 1; i < p; i++)
		if (st[p] == st[i])
			ok = 0;
	return ok;
}
int solutie(int p)
{
	return (p == k);
}
void bkt(int p)
{
	int val;
	for (val = 1; val <= n; val++)
	{
		st[p] = val;
		if (valid(p))
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