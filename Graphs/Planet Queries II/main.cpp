#include <bits/stdc++.h>

using namespace std;

int p[200001][32];
bool vis[200001];
int len[200001];

int walk(int x, int step)
{
    for(int i = 0; i <= 31; i++)
    {
        if(step&(1 << i))
        {
            x = p[x][i];
        }
    }
    return x;
}

void dfs(int i)
{
    if(vis[i]) return;
    vis[i] = 1;
    dfs(p[i][0]);
    len[i] = len[p[i][0]]+1;
    return;
}

void minPath(int a, int b)
{
    int a1 = walk(a, len[a]);
    if(walk(a, len[a]-len[b]) == b)
        cout << len[a] - len[b] << endl;
    else if(walk(a1, len[a1]-len[b]) == b)
        cout << len[a]+len[a1]-len[b] << endl;
    else
        cout << -1 << endl;
}

int main()
{
    int n, q; cin >> n >> q;

    for(int i = 1; i <= n; i++)
    {
        cin >> p[i][0];
        vis[i] = 0;
        len[i] = 0;
    }

    for(int k = 1; k <= 31; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            p[i][k] = p[p[i][k-1]][k-1];
        }
    }

    for(int i = 1; i <= n; i++)
        if(!vis[i])
            dfs(i);

    while(q--)
    {
        int a, b;
        cin >> a >> b;
        minPath(a, b);
    }

    return 0;
}
