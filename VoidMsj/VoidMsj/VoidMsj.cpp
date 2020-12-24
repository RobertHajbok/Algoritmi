#include<stdio.h>
void mesaj(int a[50], int& n)
{
	int i;
	FILE* f;
	f = fopen("vector.txt", "r");
	fscanf(f, "%d", &n);
	for (i = 1; i <= n; i++)
		fscanf(f, "%d", &a[i]);
}
int main()
{
	int a[50], n, i;
	mesaj(a, n);
	for (i = 1; i <= n; i++)
		printf("%d ", a[i]);
	getchar();
	return 0;
}
