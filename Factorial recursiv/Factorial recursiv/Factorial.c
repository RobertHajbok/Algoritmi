#include<stdio.h>
#include<conio.h>
int factorial(int val)
{
	if (val > 1)
		return (val * factorial(val - 1));
	return 1;
}
void main(void)
{
	int n;
	printf("n=");
	scanf("%d", &n);
	printf("%d! este %d\n", n, factorial(n));
	getch();
}