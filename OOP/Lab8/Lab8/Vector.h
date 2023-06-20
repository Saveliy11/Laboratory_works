#pragma once
#include "Object.h"
#include "Event.h"

class Vector
{
public:
	Vector();
	Vector(int);
	~Vector(void);
	void Add();
	void Del();
	void HandleEvent(const TEvent& e);
	void Show();
	int operator()();
protected:
	Object** beg;
	int size;
	int cur;
};
