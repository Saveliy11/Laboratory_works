#include <iostream>
#include <windows.h>
using namespace std;

char a;	// ���-�� �������� � �����

struct Stack
{
	char data;
	Stack* prev;
};

Stack* make_stack(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else
	{
		Stack* top, * p;
		top = NULL;
		p = new Stack;
		cin >> a;
		p->data = a;
		p->prev = NULL;
		top = p;
		for (int i = 2; i <= n; i++)
		{
			Stack* h = new Stack;
			cin >> a;
			h->data = a;
			h->prev = top;
			top = h;
		}
		return top;
	}
}

void print_stack(Stack* top)
{
	if (top == NULL)
	{
		cout << "Stack is empty";
	}
	else
	{
		Stack* p = top;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->prev;
		}
		cout << endl;
	}
}

char pop(Stack*& top)
{
	Stack* p = top;
	int k = 0;
	while (p != NULL)
	{
		k++;
		p = p->prev;
	}
	p = top;
	if (k == 1)
	{
		char t = top->data;
		delete p;
		top = NULL;
		return t;
	}
	else
	{
		Stack* t = p->prev;
		char u = p->data;
		top = t;
		delete p;
		return u;
	}
}

Stack* push(Stack*& top, char val)	// ���������� �������� � ����
{
	Stack* p = new Stack;	// ��������� ������ ��� ������ ��������
	p->data = val;			// ������������ ������ ��������
	p->prev = top;			// ����� ������� ���p����� �� ������ �������
	top = p;				// ����� ������� ���� ����� ��������� �����
	return top;
}

int main()
{
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	int n;
	cout << "Number of stack elements: ";
	cin >> n;
	cout << "Stack elements";
	Stack* st = make_stack(n);
	cout << "Source stack: ";
	print_stack(st);

	char b;
	cout << "Number of items to remove: ";
	cin >> b;
	int c = 0;
	Stack* st2 = make_stack(0);

	for (int i = 0; i < n; i++)
	{
		cout << "The number of the element to be removed: ";
		int g;
		cin >> g;
		for (int i = 0; i < n - g + 1; i++)
		{

		}

		char t = pop(st);
		if (t != b)
		{
			push(st2, t);
		}
		else
		{
			c = c + 1;
		}
	}
	n = n - c;
	for (int i = 0; i < n; i++)
	{
		char t = pop(st2);
		push(st, t);
	}

	cout << "Stack after removal: ";
	print_stack(st);

	int k;
	cout << "Number of elements to add: ";
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cout << "The number of the element to add the new element to: ";
		int s;
		cin >> s;
		for (int i = 0; i < n - s + 1; i++)
		{
			char t = pop(st);
			push(st2, t);
		}
		cout << "Element to be added: ";
		cin >> a;
		push(st, a);
		for (int i = 0; i < n - s + 1; i++)
		{
			char t = pop(st2);
			push(st, t);
		}
	}
	cout << "Received stack: ";
	print_stack(st);

	return 0;
}