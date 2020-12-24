//sa se afiseze palindroamele dintr-un interval [a,b]
#include<stdio.h>
#include<conio.h>
int inv(int x)
{
	int y = 0, z = x;
	while (x != 0)
	{
		y = y * 10 + x % 10;
		x = x / 10;
	}
	if (y == z)
		return 1;
	else
		return 0;
}
int main()
{
	int n, a, b, aux;
	scanf("%d", &a);
	scanf("%d", &b);
	if (a > b)
	{
		aux = a;
		a = b;
		b = aux;
	}
	for (n = a; n <= b; n++)
	{
		if (inv(n) == 1)
			printf("%d ", n);
	}
	getch();
	return 0;
}
