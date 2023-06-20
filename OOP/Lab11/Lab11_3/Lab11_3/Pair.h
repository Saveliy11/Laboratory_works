#pragma once
#include <iostream>
using namespace std;

class Pair
{
private:
	int first;
	double second;
public:
	void random()
	{
		first = rand() % 100;
		second = (rand() % 101 - 50) / 10.0;
	}
	Pair();
	Pair(int, double);
	Pair(const Pair&);
	~Pair();
	int get_first();
	void set_first(int);
	double get_second();
	void set_second(double);
	Pair& operator=(const Pair&);
	Pair operator-(const Pair&);
	Pair operator+(int);
	Pair operator+(double);
	Pair operator+(const Pair&);
	Pair operator /(int);
	Pair operator/(const Pair&);
	bool operator>=(const Pair&);
	bool operator<=(const Pair&);
	bool operator>(const Pair&);
	bool operator<(const Pair&);
	friend istream& operator>>(istream& in, Pair& N);
	friend ostream& operator<<(ostream& out, const Pair& N);
};
