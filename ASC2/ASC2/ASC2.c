#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define m 4
#define n 4

struct T
{
	int V[n];
} X[m];

void printVector(int v[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%i ", v[i]);
	}
	printf("\n");
}

int compareVector(int v1[], int v2[], int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		//printf("comp %i ? %i\n", v1[i], v2[i]);
		if (v1[i] < v2[i])
		{
			//printf("=> v1 < v2\n");
			return 1;
		}
		else if (v1[i] > v2[i])
		{
			break;
		}
	}

	return 0;
}

int main()
{
	int aux[n];
	int i, j, k, l;

	for (i = 0; i < m; i++)
	{
		printf("X[%i].V = ", i);

		for (j = 0; j < n; j++)
		{
			X[i].V[j] = rand() % 10;
		}

		printVector(X[i].V, n);
	}

	printf("\n Sorted:\n");

	for (i = 0; i < m - 1; i++)
	{
		for (j = i + 1; j < m; j++)
		{
			if (compareVector(X[i].V, X[j].V, n))
			{
				//printf("\nSWAP X[%i].V < X[%i].V\n", i, j);
				for (k = 0; k < n; k++)
				{
					aux[k] = X[i].V[k];
					X[i].V[k] = X[j].V[k];
					X[j].V[k] = aux[k];
				}

				//for (l = 0; l < m; l++)
				//{
				//printf("X[%i].V = ", l);
				//printVector(X[l].V, n);
				//}
			}
		}
	}

	for (i = 0; i < m; i++)
	{
		printf("X[%i].V = ", i);
		printVector(X[i].V, n);
	}
	getch();
	return 0;
}