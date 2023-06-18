#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

struct Node
{
	string key;
	Node* next;
};

struct LinkedList
{
	Node* head; // указатель на начало списка
	Node* tail; // указатель на конец списка
	// Конструктор
	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}
};

// Функция для добавления элемента в конец списка
void addNode(LinkedList& list, const string& value)
{
	Node* newNode = new Node;
	newNode->key = value;
	newNode->next = nullptr;

	if (list.head == nullptr) // если список пустой, новый элемент становится головным и хвостовым
	{
		list.head = newNode;
		list.tail = newNode;
	}
	else
	{
		list.tail->next = newNode; // добавляем новый элемент после текущего хвостового элемента
		list.tail = newNode; // обновляем указатель на хвостовой элемент
	}
}

// Функция для вывода списка
void print_list(Node* beg)
{
	if (beg == nullptr) //Если список пустой
	{
		cout << "List is empty" << endl;
		return;
	}
	Node* p = beg;
	while (p != nullptr) //Пока не конец списка
	{
		cout << "(" << p->key << ")" << ' ';
		p = p->next; //Перейти на следующий элемент
	}
}

// Функция для удаления узла 
Node* del_Node(Node* beg, int k)
{
	k--;
	Node* p = beg;
	if (k == 0)
	{
		beg = beg->next;
		if (beg == nullptr)
		{
			return nullptr;
		}
		delete p;
		return beg;
	}
	for (int i = 0; i < k - 1 && p != nullptr; i++, p = p->next);
	if (p == nullptr || p->next == nullptr)
	{
		return beg;
	}
	Node* r = p->next; // встать на удаляемый элемент
	p->next = r->next; // изменить ссылку
	delete r;
	r = p->next; // встать на следующий
	return beg;
}

// Функция для добавления элемента
void add_Node(LinkedList& list, int k, string& value)
{
	k--;
	Node* p = new Node;
	p->key = value;
	if (k == 0)
	{
		p->next = list.head; // добавить перед головным элементом
		list.head = p; // обновить указатель на головной элемент
		return;
	}
	Node* r = list.head; // встать на начало списка
	for (int i = 0; i < k - 1 && r->next != nullptr; i++, r = r->next);
	p->next = r->next; // связать r с концом списка
	// если элемент не последний, то связать конец списка с r
	if (r->next == nullptr)
	{
		p->next = nullptr;
	}
	r->next = p;
}

Node* delete_list(Node* beg)
{
	Node* p = beg;
	int counter = 0; // Изменяем начальное значение counter на 0
	while (p != nullptr) // Изменяем условие цикла на p != nullptr
	{
		p = p->next;
		counter++;
	}
	for (int i = counter; i > 1; i--)
	{
		beg = del_Node(beg, i); // Используем функцию del_Node() для удаления узлов 
	}
	beg = del_Node(beg, 1); // Удаляем первый узел
	return beg;
}

void printINfile(Node* beg, string path)
{
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

//Функция для восстановления списка из файла
Node* readFROMfile(string path)
{
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
	string value;
	LinkedList list; // Создаем экземпляр связного списка
	cout << "List size: ";
	cin >> c;
	for (int i = 1; i <= c; i++)
	{
		cout << i << "). ";
		cin >> value;
		addNode(list, value);
	}
	cout << "\n";

	cout << "Source list: ";
	Node* first = list.head; // Устанавливаем начало списка на головной элемент
	print_list(first); // Выводим список на экран
	cout << "\n\n";

	cout << "Number of items to be removed: ";
	int b;
	cin >> b;
	for (int i = 0; i < b; i++)
	{
		cout << i + 1 << "). ";
		cout << "The number of the element to be removed: ";
		int k;
		cin >> k;
		first = del_Node(first, k); //Удаляем элемент из списка
	}
	cout << "List after removing: ";
	print_list(first); // Выводим обновленный список на экран
	cout << "\n\n";

	cout << "Number of elements to add: ";
	int d;
	cin >> d;
	for (int i = 0; i < d; i++)
	{
		cout << i + 1 << "). ";
		cout << "The element number to replace the new element with: ";
		int q;
		cin >> q;
		cout << "    ";
		cout << "Element to be added: ";
		string add;
		cin >> add;
		add_Node(list, q, add); // Добавляем элемент
	}
	cout << "List after adding: ";
	print_list(list.head); // Выводим обновленный список на экран
	cout << "\n\n";

	printINfile(first, "output.txt");
	cout << "\n";

	list.head = delete_list(first);
	cout << "List removed: ";
	print_list(list.head);
	cout << "\n";

	Node* recovery = readFROMfile("output.txt");
	list.head = recovery;
	cout << "Restored list: ";
	print_list(list.head);
	cout << "\n\n";

	return 0;
}