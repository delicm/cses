#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    char c[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> c[i][j];
        }
    }

    if(c[0][0]=='*')
    {
        cout << 0;
        return 0;
    }

    long long s[n+1][n+1];

    for(int i = 0; i <= n; i++)
    {
        s[i][0] = 0;
        s[0][i] = 0;
    }

    s[0][1] = 1;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(c[i][j] == '*') s[i+1][j+1] = 0;
            else s[i+1][j+1] = (s[i][j+1] + s[i+1][j])%1000000007;
        }
    }

    cout << s[n][n];

    return 0;
}
