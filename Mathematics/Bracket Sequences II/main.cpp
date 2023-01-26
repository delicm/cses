#include <bits/stdc++.h>
#define int long long int
#define mod 1000000007

using namespace std;

int fact[2000001];

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
    for(int i = 2; i <= 2000000; i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
}

int cnt(string s)
{
    int l = 0;
    for(char c : s){
        if(c == '(') l++;
        else{
            if(l == 0) return -1;
            l--;
        }
    }
    return l;
}

int c_k(int k)
{
    return (achooseb(2*k, k)*inverse(k+1))%mod;
}

void solve(int n, int k)
{

}

int32_t main()
{
    init();
    int n; cin >> n;
    string s; cin >> s; int k = cnt(s);

    if(n % 2 == 1 || k == -1){
        cout << 0; return 0;
    }

    n = n-s.size()-k;
    if(n < 0){
        cout << 0; return 0;
    }

    int sol = (achooseb(n, n/2)*inverse(n/2+1))%mod;
    sol = sol*achooseb(k+n/2, n/2);
    cout << sol%mod;

    return 0;
}
