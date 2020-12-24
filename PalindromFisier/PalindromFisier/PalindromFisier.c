//sa se afiseze palindroamele dintr-un fisier
#include<stdio.h>
#include<conio.h>
int inv(int x)
{
	int y = 0;
	while (x != 0)
	{
		y = y * 10 + x % 10;
		x = x / 10;
	}
	return y;
}
int main()
{
	int a[50], i, n;
	FILE* f;
	f = fopen("numere.txt", "r");
	fscanf(f, "%d", &n);
	for (i = 1; i <= n; i++)
		fscanf(f, "%d", &a[i]);
	for (i = 1; i <= n; i++)
	{
		if (inv(a[i]) == a[i])
			printf("%d ", a[i]);
	}
	getch();
	return 0;
}
