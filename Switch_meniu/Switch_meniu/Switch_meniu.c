#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
void main(void)
{
	char litera;
	do
	{
		printf("A Afiseaza continutul directorului\n");
		printf("B Modifica ora sistemului\n");
		printf("C Modifica data sistemului\n");
		printf("E Iesire\n");
		printf("Alegerea dumneavoastra: ");
		litera = _getch();
		litera = toupper(litera);
		switch (litera)
		{
		case 'A': system("DIR");
			break;
		case 'B': system("TIME");
			break;
		case 'C': system("DATE");
			break;
		};
	} while (litera != 'E');
}