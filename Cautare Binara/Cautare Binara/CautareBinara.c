#include<stdio.h>
#include<conio.h>
int main()
{
	int v[] = { 1,2,3,4,5,6,7,8,9 }, n = 9, i, x, st, dr, mij = 0, ok = 0;
	st = 1; dr = n;
	scanf("%d", &x);
	while (st <= dr && ok == 0)
	{
		mij = (st + dr) / 2;
		if (v[mij] == x)
			ok = 1;
		else if (v[mij] < x)
			st = mij + 1;
		else
			dr = mij - 1;
	}
	if (ok == 1)
		printf("da");
	else
		printf("nu");
	getch();
	return 0;
}
