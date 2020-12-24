#include<stdio.h>
#include<conio.h>
#define MAXLINE 100
#define EOF -1
int getline(char s[], int lim)
{
	//Citeste o linie in s si returneaza lungimea
	int c, i;
	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
int index(char s[], char t[])
{
	//Returneaza pozitia din sirul s unde incepe sirul t, sau -1
	int i, j, k;
	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (t[k] == '\0')
			return i;
	}
	return -1;
}
void main()
{
	//Imprima toate liniile care contin cuvantul "the"
	char line[MAXLINE];
	while (getline(line, MAXLINE) > 0)
		if (index(line, "the") >= 0)
			printf("%s", line);
	getch();
}