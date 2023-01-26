#include <bits/stdc++.h>

using namespace std;

int n;
vector <int> sol;
vector <vector <int>> g;
vector <set <int>> color;

void dfs(int node, int parent)
{
    for(auto next : g[node]){
        if(next == parent) continue;
        dfs(next, node);
        if(color[node].size() < color[next].size()) swap(color[node], color[next]);
        for(auto c : color[next]) color[node].insert(c);
    }
    sol[node] = color[node].size();
}

void init()
{
    cin >> n;
    g.resize(n+1);
    color.resize(n+1);
    sol.resize(n+1, 0);

    for(int i = 1; i <= n; i++){
        int c; cin >> c;
        color[i].insert(c);
    }
    for(int i = 1; i < n; i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0);
}

int32_t main()
{
    init();
    for(int i = 1; i <= n; i++) cout << sol[i] << " ";
    return 0;
}
