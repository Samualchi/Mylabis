#include <iostream>
#include <string>
#include "Postfix.h"
using namespace std;


int main()
{
	string formula;
	double res;
	Postfix postfix;
	cout << "Your formula: ";
	cin >> formula;
	postfix.put_infix(formula);
	if (postfix.check())
	{
		cout << "Infix: " << postfix.get_infix() << endl;
		postfix.save_inti_stek();
		cout << "Postfix: " << postfix.get_postfix() << endl;
		res = postfix.get_result();
		cout << "Result: " << res << endl;
	}
	return 0;
}
