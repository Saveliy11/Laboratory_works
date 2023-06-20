#include <iostream>
#include <map>
#include <ctime>
#include "Pair.h"
using namespace std;

typedef multimap<int, Pair> TMM;
typedef TMM::iterator it;

TMM make_multimap(int n)
{
    srand(time(0));
    TMM mm;
    Pair P;
    int a;
    for (int i = 0; i < n; i++)
    {
        a = (int)rand() % 100;
        P.random();
        mm.insert(make_pair(a, P));
    }
    return mm;
}

void print(TMM& mm)
{
    int k = 1;
    for (const auto& pair : mm)
    {
        cout << k++ << "). " << pair.first << " - " << pair.second << endl;
    }
}

void add_min(TMM& mm)
{

    it it = mm.begin();
    Pair min = it->second;

    for (; it != mm.end(); it++)
    {
        if (min > it->second)
        {
            min = it->second;
        }
    }
    cout << "Index at which to insert the minimum element: ";
    int pos;
    cin >> pos;
    mm.insert(make_pair(pos, min));
}

void delete_less_average(TMM& mm)
{
    
    Pair sum;
    int n = mm.size();
    for (const auto& pair : mm)
    {
        sum = sum + pair.second;
    }
    Pair avg = sum / mm.size();
    for (it it = mm.begin(); it != mm.end();)
    {
        if (it->second < avg)
        {
            it = mm.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void divide_by_max(TMM& mm)
{
    it i = mm.begin();
    Pair max = i->second;

    for (; i != mm.end(); i++)
    {
        if (max < i->second)
        {
            max = i->second;
        }
    }
    TMM mm_1;
    for (auto& pair : mm)
    {
        Pair value = pair.second / max;
        mm_1.insert(make_pair(pair.first, value));
    }
    mm = mm_1;
}

int main()
{
    int n;
    cout << "Container size: ";
    cin >> n;
    cout << "\n";

    TMM mm = make_multimap(n);

    cout << "Source container:";
    cout << "\n";
    print(mm);
    cout << "\n";

    add_min(mm);
    cout << "Container after adding the minimum element:";
    cout << "\n";
    print(mm);
    cout << "\n";

    delete_less_average(mm);
    cout << "Container after removing elements smaller than average:";
    cout << "\n";
    print(mm);
    cout << "\n";

    divide_by_max(mm);
    cout << "Container after dividing all elements by the maximum:";
    cout << "\n";
    print(mm);
    cout << "\n";

    return 0;
}
