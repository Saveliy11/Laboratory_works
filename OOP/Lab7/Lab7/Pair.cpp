#include <iostream>
#include "Pair.h"
#include "List.h"
using namespace std;

Pair& Pair::operator=(const Pair& p)
{
	if (&p == this)
	{
		return *this;
	}
	first = p.first;
	second = p.second;
	return *this;
}

Pair& Pair::operator--()
{
	first = first - 1;
	return *this;
}

Pair Pair::operator--(int)
{
	double temp = second;
	Pair p(first, second);
	second = temp - 1;
	return p;
}

bool Pair::operator<(const Pair& p)
{
	double temp1 = first + second;
	double temp2 = p.first + p.second;
	if (temp1 < temp2)
	{
		return true;
	}
	return false;
}

bool Pair::operator>(const Pair& p)
{
	double temp1 = first + second;
	double temp2 = p.first + p.second;
	if (temp1 > temp2)
	{
		return true;
	}
	return false;
}

Pair Pair::operator*(const Pair k)
{
	Pair temp;
	temp.first = first * k.first;
	temp.second = second * k.second;
	return temp;
}

istream& operator>>(istream& in, Pair& p)
{
	cout << "Integer: "; in >> p.first;
	cout << "Double: "; in >> p.second;
	return in;
}

ostream& operator<<(ostream& out, const Pair& p)
{
	return (out << "(" << p.first << " : " << p.second << ")");
}
