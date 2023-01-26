#include <bits/stdc++.h>
#define int long long int
using namespace std;

int n, k, sol = 0;
vector<int> p;

int bitcnt(int s)
{
    int ans = 0;
    for(int i = 0; i < 20; i++)
        if((1<<i)&s) ans++;
    if(ans % 2 == 0) return -1;
    return 1;
}

bool overflow(int a, int b)
{
    return LLONG_MAX/a < b;
}

void inclusion_exclusion()
{
    for(int i = 1; i < (1<<k); i++){
        int cnt = 1;
        for(int j = 0; j < k; j++){
            if(i & (1<<j)){
                if(overflow(cnt, p[j])){
                    cnt = n+1; break;
                }
                cnt *= p[j];
            }
        }
        int bcnt = bitcnt(i);
        sol += bcnt*(n/cnt);
    }
}

int32_t main()
{
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        p.push_back(0); cin >> p[i];
    }
    inclusion_exclusion();
    cout << sol;

    return 0;
}
