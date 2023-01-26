#include <iostream>
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

int solve(int n)
{
    int sol = 0;
    sol += exp(2, (n*n/4)%(mod-1));
    if(n%2 == 1) sol *= 2;
    sol *= 2; sol %= mod;

    sol += exp(2, (n*n/2)%(mod-1)); sol %= mod;
    if(n%2 == 1){
        sol += exp(2, (n*n/2)%(mod-1)); sol %= mod;
    }

    sol += exp(2, (n*n)%(mod-1)); sol %= mod;
    return (sol*((mod+1)/4))%mod;
}

int32_t main()
{
    int n; cin >> n; cout << solve(n);
    return 0;
}
