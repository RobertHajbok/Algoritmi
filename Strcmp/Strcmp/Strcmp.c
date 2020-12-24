//Se citesc n cuvinte de la tastatura si sa se ordoneze alfabetic
#include<stdio.h>
#include<string.h>
int main()
{
	char sir[100][20], aux[20];
	//matrice de caractere cu 100 de linii si 20 de coloane
	//poate fi considerata un vector ale carui elemente sunt siruri de caracte
	//putem memora maxim 100 de cuvinte de maxim 20 de caractere
	int n, i, j;
	FILE* f;
	f = fopen("bac.in", "w");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%s", &sir[i]);
	for (i = 1; i <= n - 1; i++)
		for (j = i; j <= n; j++)
			if (strcmp(sir[i], sir[j]) == 1)
			{
				strcpy(aux, sir[i]);
				strcpy(sir[i], sir[j]);
				strcpy(sir[j], aux);
			}
	for (i = 1; i <= n; i++)
		fprintf(f, "%s\n", sir[i]);
	return 0;
}
