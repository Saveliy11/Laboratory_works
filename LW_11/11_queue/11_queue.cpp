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
	{
		line.head = newNode; // ���� ������� ���� �����, ���������� ��������� �� ������
	}
	else
	{
		line.tail->next = newNode; // ����� ���������� ��������� �� ��������� ������� � ���������� ��������
	}
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
		cout << "(" << current->data << ")" << " "; // ����� �������� ����
		current = current->next; // ������� � ���������� ����
	}
}

// ������� ��� �������� �����
void delete_key(Line& line, Line& line1, Line& line2, string key)
{
	while (line.head->data != key)
	{ // ���� �� ����� ��������� ����
		push(line1, line.head->data); // ���������� � ������������� ������� ��������� �� �����
		pop(line); // �������� �� ����������� ������� ��������� �� �����
	}
	pop(line); // �������� ����� �� ����������� �������
	while (line.head != nullptr)
	{
		push(line2, line.head->data); // ���������� � ������������� ������� ��������� ����� �����
		pop(line); // �������� �� ����������� ������� ��������� ����� �����
	}
}

// ������� ��� ��������� �� ������������� �������
void add_elem(Line& line, Line& line1, Line& line2, Line& line3, int n, int m)
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
}

// ������� ��� �������������� ������� �� 1-�� �������
void copy_line1(Line& source1, Line& source2, Line& destination)
{
	while (source1.head != nullptr)
	{
		push(destination, source1.head->data); // ����������� �������� �������� �� ������������� ������� � �����������
		pop(source1); // ������� � ���������� �������� � ������������� ������� 
	}
	while (source2.head != nullptr)
	{
		push(destination, source2.head->data); // ����������� �������� �������� �� ������������� ������� � �����������
		pop(source2); // ������� � ���������� �������� � ������������� ������� 
	}
	cout << "Queue with removed key: ";
	printLine(destination);
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
	for (int i = 0; i < k; i++)
	{
		cout << i + 1 << "). ";
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
	cout << "Queue size: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << i << "). ";
		cin >> a;
		push(line, a);
	}
	cout << "\n";

	cout << "Source queue: ";
	printLine(line);
	cout << "\n\n";

	cout << "Delete key: ";
	cin >> key;
	delete_key(line, line1, line2, key);
	copy_line1(line1, line2, line);
	cout << "\n\n";

	
	cout << "The number of the element to replace with new elements: ";
	cin >> m;
	add_elem(line, line1, line2, line3, n, m);
	copy_line2(line1, line2, line3, line);
	cout << "\n\n";
	
	return 0;
}
