#include "Object.h"
#include "Print.h"
#include "Book.h"
#include "Vector.h"
#include <string>
#include <iostream>
#include <Windows.h>
#include "Dialog.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "m + number: create a group" << endl;
	cout << "+: add an element to a group" << endl;
	cout << "-: remove an element from a group" << endl;
	cout << "s: display information about group members" << endl;
	cout << "z: display information about the names of all elements of the group" << endl;
	cout << "q: end of work" << endl << endl;
	Dialog D;
	D.Execute();

	return 0;
}