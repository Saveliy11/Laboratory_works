#pragma once
#include "Object.h"
#include <string>
#include <iostream>
using namespace std;

class Person:
	public Object
{
public:
	Person(void);
	virtual ~Person(void);
	void Show();
	Person(string, int);
	Person(const Person&);
	string Get_Name() { return Name; }
	int Get_Age() { return Age; }
	void Set_Name(string);
	void Set_Age(int);
	Person& operator=(const Person&);
	friend istream& operator>>(istream& in, Person& c);
	friend ostream& operator<<(ostream& out, const Person& c);
protected:
	string Name;
	int Age;
};


