#include <bits/stdc++.h>
#define int long long int
#define mod 1000000007

using namespace std;

int fact[1000001];

tuple<int, int, int> helper(int a, int b)
{
    if(b == 0){
        return {1, 0, a};
    }
    else{
        int x, y, g;
        tie(x, y, g) = helper(b, a%b);
        return {y, x-(a/b)*y, g};
    }
}

int inverse(int k)
{
    int x, y, g;
    tie(x, y, g) = helper(mod, k);
    y *= g; y %= mod;
    if(y < 0) y = mod+y;
    return y;
}

int achooseb(int a, int b)
{
    int sol = fact[a];
    sol = (sol*inverse(fact[b]))%mod;
    sol = (sol*inverse(fact[a-b]))%mod;
    return sol;
}

void init()
{
    fact[0] = 1; fact[1] = 1;
    for(int i = 2; i <= 1000000; i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
}

int32_t main()
{
    init();
    int n; cin >> n;
    while(n--){
        int a, b; cin >> a >> b;
        cout << achooseb(a, b) << endl;
    }
    return 0;
}
