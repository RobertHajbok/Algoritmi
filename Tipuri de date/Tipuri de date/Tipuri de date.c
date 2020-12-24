#include<stdio.h>
#include<conio.h>
void main(void)
{
	//Tiparirea unei valori intregi octale sau hexazecimale
	int valoare1 = 255;
	unsigned int valoare2 = 4232443067;
	long int un_milion = 2099909540;
	float pret = 525.75;
	float rata_impozit = 0.06;
	float pi = 3.14159;
	float raza = 2.0031;
	int valoare;
	char titlu[255] = "Totul despre C/C++";
	printf("Valoarea zecimala %d este %o in octal\n", valoare1, valoare1);
	printf("Valoarea zecimala %d este %x in hexazecimal\n", valoare1, valoare1);
	printf("Valoarea zecimala %d este %X in hexazecimal\n", valoare1, valoare1);
	//Afisarea valorilor de tip unsigned int	
	printf("Afiseaza 42000 ca unsigned %u\n", valoare2);
	printf("Afiseaza 42000 ca int %d\n", valoare2);
	//Afisarea valorilor de tip long int	
	printf("Un milion este %ld\n", un_milion);
	//Afisarea valorilor de tip float	
	printf("Pretul este %f\n", pret);
	printf("Impozitul pe vanzari este %f\n", pret * rata_impozit);
	//Afisarea valorilor de tip char
	printf("Litera este %c\n", 'A');
	printf("Litera este %c\n", 65);
	//Afisarea valorilor in virgula mobila in format exponential	
	printf("Aria cercului este %e\n", 2 * pi * raza);
	printf("Aria cercului este %E\n", 2 * pi * raza);
	//Afisarea valorilor in virgula mobila											 
	printf("Numarul 0.1234 este afisat in formatul %d\n", 0.1234);                    //Specificatorii %g si %G aleg dintre formatele %f si %e astfel incat
	printf("Numarul 0.00001234 este afisat in formatul %g\n", 0.00001234);			 //sa ofere utilizatorului o afisare cat mai convenabila
	//Afisarea unui sir de caractere	
	printf("Numele acestei carti este %s\n", titlu);
	//Afisarea pointerilor	
	printf("Adresa valorii variabilei este %p\n", &valoare);
	getch();
}