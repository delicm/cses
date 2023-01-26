#include <bits/stdc++.h>

using namespace std;

int n, centroid;
vector <vector <int>> g;
vector <int> ssize;

void updateCentroid()
{
    for(auto next : g[centroid]){
        if(ssize[next] > n/2){
            ssize[centroid] -= ssize[next];
            ssize[next] = n;
            centroid = next;
            updateCentroid();
            return;
        }
    }
}

void dfs(int node, int parent)
{
    for(auto next : g[node]){
        if(next == parent) continue;
        dfs(next, node);
        ssize[node] += ssize[next];
    }
}

void init()
{
    cin >> n;
    g.resize(n+1);
    ssize.resize(n+1, 1);

    for(int i = 1; i < n; i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0);
    centroid = 1;
    updateCentroid();
    cout << centroid;
}

int main()
{
    init();
    return 0;
}
