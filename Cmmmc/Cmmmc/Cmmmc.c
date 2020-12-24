#include<stdio.h>
#include<conio.h>
int cmmdc(int a, int b)
{
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}
int cmmmc(int x, int y)
{
	return (x * y) / cmmdc(x, y);
}
int main()
{
	int x, y, c;
	scanf("%d", &x);
	scanf("%d", &y);
	c = cmmdc(x, y);
	printf("%d/%d ", x / c, y / c);
	printf("%d", cmmmc(x, y));
	getch();
	return 0;
}
