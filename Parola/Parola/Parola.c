#include<stdio.h>
#include<conio.h>
#include<string.h>
#define BACKSPACE 8
char* get_password(const char* prompt)
{
	static char buffer[128];
	int i = 0;
	char litera = NULL;
	printf(prompt);
	while ((i < 127) && (litera != '\r'))
	{
		litera = getch();
		if (litera == BACKSPACE)
		{
			if (i > 0)
			{
				buffer[--i] = NULL;  //sterge anteriorul *
				putchar(BACKSPACE);
				putchar(' ');
				putchar(BACKSPACE);
			}
			else
				putchar(7);       //caracter ASCII de atentionare (beep)
		}
		else if (litera != '\r')
		{
			buffer[i++] = litera;
			putchar('*');
		}
	}
	buffer[i] = NULL;
	return (buffer);
}
void main(void)
{
	char* parola;
	parola = get_password("Introduceti parola: ");
	if (strcmp(parola, "Gaogan"))
		printf("\nParola incorecta\n");
	else
		printf("\nParola OK\n");
	getch();
}