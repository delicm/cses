#include <bits/stdc++.h>
#define int long long int
#define mod 1000000007

using namespace std;

int fact[1000001];
int chars[26];

pair<int, int> helper(int a, int b)
{
    if(b == 0){
        return {1, 0};
    }
    else{
        int x, y;
        tie(x, y) = helper(b, a%b);
        return {y, x-(a/b)*y};
    }
}

int inverse(int k)
{
    int y = helper(mod, k).second;
    y %= mod;
    if(y < 0) y += mod;
    return y;
}

void init()
{
    fact[0] = 1;
    for(int i = 1; i <= 1000000; i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
}

void solve(int n)
{
    int s = fact[n];
    for(int i = 0; i <= 'z'-'a'; i++){
        s *= inverse(fact[chars[i]]);
        s %= mod;
    }
    cout << s;
}

int32_t main()
{
    init();
    int n;
    string s; cin >> s; n = s.size();
    for(int i = 0; i < 26; i++) chars[i] = 0;
    for(auto c : s) chars[c-'a']++;
    solve(n);

    return 0;
}
