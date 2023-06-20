#include "ATM.h"
#include <iostream>
using namespace std;

//конструктор без параметров
ATM::ATM()
{
	number = 0;
	balance = 0;
	maxAmount = 0;
	cout << "Constructor with no parameters for an object" << endl;
}

//конструктор с параметрами
ATM::ATM(int N, double B, double M)
{
	number = N;
	balance = B;
	maxAmount = M;
	cout << "Constructor with parameters for an object" << endl;
}

//конструктор копирования
ATM::ATM(const ATM& t)
{
	number = t.number;
	balance = t.balance;
	maxAmount = t.maxAmount;
	cout << "Copy constructor for an object" << endl;
}

//деструктор
ATM::~ATM()
{
	cout << "Destructor for an object" << endl;
}

//селекторы
int ATM::get_number()
{
	return number;
}
double ATM::get_balance()
{
	return balance;
}
double ATM::get_maxAmount()
{
	return maxAmount;
}

//модификаторы
void ATM::set_number(int N)
{
	number = N;
}
void ATM::set_balance(double B)
{
	balance = B;
}
void ATM::set_maxAmount(double M)
{
	maxAmount = M;
}

//метод для просмотра атрибутов
void ATM::show()
{
	cout << "Number: " << number << endl;
	cout << "Balance: " << balance << endl;
	cout << "MaxAmount: " << maxAmount << endl;
}