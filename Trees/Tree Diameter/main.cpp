#include <bits/stdc++.h>

using namespace std;

vector <vector <int>> g;
int dist = 0, e = 1;

void dfs(int v, int p, int d)
{
    if(dist < d)
    {
        dist = d;
        e = v;
    }

    for(auto u : g[v])
        if(u != p) dfs(u, v, d+1);
}

int main()
{
    int n; cin >> n;
    g.resize(n+1);

    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 0, 0);
    dist = 0;
    dfs(e, 0, 0);

    cout << dist;

    return 0;
}
