#include "Pair.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);
	if (!stream)
	{
		return -1;
	}
	int n;
	Pair p;
	cout << "Amount of elements: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		stream << p << "\n";
	}
	stream.close();
	return n;
}
int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in);
	if (!stream)
	{
		return -1;
	}
	Pair temp;
	int i = 0;
	while (stream >> temp)
	{
		cout << temp << "\n";
		i++;
	}
	stream.close();
	return i;
}
int file_deleteRecordsUnderValue(const char* filename, int intlimitValue, double doublelimitValue)
{
	fstream fromStream(filename, ios::in);
	fstream inStream("tmpFile", ios::out | ios::trunc);
	int i = 0;
	Pair p;
	while (fromStream >> p)
	{
		if (p.get_first() >= intlimitValue && p.get_second() >= doublelimitValue && !fromStream.eof())
		{
			inStream << p;
			i++;
		}
	}
	fromStream.close();
	inStream.close();
	remove(filename);
	rename("tmpFile", filename);
	return i;
}
int file_addRecordsWithValue(const char* filename, int intcurrentValue, double doublecurrentValue, int L1, double L2)
{
	L1 = 2;
	L2 = 2.0;
	fstream fromStream(filename, ios::in);
	fstream inStream("tmpFile", ios::out | ios::trunc);
	int i = 0;
	Pair p;
	while (fromStream >> p)
	{
		if ((p.get_first() == intcurrentValue && p.get_second() == doublecurrentValue) && !fromStream.eof())
		{
			p = p * L1;
			p = p * L2;
			i++;
		}
		inStream << p;
	}
	fromStream.close();
	inStream.close();
	remove(filename);
	rename("tmpFile", filename);
	return i;
}
int add_file(const char* f_name, int count, Pair pp)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream)
	{
		return -1;
	}
	Pair p;
	int i = 0, l = 0;
	while (stream >> p)
	{
		if (stream.eof())break;
		i++;
		if (i == 1)
		{
			for (int j = 0; j < count; j++)
			{
				Pair new_Pair;
				cin >> new_Pair;
				temp << new_Pair;
				l++;
			}
		}
		temp << p;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;
}
int del_file(const char* f_name, int k)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream)
	{
		return -1;
	}
	int i = 0;
	Pair p;
	while (stream >> p)
	{
		if (stream.eof())
		{
			break;
		}
		i++;
		if (i != k)
		{
			temp << p;
		}
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}
int add_end(const char* f_name, Pair pp)
{
	fstream stream(f_name, ios::app);
	if (!stream)
	{
		return -1;
	}
	stream << pp;
	return 1;
}
