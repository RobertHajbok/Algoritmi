#include<stdio.h>
#include<ctype.h>
#include<conio.h>
void main(void)
{
	int litera;
	int gata = 0;
	int maj_gasite = 0;
	do
	{
		litera = getch();
		if (islower(litera))
			putchar(litera);
		else
		{
			if (isupper(litera))
			{
				ungetch(litera);
				maj_gasite = 1;
				putchar('\n');
			}
			gata = 1;
		}
	} while (!gata);
	if (maj_gasite)
		do
		{
			litera = getch();
			putchar(litera);
		} while (litera != '\r');
}