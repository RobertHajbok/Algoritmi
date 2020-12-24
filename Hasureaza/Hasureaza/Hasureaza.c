#include<stdio.h>
#include<ctype.h>
#define Max 6
int M[Max][Max], m, n;
void Hasureaza(int i, int j, int v)
{
	M[i][j] = v;
	if (i + 1 < m) if (M[i + 1][j] == 1) Hasureaza(i + 1, j, v);
	if (i - 1 >= 0) if (M[i - 1][j] == 1) Hasureaza(i - 1, j, v);
	if (j + 1 < m) if (M[i][j + 1] == 1) Hasureaza(i, j + 1, v);
	if (j - 1 >= 0) if (M[i][j - 1] == 1) Hasureaza(i, j - 1, v);
}
void tipareste()
{
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			printf("%d", M[i][j]);
		printf("\n");
	}
}
int main()
{
	FILE* fp;
	char ch;
	int i = 0, j = 0, k = 0;
	fp = fopen("poza.txt", "r");
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
				M[i][j++] = ch - '0';
			if (ch == '\n' && j > 0)
			{
				m = j;
				j = 0;
				i++;
			}
		}
		if (j == 0) n = i;
		if (j > 0) n = i + 1;
		tipareste();
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
			{
				if (M[i][j] == 1) {
					k++;
					Hasureaza(i, j, k + 1);
				}
			}
		printf("Poza are %d obiecte\n", k);
		tipareste();
	}
	getchar();
	return 0;
}