//Compararea sirurilor de caractere
#include<stdio.h>
#include<string.h>
#include<conio.h>
int main()
{
	char s[50], v[50];
	FILE* f, * g;
	f = fopen("bac.in", "r");
	g = fopen("bach.in", "r");
	fgets(s, 50, f);
	fgets(v, 50, g);
	if (strcmp(s, v) == 0)
		printf("sirurile sunt identice");
	else
	{
		if (strcmp(s, v) == 1)
			printf("%s mai mare ca %s", s, v);
		else
			printf("%s mai mare ca %s", v, s);
	}
	getch();
	return 0;
}
