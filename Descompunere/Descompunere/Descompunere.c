#include<stdio.h>
#include<conio.h>
int main()
{
	int n, p, d = 2;
	scanf("%d", &n);
	while (n != 1)
	{
		if (n % d == 0)
		{
			printf("%d", d);
			p = 0;
			while (n % d == 0)
			{
				p++;
				n = n / d;
			}
			printf("^%d", p);
			if (n != 1)
				printf("*");
		}
		d++;
	}
	getch();
	return 0;
}
