#include <bits/stdc++.h>

using namespace std;

vector <vector <int>> g;
vector <pair<int, int>> FL;
int cnt = 0;

void dfs(int v, int parent)
{
    FL[v].first = cnt;
    cnt++;

    for(auto u : g[v])
        if(u != parent) dfs(u, v);
    FL[v].second = cnt;
}

int main()
{
    int n; cin >> n;
    g.resize(n+1);
    FL.resize(n+1, {-1, -1});

    for(int i = 2; i <= n; i++)
    {
        int x; cin >> x;
        g[x].push_back(i);
        g[i].push_back(x);
    }

    dfs(1, 0);
    for(int i = 1; i <= n; i++)
        cout << (FL[i].second-FL[i].first-1) << " ";


    return 0;
}
