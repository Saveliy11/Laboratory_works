#pragma once
#include <iostream>
using namespace std;

class Stack
{
private:
    int* data;
    int size;
    int top;
public:
    Stack()
    {
        data = nullptr;
        size = 0;
        top = -1;
    }

    Stack(int n)
    {
        size = n;
        data = new int[size];
        top = -1;
    }

    ~Stack()
    {
        delete[] data;
    }

    void push(int value)
    {
        if (top == size - 1)
        {
            cout << "Stack overflow!" << endl;
            return;
        }
        top++;
        data[top] = value;
    }

    void multiply(int num)
    {
        for (int i = 0; i <= top; i++)
        {
            data[i] *= num;
        }
    }

    void push_front(int value)
    {
        if (top == size - 1)
        {
            cout << "Stack overflow!" << endl;
            return;
        }
        for (int i = top; i >= 0; i--)
        {
            data[i + 1] = data[i];
        }
        top++;
        data[0] = value;
    }

    void pop_back()
    {
        if (top == -1)
        {
            cout << "Stack underflow!" << endl;
            return;
        }
        top--;
    }

    void print()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << data[i] << " ";
        }
    }

    int& operator[](int index)
    {
        return data[index];
    }
};