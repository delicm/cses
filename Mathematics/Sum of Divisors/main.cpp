#include <iostream>
#include <cmath>
#define int long long int
#define M 1000000007

using namespace std;

int rangesum(int k)
{
    k %= M;
    return (k*(k+1)/2)%M;
}

int solve(int n)
{
    int s = (int) sqrt(n);
    int sol = 0;
    for(int i = 1; i <= s; i++){
        int reach = n/i;
        sol += rangesum(reach); sol %= M;
    }
    for(int i = 1; i <= s; i++){
        sol += (((int)n/i)-s)*i; sol %= M;
    }
    return sol;
}

int32_t main()
{
    int n; cin >> n; cout << solve(n);
    return 0;
}
