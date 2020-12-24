#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	int v[100], i, l = 0, k = 0, n;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> v[i];
	for (i = 0; i < n; i++)
	{
		if (v[i] < 0)
		{
			v[l] += v[i];
			v[i] = v[l] - v[i];
			v[l++] -= v[i];
		}
		if (v[i] == 0)
		{
			v[k] += v[i];
			v[i] = v[k] - v[i];
			v[k++] -= v[i];
		}
	}
	for (i = 0; i < n; i++)
		cout << v[i] << " ";
	getch();
}