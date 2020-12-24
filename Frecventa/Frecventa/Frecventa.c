//Frecventa de aparitie a literelor intr-un text
#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
	char s[50];
	int v[26] = { 0 }, i;
	gets(s);
	strlwr(s);
	for (i = 0; i < strlen(s); i++)
		v[s[i] - 97]++;
	for (i = 0; i < 26; i++)
	{
		if (v[i] != 0)
		{
			printf("litera %c apare de %d ori", i + 97, v[i]);
			printf("\n");
		}
	}
	getch();
	return 0;
}
