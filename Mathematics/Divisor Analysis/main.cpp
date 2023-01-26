#include <bits/stdc++.h>
#define mod 1000000007
#define int long long int

using namespace std;

int exp(int a, int b)
{
    if(b == 0) return 1;
    int temp = exp(a, b/2);
    temp = (temp*temp)%mod;
    if(b%2 == 1) temp = (temp*a)%mod;
    return temp;
}

tuple<int, int, int> divAnalysis(stack <pair <int, int>> factor)
{
    if(factor.size() == 0) return make_tuple(1, 1, 1);
    int p = factor.top().first, k = factor.top().second; factor.pop();
    tuple<int, int, int> nxt = divAnalysis(factor);

    int nxtTau = get<0>(nxt);

    int tau = ((k+1)%mod); tau = (tau*nxtTau)%mod;
    int sig = (exp(p, (k+1)%(mod-1))-1)/(p-1); sig %= mod; sig = (sig*get<1>(nxt))%mod;
    int prod = exp(get<2>(nxt), (k+1)%(mod-1));

    int help = exp(p, (nxtTau)%(mod-1));
    prod = (prod*exp(help, (k*(k+1)/2)%(mod-1)))%mod;

    return make_tuple(tau, sig, prod);
}

int32_t main()
{
    int n; cin >> n;
    stack <pair<int, int>> factor;
    while(n--){
        int x, k; cin >> x >> k;
        factor.push(make_pair(x, k));
    }
    tuple <int, int, int> sol = divAnalysis(factor);
    cout << get<0>(sol) << " " << get<1>(sol) << " " << get<2>(sol);

    return 0;
}
