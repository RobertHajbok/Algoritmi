#include<stdio.h>
#include<conio.h>
#define NR_INCERCARI 3
int VerificareParola(int parolaTrimisa)
{
	static int contor = 1;
	static int parola = 1234;
	int ret = 0;
	if (contor < NR_INCERCARI)
	{
		if (parola == parolaTrimisa)
		{
			printf("Acces permis\n");
			contor = 0;
			ret = 1;
		}
		else
		{
			printf("Parola gresita. Incercati inca o data.\n");
			contor++;
		}
	}
	else
	{
		printf("Cont blocat.\n");
		ret = -1;
	}
	return ret;
}
int main()
{
	int n, rezultat;
	do
	{
		printf("Introduceti codul PIN: ");
		scanf("%d", &n);
		rezultat = VerificareParola(n);
	} while (rezultat == 0);
	getch();
	return 0;
}