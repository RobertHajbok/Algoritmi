#include<stdio.h>
#include<conio.h>
int suma(int n)
{
	int s = 0, c;
	while (n != 0)
	{
		c = n % 10;
		s = s + c;
		n = n / 10;
	}
	return s;
}
int main()
{
	int x;
	scanf("%d", &x);
	printf("%d", suma(x));
	printf("\n%d", x);
	getch();
	return 0;
}
