#include <bits/stdc++.h>
#define int long long int

using namespace std;

int n, k1, k2, sol = 0;
vector <int> ssize;
vector <set <int>> g;
vector <int> cnt;
vector <int> tree;

//################################

int sum(int pos)
{
    int summ = 0;
    while(pos >= 1){
        summ += tree[pos];
        pos -= pos&-pos;
    }
    return summ;
}

void update(int pos, int val)
{
    while(pos <= k2){
        tree[pos] += val;
        pos += pos&-pos;
    }
}

//################################

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
    if(depth >= k2) return;
    sol += sum(k2-depth)-sum(k1-1-depth);
    for(auto next : g[node]){
        if(next == parent) continue;
        dfsPaths(next, node, depth+1);
    }
}

void dfsCnt(int node, int parent, int depth)
{
    if(depth >= k2) return;
    cnt[depth+1]++; update(depth+1, 1);
    for(auto next : g[node]){
        if(next == parent) continue;
        dfsCnt(next, node, depth+1);
    }
}

void pathsThroughRoot(int root)
{
    if(ssize[root] < k1) return;
    fill(cnt.begin(), cnt.end(), 0);
    fill(tree.begin(), tree.end(), 0);
    cnt[1] = 1;
    update(1, 1);

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
    cin >> n >> k1 >> k2; k1++; k2++;
    g.resize(n+1);
    ssize.resize(n+1, 1);
    cnt.resize(k2+1, 0);
    tree.resize(k2+1, 0);

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
