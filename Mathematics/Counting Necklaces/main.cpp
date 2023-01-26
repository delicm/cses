#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

int exp(int a, int b)
{
    if(b == 0) return 1;
    int temp = exp(a, b/2);
    temp = temp*temp; temp %= mod;
    if(b%2 == 1) temp = (temp*a)%mod;
    return temp;
}

int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a%b);
}

pair<int, int> inverseHelper(int a, int b)
{
    if(b == 0) return {1, 0};
    int x, y;
    tie(x, y) = inverseHelper(b, a%b);
    return {y, x-(a/b)*y};
}

int inverse(int k)
{
    int y = inverseHelper(mod, k).second; y%=mod;
    if(y < 0) y += mod;
    return y;
}

void solve(int n, int m)
{
    int sol = 0;
    for(int i = 1; i <= n; i++){
        sol += exp(m, gcd(n, i));
        sol %= mod;
    }
    sol *= inverse(n);
    cout << sol%mod;
}

int32_t main()
{
    int n, m; cin >> n >> m;
    solve(n, m);
    return 0;
}
