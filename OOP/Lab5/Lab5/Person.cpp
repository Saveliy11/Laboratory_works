#include "Person.h"

Person::Person(void)
{
	Name = "";
	Age = 0;
}

Person::~Person(void)
{
}

Person::Person(string N, int A)
{
	Name = N;
	Age = A;
}

Person::Person(const Person& P)
{
	Name = P.Name;
	Age = P.Age;
}

void Person::Set_Name(string N)
{
	Name = N;
}

void Person::Set_Age(int A)
{
	Age = A;
}

Person& Person::operator=(const Person& p)
{
	if (&p == this)
	{
		return *this;
	}
	Name = p.Name;
	Age = p.Age;
	return *this;
}

istream& operator>>(istream& in, Person& p)
{
	cout << "Name: "; in >> p.Name;
	cout << "Age: "; in >> p.Age;
	cout << "\n";
	return in;
}

ostream& operator<<(ostream& out, const Person& p)
{
	out << "Name: " << p.Name;
	out << "\nAge: " << p.Age;
	out << "\n";
	return out;
}

void Person::Show()
{
	cout << "\nName: " << Name;
	cout << "\nAge: " << Age;
	cout << "\n";
}

