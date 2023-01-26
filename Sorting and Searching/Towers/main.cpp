#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    int n; cin >> n;
    multiset <int> s;
    for(int i = 0; i < n; i++)
    {
        int k;
        scanf("%d", &k);
        auto t = s.upper_bound(k);
        if(t != s.end()) s.erase(t);
        s.insert(k);
    }

    cout << s.size();

    return 0;
}
