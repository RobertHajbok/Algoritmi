#include<stdio.h>
#include<time.h>
#include<conio.h>
int _fastcall adun_rapid(int a, int b)
{
	return(a + b);
}
int adun_lent(int a, int b)
{
	return(a + b);
}
void main(void)
{
	unsigned long int i, rezultat;
	clock_t start_time, stop_time;
	printf("Prelucreaza...\n");
	start_time = clock();
	for (i = 0; i < 20000000L; i++)
		rezultat = adun_rapid(i, 1);
	stop_time = clock();
	printf("Timpul de prelucrare pentru apelul rapid a fost de %d batai de ceas\n", stop_time - start_time);
	printf("Prelucreaza...\n");
	start_time = clock();
	for (i = 0; i < 20000000L; i++)
		rezultat = adun_lent(i, 1);
	stop_time = clock();
	printf("Timpul de prelucrare pentru apelul normal a fost de %d batai de ceas\n", stop_time - start_time);
	getch();
}