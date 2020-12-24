#include<stdio.h>
#include<conio.h>
int main()
{
	int n, s, d;
	s = 0;
	printf("n=");
	scanf("%d", &n);
	for (d = 1; d <= n / 2; d++)
	{
		if (n % d == 0)
			s = s + d;
	}
	if (s == n)
		printf("este nr perfect");
	else
		printf("nu este nr perfect");
	getch();
	return 0;
}
