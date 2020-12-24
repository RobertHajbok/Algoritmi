#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#define max 6
int a[max][max], n, k = 1;
void tipareste()
{
	int i, j;
	printf("Solutia %d\n", k);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%d", a[i][j]);
		printf("\n");
	}
	k++;
}
void cauta(int i1, int j1, int i2, int j2)
{
	a[i1][j1] = 8;
	if (i1 == i2 && j1 == j2)
		tipareste();
	else
	{
		if (i1 + 1 < n)
			if (a[i1 + 1][j1] == 0)
				cauta(i1 + 1, j1, i2, j2);
		if (i1 - 1 >= 0)
			if (a[i1 - 1][j1] == 0)
				cauta(i1 - 1, j1, i2, j2);
		if (j1 + 1 < n)
			if (a[i1][j1 + 1] == 0)
				cauta(i1, j1 + 1, i2, j2);
		if (j1 - 1 >= 0)
			if (a[i1][j1 - 1] == 0)
				cauta(i1, j1 - 1, i2, j2);
	}
	a[i1][j1] = 0;
}
int main()
{
	FILE* fp;
	char ch;
	int i = 0, j = 0;
	int i1, j1, i2, j2;
	printf("Pozitia initiala:");
	scanf("%d %d", &i1, &j1);
	printf("Pozitia finala:");
	scanf("%d %d", &i2, &j2);
	fp = fopen("matrice.txt", "r");
	if (fp == NULL)
	{
		printf("Nu pot deschide fisierul");
		return -1;
	}
	else
	{
		while ((ch = getc(fp)) != EOF)
		{
			if (isdigit(ch))
				a[i][j++] = ch - '0';
			if (ch == '\n' && j > 0)
			{
				n = j;
				j = 0;
				i++;
			}
		}
		if (j == 0) n = i;
		if (j > 0) n = i + 1;
		if (a[i1][j1] == 0)
		{

			cauta(i1, j1, i2, j2);
		}

	}
	getch();
	return 0;
}