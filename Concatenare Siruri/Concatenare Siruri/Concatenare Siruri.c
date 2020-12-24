//Concatenare
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
	strcat(s, v);
	puts(s);
	puts(v);
	getch();
	return 0;
}
