#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <ctime>
#include "Pair.h"
using namespace std;

typedef multimap<int, Pair> TMM;
typedef TMM::iterator it;

struct mean
{
    void operator()(pair<int, Pair> p)
    {
        ++n;
        s_f += p.second.get_first();
        s_s += p.second.get_second();
    }
    Pair get_result() { return Pair(s_f / n, s_s / n); }
private:
    int n{ 0 };
    int s_f{ 0 };
    double s_s{ 0 };
};

TMM make_multimap(int n)
{
    srand(time(0));
    TMM mm;
    Pair p;
    int a;
    for (int i = 0; i < n; ++i)
    {
        a = (int)rand() % 100;
        p.random();
        mm.insert(make_pair(a, p));
    }
    return mm;
}

void print_multimap(TMM mm)
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
    int min_index = it->first;
    Pair min_key = it->second;
    for (; it != mm.end(); it++)
    {
        if (min_key > it->second)
        {
            min_index = it->first;
            min_key = it->second;
        }
    }
    cout << "Min (key): [" << min_index << " - " << min_key << "]";
    cout << "\n";
    cout << "Index at which to insert the minimum element: ";
    int pos;
    cin >> pos;
    mm.insert(make_pair(pos, min_key));
}

void delete_less_average(TMM& mm)
{

    mean mpos = for_each(mm.begin(), mm.end(), mean());
    Pair avg_key = mpos.get_result();
    cout << "Avg (key): " << avg_key;
    cout << "\n";
    
    for (it it = mm.begin(); it != mm.end();)
    {
        if (it->second < avg_key)
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
    int max_index = i->first;
    Pair max_key = i->second;
    for (; i != mm.end(); i++)
    {
        if (max_key < i->second)
        {
            max_index = i->first;
            max_key = i->second;
        }
    }
    cout << "Max (key): [" << max_index << " - " << max_key << "]";
    cout << "\n";
    for_each(mm.begin(), mm.end(), [max_key](pair<const int, Pair>& p) { p.second = p.second / max_key; });
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
    print_multimap(mm);
    cout << "\n";

    add_min(mm);
    cout << "Container after adding the minimum element:";
    cout << "\n";
    print_multimap(mm);
    cout << "\n";
           
    delete_less_average(mm); 
    cout << "Container after removing elements smaller than average:";
    cout << "\n";
    print_multimap(mm);
    cout << "\n";
    
    divide_by_max(mm);
    cout << "Container after dividing all elements by the maximum:";
    cout << "\n";
    print_multimap(mm);
    cout << "\n";
     
    return 0;
}