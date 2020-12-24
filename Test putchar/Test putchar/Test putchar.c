#include<stdio.h>
#include<conio.h>
#include<time.h>
void main(void)
{
	int litera;
	int nr;
	time_t start_time, stop_time;
	time(&start_time);
	for (nr = 0; nr < 5000; nr++)
		for (litera = 'A'; litera <= 'Z'; litera++)
			putchar(litera);
	time(&stop_time);
	printf("\n\nTimpul cerut de putchar %d secunde\n", stop_time - start_time);
	printf("Apasati orice tasta...\n");
	getch();
	time(&start_time);
	for (nr = 0; nr < 5000; nr++)
		for (litera = 'A'; litera <= 'Z'; litera++)
			putch(litera);
	time(&stop_time);
	printf("\n\nTimpul cerut de putch %d secunde\n", stop_time - start_time);
	getch();
}