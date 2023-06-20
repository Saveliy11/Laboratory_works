#include "Vector.h"
#include "Print.h"
#include "Book.h"
#include "Event.h"
#include <iostream>
using namespace std;


Vector::Vector()
{
	beg = nullptr;
	cur = 0;
	size = 0;
}
è
Vector::Vector(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}

Vector::~Vector()
{
	if (beg != 0)
		delete[] beg;
	beg = 0;
}

void Vector::Add()
{
	Object* p;
	cout << "1. Print" << endl;
	cout << "2. Book" << endl;
	int y;
	cin >> y;
	if (y == 1)
	{
		Print* a = new (Print);
		a->Input();
		p = a;
		if (cur < size)
		{
			beg[cur] = p;
			cur++;
		}
	}
	else
	{
		if (y == 2)
		{
			Book* b = new Book;
			b->Input();
			p = b;
			if (cur < size)
			{
				beg[cur] = p;
				cur++;
			}
		}
		else
		{
			return;
		}
	}
}

void Vector::Show()
{
	if (cur == 0)
	{
		cout << "Empty" << endl;
	}
	Object** p = beg;
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();
		p++;
	}
}

int Vector::operator ()()
{
	return size;
}

void Vector::Del()
{
	if (cur == 0)
	{
		return;
	}
	cur--;
}

void Vector::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->HandleEvent(e);
			p++;
		}
	}
}