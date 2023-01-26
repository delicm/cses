#include <bits/stdc++.h>
#define int long long int

using namespace std;

int n, q;
vector <int> a;
vector <int> tree;

int sum(int k)
{
    if(k == 0) return 0;
    int s = 0;
    while(k >= 1)
    {
        s += tree[k];
        k -= k & -k;
    }
    return s;
}

void update(int k, int x)
{
    int add = x-a[k];
    a[k] = x;
    while(k <= n)
    {
        tree[k] += add;
        k += k & -k;
    }
}

int range(int a, int b)
{
    return sum(b) - sum(a-1);
}

void init()
{
    cin >> n >> q;
    a.resize(n+1, 0);
    tree.resize(n+1, 0);

    for(int i = 1; i <= n; i++)
    {
        int k; cin >> k;
        update(i, k);
    }
}

int32_t main()
{
    init();
    while(q--)
    {
        int x, y, z; cin >> x >> y >> z;
        if(x == 1) update(y, z);
        else cout << range(y, z) << endl;
    }

    return 0;
}
