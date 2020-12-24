/* LIBRARY SORT
Cazul mediu: O(N log N)
Cazul defavorabil: O(N^2)
Memorie folosita: O(N)
Stabil: DA
Sortare descrescatoare: a[i]<a[i+1]
Sortare crescatoare: a[i]>a[i+1]

Descriere: Library Sort este un algoritm de sortare care foloseste sortarea prin insertie, insa cu "gap"-uri pentru a accelera
		   sortarea. Totusi, a fost dovedit faptul ca algoritmul ruleaza mai degraba in timp O(N log N) (la fel ca Quick Sort) decat O(N^2) (la fel ca sortarea
		   prin insertie). In comparatie cu sortarea prin insertie, aceasta are dezavantajul ca necesita mai multa memorie din cauza "gap"-urilor.
		   Un dezavantaj al sortarii prin insertie este faptul ca necesita multe interschimbari. Library Sort rezolva putin aceasta problema, deoarece trebuie mutate mai
		   putine elemente.*/

#include<iostream>
#include<conio.h>
using namespace std;
#define swap(a,b) (a)=(b)+(a)-((b)=(a))
int last, queue[1000008];
//Aceasta functie insereaza numarul de spatii potrivite intre numere
void balance(int f[], int e, int inserted)
{
	int top, bottom;
	top = bottom = 0;
	int i = 1, s = 1, t;
	while (s < inserted)
	{
		t = 0;
		while (t < e)
		{
			if (f[i] != -1)
			{
				queue[bottom++] = f[i];
			}
			f[i++] = -1;
			t++;
		}
		if (f[i] != -1)
			queue[bottom++] = f[i];
		f[i++] = queue[top++];
		s++;
	}
	last = i - 1;
}
//Aceasta functie insereaza elementul in pozitia gasit de Cautarea Binara
//si apoi interschimba elementele urmatoare pana la primul spatiu gol
void insert(int f[], int element, int position)
{
	if (f[position] == -1)
	{
		f[position] = element;
		if (position > last)
			last = position;
	}
	else
	{
		int temp = element;
		swap(temp, f[position]);
		position++;
		while (f[position] != -1)
		{
			swap(temp, f[position]);
			position++;
		}
		f[position] = temp;
		if (position > last)
			last = position;
	}
}
//Functie pentru Cautarea binara pentru gasirea locului unde noul element 
//trebuie inserat
void find_place(int f[], int element, int start, int end)
{
	int mid = start + ((end - start) / 2);
	if (start == end)
	{
		if (f[mid] == -1)
		{
			f[mid] = element;
			if (mid > last)
				last = mid;
			return;
		}
		else if (f[mid] <= element)
		{
			insert(f, element, mid + 1);
			return;
		}
		else
		{
			insert(f, element, mid);
			return;
		}
	}
	int m = mid;
	while (m < end && f[m] == -1)
		m++;
	if (m == end)
	{
		if (f[m] != -1 && f[m] <= element)
			insert(f, element, m + 1);
		else
			find_place(f, element, start, mid);
	}
	else if (m == start)
	{
		if (f[m] > element)
			insert(f, element, m);
		else
			find_place(f, element, m + 1, end);
	}
	else
	{
		if (f[m] == element)
		{
			insert(f, element, m + 1);
		}
		else if (f[m] > element)
		{
			find_place(f, element, start, m - 1);
		}
		else
			find_place(f, element, m + 1, end);
	}
}
void main()
{
	int i, k, n, e;
	int* s, * f;
	cin >> n;                              //Introducere numar de elemente
	s = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		cin >> s[i];
	cin >> e;                              //Introducere "gap"
	f = (int*)malloc((1 + e) * n * sizeof(int));
	for (i = 0; i < (1 + e) * n; i++)
		f[i] = -1;
	f[0] = s[0];
	i = 1;
	last = 0;
	int inserted = 1;
	while (inserted < n)
	{
		k = inserted;
		while (inserted < n && k--)
		{
			find_place(f, s[i], 0, last);
			inserted++;
			i++;
		}
		balance(f, e, inserted);
	}
	for (i = 0; i < (1 + e) * n; i++)
		if (f[i] >= 0)
			cout << f[i] << " ";
	_getch();
}