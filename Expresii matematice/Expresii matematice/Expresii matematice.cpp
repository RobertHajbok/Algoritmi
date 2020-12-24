#include <fstream>
using namespace std;
const int maxn = 1001;
const char oper[2][3] = { "+-", "*/" };

double operatie(double a, double b, char op)
{
	switch (op)
	{
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	}
}

double eval(char expr[], int nivel, int& k)
{
	double ret;
	if (nivel == 2) // paranteze sau operand
	{
		if (expr[k] == '(')
		{
			++k;
			ret = eval(expr, 0, k);
			++k;
		}
		else
			ret = expr[k++] - '0';
		return ret;
	}
	// +, -, * sau /
	ret = eval(expr, nivel + 1, k);
	while (expr[k] == oper[nivel][0] || expr[k] == oper[nivel][1])
	{
		int poz = k++;
		ret = operatie(ret, eval(expr, nivel + 1, k), expr[poz]);
	}
	return ret;
}

int main()
{
	char expr[maxn];
	ifstream in("expr.in");
	in >> expr;
	in.close();
	int k = 0;
	ofstream out("expr.out");
	out << eval(expr, 0, k);
	out.close();
	return 0;
}