#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    int c[n];
    long long d = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> c[i];
        d += c[i];
    }

    bool s[d+1][n+1];

    for(int i = 0; i < d+1; i++)
    {
        for(int j = 0; j < n+1; j++)
        {
            s[i][j] = 0;
        }
    }

    s[0][0] = 1;
    long long ans = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= d; j++)
        {
            if(j >= c[i-1]) s[j][i] = s[j][i-1] | s[j-c[i-1]][i-1];
            else s[j][i] = s[j][i-1];
        }
    }

    for(int i = 1; i <= d; i++)
    {
        if(s[i][n]) ans++;
    }

    cout << ans << endl;

    for(int i = 1; i <= d; i++)
    {
        if(s[i][n]) cout << i << " ";
    }

    return 0;
}
