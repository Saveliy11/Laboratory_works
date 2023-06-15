#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

struct Node
{
	int key;
	Node* next;
};

struct LinkedList
{
	Node* head; // ��������� �� ������ ������
	Node* tail; // ��������� �� ����� ������

	// �����������
	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}
};

// ������� ��� ���������� �������� � ����� ������
void addNode(LinkedList& list, const int& value)
{
	Node* newNode = new Node;
	newNode->key = value;
	newNode->next = nullptr;

	if (list.head == nullptr) // ���� ������ ������, ����� ������� ���������� �������� � ���������
	{
		list.head = newNode;
		list.tail = newNode;
	}
	else
	{
		list.tail->next = newNode; // ��������� ����� ������� ����� �������� ���������� ��������
		list.tail = newNode; // ��������� ��������� �� ��������� �������
	}
}

// ������� ��� ������ ������
void print_list(Node* beg)
{
	if (beg == nullptr) // ���� ������ ������
	{
		cout << "List is empty" << endl;
		return;
	}

	cout << "Source list: ";
	Node* p = beg;
	while (p != nullptr) // ���� �� ����� ������
	{
		cout << p->key << ' ';
		p = p->next; // ������� �� ��������� �������
	}
	cout << endl;
}

// ������� ��� �������� ���� 
Node* del_Node(Node* beg, int k)
{
	setlocale(0, "ru");
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

	if (p == nullptr || p->next == nullptr)
	{
		return beg;
	}

	Node* r = p->next; // ������ �� ��������� �������
	p->next = r->next; // �������� ������
	delete r;
	r = p->next; // ������ �� ���������
	return beg;
}

// ������� ��� ���������� ��������
void add_Node(LinkedList& list, int k, const int& value)
{
	setlocale(0, "ru");
	k--;

	Node* p = new Node;
	p->key = value;

	if (k == 0)
	{
		p->next = list.head; // �������� ����� �������� ���������
		list.head = p; // �������� ��������� �� �������� �������
		return;
	}

	Node* r = list.head; // ������ �� ������ ������
	for (int i = 0; i < k - 1 && r->next != nullptr; i++, r = r->next);
	p->next = r->next; // ������� r � ������ ������

	// ���� ������� �� ���������, �� ������� ����� ������ � r
	if (r->next == nullptr) p->next = nullptr;
	r->next = p;
}

Node* delete_list(Node* beg)
{
	setlocale(0, "ru");
	Node* p = beg;
	int counter = 0; // �������� ��������� �������� counter �� 0
	while (p != nullptr) // �������� ������� ����� �� p != nullptr
	{
		p = p->next;
		counter++;
	}
	for (int i = counter; i > 1; i--)
	{
		beg = del_Node(beg, i); // ���������� ������� del_Node() ��� �������� ����� 
	}
	beg = del_Node(beg, 1); // ������� ������ ����
	return beg;
}

void printINfile(Node* beg, string path)
{
	setlocale(0, "ru");
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
	{
		cout << "Error!" << endl;
	}
	else
	{
		cout << "Information added to file" << endl;
		Node* p = beg;
		while (p != nullptr)
		{
			fout << p->key;
			fout << "\n";
			p = p->next;
		}
	}
	fout.close();
}

//������� ��� �������������� ������ �� �����
Node* readFROMfile(string path)
{
	setlocale(0, "ru");
	ifstream fin;
	fin.open(path);
	Node* beg = nullptr;
	if (!fin.is_open())
	{
		cout << "Error!" << endl;
	}
	else
	{
		cout << "Information has been restored from a file" << endl;
		int word;
		Node* p = nullptr;
		Node* r = nullptr;
		fin >> word;
		while (!fin.eof())
		{
			if (p == nullptr)
			{
				p = new(Node);
				p->key = word;
				p->next = nullptr;
				beg = p;
			}
			else
			{
				r = new(Node);
				r->key = word;
				p->next = r;
				r->next = nullptr;
				p = r;
			}
			fin >> word;
		}
	}
	fin.close();
	return beg;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int c;
	int value;
	LinkedList list; // ������� ��������� �������� ������
	cout << "Number of list items: ";
	cin >> c;
	for (int i = 1; i <= c; i++)
	{
		cout << i << "-th element of the list: ";
		cin >> value;
		addNode(list, value);
	}

	Node* first = list.head; // ������������� ������ ������ �� �������� �������
	print_list(first); // ������� ������ �� �����

	cout << "Number of items to be removed: ";
	int b;
	cin >> b;
	for (int i = 0; i < b; i++)
	{
		cout << i + 1 << "-th:";
		cout << "\tThe number of the element to be removed: ";
		int k;
		cin >> k;
		first = del_Node(first, k); //������� ������� �� ������
	}

	print_list(first); // ������� ����������� ������ �� �����

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
		int add;
		cin >> add;
		add_Node(list, k, add); // ��������� �������
	}

	print_list(list.head); // ������� ����������� ������ �� �����
	cout << endl;
	printINfile(first, "output.txt");
	list.head = delete_list(first);
	cout << "List removed: ";
	print_list(list.head);
	Node* recovery = readFROMfile("output.txt");
	list.head = recovery;
	print_list(list.head);
	return 0;
}