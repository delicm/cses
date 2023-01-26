#include <bits/stdc++.h>
#define int long long int
#define mod 1000000007

using namespace std;

int fact[1000001];

int solve(int n)
{
    int sol = 0;
    for(int i = 0; i <= n; i++){
        int p = 1; if(i%2 == 1) p = -1;
        sol += p*fact[i];
        sol %= mod;
    }
    if(sol < 0) sol += mod;
    return sol;
}

void init(int n)
{
    fact[n] = 1;
    for(int i = n-1; i >= 0; i--){
        fact[i] = (fact[i+1]*(i+1))%mod;
    }
}

int32_t main()
{
    int n; cin >> n;
    init(n);
    cout << solve(n);

    return 0;
}
