#include<conio.h>
#include<iostream>
using namespace std;
void main()
{
	int m;
	float d[50][50], a[50];
	cout << "Introduceti ordinul maxim al diferentei divizate: ";
	cin >> m;
	for (int l = 0; l <= m; l++)
		for (int k = 0; k <= m; k++)
		{
			if (l == 0)
			{
				float x;
				cout << "x" << k << " = ";
				cin >> x;
				a[k] = x;
				d[k][l] = 1 / (1 + x * x);
			}
			else
				d[k][l] = (d[k + 1][l - 1] - d[k][l - 1]) / (a[k + l] - a[k]);
		}
	for (int k = 0; k <= m; k++)
	{
		for (int l = 0; l <= m - k; l++)
			cout << d[k][l] << " ";
		cout << endl;
	}
	getch();
}