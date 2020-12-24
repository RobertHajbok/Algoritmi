/* Fiind dată o tablă de şah de dimensiunea n x n şi un cal în colţul stânga sus al acesteia, se cere să se afişeze toate posibilităţile de mutare a
acestei piese de şah astfel încât să treacă o singură dată prin fiecare pătrat al tablei. O soluţie va fi afişată ca o matrice n x n în care sunt
numerotate săriturile calului. */

#include<iostream>
#include<conio.h>
using namespace std;
const int x[8] = { -1,1,2,2,1,-1,-2,-2 };
const int y[8] = { 2,2,1,-1,-2,-2,-1,1 };
int n, sol[1000][2], t[25][25], c, tabla[10][10];
void back(int k, int lin, int col)
{
	int linie, coloana, i, j;
	if (k == n * n)
	{
		sol[k][0] = lin;
		sol[k][1] = col;
		for (i = 1; i <= k; i++)
		{
			cout << "mutarea nr." << i << " este la 	coordonatele" << "(" << sol[i][0] << "," << sol[i][1] << ")" << endl;
			tabla[sol[i][0]][sol[i][1]] = i;
		}
		c++;		//numara solutiile
		cout << endl << "varianta este" << endl << endl;
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
				cout << tabla[i][j] << " ";
			cout << endl;
		}
		cout << endl;
		getch();
		if (c == 3)
			exit(EXIT_SUCCESS);
	}
	else
		sol[k][0] = lin;
	sol[k][1] = col;
	for (i = 0; i <= 7; i++)
	{
		linie = lin + x[i];
		coloana = col + y[i];
		if (linie <= n && linie >= 1 && coloana <= n && coloana >= 1 && t[linie][coloana] == 0)
		{
			t[linie][coloana] = 1;
			back(k + 1, linie, coloana);
			t[linie][coloana] = 0;
		}
	}
}
void main()
{
	cout << "n=";
	cin >> n;
	t[1][1] = 1;  //ocup prima pozitie
	back(1, 1, 1);
	getch();
}