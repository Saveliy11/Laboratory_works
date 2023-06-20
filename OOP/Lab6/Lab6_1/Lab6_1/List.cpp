#include "List.h"
#include <iostream>
using namespace std;

Iterator operator-(List& a, int n)
{
	for (int i = 0; i <= a.size - n; i++)
	{
		--a.end;
	}
	return a.end;
}
List::List()
{
	size = 0;
	data = 0;
}

List::List(int s, int k)
{
	size = s;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = k;
	}
	beg.elem = &data[0];
	end.elem = &data[size];
};

List::List(const List& a)
{
	size = a.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = a.data[i];
	}
	beg = a.beg;
	end = a.end;
};

List::~List()
{
	delete[] data;
	data = 0;
};

List& List:: operator=(const List& a)
{
	if (this == &a)
	{
		return *this;
	}
	size = a.size;
	if (data != 0)
	{
		delete[] data;
	}
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = a.data[i];
	}
	beg = a.beg;
	end = a.end;
	return *this;
};

int& List:: operator[](int index)
{
	if (index < size || index>0)
	{
		return data[index];
	}
	else
	{
		cout << "Index out of range!";
	}
};

List List:: operator*(const int k)
{
	List tmp(size);
	for (int i = 0; i < size; i++)
	{
		tmp.data[i] += data[i] * k;
	}
	return tmp;
};

int List:: operator()()
{
	return size;
};

ostream& operator<<(ostream& out, const List& a)
{
	for (int i = 0; i < a.size; i++)
	{
		out << a.data[i] << " ";
	}
	return out;
};

istream& operator>>(istream& in, List& a)
{
	for (int i = 0; i < a.size; i++)
	{
		in >> a.data[i];
	}
	return in;
};