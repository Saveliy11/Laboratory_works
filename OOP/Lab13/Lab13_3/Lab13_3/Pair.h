#pragma once
#include <iostream>
using namespace std;

class Pair
{
protected:
	int first;
	double second;
public:
	void random()
	{
		first = rand() % 100;
		second = round(((double)(rand()) / RAND_MAX * 10 + 1) * 1000) / 100;
	}
	Pair();
	Pair(int, double);
	Pair(const Pair&);
	~Pair();
	int get_first()const;
	void set_first(int);
	double get_second()const;
	void set_second(double);
	Pair& operator=(const Pair&);
	Pair operator-(const Pair&);
	Pair operator+(int);
	Pair operator+(double);
	Pair operator+(const Pair&);
	Pair operator/(int);
	Pair operator/(const Pair&);
	bool operator>=(const Pair&);
	bool operator<=(const Pair&);
	bool operator>(const Pair&);
	friend istream& operator>>(istream& in, Pair& N);
	friend ostream& operator<<(ostream& out, const Pair& N);
	friend bool operator>(const Pair&, double);
	friend bool operator>(double, const Pair&);
	friend bool operator>(const Pair&, const Pair&);
	friend bool operator<(const Pair&, const Pair&);
};


