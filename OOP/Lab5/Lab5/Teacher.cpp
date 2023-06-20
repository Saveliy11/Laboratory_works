#include "Teacher.h"


Teacher::Teacher(void) :Person()
{
	Subject = "";
	Hours = 0;
}

Teacher::~Teacher(void)
{
}

Teacher::Teacher(string N, int A, string S, int H) :Person(N, A)
{
	Subject = S;
	Hours = H;
}

Teacher::Teacher(const Teacher& T)
{
	Name = T.Name;
	Age = T.Age;
	Subject = T.Subject;
	Hours = T.Hours;
}

void Teacher::Set_Subject(string S)
{
	Subject = S;
}

void Teacher::Set_Hours(int G)
{
	Hours = G;
}

Teacher& Teacher::operator=(const Teacher& t)
{
	if (&t == this)
	{
		return *this;
	}
	Name = t.Name;
	Age = t.Age;
	Subject = t.Subject;
	Hours = t.Hours;
	return *this;
}

void Teacher::operator+(const Teacher&)
{
	int value;
	cin >> value;
	Hours = Hours + value;
}

void Teacher::operator-(const Teacher&)
{
	int value;
	cin >> value;
	Hours = Hours - value;
}

istream& operator>>(istream& in, Teacher& t)
{
	cout << "Name: "; in >> t.Name;
	cout << "Age: ";in >> t.Age;
	cout << "Subject: ";in >> t.Subject;
	cout << "Hours: ";in >> t.Hours;
	return in;
}

ostream& operator<<(ostream& out, const Teacher& t)
{
	out << "\nName: " << t.Name;
	out << "\nAge: " << t.Age;
	out << "\nSubject: " << t.Subject;
	out << "\nHours: " << t.Hours;
	out << "\n";
	return out;
}

void Teacher::Show()
{
	cout << "\nName: " << Name;
	cout << "\nAge: " << Age;
	cout << "\nSubject: " << Subject;
	cout << "\nHours: " << Hours;
	cout << "\n";
}