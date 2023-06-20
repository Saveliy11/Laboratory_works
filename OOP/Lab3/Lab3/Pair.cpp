#include <iostream>
#include "Pair.h"
using namespace std;

Pair::Pair()
{
	a = 0;
	b = 0.0;
}

Pair::Pair(int n1, double n2)
{
	a = n1;
	b = n2;
}

Pair::Pair(const Pair& N)
{
	a = N.a;
	b = N.b;
}

Pair::~Pair()
{

}

int Pair::get_a()
{
	return a;
}

void Pair::set_a(int n)
{
	a = n;
}

double Pair::get_b()
{
	return b;
}

void Pair::set_b(double n)
{
	b = n;
}

Pair& Pair::operator=(const Pair& N)
{
	if (&N == this)
	{
		return *this;
	}
	a = N.a;
	b = N.b;
	return *this;
}

Pair Pair::operator-(int constant)
{
	return Pair(a - constant, b);
}

Pair Pair::operator-(double constant)
{
	return Pair(a, b - constant);
}

void Pair::operator==(const Pair& t)
{
	if (a == b)
	{
		cout << "The numbers are equal" << endl;
	}
	if (a > b)
	{
		cout << "The first number is greater than the second" << endl;
	}
	if (a < b)
	{
		cout << "The first number is less than the second" << endl;
	}
}

istream& operator>>(istream& in, Pair& N)
{
	cout << "Integer: "; in >> N.a;
	cout << "Double: "; in >> N.b;
	return in;
}

ostream& operator<<(ostream& out, const Pair& N)
{
	return (out << "(" << N.a << " : " << N.b << ")");
}
