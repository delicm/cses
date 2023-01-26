#include <bits/stdc++.h>
#define int long long int

using namespace std;

int n, k, sol = 0;
vector <int> ssize;
vector <set <int>> g;
vector <int> cnt;


void rearange(int& root)
{
    int treeSize = ssize[root];
    for(auto next : g[root]){
        if(ssize[next] > treeSize/2){
            ssize[root] -= ssize[next];
            ssize[next] = treeSize;
            root = next;
            rearange(root);
            return;
        }
    }
}

void removeRoot(int root)
{
    for(auto x : g[root]) g[x].erase(root);
    g[root].clear();
}

//################################

void dfsPaths(int node, int parent, int depth)
{
    if(depth >= k) return;
    sol += cnt[k-1-depth];
    for(auto next : g[node]){
        if(next == parent) continue;
        dfsPaths(next, node, depth+1);
    }
}

void dfsCnt(int node, int parent, int depth)
{
    if(depth >= k) return;
    cnt[depth]++;
    for(auto next : g[node]){
        if(next == parent) continue;
        dfsCnt(next, node, depth+1);
    }
}

void pathsThroughRoot(int root)
{
    if(ssize[root] < k) return;
    fill(cnt.begin(), cnt.end(), 0);
    cnt[0] = 1;

    for(auto child : g[root]){
        dfsPaths(child, root, 1);
        dfsCnt(child, root, 1);
    }
}

//################################

void process(int root)
{
    rearange(root);
    pathsThroughRoot(root);
    set <int> children = g[root];
    removeRoot(root);
    //cout << root << endl;
    for(auto next : children) process(next);
}

//################################

void initDFS(int node, int parent)
{
    for(auto next : g[node]){
        if(next == parent) continue;
        initDFS(next, node);
        ssize[node] += ssize[next];
    }
}

void init()
{
    cin >> n >> k; k++;
    g.resize(n+1);
    ssize.resize(n+1, 1);
    cnt.resize(k, 0);

    for(int i = 1; i < n; i++){
        int a, b; cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }
    initDFS(1, 0);
    process(1);
}

int32_t main()
{
    init();
    cout << sol;
    return 0;
}
