#include <bits/stdc++.h>
#define int long long int
#define mod 1000000007

using namespace std;

int n, m, k;
vector<vector<int>> g;
vector<vector<int>> zero;
vector<vector<int>> id;

vector<vector<int>> prod(vector<vector<int>> a, vector<vector<int>> b)
{
    vector<vector<int>> c = zero;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int l = 0; l < n; l++){
                c[i][j] += a[i][l]*b[l][j];
                c[i][j] %= mod;
            }
        }
    }
    return c;
}

vector<vector<int>> exp(vector<vector<int>> a, int b)
{
    if(b == 0) return id;
    vector<vector<int>> temp = exp(a, b/2);
    temp = prod(temp, temp);
    if(b%2==1) temp = prod(temp, a);
    return temp;
}

int32_t main()
{
    cin >> n >> m >> k;
    g.resize(n);
    for(int i = 0; i < n; i++) g[i].resize(n, 0);
    zero = g; id = g;

    for(int i = 0; i < n; i++) id[i][i] = 1;

    while(m--){
        int a, b; cin >> a >> b;
        g[a-1][b-1] += 1;
    }

    g = exp(g, k);
    cout << g[0][n-1];

    return 0;
}
