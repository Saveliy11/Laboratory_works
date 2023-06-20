#include <iostream>
#include "fraction.h"
using namespace std;

void fraction::Init(int F, float S)
{
	first = F; second = S;
}

double fraction::multiply(int k)
{
	return ((first + second) * k);
}