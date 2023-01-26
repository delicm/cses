#include <iostream>
#include <set>

using namespace std;

int main()
{
    int x, n, k; cin >> x >> n;
    set <int> a;
    a.insert(x); a.insert(0);
    multiset <int> s;
    s.insert(x);


    while(n--)
    {
        cin >> k;
        auto i = a.lower_bound(k);
        auto j = i;
        --j;

        s.erase(s.find(*i-*j));
        s.insert(*i-k);
        s.insert(k-*j);
        cout << *--s.end() << " ";
        a.insert(k);
    }



    return 0;
}
