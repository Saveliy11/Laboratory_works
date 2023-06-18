#include <iostream>
#include <windows.h>
using namespace std;

struct Node
{
	string data;
	Node* next;
};

Node* make_stack(int n)
{
	if (n == 0)
	{
		return nullptr;
	}
	else
	{
		Node* head = nullptr;
		Node* prev = nullptr;
		for (int i = 1; i <= n; i++)
		{
			cout << i << "). ";
			Node* newNode = new Node;
			string data;
			cin >> data;
			newNode->data = data;
			newNode->next = nullptr;
			if (prev == nullptr)
			{
				head = newNode;
			}
			else
			{
				prev->next = newNode;
			}
			prev = newNode;
		}
		return head;
	}
}

void print_stack(Node* head)
{
	if (head == nullptr)
	{
		cout << "Stack is empty";
	}
	else
	{
		Node* current = head;
		while (current != nullptr)
		{
			cout << "(" << current->data << ")" << " ";
			current = current->next;
		}
	}
}

void remove_node(Node*& head, int position)
{
	if (position == 1)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	else
	{
		Node* prev = nullptr;
		Node* current = head;
		int count = 1;
		while (current != nullptr && count < position)
		{
			prev = current;
			current = current->next;
			count++;
		}
		if (current != nullptr)
		{
			prev->next = current->next;
			delete current;
		}
	}
}

void insert_node(Node*& head, int position, const string& value)
{
	Node* newNode = new Node;
	newNode->data = value;
	if (position == 1)
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{
		Node* prev = nullptr;
		Node* current = head;
		int count = 1;
		while (current != nullptr && count < position)
		{
			prev = current;
			current = current->next;
			count++;
		}

		if (prev != nullptr)
		{
			prev->next = newNode;
			newNode->next = current;
		}
	}
}

int main()
{

	int n;
	cout << "Stack size: ";
	cin >> n;
	Node* stack = make_stack(n);
	cout << "\n";

	cout << "Source stack: ";
	print_stack(stack);
	cout << "\n\n";

	int k;
	cout << "Number of items to remove: ";
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cout << i + 1 << "). ";
		cout << "The position of the element to be removed: ";
		int position;
		cin >> position;
		remove_node(stack, position);
	}
	cout << "Stack after removing: ";
	print_stack(stack);
	cout << "\n\n";

	int m;
	cout << "Number of elements to add: ";
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cout << i + 1 << "). ";
		cout << "The position to add the new element: ";
		int pos;
		cin >> pos;
		cout << "    ";
		cout << "Element to be added: ";
		string element;
		cin >> element;
		insert_node(stack, pos, element);
	}
	cout << "Stack after adding: ";
	print_stack(stack);
	cout << "\n\n";

	return 0;
}
