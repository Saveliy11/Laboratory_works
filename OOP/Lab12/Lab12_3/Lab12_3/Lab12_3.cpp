#include <iostream>
#include "Vector.h"
using namespace std;

int main()
{
	int n;
	cout << "Container size: ";
	cin >> n;
	cout << "\n";

	Vector<double> mm(n);

	cout << "Source container:";
	cout << "\n";
	mm.print();
	cout << "\n";

	mm.add_min();
	cout << "Container after adding the minimum element:";
	cout << "\n";
	mm.print();
	cout << "\n";

	mm.delete_less_average();
	cout << "Container after removing elements smaller than average:";
	cout << "\n";
	mm.print();
	cout << "\n";

	mm.divide_by_max();
	cout << "Container after dividing all elements by the maximum:";
	cout << "\n";
	mm.print();
	cout << "\n";

	return 0;
}
