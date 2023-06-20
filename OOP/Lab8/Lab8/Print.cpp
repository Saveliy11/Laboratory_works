#include "Print.h"
#include "Event.h"
#include "Object.h"
#include <iostream>
using namespace std;

Print::Print()
{
	Name = "";
	Author = "";
}

Print::~Print(void)
{
}

Print::Print(string N, string A)
{
	Name = N;
	Author = A;
}

Print::Print(const Print& P)
{
	Name = P.Name;
	Author = P.Author;
}

void Print::Set_Name(string N)
{
	Name = N;
}

void Print::Set_Author(string A)
{
	Author = A;
}

Print& Print::operator=(const Print& p)
{
	if (&p == this)
	{
		return *this;
	}
	Name = p.Name;
	Author = p.Author;
	return *this;
}

istream& operator>>(istream& in, Print& p)
{
	cout << "Name: "; in >> p.Name;
	cout << "Author: "; in >> p.Author;
	cout << "\n";
	return in;
}

ostream& operator<<(ostream& out, const Print& p)
{
	out << "Name: " << p.Name;
	out << "\nAuthor: " << p.Author;
	out << "\n";
	return out;
}

void Print::Show()
{
	cout << "\nName: " << Name;
	cout << "Author: " << Author;
	cout << "\n";
}

void Print::Input()
{
	cout << "\nName: ";
	cin >> Name;
	cout << "Author: ";
	cin >> Author;
	cout << "\n";
}
// 
void Print::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		switch (e.command)
		{
		case cmGet:cout << "Name: " << Get_Name() << endl;
			break;
		}
	}
}
