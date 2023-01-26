#include <bits/stdc++.h>
#define int long long int

using namespace std;

int n, m;
vector <vector <int>> tree;

int sum(int a, int k)
{
    int sol = 0;
    while(a >= 1){
        sol += tree[k][a];
        a -= a&-a;
    }
    return sol;
}

int range(int a, int b, int k)
{
    return sum(b, k)-sum(a-1, k);
}

void update(int a, int k, int x)
{
    int u = x-(sum(a, k)-sum(a-1,k));
    while(a <= n){
        tree[k][a] += u;
        a += a&-a;
    }
}

void copyy(int k)
{
    tree.push_back(tree[k]);
}

void querie()
{
    int t; cin >> t;
    if(t == 1){
        int a, k, x; cin >> k >> a >> x;
        update(a, k, x);
        return;
    }
    if(t == 2){
        int k, a, b; cin >> k >> a >> b;
        cout << range(a, b, k) << endl;
        return;
    }
    int k; cin >> k; copyy(k);
    return;
}

void init()
{
    cin >> n >> m;
    tree.resize(2);
    tree[0].resize(n+1, 0);
    tree[1].resize(n+1, 0);

    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        update(i, 1, x);
    }
    cout << "init done" << endl;
}

int32_t main()
{
    init();
    while(m--) querie();
    return 0;
}
