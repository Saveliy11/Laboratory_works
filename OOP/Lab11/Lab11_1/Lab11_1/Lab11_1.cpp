#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

typedef vector<double>Vector;

Vector make_vector(int n)
{
	Vector V;
	for (int i = 0; i < n; i++)
	{
		float a = (rand() % 1000) / 10.0;
		V.push_back(a);
	}
	return V;
}

void print(Vector& V)
{
	for (auto i = V.begin(); i != V.end(); ++i)
	{
		cout << "(" << *i << ")" << " ";
	}
	cout << endl;
}

void add_min(Vector& V)
{
	cout << "The number of the cell where you want to insert the minimum element: ";
	int pos;
	cin >> pos;
	if (pos < 0 || pos > V.size())
	{
		cout << "Error! Invalid position." << endl;
		return;
	}
	float min = V.front();
	for (auto i = V.begin(); i != V.end(); i++)
	{
		if (*i < min)
		{
			min = *i;
		}
	}
	V.insert(V.begin() + pos - 1, min);
}

void delete_less_average(Vector& V)
{
	float sum = 0.0;
	for (auto i = V.begin(); i != V.end(); ++i)
	{
		sum += *i;
	}
	int size = V.size();
	float avg = sum / size;
	for (auto i = V.begin(); i != V.end();)
	{
		if (*i < avg)
		{
			i = V.erase(i);
		}
		else
		{
			++i;
		}
	}
}

void divide_by_max(Vector& V)
{
	float max = V.front();
	for (auto i = V.begin(); i != V.end(); i++)
	{
		if (*i > max)
		{
			max = *i;
		}
	}
	for (auto i = V.begin(); i != V.end(); ++i)
	{
		*i = *i / max;
	}
}

int main() 
{
	srand(time(0));

	Vector V;
	int n;
	cout << "Vector size: ";
	cin >> n;
	cout << "\n";
	V = make_vector(n);

	cout << "Source vector: ";
	print(V);
	cout << "\n";

	add_min(V);
	cout << "The vector after adding the minimum element: ";
	print(V);
	cout << "\n";

	delete_less_average(V);
	cout << "The vector after removing elements smaller than the mean: ";
	print(V);
	cout << "\n";

	divide_by_max(V);
	cout << "The vector after dividing all elements by the maximum: ";
	print(V);
	cout << "\n";

	return 0;
}
