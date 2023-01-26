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
        tree[k] = (tree[2*k] ^ tree[2*k+1]);
        k /= 2;
    }
}

int ask(int a, int b)
{
    a += N; b += N;
    int s = 0;
    while(a <= b)
    {
        if(a % 2 == 1) s ^= tree[a++];
        if(b % 2 == 0) s ^= tree[b--];
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
    tree.resize(2*N, 0);

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
        int a, b; cin >> a >> b;
        cout << ask(a,b) << endl;
    }

    return 0;
}
