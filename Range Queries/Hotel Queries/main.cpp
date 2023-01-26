#include <bits/stdc++.h>

using namespace std;

int n, N = 1, m;
vector <int> tree;

void update(int k, int u)
{
    k += N;
    tree[k] = u; k /= 2;
    while(k >= 1)
    {
        tree[k] = max(tree[2*k], tree[2*k+1]);
        k /= 2;
    }
}

int first(int guest)
{
    if(tree[1] < guest) return 0;
    int i = 1;
    while(i < N)
    {
        if(tree[2*i] >= guest) i *= 2;
        else i = 2*i+1;
    }
    update(i-N, tree[i]-guest);
    return i-N+1;
}

void init()
{
    cin >> n >> m;
    while(N < n) N *= 2;
    tree.resize(2*N, INT_MIN);

    for(int i = 0; i < n; i++)
    {
        int k; cin >> k;
        update(i, k);
    }
}

int main()
{
    init();

    while(m--)
    {
        int k; cin >> k;
        cout << first(k) << endl;
    }

    return 0;
}
