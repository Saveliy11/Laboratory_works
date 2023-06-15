#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

struct Node
{
	string key;
	Node* next;
	Node* prev; //��������� �� ���������� �������
};

struct LinkedList
{
	Node* head; //��������� �� ������ ������
	Node* tail; //��������� �� ����� ������
	// �����������
	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}
};

//������� ��� ���������� �������� � ����� ������
void addNode(LinkedList& list, const string& value)
{
	Node* newNode = new Node;
	newNode->key = value;
	newNode->next = nullptr;
	newNode->prev = nullptr; //�������������� ��������� �� ���������� �������

	if (list.head == nullptr) //���� ������ ������, ����� ������� ���������� �������� � ���������
	{
		list.head = newNode;
		list.tail = newNode;
	}
	else
	{
		newNode->prev = list.tail; //��������� �� ���������� �������
		list.tail->next = newNode; //��������� ����� ������� ����� �������� ���������� ��������
		list.tail = newNode; //��������� ��������� �� ��������� �������
	}
}

//������� ��� ������ ������
void print_list(Node* beg)
{
	if (beg == nullptr) //���� ������ ������
	{
		cout << "List is empty" << endl;
		return;
	}

	cout << "Source list: ";
	Node* p = beg;
	while (p != nullptr) //���� �� ����� ������
	{
		cout << p->key << ' ';
		p = p->next; //������� �� ��������� �������
	}
	cout << endl;
}

//������� ��� �������� ����
Node* del_Node(Node* beg, int k)
{
	setlocale(LC_ALL, "RUS");
	k--;
	Node* p = beg;

	if (k == 0)
	{
		beg = beg->next;
		if (beg == nullptr) return nullptr;
		delete p;
		return beg;
	}

	for (int i = 0; i < k - 1 && p != nullptr; i++, p = p->next);

	if (p == nullptr || p->next == nullptr) return beg;

	Node* r = p->next; //������ �� ��������� �������
	p->next = r->next; //�������� ������

	if (r->next != nullptr) //���� ��������� ������� �� ���������
		r->next->prev = p; //��������� ��������� �� ���������� �������

	delete r;
	r = p->next; //������ �� ���������
	return beg;
}

void add_Node(LinkedList& list, int k, const string& value)
{
	setlocale(LC_ALL, "RUS");
	k--;

	Node* p = new Node;
	p->key = value;

	if (k == 0)
	{
		p->next = list.head; //�������� ����� �������� ���������
		if (list.head != nullptr) {
			list.head->prev = p; //���������� ��������� �� ���������� ������� ��� ��������� ��������
		}
		list.head = p; //�������� ��������� �� �������� �������
		return;
	}

	Node* r = list.head; //������ �� ������ ������
	for (int i = 0; i < k - 1 && r != nullptr; i++, r = r->next);
	if (r == nullptr) {
		cout << "The specified index is out of range" << endl;
		return;
	}
	p->next = r->next; //������� r � ������ ������
	p->prev = r; //������� p � r � �������� �����������
	if (r->next != nullptr) {
		r->next->prev = p; //���������� ��������� �� ���������� ������� ��� ���������� �������� ����� r
	}
	r->next = p;
}


//������� ��� �������� ������
Node* delete_list(Node* beg)
{
	setlocale(LC_ALL, "RUS");
	Node* p = beg;
	int counter = 0;
	while (p != nullptr)
	{
		p = p->next;
		counter++;
	}
	for (int i = counter; i > 1; i--)
	{
		beg = del_Node(beg, i); //���������� ������� del_Node() ��� �������� �����
	}
	beg = del_Node(beg, 1); //������� ������ ����
	return beg;
}

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int c;
	string value;
	LinkedList list; //������� ��������� �������� ������
	cout << "Number of list items: ";
	cin >> c;
	for (int i = 1; i <= c; i++)
	{
		cout << i << "-th element of list: ";
		cin >> value;
		addNode(list, value);
	}

	Node* first = list.head; //������������� ������ ������ �� �������� �������
	print_list(first); //������� ������ �� �����

	cout << "Number of items to be removed: ";
	int b;
	cin >> b;
	for (int i = 0; i < b; i++)
	{
		cout << i + 1 << "-th:";
		cout << "\tThe number of the element to be removed: ";
		int n;
		cin >> n;
		first = del_Node(first, n); //������� ������� �� ������
	}

	print_list(first); //������� ����������� ������ �� �����

	cout << "Number of elements to add: ";
	int d;
	cin >> d;
	for (int i = 0; i < d; i++)
	{
		cout << i + 1 << "-th:";
		cout << "\tThe element number to replace the new element with: ";
		int k;
		cin >> k;
		cout << "\tElement to be added: ";
		string add;
		cin >> add;
		add_Node(list, k, add); // ��������� �������
	}

	print_list(list.head); //������� ����������� ������ �� �����
	cout << endl;
	return 0;
}