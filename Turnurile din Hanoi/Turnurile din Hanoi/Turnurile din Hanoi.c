/*  Se dau 3 tije simbolizate prin A, B, C. Pe tija A se gasesc n discuri de diametre diferite, asezate in ordine descrescatoare a diametrelor. Se cere sa
se mute de pe tija A pe B, utilizand tija intermediara C, toate cele n discuri, respectand urmatoarele reguli:
															-la fiecare pas se muta un singur disc;
															-nu este permis sa se aseze un disc cu diametrul mai mare peste un disc cu diametrul mai mic
	Rezolvare: - daca n=1 se face mutarea A->B, adica se muta discul de pe tija A pe tija B.
			   - daca n=2 se fac mutarile A->C, A->B, C->B.
			   - daca n>2, notam cu Hanoi(n,A,B,C) sirul mutarilor celor n discuri de pe tija A pe tija B, utilizand ca tija intermediara tija C.
		Conform strategiei Divide et Impera incercam sa descompunem problema in alte doua subprobleme de acelasi tip, urmand apoi combinarea solutiilor.
		Deci mutarea celor n discuri de pe tija A pe tija B, utilizand ca tija intermediara tija C, este echivalenta cu: (1) mutarea a n-1 discuri de pe
		tija A pe tija C, utilizand ca tija intermediara tija B; (2) mutarea discului ramas de pe tija A pe tija B; (3) mutarea a n-1 discuri de pe tija C
		pe tija B, utilizand ca tija intermediara tija A. */

#include<stdio.h>
#include<conio.h>
char x, y, z;
int n;
void h(int n, char x, char y, char z)
{
	if (n == 1)
		printf("%c->%c\n", x, y);
	else
	{
		h(n - 1, x, z, y);
		printf("%c->%c\n", x, y);
		h(n - 1, z, y, x);
	}
}
void main()
{
	printf("n=");
	scanf("%d", &n);
	h(n, 'A', 'B', 'C');
	getch();
}