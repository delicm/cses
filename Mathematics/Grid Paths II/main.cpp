#include <bits/stdc++.h>
#define int long long int

using namespace std;

int n, m, k;
vector<vector<int>> g;
vector<vector<int>> inf;

bool overflow(int a, int b)
{
    return a+b < 0;
}

vector<vector<int>> prod(vector<vector<int>> a, vector<vector<int>> b)
{
    vector<vector<int>> c = inf;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int l = 0; l < n; l++){
                if(overflow(a[i][l],b[l][j])) continue;
                else c[i][j] = min(a[i][l]+b[l][j], c[i][j]);
            }
        }
    }
    return c;
}

vector<vector<int>> exp(vector<vector<int>> a, int b)
{
    if(b == 1) return a;
    vector<vector<int>> temp = exp(a, b/2);
    temp = prod(temp, temp);
    if(b%2==1) temp = prod(temp, a);
    return temp;
}

int32_t main()
{
    cin >> n >> m >> k;
    g.resize(n);
    inf.resize(n);
    for(int i = 0; i < n; i++) inf[i].resize(n, LLONG_MAX);
    g = inf;

    while(m--){
        int a, b, c; cin >> a >> b >> c;
        g[a-1][b-1] = min(g[a-1][b-1], c);
    }

    g = exp(g, k);
    if(g[0][n-1] == LLONG_MAX) cout << -1;
    else cout << g[0][n-1];

    return 0;
}
