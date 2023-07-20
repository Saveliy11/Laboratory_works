#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include "Pair.h"
using namespace std;

typedef queue<Pair> Queue;
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


Queue make_queue(int n)
{
    Queue q;
    Pair p;
    for (int i = 0; i < n; ++i)
    {
        cout << i + 1 << "). ";
        cin >> p;
        q.push(p);
    }
    return q;
}

Vector copy_queue_to_vector(Queue q)
{
    Vector v;
    while (!q.empty())
    {
        v.push_back(q.front());
        q.pop();
    }
    return v;
}

Queue copy_Vector_to_queue(Vector v)
{
    Queue q;
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        q.push(*it);
    }
    return q;
}

void print_queue(Queue q)
{
    int k = 1;
    while (!q.empty())
    {
        cout << k++ << "). " << q.front() << endl;
        q.pop();
    }
}

int main()
{

    setlocale(LC_ALL, "RUS");
    int n;
    cout << "Queue size: ";
    cin >> n;
    cout << "\n";

    Queue q = make_queue(n);
    cout << "\n";

    cout << "Source queue:";
    cout << "\n";
    print_queue(q);
    cout << "\n";

    Vector v = copy_queue_to_vector(q);
    auto min = min_element(v.begin(), v.end());
    cout << "Min: " << *min;
    cout << "\n";
    cout << "Index at which to insert the minimum element: ";
    int pos;
    cin >> pos;
    v.insert(v.begin() + pos - 1, *min);
    cout << "Queue after adding the minimum element:";
    cout << "\n";
    q = copy_Vector_to_queue(v);
    print_queue(q);
    cout << "\n";

    mean m = for_each(v.begin(), v.end(), mean());
    Pair res_1 = m.get_result();
    cout << "Avg: " << res_1;
    cout << "\n";
    cout << "Queue after removing elements smaller than average:";
    cout << "\n";
    v = copy_queue_to_vector(q);
    auto result = remove_if(v.begin(), v.end(), [res_1](const Pair& p) { return (res_1 > p); });
    v.erase(result, v.end());
    q = copy_Vector_to_queue(v);
    print_queue(q);
    cout << "\n";

    v = copy_queue_to_vector(q);
    auto max = max_element(v.begin(), v.end());
    cout << "Max: " << *max;
    cout << "\n";
    Pair res_2 = *max;
    for_each(v.begin(), v.end(), [res_2](Pair& p) { p = p / res_2; });
    cout << "Vector after dividing all elements by the maximum:";
    cout << "\n";
    q = copy_Vector_to_queue(v);
    print_queue(q);
    cout << "\n";

    return 0;
}