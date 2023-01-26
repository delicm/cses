#include <iostream>

using namespace std;

int main()
{
    int n, m; cin >> n >> m; int x[n];
    for(int i = 0; i < n; i++) cin >> x[i];

    long long s[m+2][n];

    for(int i = 0; i < n; i++)
    {
        s[0][i] = 0;
        s[m+1][i] = 0;
    }
    for(int i = 1; i <= m; i++)
    {
        if(x[0] == i || x[0] == 0) s[i][0] = 1;
        else s[i][0] = 0;
    }

    for(int i = 1; i < n; i++)
    {
        if(x[i] == 0)
        {
            for(int j = 1; j <= m; j++)
            {
                s[j][i] = s[j-1][i-1]+s[j+1][i-1]+s[j][i-1];
                s[j][i] %= 1000000007;
            }
        }
        else
        {
            for(int j = 1; j <= m; j++)
            {
                s[j][i] = 0;
            }
            s[x[i]][i] = s[x[i]][i-1]+s[x[i]-1][i-1]+s[x[i]+1][i-1];
            s[x[i]][i] %= 1000000007;
        }
    }

    long long ans = 0;

    for(int i = 1; i <= m; i++)
    {
        ans = (ans+s[i][n-1])%1000000007;
    }

    /*for(int i = 0; i < m+2; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }*/

    cout << ans;

    return 0;
}
