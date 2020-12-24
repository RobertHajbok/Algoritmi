#include<stdio.h>
#include<string.h>
#include<conio.h>
int main()
{
	char s[25], aux[25];
	int n;
	FILE* f;
	f = fopen("prog.in", "r");
	fgets(s, 25, f);
	n = strlen(s);
	strcpy(aux, s);
	strrev(s);
	if (strcmp(aux, s) == 0)
		printf("este palindrom");
	else
		printf("nu este palindrom");
	getch();
	return 0;
}
