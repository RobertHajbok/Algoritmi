#include<stdio.h>
#include<conio.h>
#include<math.h>
FILE* f, * fp;
float Gauss(int, float A[][50], float*, float*);
void schimb(float*, float*);
void main(void)
{
	int n, i, j;
	float A[50][50], B[50], X[50], d;
	errno_t err, err2;
	err = fopen_s(&fp, "matrice.in", "r");
	err2 = fopen_s(&f, "termeni.in", "r");
	fscanf_s(fp, "%d", &n);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			fscanf_s(fp, "%f", &A[i][j]);
	for (i = 1; i <= n; i++)
		fscanf_s(f, "%f", &B[i]);
	// rezultatele apelului functiei Gauss.
	if ((d = Gauss(n, A, B, X)) != 0)
	{
		printf("Determinantul sistemului: %f", d);
		printf("\nVectorul solutiilor: ");
		for (i = 1; i <= n; i++)
			printf("%f ", X[i]);
	}
	else
		printf("\n ! Eroare ! Determinantul este nul !");
	_getch();
}

// implementarea functiilor
float Gauss(int n, float A[][50], float* B, float* X)
{
	int i, k, j, lp;
	float m, det, max;
	det = 1;				// initializarea pentru un produs.
	for (i = 1; i < n; i++)
	{
		max = fabs(A[i][i]);
		lp = i;
		for (k = i + 1; k <= n; k++)
			if (fabs(A[k][i]) > max)
			{
				max = fabs(A[k][i]);
				lp = k;
			}
		if (max == 0)
			return 0;
		if (lp != i)
		{
			for (j = i; j <= n; j++)
				schimb(&A[i][j], &A[lp][j]);
			schimb(&B[i], &B[lp]);
			det *= -1; 		// schimb semnul determinantului in urma interschimbarii unei linii din determinant cu alta
		}
		for (k = i + 1; k <= n; k++)
		{
			m = A[k][i] / A[i][i];
			for (j = i; j <= n; j++)
				A[k][j] -= m * A[i][j];
			// scad din fiecare linie de sub prima, pe prima inmultita cu 'm'. 
			// Astfel obtin valori 0 in pozitiile dorite ale coeficientilor necunoscutelor, de 
			// sub diagonala principala
			B[k] -= m * B[i];	// la fel din termenii liberi
		}
	}
	// calculez determinantul matricei in forma sa finala (superior triunghiulara)
	if (A[n][n] == 0)
		return 0;
	for (i = 1; i <= n; i++)
		det *= A[i][i];
	// determinantul unui sistem triunghiular este produsul 
	// elementelor de pe diagonala principala.
	if (!det)
	{
		printf("\n Determinantul este nul !");
		return 0;
	}
	// rezolvarea sistemului superior triunghiular
	for (i = n; i >= 1; i--)
	{
		X[i] = B[i];
		for (j = n; j >= i + 1; j--)
			X[i] -= A[i][j] * X[j];
		X[i] /= A[i][i];
	}
	return det;
}

void schimb(float* pVal1, float* pVal2)
{
	float temp;
	temp = *pVal1;
	*pVal1 = *pVal2;
	*pVal2 = temp;
}