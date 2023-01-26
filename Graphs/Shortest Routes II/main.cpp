#include <bits/stdc++.h>

using namespace std;

#define int long long int

int32_t main()
{
    int n, m, q;
    cin >> n >> m >> q;

    int adj[n+1][n+1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) adj[i][j] = 5000000000001;

    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a][b] = min(c, adj[a][b]);
        adj[b][a] = adj[a][b];

    }

    for(int i = 1; i <= n; i++)
    {
        adj[i][i] = 0;
    }

    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    while(q--)
    {
        int a, b; cin >> a >> b;
        if(adj[a][b] == 5000000000001) cout << -1 << endl;
        else cout << adj[a][b] << endl;
    }

    return 0;
}
