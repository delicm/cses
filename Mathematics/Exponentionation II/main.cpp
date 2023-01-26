#include <iostream>
#define int long long int
#define M 1000000007

using namespace std;

int exp(int a, int b, int mod)
{
    if(b == 0) return 1;
    int temp = exp(a, b/2, mod);
    temp = (temp*temp)%mod;
    if(b%2) temp = (temp*a)%mod;
    return temp;
}

int solve(int a, int b, int c)
{
    int e = exp(b, c, M-1);
    return exp(a, e, M);
}

int32_t main()
{
    int n; cin >> n;
    while(n--){
        int a, b, c; cin >> a >> b >> c;
        cout << solve(a,b,c) << endl;

    }
    return 0;
}
