//Se citesc n nr dintr-un fisier nr.txt. Sa se afiseze cele care au suma cifrelor maxima
#include<stdio.h>
#include<conio.h>
int sumacif(int x)
{
	int s = 0, c;
	while (x != 0)
	{
		c = x % 10;
		s = s + c;
		x = x / 10;
	}
	return s;
}
int main()
{
	int n, a[50], i, max = 0;
	FILE* f;
	f = fopen("numere.txt", "r");
	fscanf(f, "%d", &n);
	for (i = 1; i <= n; i++)
		fscanf(f, "%d", &a[i]);
	for (i = 1; i <= n; i++)
	{
		if (sumacif(a[i]) > max)
			max = sumacif(a[i]);
	}
	for (i = 1; i <= n; i++)
		if (sumacif(a[i]) == max)
			printf("%d ", a[i]);
	getch();
	return 0;
}
