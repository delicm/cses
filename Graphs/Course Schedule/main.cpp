#include <bits/stdc++.h>

using namespace std;

vector <vector <int>> v;
vector <int> vis;
vector <int> order;

void dfs(int x)
{
    if(vis[x] == 1)
    {
        cout << "IMPOSSIBLE";
        exit(0);
    }
    if(vis[x] == 2) return;
    vis[x] = 1;
    for(auto e : v[x]) dfs(e);
    vis[x] = 2;
    order.push_back(x);
    return;
}

int main()
{
    int n, m;
    cin >> n >> m;

    v.resize(n+1);
    vis.resize(n+1, 0);
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    for(int i = 1; i <= n; i++)
    {
        if(vis[i] == 2) continue;
        dfs(i);
    }
    reverse(order.begin(), order.end());
    for(auto e : order) cout << e << " ";

    return 0;
}
