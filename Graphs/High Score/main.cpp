#include <bits/stdc++.h>

using namespace std;
#define int long long int

int n, m;
vector <pair<pair<int, int>, int>> edges;
vector <vector <int>> graph;
vector <int> dist;
vector <bool> origin;
bool swtch = false;

void init()
{
    cin >> n >> m;
    dist.resize(n+1, LLONG_MIN);
    origin.resize(n+1, false);
    graph.resize(n+1);
    dist[1] = 0;

    for(int i = 0; i < m; i++)
    {
        int w, a, b;
        cin >> a >> b >> w;
        edges.push_back(make_pair(make_pair(a, b), w));
        graph[b].push_back(a);
    }
}

void improve()
{
    for(auto e : edges)
    {
        int w = e.second, a = e.first.first, b = e.first.second;
        if(dist[a] != LLONG_MIN) dist[b] = max(dist[a]+w, dist[b]);
    }
}

void improveAlt()
{
    for(auto e : edges)
    {
        int w = e.second, a = e.first.first, b = e.first.second;
        if(dist[a] != LLONG_MIN && dist[a]+w > dist[b])
        {
            dist[b] = dist[a]+w, dist[b];
            if(origin[b]) swtch = true;
        }
    }
}

void reverseDFS(int v)
{
    if(origin[v]) return;
    origin[v] = true;
    for(auto x : graph[v])
        reverseDFS(x);
}

int solve()
{
    reverseDFS(n);
    for(int i = 1; i <= n; i++)
        improve();

    int sol = dist[n];
    improveAlt();

    if(swtch) return -1;
    return sol;
}

int32_t main()
{
    init();
    cout << solve();

    return 0;
}
