#include<stdio.h>
#include<conio.h>
long ack(unsigned int x, unsigned int y)
{
	if (x == 0)
		return y + 1;
	if (y == 0)
		return ack(x - 1, 1);
	return ack(x - 1, ack(x, y - 1));
}
int main()
{
	unsigned int m, n;
	printf("m=");
	scanf("%d", &m);
	printf("n=");
	scanf("%d", &n);
	printf("%lu", ack(m, n));
	printf("\n");
	getch();
	return 0;
}