#include <bits/stdc++.h>

using namespace std;

int n, m;
vector <int> no;
vector <int> tree;

void add(int k, int x)
{
    while(k <= n){
        tree[k] += x;
        k += k&-k;
    }
}

int sum(int k)
{
    int sol = 0;
    while(k >= 1){
        sol += tree[k];
        k -= k&-k;
    }
    return sol;
}

int range(int a, int b)
{
    return sum(b)-sum(a);
}

void init()
{
    cin >> n >> m;
    tree.resize(n+1, 0);
    no.resize(n+1, 0);
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        no[i] = x;
        add(i, max(no[i-1]-no[i], 0));
    }

}

int main()
{
    init();
    while(m--){
        int a, b; cin >> a >> b;
        cout << range(a,b) << endl;
    }
    return 0;
}
