#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	long double grad;
	cout << "Temperatura in grade Celsius:";
	cin >> grad;
	cout << "Temperatura in grade Fahrenheit este:" << grad * 9 / 5 + 32 << "\n";
	cout << "Temperatura in grade Kelvin este:" << grad + 273.15 << "\n";
	cout << "Temperatura in grade Rankine este:" << (grad + 273.15) * 9 / 5 << "\n";
	cout << "Temperatura in grade Romer este:" << grad * 21 / 40 + 7.5 << "\n";
	cout << "Temperatura in grade Newton este:" << grad * 33 / 100 << "\n";
	cout << "Temperatura in grade Delisle este:" << (100 - grad) * 3 / 2 << "\n";
	cout << "Temperatura in grade Reaumur este:" << grad * 4 / 5 << "\n";
	getch();
	return 0;
}