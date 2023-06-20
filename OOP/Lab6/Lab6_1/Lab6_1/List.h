#pragma once
#include <string>
#include <iostream>
using namespace std;

class List;
class Iterator
{
	friend class List;
private:
	int* elem;
public:
	Iterator()
	{
		elem = 0;
	}
	~Iterator()
	{

	}
	bool operator==(const Iterator& i)
	{
		return elem == i.elem;
	}
	bool operator!=(const Iterator& i)
	{
		return elem != i.elem;
	}
	void operator++()
	{
		elem++;
	}
	void operator--()
	{
		--elem;
	}
	int& operator*() const
	{
		return *elem;
	}
};

class List
{
private:
	int size;
	int* data;
	Iterator beg;
	Iterator end;
public:
	List(int s, int k = 0);
	List(const List& a);
	~List();
	List();
	List& operator=(const List& a);
	int& operator[](int index);
	List operator*(const int k);
	int operator()();
	friend ostream& operator<<(ostream& out, const List& a);
	friend istream& operator>>(istream& in, List& a);
	Iterator first()
	{
		return beg;
	}
	Iterator last()
	{
		return end;
	}
	friend  Iterator operator-(List& a, int n);

};