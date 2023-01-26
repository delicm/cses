#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

vector<vector<int>> M = {{0,1}, {1,1}};
vector<vector<int>> id = {{1, 0},{0, 1}};

vector<vector<int>> prod(vector<vector<int>> a, vector<vector<int>> b)
{
    vector<vector<int>> c; c.resize(2); c[0].resize(2); c[1].resize(2);
    c[0][0] = a[0][0]*b[0][0]+a[0][1]*b[1][0]; c[0][0] %= mod;
    c[0][1] = a[0][0]*b[0][1]+a[0][1]*b[1][1]; c[0][1] %= mod;
    c[1][0] = a[1][0]*b[0][0]+a[1][1]*b[1][0]; c[1][0] %= mod;
    c[1][1] = a[1][0]*b[0][1]+a[1][1]*b[1][1]; c[1][1] %= mod;
    return c;
}

vector<vector<int>> exp(vector<vector<int>> a, int k)
{
    if(k == 0) return id;
    vector<vector<int>> temp = exp(a, k/2);
    temp = prod(temp, temp);
    if(k%2 == 1) temp = prod(temp, a);
    return temp;
}

int Fibb(int n)
{
    vector<vector<int>> v = exp(M, n);
    return v[0][1];
}

int32_t main()
{
    int n; cin >> n;
    cout << Fibb(n);

    return 0;
}
