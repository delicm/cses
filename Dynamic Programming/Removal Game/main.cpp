#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    int a[n];

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long s[n][n][2];

    for(int i = 0; i < n; i++)
    {
        s[i][i][0] = a[i];
        s[i][i][1] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = i-1; j >= 0; j--)
        {
            if(s[i][j+1][1] + a[j] > s[i-1][j][1] + a[i])
            {
                s[i][j][0] = s[i][j+1][1] + a[j];
                s[i][j][1] = s[i][j+1][0];
            }
            else
            {
                s[i][j][0] = s[i-1][j][1] + a[i];
                s[i][j][1] = s[i-1][j][0];
            }
        }
    }

    cout << s[n-1][0][0];

    return 0;
}
