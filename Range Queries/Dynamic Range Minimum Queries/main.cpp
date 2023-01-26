#include <bits/stdc++.h>
#define int long long int

using namespace std;

int n, N, q;
vector <int> tree;

void update(int k, int u)
{
    k += N;
    tree[k] = u;
    k /= 2;
    while(k >= 1)
    {
        tree[k] = min(tree[2*k], tree[2*k+1]);
        k /= 2;
    }
}

int ask(int a, int b)
{
    a += N; b += N;
    int s = tree[a];
    while(a <= b)
    {
        if(a % 2 == 1) s = min(s, tree[a++]);
        if(b % 2 == 0) s = min(s, tree[b--]);
        a /= 2; b /= 2;
    }

    return s;
}

void makeN()
{
    N = 1;
    while(N <= n) N *= 2;
}

void init()
{
    cin >> n >> q;
    makeN();
    tree.resize(2*N, LLONG_MAX);

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
        int a, b, c; cin >> a >> b >> c;
        if(a == 1) update(b, c);
        else cout << ask(b, c) << endl;
    }

    return 0;
}
