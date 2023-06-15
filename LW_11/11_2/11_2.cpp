#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

struct Node
{
	string key;
	Node* next;
	Node* prev; //Указатель на предыдущий элемент
};

struct LinkedList
{
	Node* head; //Указатель на начало списка
	Node* tail; //Указатель на конец списка
	// Конструктор
	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}
};

//Функция для добавления элемента в конец списка
void addNode(LinkedList& list, const string& value)
{
	Node* newNode = new Node;
	newNode->key = value;
	newNode->next = nullptr;
	newNode->prev = nullptr; //Инициализируем указатель на предыдущий элемент

	if (list.head == nullptr) //Если список пустой, новый элемент становится головным и хвостовым
	{
		list.head = newNode;
		list.tail = newNode;
	}
	else
	{
		newNode->prev = list.tail; //Указываем на предыдущий элемент
		list.tail->next = newNode; //Добавляем новый элемент после текущего хвостового элемента
		list.tail = newNode; //Обновляем указатель на хвостовой элемент
	}
}

//Функция для вывода списка
void print_list(Node* beg)
{
	if (beg == nullptr) //Если список пустой
	{
		cout << "List is empty" << endl;
		return;
	}

	cout << "Source list: ";
	Node* p = beg;
	while (p != nullptr) //Пока не конец списка
	{
		cout << p->key << ' ';
		p = p->next; //Перейти на следующий элемент
	}
	cout << endl;
}

//Функция для удаления узла
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

	Node* r = p->next; //Встать на удаляемый элемент
	p->next = r->next; //Изменить ссылку

	if (r->next != nullptr) //Если удаляемый элемент не последний
		r->next->prev = p; //Обновляем указатель на предыдущий элемент

	delete r;
	r = p->next; //Встать на следующий
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
		p->next = list.head; //Добавить перед головным элементом
		if (list.head != nullptr) {
			list.head->prev = p; //Установить указатель на предыдущий элемент для головного элемента
		}
		list.head = p; //Обновить указатель на головной элемент
		return;
	}

	Node* r = list.head; //Встать на начало списка
	for (int i = 0; i < k - 1 && r != nullptr; i++, r = r->next);
	if (r == nullptr) {
		cout << "The specified index is out of range" << endl;
		return;
	}
	p->next = r->next; //Связать r с концом списка
	p->prev = r; //Связать p с r в обратном направлении
	if (r->next != nullptr) {
		r->next->prev = p; //Установить указатель на предыдущий элемент для следующего элемента после r
	}
	r->next = p;
}


//Функция для удаления списка
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
		beg = del_Node(beg, i); //Используем функцию del_Node() для удаления узлов
	}
	beg = del_Node(beg, 1); //Удаляем первый узел
	return beg;
}

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int c;
	string value;
	LinkedList list; //Создаем экземпляр связного списка
	cout << "Number of list items: ";
	cin >> c;
	for (int i = 1; i <= c; i++)
	{
		cout << i << "-th element of list: ";
		cin >> value;
		addNode(list, value);
	}

	Node* first = list.head; //Устанавливаем начало списка на головной элемент
	print_list(first); //Выводим список на экран

	cout << "Number of items to be removed: ";
	int b;
	cin >> b;
	for (int i = 0; i < b; i++)
	{
		cout << i + 1 << "-th:";
		cout << "\tThe number of the element to be removed: ";
		int n;
		cin >> n;
		first = del_Node(first, n); //Удаляем элемент из списка
	}

	print_list(first); //Выводим обновленный список на экран

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
		add_Node(list, k, add); // Добавляем элемент
	}

	print_list(list.head); //Выводим обновленный список на экран
	cout << endl;
	return 0;
}