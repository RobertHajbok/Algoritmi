#include<stdio.h>
#include<time.h>
#include<sys\timeb.h>
#include<conio.h>
void main(void)
{
	//Data si ora curente ca secunde de la 1/1/1970
	time_t timp_curent;
	time_t timp_start;
	printf("Pe punctul de a face o intarziere de 5 secunde\n");
	time(&timp_start);   //Timpul in secunde la start
	do
	{
		time(&timp_curent);
	} while ((timp_curent - timp_start) < 5);
	printf("Gata\n");
	//Trecerea automata la orarul de vara
	if (_get_daylight)
		printf("Orarul de vara este in vigoare\n");
	else
		printf("Nu este in vigoare orarul de vara\n");
	time(&timp_start);
	printf("Pe punctul de a face o intarziere de 5 scunde\n");
	do
	{
		time(&timp_curent);
	} while (difftime(timp_curent, timp_start) < 5.0);
	printf("Gata\n");
	//Determinarea fusului orar curent
	tzset();
	printf("Fusul orar curent este %s\n", _tzname[0]);
	if (_tzname[1])
		printf("Zona de orar de vara este %s\n", _tzname[1]);
	else
		printf("Zona de orar de vara nu este definita\n");
	//Utilizarea fuselor orare pentru a calcula diferentele de ora
	printf("Diferenta intre ora locala si GMT este de %d ore\n", _timezone / 3600);
	getch();
}