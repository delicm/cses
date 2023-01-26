#include <bits/stdc++.h>
#define int long long int

using namespace std;

int n, q;
vector <vector <int>> g;
vector <int> sizee;
vector <int> ord;
vector <int> pos;

vector <int> val;
vector <int> diffArray;
vector <int> tree;


int sumTree(int k)
{
    int sol = 0;
    while(k >= 1){
        sol += tree[k];
        k -= k&-k;
    }
    return sol;
}

void updateTree(int k, int x)
{
    while(k <= n){
        tree[k] += x;
        k += k&-k;
    }
}

void update(int k, int u)
{
    int x = u - val[k];
    val[k] = u;
    int newk = pos[k];
    updateTree(newk, x);
    updateTree(newk+sizee[k], -x);
}

//###############################################

void setupDiffArray()
{
    int temp = 0;
    for(int i = 1; i <= n; i++){
        int temp2 = diffArray[i];
        diffArray[i] = diffArray[i] - temp;
        temp = temp2;
    }

    for(int i = 1; i <= n; i++){
        updateTree(i, diffArray[i]);
    }

}

void createOrder(int node, int parent)
{
    ord.push_back(node);
    pos[node] = ord.size()-1;
    diffArray[pos[node]] = val[node] + diffArray[pos[parent]];
    for(auto next : g[node]){
        if(next == parent) continue;
        createOrder(next, node);
        sizee[node] += sizee[next];
    }
}

void init()
{
    cin >> n >> q;
    g.resize(n+1);
    sizee.resize(n+1, 1);
    pos.resize(n+1, 0);
    ord.push_back(0);

    tree.resize(n+1, 0);
    diffArray.resize(n+1, 0);
    val.resize(n+1, 0);

    for(int i = 1; i <= n; i++) cin >> val[i];

    for(int i = 1; i < n; i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    createOrder(1, 0);
    setupDiffArray();

}

//###############################################

int32_t main()
{
    init();

    while(q--){
        int t; cin >> t;
        if(t == 1){
            int k, u; cin >> k >> u;
            update(k, u);
        }
        else{
            int k; cin >> k;
            cout << sumTree(pos[k]) << endl;
        }
    }
    return 0;
}
