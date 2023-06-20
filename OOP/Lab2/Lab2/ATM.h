#include <iostream>
using namespace std;

class ATM
{
	int number;
	double balance;
	double maxAmount;
public:
	ATM();
	ATM(int, double, double);
	ATM(const ATM&);
	~ATM();

	int get_number();
	//void set_numder(int);
	void set_number(int N);

	double get_balance();
	void set_balance(double);

	double get_maxAmount();
	void set_maxAmount(double);

	void show();
};
