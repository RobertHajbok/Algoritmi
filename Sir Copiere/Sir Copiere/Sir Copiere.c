//Copierea sirurilor de caractere
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
	strncpy(v, s, 2);
	v[2] = NULL;
	puts(v);
	getch();
	return 0;
}
