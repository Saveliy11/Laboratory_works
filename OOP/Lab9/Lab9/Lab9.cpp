#include <iostream>
#include <Windows.h>
#include "List.h"
#include "Error.h"
#include <ctime>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));

	try {
		int n1, n2, n3, n4, i, s, c;
		cout << "First list size: ";
		cin >> n1;

		List l1(n1);
		cout << "First list: " << l1;
		cout << "The number of the element to be displayed: ";
		cin >> i;
		cout << "Eelement: " << l1[i - 1];
		cout << "\n\n";

		cout << "Second list size: ";
		cin >> n2;
		List l2(n2);
		cout << "Second list: " << l2;
		cout << "Multiplying list elements: " << l1 * l2;
		cout << "\n";
		
		cout << "Third list size: ";
		cin >> n3;
		List l3(n3);
		cout << "Third list: " << l3;
		cout << "Number of elements to move: ";
		cin >> s;
		l3.shift_right(s);
		cout << "Third list after moving: " << l3;
		cout << "\n";

		cout << "Fourth list size: ";
		cin >> n4;
		List l4(n4);
		cout << "Fourth list: " << l4;
		cout << "Number of items to move: ";
		cin >> c;
		l4.shift_left(c);
		cout << "Fourth list after moving: " << l4;
		cout << "\n";

		cout << "Removing list";
		cout << "\n";
		for (int j = 0; j < n4 + 1; j++)
		{
			cout << l4;
			l4.pop();
		}
	}
	catch (Error& e)
	{
		e.what();
	}
	return 0;
}
