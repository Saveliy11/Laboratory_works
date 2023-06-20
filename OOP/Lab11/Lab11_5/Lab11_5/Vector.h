#pragma once
#include <vector>
#include <list>
#include <queue>
#include <iostream>
#include "Pair.h"
using namespace std;

template <typename type>
class Vector
{
private:
	queue <type> Q;
	int size = Q.size();
public:
	Vector(int n);
	~Vector() {};
	void add(type data)
	{
		Q.push(data);
	}
	void print();
	void add_min();
	void delete_less_average();
	void  divide_by_max();
};

template <typename type>
queue<type> copy_vector_to_queue(vector<type> V)
{
	queue<type> Q;
	for (auto it = V.begin(); it != V.end(); ++it)
	{
		Q.push(*it);
	}
	return Q;
}

template <typename type>
vector<type> copy_queue_to_vector(queue<type> Q)
{
	vector<type> V;
	while (!Q.empty())
	{
		V.push_back(Q.front());
		Q.pop();
	}
	return V;
}

template <typename type>
Vector<type>::Vector(int n)
{
	type a; size = n;
	for (int i = 0; i < n; ++i)
	{
		cout << i+1 << "). ";
		cin >> a;
		this->add(a);
	}
}

template <typename type>
void Vector<type>::print()
{
	vector<type> V = copy_queue_to_vector(Q);
	for (auto it = V.begin(); it != V.end(); ++it)
	{
		cout << *it << " ";
	}
}

template <typename type>
void Vector<type>::add_min()
{
	type s{};
	vector<type> V = copy_queue_to_vector(Q);
	cout << "The number of the cell where you want to insert the minimum element: ";
	int pos;
	cin >> pos;
	if (pos < 0 || pos > V.size())
	{
		cout << "Error! Invalid position." << endl;
		return;
	}
	s = V.front();
	for (auto i = V.begin(); i != V.end(); i++)
	{
		if (*i < s)
		{
			s = *i;
		}
	}
	V.insert(V.begin() + pos - 1, s);
	Q = copy_vector_to_queue(V);
}

template <typename type>
void Vector<type>::delete_less_average()
{
	vector<type> V = copy_queue_to_vector(Q);
	type sum{};
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
	Q = copy_vector_to_queue(V);
}

template <typename type>
void Vector<type>:: divide_by_max()
{
	vector<type> V = copy_queue_to_vector(Q);
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
	Q = copy_vector_to_queue(V);
}
