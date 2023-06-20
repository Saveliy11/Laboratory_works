#pragma once
#include<iostream>
#include "List.h"

using namespace std;
class Pair
{
	int first;
	double second;
public:
	void random()
	{
		first = rand() % 100;
		second = round(((double)(rand()) / RAND_MAX * 10 + 1) * 1000) / 100;
	}
	Pair() { first = 0; second = 0.0; }
	Pair(int first, double ssecond) { first = first; second = second; }
	Pair(const Pair& p) { first = p.first; second = p.second; }
	~Pair() {};
	int get_first() { return first; }
	double get_second() { return second; }
	void set_first(int first) { first = first; }
	void set_second(double second) { second = second; }
	Pair& operator=(const Pair&);
	bool operator<(const Pair&);
	bool operator>(const Pair&);
	Pair operator--(int);
	Pair& operator--();
	Pair operator*(const Pair k);
	friend istream& operator>>(istream& in, Pair& p);
	friend ostream& operator<<(ostream& out, const Pair& t);
};
