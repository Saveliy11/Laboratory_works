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

int Pair::get_first()const
{
	return first;
}

void Pair::set_first(int n)
{
	first = n;
}

double Pair::get_second()const
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

Pair Pair::operator/(int s)
{
	Pair temp;
	temp.first = first / s;
	temp.second = second / s;
	return temp;
}

Pair Pair::operator/(const Pair& P)
{
	Pair temp;
	temp.first = first / P.first;
	temp.second = second / P.second;
	return temp;
}

bool Pair::operator>=(const Pair& P)
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

bool Pair::operator<=(const Pair& P)
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

bool Pair::operator>(const Pair& P)
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

istream& operator>>(istream& in, Pair& N)
{
	cout << "Целое число: "; in >> N.first;
	cout << "    ";
	cout << "Вещественное число: "; in >> N.second;
	return in;
}

ostream& operator<<(ostream& out, const Pair& N)
{
	out << "(" << N.first << " : " << N.second << ")";
	return out;
}

bool operator>(const Pair& p1, double t)
{
	double sum1 = p1.second + p1.first;
	return (sum1 > t);
}

bool operator>(double t, const Pair& p1)
{
	double sum1 = p1.second + p1.first;
	return (t > sum1);
}

bool operator>(const Pair& p1, const Pair& p2)
{
	double sum1 = p1.second + p1.first;
	double sum2 = p2.second + p2.first;
	return (sum1 > sum2);
}

bool operator<(const Pair& p1, const Pair& p2)
{
	double sum1 = p1.second + p1.first;
	double sum2 = p2.second + p2.first;
	return (sum1 < sum2);
}
