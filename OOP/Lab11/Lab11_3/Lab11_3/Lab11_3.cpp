#include <iostream>
#include "Vector.h"
#include "Pair.h"
using namespace std;

int main()
{
	int n;
	cout << "Vector size: ";
	cin >> n;
	cout << "\n";

	Vector<Pair> V(n);

	cout << "\n";
	cout << "Source vector: ";
	V.print();
	cout << "\n";

	V.add_min();
	cout << "The vector after adding the minimum element: ";
	V.print();
	cout << "\n";

	V.delete_less_average();
	cout << "The vector after removing elements smaller than the mean: ";
	V.print();
	cout << "\n";

	V.divide_by_max();
	cout << "The vector after dividing all elements by the maximum: ";
	V.print();
	cout << "\n";

	return 0;
}
