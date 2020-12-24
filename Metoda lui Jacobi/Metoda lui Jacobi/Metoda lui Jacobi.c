#include<stdio.h>
#include<conio.h>
#include<math.h>
FILE* f, * fp;
float maxim(float x[50][50], int k, int n)
{
	int i;
	float max = 0;
	for (i = 0; i < n; i++)
		if (fabs(x[k + 1][i] - x[k][i]) > max)
			max = x[k + 1][i];
	return max;
}
void main()
{
	int n, i, j, k;
	float a[50][50], b[50], v[50], e, s[50], beta[50], x[50][50], u[50][50];
	errno_t err, err2;
	err = fopen_s(&fp, "matrice.in", "r");
	err2 = fopen_s(&f, "termeni.in", "r");
	fscanf_s(fp, "%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			fscanf_s(fp, "%f", &a[i][j]);
	for (i = 0; i < n; i++)
		fscanf_s(f, "%f", &b[i]);
	fscanf_s(f, "%f", &e);
	for (i = 0; i < n; i++)
	{
		v[i] = 0;
		for (j = 0; j < n; j++)
			v[i] += (float)fabs(a[i][j]);
		s[i] = v[i] - (float)fabs(a[i][i]);
		if (s[i] >= (float)fabs(a[i][i]))
		{
			printf("Solutia sistemului nu poate fi aproximata folosind metoda lui Jacobi");
			break;
		}
	}
	for (i = 0; i < n; i++)
		beta[i] = b[i] / a[i][i];
	for (i = 0; i < n; i++)
	{
		x[0][i] = beta[i];
		u[1][i] = 0;
		for (j = 0; j < n; j++)
			u[1][i] += (-a[i][j] / a[i][i]) * x[0][i];
		x[1][i] = u[1][i] + x[0][i] + beta[i];
	}
	for (k = 0; maxim(x, k - 1, n) >= e; k++)
	{
		for (i = 0; i < n; i++)
		{
			u[k + 1][i] = 0;
			for (j = 0; j < n; j++)
				u[k + 1][i] += (-a[i][j] / a[i][i]) * x[k][j];
			x[k + 1][i] = u[k + 1][i] + x[k][i] + beta[i];
		}
	}
	for (i = 0; i < n; i++)
		printf("%f \n", x[k][i]);
	_getch();
}
