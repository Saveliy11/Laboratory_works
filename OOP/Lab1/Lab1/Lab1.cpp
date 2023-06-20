#include <iostream>
#include "fraction.h"
using namespace std;

int main()
{
	fraction A;
	int k;
	int first;
	float second;
	cout << "Integer: ";
	cin >> first;
	cout << "Double: ";
	cin >> second;
	while (second >= 1)
	{
		cout << "Double: ";
		cin >> second;
	}
	cout << "First multiplier: " << first + second << endl;
	cout << "Multiplier k: ";
	cin >> k;
	A.Init(first, second);
	cout << "Multiplication: " << A.multiply(k) << endl;
}

