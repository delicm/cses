#include <bits/stdc++.h>

using namespace std;

int n, m;
vector <vector <int>> g;
vector <pair <int, int>> heavy;
vector <vector <int>> par;
vector <int> depth;
vector <vector <int>> paths;
vector <vector <int>> trees;
vector <pair <int, int>> ind;
vector <int> vals;

//#########################################

int ancestor(int node, int k)
{
    for(int i = 0; i < 19; i++){
        if((1<<i) & k) node = par[node][i];
    }
    return node;
}

pair<int, int> equalize(int a, int b)
{
    if(depth[a] == depth[b]) return make_pair(a, b);
    if(depth[a] > depth[b]) a = ancestor(a, depth[a]-depth[b]);
    else b = ancestor(b, depth[b]-depth[a]);
    return make_pair(a, b);
}

int LCA(int a, int b)
{
    pair<int, int> temp = equalize(a, b);
    a = temp.first; b = temp.second;
    if(a == b) return a;

    int left = 1, right = n;
    while(left <= right){
        int mid = (left+right)/2;
        if(ancestor(a, mid-1) == ancestor(b, mid-1)){
            right = mid;
            continue;
        }
        if(ancestor(a, mid) != ancestor(b, mid)){
            left = mid;
            continue;
        }
        return ancestor(a, mid);
    }
    return n;
}

//#########################################

int findMax(int left, int right, int chain)
{
    int L = trees[chain].size();
    left += L/2; right += L/2;
    int sol = max(trees[chain][left], trees[chain][right]);

    while(left <= right){
        if(left % 2 == 1) sol = max(sol, trees[chain][left++]);
        if(right % 2 == 0) sol = max(sol, trees[chain][right--]);
        left /= 2; right /= 2;
    }
    return sol;
}

int pathMax(int node, int anc)
{
    if(node == anc) return vals[node];
    int chain = ind[node].first;
    if(chain == ind[anc].first){
        int a = ind[node].second, b = ind[anc].second;
        return findMax(b, a, chain);
    }
    int sol = findMax(1, ind[node].first, chain);
    node = paths[chain][1];
    node = par[node][0];
    return max(sol, pathMax(node, anc));
}

int pathSolve(int a, int b)
{
    int lc = LCA(a, b);
    return max(pathMax(a, lc), pathMax(b, lc));
}

void update(int node, int s)
{
    int chain = ind[node].first, pos = ind[node].second;
    vals[node] = s;

    int L = trees[chain].size();
    pos += L/2;
    trees[chain][pos] = vals[node]; pos /= 2;
    while(pos >= 1){
        trees[chain][pos] = max(trees[chain][2*pos], trees[chain][2*pos+1]);
        pos /= 2;
    }

}

//#########################################

void initTrees()
{
    for(unsigned int i = 0; i < paths.size(); i++){
        int l = paths[i].size(), L = 1;
        while(L < l) L *= 2;
        vector <int> prototype(2*L, INT_MIN);
        trees.push_back(prototype);
    }
    for(int i = 1; i <= n; i++){
        update(i, vals[i]);
    }
}

void initPaths()
{
    vector <bool> vis(n+1, false);
    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;
        int curNode = i;
        while(heavy[curNode].first != 0) curNode = heavy[curNode].first;
        vector <int> newChain(1, 0); newChain.push_back(curNode); paths.push_back(newChain);

        while(heavy[curNode].second != 0){
            ind[curNode] = make_pair(paths.size()-1, paths[paths.size()-1].size()-1);
            vis[curNode] = true;
            curNode = heavy[curNode].second;
            paths[paths.size()-1].push_back(curNode);
        }
        ind[curNode] = make_pair(paths.size()-1, paths[paths.size()-1].size()-1);
        vis[curNode] = true;
    }
}

void initPar()
{
    for(int i = 1; i < 19; i++){
        for(int node = 1; node <= n; node++){
            par[node][i] = par[par[node][i-1]][i-1];
        }
    }
}

void dfs(int node, int parent, vector <int>& ssize)
{
    int succ = 0, curmax = -1;
    par[node][0] = parent;
    depth[node] = depth[parent]+1;

    for(auto next : g[node]){
        if(next == parent) continue;
        dfs(next, node, ssize);
        ssize[node] += ssize[next];
        if(ssize[next] > curmax){
            curmax = ssize[next]; succ = next;
        }
    }
    heavy[node].second = succ;
    heavy[succ].first = node;
}

void init()
{
    cin >> n >> m;
    g.resize(n+1);
    vector <int> ssize(n+1, 1);
    heavy.resize(n+1, make_pair(0, 0));
    par.resize(n+1); for(int i = 0; i <= n; i++) par[i].resize(19, 0);
    depth.resize(n+1, 0);
    ind.resize(n+1);

    vals.resize(n+1, 0);

    for(int i = 1; i <= n; i++) cin >> vals[i];
    for(int i = 1; i < n; i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 1, ssize);
    heavy[0] = make_pair(0, 0);
    initPar();
    initPaths();
    initTrees();

}

//#########################################

int main()
{
    init();
    //cout << "hello " << depth[10] << " " << depth[2] << " " << equalize(10, 2).first << " " << equalize(10, 2).second << " "  << LCA(2, 10) << endl;
    /*cout << "start" << endl;
    for(int i = 0; i < paths.size(); i++){
        for(int j = 0; j < paths[i].size(); j++){
            cout << paths[i][j] << " ";
        }
        cout << endl;
    }*/

    while(m--){
        int t; cin >> t;
        if(t == 1){
            int s, x; cin >> s >> x;
            update(s, x);
        }
        else{
            int a, b; cin >> a >> b;
            cout << pathSolve(a, b) << " ";
        }
    }
    return 0;
}
