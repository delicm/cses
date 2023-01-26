#include <bits/stdc++.h>

using namespace std;

#define S 200005

int n, m, q;
int jump[21][S];
int depth[S];

vector <int> g[S];

void dfs(int v, int p, int d)
{
    jump[0][v] = p;
    depth[v] = d;

    for(auto u : g[v])
        if(u != p) dfs(u, v, d+1);
}

void preprocess()
{
    dfs(1, -1, 1);

    for(int i = 1; (1<<i) <= n; i++)
        for(int j = 1; j <= n; j++)
            jump[i][j] = jump[i-1][jump[i-1][j]];
}

int LCA(int x, int y)
{
    if(depth[x] < depth[y]) swap(x, y);

    int diff = depth[x] - depth[y];

    for(int i = 20; i >= 0; i--)
        if(diff&(1<<i)) x = jump[i][x];

    if(x == y) return x;

    for(int i = 20; i >= 0; i--)
    {
        if(jump[i][x] != jump[i][y])
        {
            x = jump[i][x];
            y = jump[i][y];
        }
    }
    return jump[0][x];
}

int main()
{
    cin >> n >> q;

    for(int i = 2; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    preprocess();

    while(q--)
    {
        int a, b;
        cin >> a >> b;
        cout << depth[a] + depth[b] - 2*depth[LCA(a, b)] << " ";
    }

    return 0;
}
