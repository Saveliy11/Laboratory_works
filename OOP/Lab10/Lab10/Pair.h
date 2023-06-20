#pragma once
#include <iostream>
using namespace std;

class Pair
{
private:
	int first;
	double second;
public:
	Pair();
	Pair(int, double);
	Pair(const Pair&);
	~Pair();
	int get_first();
	void set_first(int);
	double get_second();
	void set_second(double);

	void operator == (const Pair&);

	Pair& operator=(const Pair&);
	Pair operator-(const Pair&);
	Pair operator*(int);
	Pair operator*(double);
	friend istream& operator>>(istream&, Pair&);
	friend ostream& operator<<(ostream&, const Pair&);
	friend fstream& operator>>(fstream&, Pair&);
	friend fstream& operator<<(fstream&, const Pair&);
};
