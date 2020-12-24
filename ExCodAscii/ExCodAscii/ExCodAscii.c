#include<stdio.h>
#include<string.h>
#include<conio.h>
int main()
{
	char s[256];
	int n, i, ok[26] = { 0 };
	FILE* f;
	f = fopen("prog.in", "r");
	fgets(s, 25, f);
	n = strlen(s);
	for (i = 0; i < n; i++)
		if (s[i] >= 'a' && s[i] <= 'z' && ok[s[i] - 97] == 0)
		{
			printf("%c ", s[i]);
			ok[s[i] - 97] = 1;
		}
	getch();
	return 0;
}
