#include <iostream>
#include <vector>
#include <ctime>
#include "Pair.h"
using namespace std;

typedef vector<Pair>Vector;

Vector make_vector(int n)
{
    Vector V;
    Pair P;
    for (int i = 0; i < n; i++)
    {
        P.random();
        V.push_back(P);
    }
    return V;
}
void print_vector(Vector& V)
{
    for (auto i = V.begin(); i != V.end(); ++i)
    {
        cout << *i << ' ';
    }
    cout << endl;
}
void add_min(Vector& V)
{
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
    V.insert(V.begin() + pos, min);
}
void delete_less_average(Vector& V)
{
    Pair sum;
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
}
void divide_by_max(Vector& V)
{
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
    print_vector(V);
    cout << "\n";

    add_min(V);
    cout << "The vector after adding the minimum element: ";
    print_vector(V);
    cout << "\n";

    delete_less_average(V);
    cout << "The vector after removing elements smaller than the mean: ";
    print_vector(V);
    cout << "\n";

    divide_by_max(V);
    cout << "The vector after dividing all elements by the maximum: ";
    print_vector(V);
    cout << "\n";

    return 0;
}
