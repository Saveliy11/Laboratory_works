#include <iostream>
#include "Pair.h"
#include <list>
#include <vector>
#include <queue>
using namespace std;

typedef queue<Pair>Queue;
typedef vector<Pair>Vector;

Queue make_queue(int n)
{
	Queue Q;
	Pair P;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << "). ";
		cin >> P;
		Q.push(P);
	}
	return Q;
}
Vector copy_queue_to_vector(Queue Q)
{
	Vector V;
	while (!Q.empty())
	{
		V.push_back(Q.front());
		Q.pop();
	}
	return V;
}
Queue copy_vector_to_queue(Vector V)
{
	Queue Q;
	for (auto it = V.begin(); it != V.end(); ++it)
	{
		Q.push(*it);
	}
	return Q;
}
void print_queue(Queue Q)
{
	Vector V = copy_queue_to_vector(Q);
	for (auto it = V.cbegin(); it != V.cend(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void add_min(Queue& Q)
{
    Vector V = copy_queue_to_vector(Q);
	cout << "Cell number after which to insert the minimum element: ";
    int pos;
    cin >> pos;
    if (pos < 0 || pos > V.size())
    {
        cout << "Error! Invalid position." << endl;
        return;
    }
    Pair min = V.front();
    for (auto i = V.begin(); i != V.end(); i++)
    {
        if (*i < min)
        {
            min = *i;
        }
    }
    V.insert(V.begin() + pos - 1, min);
	Q = copy_vector_to_queue(V);
}
void delete_elements(Queue& Q)
{
	Pair sum;
	Vector V = copy_queue_to_vector(Q);
	for (auto i = V.begin(); i != V.end(); ++i)
	{
		sum = sum + *i;
	}
	int size = V.size();
	Pair avg = sum / size;
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
	Q = copy_vector_to_queue(V);
}
void max_division(Queue& Q)
{
	Vector V = copy_queue_to_vector(Q);
	if (V.empty())
	{
		cout << "Error! Vector is empty." << endl;
		return;
	}
	Pair max = V.front();
	for (auto i = V.begin(); i != V.end(); i++)
	{
		if (*i > max)
		{
			max = *i;
		}
	}
	for (auto i = V.begin(); i != V.end(); i++)
	{
		*i = *i / max;
	}
	Q = copy_vector_to_queue(V);
}

int main()
{

	Queue Q;
	int n;
	cout << "Vector size: ";
	cin >> n;
	cout << "\n";

	Q = make_queue(n);

	cout << "\n";
	cout << "Source vector: ";
	print_queue(Q);
	cout << "\n";

	add_min(Q);
	cout << "The vector after adding the minimum element: ";
	print_queue(Q);
	cout << "\n";

	delete_elements(Q);
	cout << "The vector after removing elements smaller than the mean: ";
	print_queue(Q);
	cout << "\n";

	max_division(Q);
	cout << "The vector after dividing all elements by the maximum: ";
	print_queue(Q);
	cout << "\n";

	return 0;
}
