//Sa se genereze toate modurile corecte d.p.d.v matematic in care se pot deschide si inchide n paranteze
char p[100];
int n;
#include<stdio.h>
#include<conio.h>
void paranteze(int k, int d, int i)
{
	if (d < n / 2)
	{
		p[k] = '(';
		paranteze(k + 1, d + 1, i);
	}
	if (i < d)
	{
		p[k] = ')';
		if (k == n - 1)
		{
			p[k + 1] = '\0';
			printf("%s\n", p);
		}
		else
			paranteze(k + 1, d, i + 1);
	}
}
int main()
{

	p[0] = '(';
	scanf("%d", &n);
	if (n % 2 == 1)
		printf("Nu este posibila nici o generare corecta dpdv matematic\n");
	else
		paranteze(1, 1, 0);
	getch();
	return 0;
}