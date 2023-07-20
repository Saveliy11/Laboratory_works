#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "Pair.h"
using namespace std;

typedef vector<Pair> Vector;

struct mean
{
    void operator()(Pair p)
    {
        ++n;
        s_f += p.get_first();
        s_s += p.get_second();
    }
    Pair get_result() { return Pair(s_f / n, s_s / n); }
private:
    int n{ 0 };
    int s_f{ 0 };
    double s_s{ 0 };
};

Vector make_list(int n)
{
    Vector v;
    random_device rd;
    default_random_engine eng(rd());
    uniform_real_distribution<double> distr(0, 100);
    for (int i = 0; i < n; ++i)
    {
        Pair p;
        p.set_first(distr(eng));
        p.set_second(distr(eng));
        v.push_back(p);
    }
    return v;
}

void print_list(Vector v)
{
    int k = 1;
    for (auto i : v)
    {
        cout << k++ << "). " << i << endl;
    }
}

int main()
{

    Vector v;
    int n;
    cout << "Vector size: ";
    cin >> n;
    cout << "\n";
    
    cout << "Source vector:";
    cout << "\n";
    v = make_list(n);
    print_list(v);
    cout << "\n";

    auto min = min_element(v.begin(), v.end());
    cout << "min: " << *min;
    cout << "\n";
    cout << "Index at which to insert the minimum element: ";
    int d;
    cin >> d;
    auto li = v.begin();
    advance(li, d-1);
    v.insert(li, *min);
    cout << "Vector after adding the minimum element:";
    cout << "\n";
    print_list(v);
    cout << "\n";

    mean m = for_each(v.begin(), v.end(), mean());
    Pair res_1 = m.get_result();
    cout << "avg: " << res_1;
    cout << "\n";
    cout << "Vector after removing elements smaller than average:";
    cout << "\n";
    auto result = remove_if(v.begin(), v.end(), [res_1](const Pair &p) { return (res_1 > p); });
    v.erase(result, v.end());
    print_list(v);
    cout << "\n";
    
    auto max = max_element(v.begin(), v.end());
    cout << "max: " << *max;
    cout << "\n";
    Pair res_2 = *max;
    for_each(v.begin(), v.end(), [res_2](Pair& p){ p = p / res_2; });
    cout << "Vector after dividing all elements by the maximum:";
    cout << "\n";
    print_list(v);
    cout << "\n";

    return 0;
}
