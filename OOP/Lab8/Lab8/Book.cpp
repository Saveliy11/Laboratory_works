#include "Book.h"

Book::Book(void) :Print()
{
	Pages = 0;
	Publisher = "";
}

Book::~Book(void)
{
}

Book::Book(string N, string A, int M, string P) :Print(N, A)
{
	Publisher = P;
	Pages = M;
}

Book::Book(const Book& T)
{
	Name = T.Name;
	Author = T.Author;
	Publisher = T.Publisher;
	Pages = T.Pages;
}

void Book::Set_Publisher(string P)
{
	Publisher = P;
}

void Book::Set_Pages(int M)
{
	Pages = M;
}

Book& Book::operator=(const Book& t)
{
	if (&t == this)
	{
		return *this;
	}
	Name = t.Name;
	Author = t.Author;
	Publisher = t.Publisher;
	Pages = t.Pages;
	return *this;
}

/*
// увелечение часов
Book& Book::operator+(const Book&)
{
	int value;
	cin >> value;
	Pages = Pages + value;
	return ; //...
}
// уменьшение часов
Book& Book::operator-(const Book&)
{
	int value;
	cin >> value;
	Pages = Pages - value;
	return 0; //...?
}
*/

istream& operator>>(istream& in, Book& t)
{
	cout << "Name: "; in >> t.Name;
	cout << "Author: ";in >> t.Author;
	cout << "Publisher: ";in >> t.Publisher;
	cout << "Pages: ";in >> t.Pages;
	return in;
}

ostream& operator<<(ostream& out, const Book& t)
{
	out << "\nName: " << t.Name;
	out << "\nAuthor: " << t.Author;
	out << "\nPublisher: " << t.Publisher;
	out << "\nPages: " << t.Pages;
	out << "\n";
	return out;
}

void Book::Show()
{
	cout << "\nName: " << Name;
	cout << "\nAuthor: " << Author;
	cout << "\nPublisher: " << Publisher;
	cout << "\nPages: " << Pages;
	cout << "\n";
}

void Book::Input()
{
	cout << "\nName: ";
	cin >> Name;
	cout << "\nAuthor: ";
	cin >> Author;
	cout << "\nPublisher: ";
	cin >> Publisher;
	cout << "\nPages: ";
	cin >> Pages;
	cout << "\n";
}