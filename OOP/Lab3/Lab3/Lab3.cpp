#include <iostream>
#include "Pair.h"
using namespace std;

int main()
{
	setlocale(0, "ru");

	Pair Obj1;
	cout << "Values of the first class instance" << endl;
	cin >> Obj1;
	cout << "First class instance: ";
	cout << Obj1 << endl << endl;

	int i;
	double d;
	int n;
	cout << "The number to be subtracted from the class instance" << endl;
	cout << "1. Integer" << endl;
	cout << "2. Double" << endl;
	cin >> n;

	switch (n)
	{
	case 1:
	{
		cout << "Integer: ";
		cin >> i;
		Obj1 = Obj1 - i;
		cout << "Modified class instance: ";
		cout << Obj1 << endl;
		break;
	}
	case 2:
	{
		cout << "Double: ";
		cin >> d;
		Obj1 = Obj1 - d;
		cout << "Modified class instance: ";
		cout << Obj1 << endl;
		break;
	}
	default: cout << "Error!" << endl;
	}

	cout << endl;
	Pair Obj2;
	cout << "Values of the second instance of the class" << endl;
	cin >> Obj2;
	cout << "Second class instance: ";
	cout << Obj2 << endl << endl;
	Obj1 == Obj2;

	return 0;
}