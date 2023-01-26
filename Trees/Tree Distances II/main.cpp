#include <bits/stdc++.h>

using namespace std;

#define int long long int

int n;
vector <vector <int>> g;
vector <int> down;
vector <int> total;
vector <int> ord;
vector <int> subTree;
vector <int> parent;

void dfs(int v, int p)
{
    for(auto u : g[v])
    {
        if(u == p) continue;
        dfs(u, v);
        parent[u] = v;
        subTree[v] += subTree[u];
    }
    if(subTree[v] == 1) down[v] = 0;
    ord.push_back(v);
}

void dfsDown(int v, int p)
{
    for(auto u : g[v])
    {
        if(u == p) continue;
        dfsDown(u, v);
        down[v] += down[u] + subTree[u];
    }
}

int32_t main()
{
    cin >> n;
    g.resize(n+1);
    down.resize(n+1);
    total.resize(n+1);
    parent.resize(n+1);
    subTree.resize(n+1, 1);

    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 0);
    dfsDown(1, 0);

    reverse(ord.begin(), ord.end());

    //for(int i = 1; i <= n; i++) cout << parent[i] << " ";

    total[1] = down[1];
    for(int i = 1; i < n; i++)
    {
        int s = ord[i], p = parent[s];
        total[s] = (total[p] - down[s]-subTree[s]) + (n-subTree[s])+down[s];
    }

    for(int i = 1; i <= n; i++) cout << total[i] << " ";

    return 0;
}
