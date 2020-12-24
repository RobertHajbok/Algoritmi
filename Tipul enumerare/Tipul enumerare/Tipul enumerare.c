#include<stdio.h>
#include<conio.h>
void main(void)
{
	enum { luni = 10, marti, miercuri, joi, vineri } zi;
	for (zi = luni; zi <= vineri; zi++)
		if (zi == luni)
			printf("Fara haz---intalniri toata ziua de luni\n");
		else if (zi == marti)
			printf("Fara haz---fac astazi treaba de luni\n");
		else if (zi == miercuri)
			printf("Ce zi...\n");
		else if (zi == joi)
			printf("Programul intalnirilor pentru urmatoarea zi de luni\n");
		else
			printf("Intalnire cu toti la petrecere!\n");
	printf("%d %d %d %d %d\n", luni, marti, miercuri, joi, vineri);
	getch();
}