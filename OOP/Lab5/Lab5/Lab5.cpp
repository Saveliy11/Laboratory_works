#include "Object.h"
#include "Person.h"
#include "Teacher.h"
#include "Vector.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	cout << "\n\n";

	cout << "Source vector:";
	cout << "\n";
	Vector v(n);
	cout << "\n";

	Person a;
	cin >> a;

	Teacher b;
	cin >> b;

	Object* p = &a;

	v.Add(p);

	p = &b;

	v.Add(p);
	cout << "\n\n\n";
	cout << "Received vector:";
	cout << "\n";
	cout << v;
	cout << "\n";

	return 0;
}