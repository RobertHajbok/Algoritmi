#include<stdio.h>
#include<conio.h>
#include<time.h>
float aduna(long int a, float b)
{
	float rezultat;
	rezultat = a + b;
	return(rezultat);
}
void main(void)
{
	long int i;
	float rezultat = 0;
	time_t start_time, stop_time;
	printf("Lucreaza...\n");
	time(&start_time);
	for (i = 1; i <= 100000000L; i++)
		rezultat += i;
	time(&stop_time);
	printf("Utilizare bucla %d secunde\n", stop_time - start_time);
	printf("Lucreaza...\n");
	time(&start_time);
	for (i = 1; i <= 100000000L; i++)
		rezultat = aduna(i, rezultat);
	time(&stop_time);
	printf("Utilizare functie %d secunde\n", stop_time - start_time);
	getch();
}