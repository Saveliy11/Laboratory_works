#pragma once
#include "Object.h"
#include <string>
#include <iostream>
using namespace std;

class Print :
	public Object
{
public:
	Print();
	virtual ~Print(void);
	void Show();
	void Input();
	Print(string, string);
	Print(const Print&);
	string Get_Name() { return Name; }
	string Get_Author() { return Author; }
	void Set_Name(string);
	void Set_Author(string);
	Print& operator=(const Print&);
	friend istream& operator>>(istream& in, Print& c);
	friend ostream& operator<<(ostream& out, const Print& c);
	void HandleEvent(const TEvent& e);
protected:
	string Name;
	string Author;
};


