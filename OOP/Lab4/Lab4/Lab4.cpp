#include <iostream>
#include "Person.h"
#include "Teacher.h"
using namespace std;

void f1(Person& p)
{
	p.Set_Name("Ben");
	cout << p;
}

Person f2()
{
	Teacher t("John", 25, "IT", 10);
	return t;
}

void f3(Teacher& t)
{
	t.Set_Subject("English");
	t.Set_Hours(789);
	cout << t;
}

int main()
{
	cout << "Working with the <Person> class" << "\n\n";
	Person a;
	cin >> a;
	cout << a;
	Person b("Henry", 90);
	cout << b << endl;
	a = b;
	cout << b << endl;

	cout << "\n\n" << "Working with the <Teacher> class" << "\n\n";
	Teacher c;
	cin >> c;
	cout << c << endl;

	cout << "Number of hours to add: ";
	c + c;
	cout << "\n" << "The <Teacher> class after adding hours" << "\n";
	cout << c << endl;
	cout << "Number of hours to subtract: ";
	c - c;
	cout << "\n" << "The <Teacher> class after subtracting hours" << "\n";
	cout << c << endl;
	f1(c);
	a = f2();
	cout << a;
}