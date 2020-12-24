//Transformam vocalele in litere mari
#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
	char s[50], voc[] = "aeiou";
	int n, i;
	gets(s);
	n = strlen(s);
	for (i = 0; i < n; i++)
		if (strchr(voc, s[i]) != 0)
			s[i] = s[i] - 32;
	puts(s);
	getch();
	return 0;
}
