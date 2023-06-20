#include <iostream>
#include <fstream>
#include <string>
#include "Pair.h"
#include "File_work.h"
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Pair p, p1, p2;
	int k, c;
	int L1 = 2;
	double L2 = 2.0;
	char file_name[30];
	do
	{
		cout << "1. Create file";
		cout << "\n2. Output file content";
		cout << "\n3. Delete record from file with given number";
		cout << "\n4. Increment all records with the given value by a factor of two";
		cout << "\n5. Append K records to the beginning of the file";
		cout << "\n0. Exit\n\n";
		cout << "> ";
		cin >> c;
		cout << endl;
		switch (c)
		{
		case 1:
			cout << "File name: ";
			cin >> file_name;
			k = make_file(file_name);
			if (k < 0)
			{
				cout << "Failed to create file";
			}
			break;
		case 2:
			cout << "File name: ";
			cin >> file_name;
			k = print_file(file_name);
			if (k == 0)
			{
				cout << "File is empty\n";
			}
			if (k < 0)
			{
				cout << "Failed to open file\n";
			}
			break;

		case 3:
			cout << "File name: ";
			cin >> file_name;
			cout << "The number of the element to be removed: ";
			int number;
			cin >> number;
			k = del_file(file_name, number);
			if (k == 0)
			{
				cout << "File name\n";
			}
			if (k < 0)
			{
				cout << "Failed to open file\n";
			}
			break;
		case 4:
			cout << "File name: ";
			cin >> file_name;
			cout << "Given values of pairs of numbers to be doubled\n";
			cout << "Integer: ";
			int intlimitValue;
			cin >> intlimitValue;
			cout << "Double: ";
			double doublelimitValue;
			cin >> doublelimitValue;
			k = file_addRecordsWithValue(file_name, intlimitValue, doublelimitValue, L1, L2);
			if (k == 0)
			{
				cout << "Fale is empty\n";
			}
			if (k < 0)
			{
				cout << "Failed to open file\n";
			}
			break;
		case 5:
			cout << "File name: ";
			cin >> file_name;
			Pair p1;
			cout << "Number of elements to add: ";
			int count;
			cin >> count;
			cin >> p1;
			k = add_file(file_name, count, p1);
			if (k == 0)
			{
				k = add_end(file_name, p1);
			}
			if (k < 0)
			{
				cout << "Failed to open file\n";
			}
			break;
		}
	} while (c != 0);
	return 0;
}


