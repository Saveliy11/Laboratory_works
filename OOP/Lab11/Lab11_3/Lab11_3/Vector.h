#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <typename type>
class Vector
{
private:
	vector<type>V;
	int size = V.size();
public:
	Vector();
	Vector(int);
	~Vector();
	void print();
	void add_min();
	void delete_less_average();
	void divide_by_max();
};

template <typename type>
Vector<type>::Vector()
{
	size = 0;
}

template <typename type>
Vector<type>::Vector(int n)
{
	type a;
	size = n;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << "). ";
		cin >> a;
		V.push_back(a);
	}
}

template <typename type>
Vector<type>::~Vector()
{
}

template <typename type>
void Vector<type>::print()
{
	for (auto i = V.begin(); i != V.end(); i++)
	{
		cout << *i << ' ';
	}
	cout << endl;
}

template <typename type>
void Vector<type>::add_min()
{
	cout << "Cell number after which to insert the minimum element: ";
	int pos;
	cin >> pos;
	if (pos < 0 || pos > V.size())
	{
		cout << "Error! Invalid position." << endl;
		return;
	}
	type min = V.front();
	for (auto i = V.begin(); i != V.end(); i++)
	{
		if (*i < min)
		{
			min = *i;
		}
	}
	V.insert(V.begin() + pos - 1, min);
}

template <typename type>
void Vector<type>::delete_less_average()
{
	type sum;
	for (auto i = V.begin(); i != V.end(); ++i)
	{
		sum = sum + *i;
	}
	int size = V.size();
	type avg = sum / size;
	for (auto i = V.begin(); i != V.end();)
	{
		if (*i < avg)
		{
			i = V.erase(i);
		}
		else
		{
			++i;
		}
	}
}

template <typename type>
void Vector<type>::divide_by_max()
{
	type max = V.front();
	for (auto i = V.begin(); i != V.end(); i++)
	{
		if (*i > max)
		{
			max = *i;
		}
	}
	for (auto i = V.begin(); i != V.end(); i++)
	{
		*i = *i / max;
	}
}
