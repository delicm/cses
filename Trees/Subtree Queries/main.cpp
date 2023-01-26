#include <bits/stdc++.h>

using namespace std;

#define int long long int

int n, q;
vector <int> val;
vector <int> ord;
vector <int> tree;
vector <pair<int, int>> fl;
vector <vector <int>> g;

void dfs(int v, int p)
{
    ord.push_back(v);
    fl[v].first = ord.size()-1;
    for(auto u : g[v])
        if(u != p)
            dfs(u, v);

    fl[v].second = ord.size()-1;
}

int sum(int v)
{
    int index1 = fl[v].first;
    int index2 = fl[v].second;
    int s1 = 0, s2 = 0;
    index2++;

    while(index1 > 0)
    {
        s1 += tree[index1];
        index1 -= index1&(-index1);
    }
    while(index2 > 0)
    {
        s2 += tree[index2];
        index2 -= index2&(-index2);
    }
    return s2-s1;
}

void update(int v, int vall)
{
    int index = fl[v].first;
    int change = vall-val[v];
    val[v] = vall;
    index++;

    while(index <= n)
    {
        tree[index] += change;
        index += index&(-index);
    }
}

void makeTree()
{
    for(int i = 1; i <= n; i++)
    {
        int x = val[i]; val[i] = 0;
        update(i, x);
    }
}

int32_t main()
{
    cin >> n >> q;
    val.resize(n+1, 0);
    fl.resize(n+1);
    tree.resize(n+1, 0);
    g.resize(n+1);

    for(int i = 1; i <= n; i++) cin >> val[i];
    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 0);
    makeTree();

    //for(int i = 1; i <= n; i++) cout << sum(i) << " ";

    while(q--)
    {
        int c; cin >> c;
        if(c == 1)
        {
            int v, vall; cin >> v >> vall;
            update(v, vall);
        }
        else
        {
            int v; cin >> v;
            cout << sum(v) << " ";
        }
    }

    return 0;
}
