#include<stdio.h>
#include<conio.h>
void main(void)
{
	//Utilizarea semnului plus sau minus inaintea unei valori
	int neg_int = -5;
	int poz_int = 5;
	float neg_flt = -100.23;
	float poz_flt = 100.23;
	int valoare1 = 5;
	int valoare2 = 7;
	int valoare3 = 255;
	float valoare4 = 1.23456;
	float valoare5 = 1.23456;
	int val_int = 5;
	float val_flt = 3.33;
	int val_intr = 5;
	printf("Valoarea intreaga este %+d si %+d\n", neg_int, poz_int);
	printf("Valoarea in virgula mobila este %+f %+f\n", neg_flt, poz_flt);
	//Formatarea unei valori intregi	
	printf("%1d\n", valoare1);
	printf("%2d\n", valoare1);
	printf("%3d\n", valoare1);
	printf("%4d\n", valoare1);
	//Afisarea numerelor intregi precedate de zero	
	printf("%01d\n", valoare2);
	printf("%02d\n", valoare2);
	printf("%03d\n", valoare2);
	printf("%04d\n", valoare2);
	//Afisarea unui prefix inaintea valorilor octale si hexazecimale	
	printf("Valorea zecimala %d este %#o in octal\n", valoare3, valoare3);
	printf("Valorea zecimala %d este %#x in hexazecimal\n", valoare3, valoare3);
	printf("Valorea zecimala %d este %#X in hexazecimal\n", valoare3, valoare3);
	//Formatarea valorilor in firgula mobila	
	printf("%8.1f\n", valoare4);				//prima valoare indica numarul minim de caractere pe care vreti sa le afisati
	printf("%8.3f\n", valoare4);				//a doua valoare indica numarul de cifre pe care doriti sa le afisati la dreapta punctului zecimal
	printf("%8.5f\n", valoare4);
	//Formatarea unei iesiri exponentiale	
	printf("12.1e\n", valoare5);
	printf("12.3e\n", valoare5);
	printf("12.5e\n", valoare5);
	//Alinierea la stanga iesirii	
	printf("Aliniere dreapta %5d a valorii\n", val_int);
	printf("Aliniere stanga %-5d a valorii\n", val_int);
	printf("Aliniere dreapta %7.2f a valorii\n", val_flt);
	printf("Aliniere stanga %-7.2f a valorii\n", val_flt);
	//Utilizarea combinata a specificatorilor de format	
	printf("Aliniere stanga cu semn %-+3d\n", val_intr);
	getch();
}