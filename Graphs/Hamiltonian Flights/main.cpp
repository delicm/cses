#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

#define int long long int

int n, m;
vector <int> v[25];
int dp[25][(1<<20)+1];
vector <int> vv[(1<<20)+1];

int32_t main()
{
    cin >> n >> m;
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        v[b].push_back(a);
    }

    for(int i = 0; i <= (1<<n); i++)
    {
        for(int j = 0; j <= n; j++)
        {
            dp[j][i] = 0;
            if(i&(1<<j)) vv[i].push_back(j);
        }
    }

    /*for(int i = 0; i <= (1<<n); i++)
    {
        for(auto k : vv[i])
        {
            cout << k << " ";
        }
        cout << endl;
    }*/

    dp[0][1] = 1;

    for(int i = 1; i <= (1<<n); i++)
    {
        for(auto j : vv[i])
        {
            int x = i^(1<<j);
            for(auto k : v[j])
            {
                dp[j][i] += dp[k][x];
            }
            dp[j][i] %= 1000000007;
        }
        i++;
    }

    /*for(int i = 0; i <= n-1; i++)
    {
        for(int j = 0; j <= (1<<n); j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/

    cout << dp[n-1][(1<<n)-1];

    return 0;
}
