#include <bits/stdc++.h>
#define int long long int

using namespace std;

int n, N = 1, q;
vector <int> tree;

void add(int k, int u)
{
    if(k > N-1) return;
    k += N;
    tree[k] += u; k /= 2;
    while(k >= 1)
    {
        tree[k] = tree[2*k]+tree[2*k+1];
        k /= 2;
    }
}

int sum(int b)
{
    int a = N; b += N;
    int s = 0;
    while(a <= b)
    {
        if(a % 2 == 1) s += tree[a++];
        if(b % 2 == 0) s += tree[b--];
        a /= 2; b /= 2;
    }
    return s;
}

void init()
{
    cin >> n >> q;
    while(N < n) N *= 2;
    tree.resize(2*N, 0);

    int prev = 0;
    for(int i = 0; i < n; i++)
    {
        int k; cin >> k;
        add(i, k-prev);
        prev = k;
    }
    //for(auto x : tree) cout << x << " ";
}

int32_t main()
{
    init();

    while(q--)
    {
        int x; cin >> x;
        if(x == 1)
        {
            int a, b, c; cin >> a >> b >> c;
            add(a-1, c);
            add(b, -c);
        }
        else
        {
            int k; cin >> k;
            cout << sum(k-1) << endl;
        }
    }

    return 0;
}
