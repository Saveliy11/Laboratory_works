#include <iostream>
#include <fstream>
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
Pair Pair::operator*(int constant)
{
	return Pair(first * constant, second);
}
Pair Pair::operator*(double constant)
{
	return Pair(first, second * constant);
}
istream& operator>>(istream& in, Pair& N)
{
	cout << "Integer: "; in >> N.first;
	cout << "Double: "; in >> N.second;
	return in;
}
ostream& operator<<(ostream& out, const Pair& N)
{
	return (out << "(" << N.first << " : " << N.second << ")");
}
fstream& operator>>(fstream& fin, Pair& p)
{
	fin >> p.first;
	fin >> p.second;
	return fin;
}
fstream& operator<<(std::fstream& fout, const Pair& p)
{
	fout << p.first << '\n';
	fout << p.second << '\n';
	return fout;
}

void Pair::operator==(const Pair& p)
{
	if (first == second)
	{
		cout << "The numbers are equal\n";
	}
	if (first > second)
	{
		cout << "The first number is greater than the second\n";
	}
	if (first < second)
	{
		cout << "The first number is less than the second\n";
	}
}
