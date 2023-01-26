#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>

int n, m;
vector <int> sal;
ordered_set s;

int findLess(int u)
{
    return s.order_of_key(make_pair(u, INT_MAX));
}

int findRange(int a, int b)
{
    return findLess(b) - findLess(a-1);
}

void update(int k, int x)
{
    auto p = s.lower_bound(make_pair(sal[k], k));
    s.erase(p);
    s.insert(make_pair(x, k));
    sal[k] = x;
}

void init()
{
    cin >> n >> m;
    sal.resize(n+1, 0);
    for(int i = 1; i <= n; i++)
    {
        cin >> sal[i];
        s.insert(make_pair(sal[i], i));
    }
}

int main()
{
    init();
    while(m--)
    {
        char x; cin >> x;
        if(x == '!')
        {
            int k, x; cin >> k >> x;
            update(k, x);
        }
        else
        {
            int a, b; cin >> a >> b;
            cout << findRange(a, b) << endl;
        }
    }
    return 0;
}
