#pragma once
#include <iostream>
using namespace std;
const int Max_size = 20;

class Node
{
public:
	int data = 0;
	Node* next = nullptr;
	Node* prev = nullptr;
};

class List
{
private:
	int size;
	Node* first;
	Node* last;
public:
	List();
	List(int);
	List(const List&);
	~List();
	void push(int);
	void pop();
	void shift_right(int);
	void shift_left(int);
	List& operator=(const List&);
	int& operator[] (int);
	int operator()();
	friend List operator*(List&, List&);
	friend ostream& operator<<(ostream&, const List&);
	friend istream& operator>>(istream&, List&);
};

