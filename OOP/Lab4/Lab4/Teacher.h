#pragma once
#include "Person.h"

class Teacher:
	public Person
{
public:
	Teacher(void);
	~Teacher(void);
	Teacher(string, int, string, int);
	Teacher(const Teacher&);
	string Get_Subject() { return Subject; }
	int Get_Hours() { return Hours; }
	void Set_Subject(string);
	void Set_Hours(int);
	void Change_Hours();
	Teacher& operator=(const Teacher&);
	void operator+(const Teacher&);
	void operator-(const Teacher&);
	friend istream& operator>>(istream& in, Teacher& l);
	friend ostream& operator<<(ostream& out, const Teacher& l);
protected: 
	string Subject;
	int Hours;
};

