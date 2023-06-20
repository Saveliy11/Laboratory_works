#pragma once
#include <iostream>
#include <map>
#include <ctime>
using namespace std;

template <typename type>
class Vector
{
private:
	multimap<int, type>mm;
	int size = 0;
public:
	Vector();
	Vector(int);
	Vector(int, type);
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
	srand(time(0));
	type data;
	size = n;
	int a;
	for (int i = 0; i < n; ++i)
	{
		a = rand() % 100;
		data = round(((double)(rand()) / RAND_MAX * 10 + 1) * 1000) / 100;
		mm.insert(make_pair(a, data)); 
	}
}

template <typename type>
Vector<type>::Vector(int n, type k)
{
	size = n;
	for (int i = 0; i < n; ++i)
	{
		mm.insert(k);
	}
}

template <typename type>
Vector<type>::~Vector()
{
}

template <typename type>
void Vector<type>::print()
{
	int i = 1;
	for (const auto& pair : mm)
	{
		cout << i << "). " << pair.first << " - " << pair.second << endl;
		i++;
	}
}

template <typename type>
void Vector<type>::add_min()
{
	auto it = mm.begin();
	double min = it->second;
	for (; it != mm.end(); it++)
	{
		if (min > it->second)
		{
			min = it->second;
		}
	}
	cout << "Index at which to insert the minimum element: ";
	int pos;
	cin >> pos;
	mm.insert(make_pair(pos, min));
}

template <typename type>
void Vector<type>::delete_less_average()
{
	double sum = 0;
	for (auto& pair : mm)
	{
		sum += pair.second;
	}
	double avg = sum / mm.size();
	for (auto it = mm.begin(); it != mm.end();)
	{
		if (it->second < avg)
		{
			it = mm.erase(it);
		}
		else
		{
			++it;
		}
	}
}

template <typename type>
void Vector<type>::divide_by_max()
{
	auto it = mm.begin();
	double max = it->second;
	for (; it != mm.end(); it++)
	{
		if (max < it->second)
		{
			max = it->second;
		}
	}
	multimap<int, type> mm_1;
	for (const auto& pair : mm)
	{
		double value = pair.second / max;
		mm_1.insert(make_pair(pair.first, value));
	}
	mm = mm_1;
}
