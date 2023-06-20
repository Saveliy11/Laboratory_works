#include "List.h"
#include <iostream>
#include <ctime>

using namespace std;
int main()
{
    srand(time(0));

    cout << "List size: ";
    int m;
    cin >> m;
    List a(m);
    int f;
    for (int i = 0; i < a(); i++)
    {
        if (i % 2 == 0)
        {
            a[i] = (rand() % 100);
        }
        else
        {
            a[i] = (rand() % 100) / 2 - (rand() % 100);
        }
    }
    cout << "\n";

    cout << "List <a>: " << a;
    cout << "\n\n";

    List b(10);
    b = a;
    cout << "List <b> after copying: " << b;
    cout << "\n\n";

    List c(10);
    cout << "The constant to multiply all elements of the list: ";
    cin >> f;
    cout << "\n";

    c = b * f;
    cout << "The resulting list after multiplication: " << c;
    cout << "\n\n";

    Iterator it;
    cout << "Source list: ";
    for (it = a.first(); it != a.last(); ++it)
    {
        cout << *it << " ";
    }
    cout << "\n\n";

    cout << "First element of the source list: " << *(a.first());
    cout << "\n";
    it = a.first();
    ++it;
    cout << "Second element of the source list: " << *it;
    cout << "\n\n";

    cout << "The number of the element to be displayed: ";
    int n;
    cin >> n;
    it = a - n;
    cout << n << "-th element of the list: " << *it;
    cout << "\n\n";

    return 0;
}