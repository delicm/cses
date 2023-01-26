#include <bits/stdc++.h>

using namespace std;

int n, m;
vector <vector <int>> g;
vector <int> vis;
vector <int> last;

void init()
{
    cin >> n >> m;
    g.resize(n+1);
    vis.resize(n+1, 0);
    last.resize(n+1);

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
}

void finish(int w)
{
    vector <int> sol;
    int x = w;

    while(last[x] != w)
    {
        sol.push_back(x);
        x = last[x];
    }
    sol.push_back(x);
    sol.push_back(w);
    int t = sol.size();

    cout << t << endl;
    for(int i = t-1; i >= 0; i--) cout << sol[i] << " ";
    exit(0);
}

void dfs(int v)
{
    vis[v] = 1;
    for(auto w : g[v])
    {
        last[w] = v;
        if(vis[w] == 1) finish(w);
        if(vis[w] == 0) dfs(w);
    }
    vis[v] = 2;
}

void solve()
{
    for(int i = 1; i <= n; i++)
    {
        if(vis[i] == 0)
            dfs(i);
    }
}

int main()
{
    init();
    solve();

    cout << "IMPOSSIBLE";

    return 0;
}
