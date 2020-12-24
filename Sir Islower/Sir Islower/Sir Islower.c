#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
int main()
{
	char s[50];
	int n, k1 = 0, k2 = 0, k3 = 0, i;
	FILE* f;
	f = fopen("bac.in", "r");
	fgets(s, 50, f);
	puts(s);
	n = strlen(s);
	printf("%d ", n);
	//Numaram cifrele mici, mari si cifrele dintr-un sir de caractere
	for (i = 0; i < n; i++)
	{
		if (islower(s[i]))
			k1++;
		if (isupper(s[i]))
			k2++;
		if (isdigit(s[i]))
			k3++;
	}
	printf("%d ", k1);
	printf("%d ", k2);
	printf("%d ", k3);
	getch();
	return 0;
}