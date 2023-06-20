#include <iostream>
#include "List.h"
#include "Error.h"
using namespace std;

List::List()
{
	size = 0;
	first = nullptr;
	last = nullptr;
}

List::List(int s)
{
	if (s > Max_size)
	{
		throw MaxSizeError();
	}
	size = s;
	first = nullptr;
	last = nullptr;
	for (int i = 0; i < size; i++)
	{
		Node* newNode = new Node;
		newNode->data = rand() % 100;
		if (last == nullptr)
		{
			first = newNode;
			last = newNode;
		}
		else
		{
			if (last != nullptr)
			{
				last->next = newNode;
				last = newNode;
			}
		}
	}
}

List::List(const List& L)
{
	size = 0;
	first = nullptr;
	last = nullptr;
	Node* current = L.first;
	while (current != nullptr)
	{
		Node* newNode = new Node();
		newNode->data = current->data;
		newNode->next = nullptr;
		if (last == nullptr)
		{
			first = newNode;
			last = newNode;
		}
		else
		{
			last->next = newNode;
			last = newNode;
		}
		current = current->next;
		size++;
	}
}

List::~List()
{
	Node* current = first;
	while (current != nullptr)
	{
		Node* next = current->next;
		delete current;
		current = next;
	}

}

void List::push(int value)
{
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;
	if (first == nullptr)
	{
		first = newNode;
		last = newNode;
		size++;
	}
	else
	{
		last->next = newNode;
		last = newNode;
		size++;
	}
}

void List::pop()
{
	if (first == nullptr)
		throw EmptySizeError();
	if (first == last)
	{
		delete first;
		first = nullptr;
		last = nullptr;
		return;
	}
	Node* secondToLast = first;
	while (secondToLast->next != last)
	{
		secondToLast = secondToLast->next;
	}
	delete last;
	last = secondToLast;
	last->next = nullptr;
}

void List::shift_right(int n)
{
	if (n < 0)
	{
		throw IndexError_1();
	}
	if (n > size)
	{
		throw MaxSizeError();
	}
	if (n == 0)
	{
		return;
	}
	Node* current = first;
	for (int i = 0; i < n; ++i)
	{
		if (current == nullptr)
		{
			throw IndexError();
		}
		current = current->next;
	}
	first = current;
	size -= n;
}

void List::shift_left(int n)
{
	if (n < 0)
	{
		throw IndexError_1();
	}
	if (n > size)
	{
		throw MaxSizeError();
	}
	if (n == 0)
	{
		return;
	}
	Node* current = first;
	for (int i = 0; i < n; ++i)
	{
		if (current == nullptr)
		{
			throw IndexError();
		}
		current = current->next;
	}
	if (current == nullptr)
	{
		last->next = first;
		first = nullptr;
		last = nullptr;
		return;
	}
	Node* newFirst = current;
	Node* newLast = last;
	while (newLast->next != nullptr)
	{
		newLast = newLast->next;
	}
	newLast->next = first;
	first = newFirst;
	last = newLast;
	last->next = nullptr;
}

List& List::operator=(const List& other)
{
	if (this == &other)
	{
		return *this;
	}
	while (first != nullptr)
	{
		Node* temp = first;
		first = first->next;
		delete temp;
	}
	Node* otherCurrent = other.first;
	while (otherCurrent != nullptr)
	{
		push(otherCurrent->data);
		otherCurrent = otherCurrent->next;
	}

	return *this;
}

int& List::operator[](int index)
{
	if (index >= 0 && index < size)
	{
		Node* curr = first;
		for (int i = 0; i < index; i++)
		{
			curr = curr->next;
		}
		return curr->data;
	}
	if (index < 0)
	{
		throw IndexError_1();
	}
	if (index >= size)
	{
		throw IndexError_2();
	}
}

int List::operator()()
{
	return size;
}

List operator*(List& L1, List& L2)
{
	if (L1.size != L2.size)
	{
		throw DiffSizeError();
	}
	List result;
	Node* currA = L1.first;
	Node* currB = L2.first;
	while (currA != nullptr && currB != nullptr)
	{
		int multipliedValue = currA->data * currB->data;
		result.push(multipliedValue);
		currA = currA->next;
		currB = currB->next;
	}
	return result;
}

ostream& operator<<(ostream& out, const List& L)
{
	if (L.first == nullptr)
	{
		cout << "\n";
		out << "Index error!" << endl;
		return out;
	}
	Node* current = L.first;
	while (current != nullptr)
	{
		out << current->data << " ";
		current = current->next;
	}
	cout << endl;
	return out;
}

istream& operator>>(istream& in, List& L)
{
	int count;
	//cout << "������� ���������� ��������� � ������: ";
	in >> count;
	//cout << "������� �������� ������: ";
	for (int i = 0; i < count; i++)
	{
		int value;
		in >> value;
		L.push(value);
	}
	return in;
}