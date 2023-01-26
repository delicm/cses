#include <bits/stdc++.h>

using namespace std;

int n;
vector <vector <int>> g;

pair<int, bool> rec(int root, int parent)
{
    pair<int, bool> sol = make_pair(0, false);

    for(auto u : g[root]){
        if(u == parent) continue;
        pair<int, bool> subtree = rec(u, root);
        if(!subtree.second) sol.second = true;
        sol.first += subtree.first;
    }
    sol.first += sol.second;
    return sol;
}

void init()
{
    cin >> n;
    g.resize(n+1);

    for(int i = 1; i < n; i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
}

int main()
{
    init();
    cout << rec(1, 0).first;
    return 0;
}
