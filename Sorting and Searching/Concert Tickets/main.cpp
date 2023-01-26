#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    int n , m;
    cin >> n >> m;

    multiset <int> v;
    int p[m];

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.insert(temp);
    }
    for(int i = 0; i < m; i++)
    {
        cin >> p[i];
    }

    //sort(v.begin(), v.end());


    for(int per = 0; per < m; per++)
    {
        auto i = v.upper_bound(p[per]);
        if(i == v.begin() || v.size()==0)
        {
            cout << -1 << "\n";
            continue;
        }
        i--;
        cout << *i << "\n";
        v.erase(i);

    }

    return 0;
}
