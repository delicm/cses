#include <bits/stdc++.h>

using namespace std;

vector <vector <int>> v;
vector <bool> vis;
vector <int> pre;

void finish(int k)
{
    vector <int> cycle;
    cycle.push_back(k);
    int t = pre[k];
    while(t != k)
    {
        cycle.push_back(t);
        t = pre[t];
    }
    cycle.push_back(k);
    cout << cycle.size() << endl;
    for(auto e : cycle) cout << e << " ";
    exit(0);
}

void traverse(int k, int parent)
{
    if(!vis[k])
    {
        pre[k] = parent;
        vis[k] = 1;
        for(auto e : v[k]) traverse(e, k);
        return;
    }
    else
    {
        if(pre[parent] == k) return;
        pre[k] = parent;
        finish(k);
        return;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    v.resize(n+1);
    pre.resize(n+1);
    vis.resize(n+1);

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i = 0; i <= n; i++){
        vis[i] = 0;
    }

    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            traverse(i, -1);
        }
    }

    cout  << "IMPOSSIBLE";

    return 0;
}
