#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct angajati
{
	char nume[50];
	char departament[50];
	char data_angajarii[15];
}ang;
void sort_alfabetic(ang angajati[], int n)
{
	int i, j;
	ang aux;
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (strcmp(angajati[i].nume, angajati[j].nume) > 0)
			{
				aux = angajati[i];
				angajati[i] = angajati[j];
				angajati[j] = aux;
			}
}
int main()
{
	ang angajati[50];
	int i, n;
	FILE* in, * out;
	in = fopen("in.txt", "r");
	out = fopen("out.txt", "w");
	fscanf(in, "%d", &n);
	for (i = 0; i < n; i++)
	{
		fscanf(in, "%s", angajati[i].nume);
		fscanf(in, "%s", angajati[i].departament);
		fscanf(in, "%s", angajati[i].data_angajarii);
	}
	sort_alfabetic(angajati, n);
	for (i = 0; i < n; i++)
	{
		fprintf(out, "%s %s %s", angajati[i].nume, angajati[i].departament, angajati[i].data_angajarii);
		fprintf(out, "\n");
	}
	return 1;
}