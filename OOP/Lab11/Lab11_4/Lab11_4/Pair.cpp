#include <iostream>
#include <ctime>
#include "Pair.h"
using namespace std;

Pair::Pair()
{
	first = 0;
	second = 0.0;
}

Pair::Pair(int n1, double n2)
{
	first = n1;
	second = n2;
}

Pair::Pair(const Pair& N)
{
	first = N.first;
	second = N.second;
}

Pair::~Pair()
{
}

int Pair::get_first()
{
	return first;
}

void Pair::set_first(int n)
{
	first = n;
}

double Pair::get_second()
{
	return second;
}

void Pair::set_second(double n)
{
	second = n;
}

Pair& Pair::operator=(const Pair& N)
{
	if (&N == this)
	{
		return *this;
	}
	first = N.first;
	second = N.second;
	return *this;
}

Pair Pair::operator-(const Pair& N)
{
	Pair temp;
	temp.first = first - N.first;
	temp.second = second - N.second;
	return temp;
}

Pair Pair::operator+(int constant)
{
	return Pair(first + constant, second);
}

Pair Pair::operator+(double constant)
{
	return Pair(first, second + constant);
}

Pair Pair::operator+(const Pair& P)
{
	Pair temp;
	temp.first = first + P.first;
	temp.second = second + P.second;
	return temp;
}

Pair Pair::operator /(int s)
{
	Pair temp;
	temp.first = first / s;
	return temp;
}

Pair Pair::operator/(const Pair& P)
{
	Pair temp;
	temp.first = first / P.first;
	temp.second = second / P.second;
	return temp;
}

bool Pair::operator>=(const Pair& P)const
{
	if (first >= P.first && second >= P.second)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool Pair::operator<=(const Pair& P)const
{
	if (first <= P.first && second <= P.second)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool Pair::operator>(const Pair& P)const
{
	double s1 = first + second;
	double s2 = P.first + P.second;
	if (s1 > s2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool Pair::operator<(const Pair& P)const
{
	double s1 = first + second;
	double s2 = P.first + P.second;
	if (s1 < s2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
istream& operator>>(istream& in, Pair& N)
{
	cout << "Integer: "; in >> N.first;
	cout << "    ";
	cout << "Double: "; in >> N.second;
	return in;
}

ostream& operator<<(ostream& out, const Pair& N)
{
	return (out << "(" << N.first << " : " << N.second << ")");
}
