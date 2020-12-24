#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	int v1[10], v2[10], i, j, n1, n2;
	double nr1 = 0, nr2 = 0, nr_cerut;
	cin >> n1;
	for (i = 0; i < n1; i++)
		cin >> v1[i];
	cin >> n2;
	for (j = 0; j < n2; j++)
		cin >> v2[j];
	for (i = 0; i < n1; i++)
		nr1 = nr1 * 10 + v1[i];
	for (j = 0; j < n2; j++)
		nr2 = nr2 * 10 + v2[j];
	nr_cerut = nr1 + nr2 * pow(10.0, (double)(-n2));
	cout << nr_cerut;
	getch();
}