#include <bits/stdc++.h>

using namespace std;

vector <vector <int>> v;
vector <vector <int>> v1;
vector <int> vis;
vector <int> order;
vector <int> path;

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
    v1.resize(n+1);
    vis.resize(n+1, 0);
    path.resize(n+1, 0);

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v1[b].push_back(a);
    }

    for(int i = 1; i <= n; i++)
    {
        if(vis[i] == 2) continue;
        dfs(i);
    }
    reverse(order.begin(), order.end());

    path[1] = 1;
    int t = 0;
    while(order[t] != 1) t++;

    for(int i = t+1; i < n; i++)
    {
        //cout << order[i+1] << " ";
        for(auto e : v1[order[i]])
        {
            path[order[i]] += path[e];
            path[order[i]] %= 1000000007;
        }
    }

    cout << path[n];

    return 0;
}
