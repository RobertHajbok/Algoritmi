#include<stdio.h>
#include<conio.h>
int an_bisect(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 366;
	return 365;
}
int main()
{
	unsigned int zi, luna, an, s = 0, i;
	printf("Ziua:");
	scanf("%d", &zi);
	printf("Luna:");
	scanf("%d", &luna);
	printf("Anul:");
	scanf("%d", &an);
	for (i = 1; i < an; i++)
		s = s + an_bisect(i);
	for (i = 1; i < luna; i++)
		switch (i)
		{
		case 1: s = s + 31;
			break;
		case 2: if (an_bisect(an) == 366)
			s = s + 29;
			  else
			s = s + 28;
			break;
		case 3: s = s + 31;
			break;
		case 4: s = s + 30;
			break;
		case 5: s = s + 31;
			break;
		case 6: s = s + 30;
			break;
		case 7: s = s + 31;
			break;
		case 8: s = s + 31;
			break;
		case 9: s = s + 30;
			break;
		case 10: s = s + 31;
			break;
		case 11: s = s + 30;
			break;
		case 12: s = s + 31;
			break;
		}
	s = s + zi;
	switch (s % 7)
	{
	case 0: printf("Este duminica\n");
		break;
	case 1: printf("Este luni\n");
		break;
	case 2: printf("Este marti\n");
		break;
	case 3: printf("Este miercuri\n");
		break;
	case 4: printf("Este joi\n");
		break;
	case 5: printf("Este vineri\n");
		break;
	case 6: printf("Este joi\n");
		break;
	}
	getch();
	return 0;
}