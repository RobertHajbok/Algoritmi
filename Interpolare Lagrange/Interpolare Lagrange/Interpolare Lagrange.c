#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <malloc.h>

double u(double x, int n, double* a)
{
	double _u = 1;
	int i = 0;

	for (i = 0; i <= n; i++) {
		_u *= x - a[i];
		printf("u=%f\n", _u);
	}

	return _u;
}

double uix(double x, int n, double* a)
{
	int i;
	double _u = u(x, n, a);
	for (i = 0; i <= n; i++)
		_u /= x - a[i];

	return _u;
}

double l(double x, int n, double* a)
{
	double _l = 0;
	int i;

	for (i = 0; i <= n; i++)
		_l += uix(x, n, a) / uix(a[i], n, a);

	printf("L = %f\n", _l);
	return _l;
}

double li(double x, int n, double* a)
{
	double li = 0;
	int i;

	for (i = 0; i <= n; i++)
		li += uix(x, n, a) / u(a[i], n, a);

	return li;
}

int main()
{
	int n = 0;
	int i = 0;
	double x = 0;

	double* a = (double*)malloc((n + 1) * sizeof(double));
	double* f = (double*)malloc((n + 1) * sizeof(double));

	printf("n = ");
	scanf("%i", &n);

	for (i = 0; i < n; i++) {
		printf("a[%i] = ", i);
		scanf("%f", &a[i]);
		printf(" valoare a[%i] = %f\n", i, a[i]);
	}


	printf("x = ");
	scanf("%f", &x);

	for (i = 0; i < n; i++) {
		printf("f[%i] = ", i);
		scanf("%f", &f[i]);
	}

	//u(x, n, &a[MAX]);

	l(x, n, a);
	_getch();

	return 0;
}