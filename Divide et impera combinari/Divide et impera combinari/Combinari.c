/* Divide et impera se bazează pe principiul descompunerii problemei în două sau mai multe subprobleme (mai ușoare), care se rezolvă, iar soluția pentru
problema inițială se obține combinând soluțiile subproblemelor. De multe ori, subproblemele sunt de același tip și pentru fiecare din ele se poate aplica
aceeași tactică a descompunerii în (alte) subprobleme, până când (în urma descompunerilor repetate) se ajunge la probleme care admit rezolvare imediată.
Nu toate problemele pot fi rezolvate prin utilizarea acestei tehnici. Se poate afirma că numărul celor rezolvabile prin "divide et impera" este relativ
mic, tocmai datorită cerinței ca problema să admită o descompunere repetată.
Divide et impera este o tehnică ce admite o implementare recursivă. Principiul general prin care se elaborează algoritmi recursivi este: "ce se întâmplă la
un nivel, se întâmplă la orice nivel" (având grijă să asigurăm condițiile de terminare). Așadar, un algoritm prin divide et impera se elaborează astfel:
la un anumit nivel avem două posibilități:
					1. s-a ajuns la o problemă care admite o rezolvare imediată (condiția de terminare), caz în care se rezolvă și se revine din apel;
					2. nu s-a ajuns în situația de la punctul 1, caz în care problema curentă este descompusă în (două sau mai multe) subprobleme, pentru
					fiecare din ele urmează un apel recursiv al funcției, după care combinarea rezultatelor are loc fie pentru fiecare subproblemă, fie la
					final, înaintea revenirii din apel. */
#include<stdio.h>
int comb(int n, int k)
{
	if ((k == 0) || (k == n))
		return 1;
	return comb(n - 1, k - 1) + comb(n - 1, k);
}
int main()
{
	printf("%d", comb(15, 4));
	getchar();
	return 0;
}