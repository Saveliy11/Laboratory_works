#include "ATM.h"
#include <iostream>
using namespace std;

ATM make_ATM()
{
	int n;
	double b;
	double m;
	cout << "ID: ";
	cin >> n;
	cout << "Remaining money at an ATM: ";
	cin >> b;
	cout << "The maximum amount a customer can withdraw: ";
	cin >> m;
	ATM t(n, b, m);
	return t;
}

void print_ATM(ATM t)
{
	t.show();
}

int main()
{
	ATM t1;
	t1.show();
	cout << endl;
	ATM t2(57354, 468135.58, 5434.18);
	t2.show();
	cout << endl;
	ATM t3 = t2;
	t3.show();
	cout << endl;
	t3.set_number(818734);
	t3.set_balance(354191.46);
	t3.set_maxAmount(78137.87);
	print_ATM(t3);
	cout << endl;
	t1 = make_ATM();
	t1.show();
	cout << endl;
}
