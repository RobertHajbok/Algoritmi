#include<stdio.h>
#include<conio.h>
int main()
{
	int n, s, d;
	for (n = 1; n <= 10000; n++)
	{
		s = 0;
		for (d = 1; d <= n / 2; d++)
		{
			if (n % d == 0)
				s = s + d;
		}
		if (s == n)
			printf("%d ", n);
	}
	getch();
	return 0;
}
