#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
int main()
{
	char s[25];
	int n, k = 0, i;
	FILE* f;
	f = fopen("prog.in", "r");
	fgets(s, 25, f);
	n = strlen(s);
	for (i = 0; i < n; i++)
		if (isdigit(s[i]))
			k = k + 1;
	printf("%d", k);
	getch();
	return 0;
}
