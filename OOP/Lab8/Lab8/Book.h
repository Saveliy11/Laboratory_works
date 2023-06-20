#pragma once
#include "Print.h"

class Book :
	public Print
{
public:
	Book();
	~Book();
	Book(string, string, int, string);
	Book(const Book&);
	void Show();
	void Input();
	int Get_Pages() { return Pages; }
	string Get_Publisher() { return Publisher; }
	void Set_Pages(int);
	void Set_Publisher(string);
	Book& operator=(const Book&);
	friend istream& operator>>(istream& in, Book& l);
	friend ostream& operator<<(ostream& out, const Book& l);
protected:
	int Pages;
	string Publisher;
};