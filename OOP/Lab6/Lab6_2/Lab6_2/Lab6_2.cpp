#include <iostream>
#include <ctime>
#include "Stack.h"
using namespace std;

int main()
{
    srand(time(0));

    cout << "Stack size: ";
    int n;
    cin >> n;
    cout << "\n";

    Stack s(n + 1);
    for (int i = 0; i < n; i++)
    {
        s.push(rand() % 100);
    }
    s.print();
    cout << "\n\n";

    cout << "The constant to multiply all elements of the stack: ";
    int num;
    cin >> num;
    s.multiply(num);
    cout << "The resulting stack after multiplication: ";
    s.print();
    cout << "\n\n";

    cout << "The element to be added to the top of the stack: ";
    int value;
    cin >> value;
    s.push_front(value);
    cout << "Stack with added element: ";
    s.print();
    cout << "\n\n";

    s.pop_back();
    cout << "Stack with element added and last element removed: ";
    s.print();
    cout << "\n\n";

    return 0;
}