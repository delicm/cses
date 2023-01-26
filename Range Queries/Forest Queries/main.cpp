#include <iostream>

using namespace std;

int main()
{
    int n, q; cin >> n >> q;
    bool f[n+1][n+1];
    int x[n+1][n+1];

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            char c; cin >> c;
            if(c == '*') f[i][j] = 1;
            else f[i][j] = 0;
        }
    }

    for(int i = 0; i <= n; i++)
    {
        x[0][i] = 0;
        x[i][0] = 0;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            x[i][j] = x[i-1][j]+x[i][j-1]-x[i-1][j-1];
            if(f[i][j]) x[i][j]++;
        }
    }

    while(q--)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;

        cout << x[y1][y2]-x[y1][x2-1]-x[x1-1][y2]+x[x1-1][x2-1] << endl;
    }

    return 0;
}
