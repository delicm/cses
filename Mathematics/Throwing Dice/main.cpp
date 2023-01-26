#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

vector<vector<int>> M = {{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,1,0,0},{0,0,0,0,1,0},{0,0,0,0,0,1},{1,1,1,1,1,1}};
vector<vector<int>> id = {{1,0,0,0,0,0},{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,1,0,0},{0,0,0,0,1,0},{0,0,0,0,0,1}};
vector<vector<int>> zero = {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}};

vector<vector<int>> prod(vector<vector<int>> a, vector<vector<int>> b)
{
    vector<vector<int>> c = zero;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            for(int k = 0; k < 6; k++){
                c[i][j] += a[i][k]*b[k][j];
                c[i][j] %= mod;
            }
        }
    }
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

int dice(int n)
{
    vector<vector<int>> v = exp(M, n-1);

    int sol = 0;
    for(int i = 1; i <= 6; i++){
        sol += pow(2, i-1)*v[0][i-1];
        sol %= mod;
    }
    return sol;
}

int32_t main()
{
    int n; cin >> n; cout << dice(n);
    return 0;
}
