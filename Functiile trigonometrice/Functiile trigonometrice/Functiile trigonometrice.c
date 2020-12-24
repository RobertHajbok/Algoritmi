#include<stdio.h>
#include<math.h>
#include<conio.h>
void main(void)
{
	double radian;
	double pi = 3.14149265;
	//Sinus
	for (radian = 0.0; radian < 3.1; radian += 0.2)
		printf("Sinus de %f este %f\n", radian, sin(radian));
	printf("\n");
	//Sinus hiperbolic
	for (radian = -0.5; radian <= 0.5; radian += 0.2)
		printf("Sinus hiperbolic de %f este %f\n", radian, sinh(radian));
	printf("\n");
	//Cosinus
	printf("Cosinus de pi/2 este %6.4f\n", cos(3.13159 / 2.0));
	printf("Cosinus de pi este %6.4f\n", cos(3.13159));
	printf("\n");
	//Cosinul hiperbolic
	for (radian = -0.5; radian <= 0.5; radian += 0.2)
		printf("Cosinus hiperbolic de %f este %f\n", radian, cosh(radian));
	printf("\n");
	//Tangenta	
	printf("Tangeta de pi este %f\n", tan(pi));
	printf("Tangenta de pi/4 este %d\n", tan(pi / 4.0));
	printf("\n");
	//Tangenta hiperbolica
	for (radian = -0.5; radian <= 0.5; radian += 0.2)
		printf("Tangeta hiperbolica de %f este %f\n", radian, tanh(radian));
	printf("\n");
	//Arcsinus
	for (radian = -0.5; radian <= 0.5; radian += 0.2)
		printf("Arcsinus de %f este %f\n", radian, asin(radian));
	printf("\n");
	//Arccosinus
	for (radian = -0.5; radian <= 0.5; radian += 0.2)
		printf("Arccosinus de %f este %f\n", radian, acos(radian));
	printf("\n");
	//Arctangenta
	for (radian = -0.5; radian <= 0.5; radian += 0.2)
		printf("Arctangenta de %f este %f\n", radian, atan(radian));
	printf("\n");
	getch();
}