#include <stdio.h>
#include<conio.h>
int sarrus(int m[3][3])
{
	return (m[0][0] * m[1][1] * m[2][2]) + (m[0][1] * m[1][2] * m[2][0]) + (m[0][2] * m[1][0] * m[2][1]) - (m[0][2] * m[1][1] * m[2][0]) - (m[0][1] * m[1][0] * m[2][2]) - (m[0][0] * m[1][2] * m[2][1]);
}

void matrixPrint(int m[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%i ", m[i][j]);
		}
		printf("\n");
	}
}

void matrixSwap(int* m1[], int* m2[])
{
	int aux[3][3];
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			aux[i][j] = m1[i][j];

		}
	}
}

int main()
{
	int i, j, k, l;
	int aux[3][3];
	int v[4][3][3] = {
		{ {-2, 2, 3}, {-1, 1, 3}, {2, 0, -1} },		// v[0]
		{ { 3, 1, 5}, { 2, 0, 1}, {1, 4,  3} },		// v[1]
		{ {-2, 2, 3}, {-1, 1, 3}, {4, 1, -4} },		// v[2]
		{ { 1, 2, 3}, { 0, 2, 3}, {3, 0, -1} }		// v[3]
	};

	for (i = 0; i < 4; i++)
	{
		//printf("v[%i] = \n", i);
		//matrixPrint(v[i]);
		printf("det(v[%i]) = %i\n", i, sarrus(v[i]));
	}

	for (i = 0; i < 4 - 1; i++)
	{
		for (j = i + 1; j < 4; j++)
		{
			if (sarrus(v[i]) > sarrus(v[j]))
			{
				printf("v[%i] > v[%i]\n", i, j);
				// Swap
				for (k = 0; k < 3; k++)
				{
					for (l = 0; l < 3; l++)
					{
						aux[k][l] = v[i][k][l];
						v[i][k][l] = v[j][k][l];
						v[j][k][l] = aux[k][l];
					}
				}
			}
		}
	}

	for (i = 0; i < 4; i++)
	{
		printf("v[%i] = \n", i);
		matrixPrint(v[i]);
	}
	getch();
	return 0;
}