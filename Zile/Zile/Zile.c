//Numarul de zile dintre doua date calendaristice
#include<stdio.h>
#include<conio.h>
struct DC
{
	int an;
	int luna;
	int zi;
};
int DateEgale(struct DC d1, struct DC d2)
{
	if (d1.an == d2.an && d1.luna == d2.luna && d1.zi == d2.zi)
		return 1;
	return 0;
}
int AnBisect(int n)
{
	if ((n % 4 == 0 && n % 100 != 0) || (n % 400 == 0))
		return 1;
	return 0;
}
void ScadOZi(struct DC* d)
{
	if (d->zi > 1)
		d->zi--;
	else
		switch (d->luna)
		{
		case 5: case 7: case 10: case 12:
			d->luna--;
			d->zi = 30;
			break;
		case 1:
			d->an--;
			d->luna = 12;
			d->zi = 31;
			break;
		case 2: case 4: case 6: case 8: case 9: case 11:
			d->luna--;
			d->zi = 31;
			break;
		case 3:
			d->luna--;
			if (AnBisect(d->an))
				d->zi = 29;
			else
				d->zi = 28;
			break;
		}



}
//Calculeaza numarul de zile dintre d1 si d2
//d1<d2
int DiferentaZile(struct DC d1, struct DC d2)
{
	int diferenta = 0;
	while (!DateEgale(d1, d2))
	{
		diferenta++;
		ScadOZi(&d2);
	}
	return diferenta;
}
int main()
{
	struct DC d1 = { 1993,3,22 };
	struct DC d2 = { 2013,1,20 };
	int nrZile;
	nrZile = DiferentaZile(d1, d2);
	printf("Numarul de zile dintre cele doua date este: %d\n", nrZile);
	getch();
	return 0;
}