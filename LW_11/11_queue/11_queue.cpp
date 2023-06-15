#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

//����������� ���� �������
struct Node
{
	string data; // ������ ������ ����
	Node* next; // ��������� �� ��������� ����
};

//���������� ��������� �������
struct Line
{
	Node* head; // ��������� �� ������ �������
	Node* tail; // ��������� �� ����� �������
	Line()
	{
		head = nullptr;
		tail = nullptr;
	}
};

// ������� ���������� �������� � ����� �������
void push(Line& line, string value)
{
	Node* newNode = new Node; // �������� ������ ���� �������
	newNode->data = value;
	newNode->next = nullptr;
	if (line.head == nullptr)
		line.head = newNode; // ���� ������� ���� �����, ���������� ��������� �� ������
	else
		line.tail->next = newNode; // ����� ���������� ��������� �� ��������� ������� � ���������� ��������
	line.tail = newNode; // ���������� ��������� �� ����� �������
}

// ������� �������� �������� �� ������ �������
void pop(Line& line)
{
	if (line.head == nullptr)
	{
		cout << "Queue is empty" << endl; // ������� �����, ���������� ������� �������
	}
	else
	{
		Node* nodeToRemove = line.head; // ���������� ��������� �� ��������� ����
		line.head = line.head->next; // ���������� ��������� �� ������ �������
		delete nodeToRemove; // �������� ���� ������
	}
}

// ������� ������ ����������� �������
void printLine(const Line& line)
{
	Node* current = line.head; // �������� ���� ��� ������ 
	while (current != nullptr)
	{
		cout << current->data << " "; // ����� �������� ����
		current = current->next; // ������� � ���������� ����
	}
	cout << endl;
}

// ������� ��� �������� �����
void delete_key(Line& line, Line& line1, Line& line2, string key)
{
	while (line.head->data != key)
	{ // ���� �� ����� ��������� ����
		printLine(line);
		push(line1, line.head->data); // ���������� � ������������� ������� ��������� �� �����
		pop(line); // �������� �� ����������� ������� ��������� �� �����
	}
	printLine(line);
	pop(line); // �������� ����� �� ����������� �������
	printLine(line);
	cout << "First intermediate queue: ";
	printLine(line1);
	while (line.head != nullptr)
	{
		printLine(line);
		push(line2, line.head->data); // ���������� � ������������� ������� ��������� ����� �����
		pop(line); // �������� �� ����������� ������� ��������� ����� �����
	}
	cout << "Queue is empty" << endl;
	cout << "Second intermediate queue: ";
	printLine(line2);
}

// ������� ��� ��������� �� ������������� �������
void delete_elem(Line& line, Line& line1, Line& line2, Line& line3, int n, int m)
{
	for (int i = 1; i < m; i++)
	{ // ���������� ��������� �� ��������� ������ � ������������� �������
		push(line1, line.head->data);
		pop(line);
	}
	push(line2, line.head->data); // ���������� ��������� �� ������� ������ � ������������� �������
	pop(line);
	for (int i = m + 1; i < n; i++)
	{
		push(line3, line.head->data); // ���������� ��������� ����� ��������� ������ � ������������� �������
		pop(line);
	}
	cout << "First intermediate queue: ";
	printLine(line1);
	cout << "Second intermediate queue: ";
	printLine(line2);
	cout << "Thrid intermediate queue: ";
	printLine(line3);
}

// ������� ��� �������������� ������� �� 1-�� �������
void copy_line1(Line& source1, Line& source2, Line& destination)
{
	cout << endl << "Restoring the original queue: " << endl;
	while (source1.head != nullptr)
	{
		push(destination, source1.head->data); // ����������� �������� �������� �� ������������� ������� � �����������
		printLine(destination);
		pop(source1); // ������� � ���������� �������� � ������������� ������� 
	}
	while (source2.head != nullptr)
	{
		push(destination, source2.head->data); // ����������� �������� �������� �� ������������� ������� � �����������
		printLine(destination);
		pop(source2); // ������� � ���������� �������� � ������������� ������� 
	}
	cout << "Queue with removed key: "; printLine(destination);
}

// ������� ��� �������������� ������� �� 2-�� �������
void copy_line2(Line& source1, Line& source2, Line& source3, Line& destination)
{
	string s;
	int k;
	while (source1.head != nullptr)
	{
		push(destination, source1.head->data); // ����������� �������� �������� �� ������������� ������� � ����������� 
		pop(source1); // ������� � ���������� �������� � ������������� ������� 
	}
	cout << "Number of elements coming into the queue: ";
	cin >> k;
	for (int i = 1; i <= k; i++)
	{
		cout << "Element to be added: ";
		cin >> s;
		push(destination, s); // ���������� ��������� ����� �������� �������
	}
	push(destination, source2.head->data);
	while (source3.head != nullptr)
	{
		push(destination, source3.head->data); // ����������� �������� �������� �� ������������� ������� � �����������
		pop(source3); // ������� � ���������� �������� � ������������� �������
	}
	cout << "Queue with added elements: ";
	printLine(destination);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n, m;
	string a, key;
	Line line, line1, line2, line3;
	cout << "Number of queue elements : ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << i << "-th element of the queue: ";
		cin >> a;
		push(line, a);
	}
	cout << endl << "Source queue: ";
	printLine(line);
	cout << endl;
	cout << "Delete key: ";
	cin >> key;
	delete_key(line, line1, line2, key);
	copy_line1(line1, line2, line);
	cout << endl;
	cout << "The number of the element before which you want to add new elements: ";
	cin >> m;
	delete_elem(line, line1, line2, line3, n, m);
	cout << "Received queue:";
	copy_line2(line1, line2, line3, line);
	cout << endl;
	return 0;
}
