#include<stdio.h>
#define MAX_COADA 100
char coada[MAX_COADA];
int inc = 0, sf = -1, corect = 1;
int main()
{
	char c;
	freopen("paranteze.in", "r", stdin);
	freopen("paranteze.out", "w", stdout);
	while (scanf("%c", &c) && c != '.')
	{
		if (c == '(')
		{
			coada[++sf] = '(';
		}
		else
			if (c == ')')
			{
				if (inc <= sf)
					inc++;
				else
					corect = 0;
			}
	}
	if (inc <= sf)
		corect = 0;
	if (corect)
		printf("Parantezele se inchid corect.\n");
	else
		printf("Parantezele nu se inchid corect.\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}