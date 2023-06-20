#include "List.h"
#include "Pair.h"
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	setlocale(0, "ru");
	srand(time(0));

	cout << "Multiplication ñonstants: ";
	Pair p;
	p.random();
	cout << p;
	cout << "\n\n";

	cout << "List size: ";
	int n;
	cin >> n;
	cout << "\n";

	List<Pair>C(n, p);
	cout << "Source list:";
	cout << "\n";
	cin >> C;
	cout << "\n";

	cout << "List after copying: ";
	List<Pair>D(n, p);
	D = C;
	cout << D;
	cout << "\n\n";

	cout << "The number of the element to be displayed: ";
	int i;
	cin >> i;
	cout << i << "-th element of the list: " << D[i - 1];
	cout << "\n\n";

	cout << "List after multiplying of all elements by constants: ";
	D = D * p;
	cout << D;
	cout << "\n\n";
	return 0;
}