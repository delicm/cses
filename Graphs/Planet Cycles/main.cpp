#include <bits/stdc++.h>

using namespace std;

int n;
vector <bool> vis;
vector <bool> vis2;
vector <int> len;
int p[200001][32];
int group = 0;

int walk(int x, int k)
{
    for(int i = 0; i <= 31; i++)
    {
        if(k&(1<<i)) x = p[x][i];
    }
    return x;
}

bool check(int i)
{
    int x = p[walk(i, len[i])][0];
    if(walk(x, len[x]-len[i]) == i) return 0;
    return 1;
}

void cycleProtocol(int i)
{
    len[i] = len[p[i][0]]+1;
    int t = p[i][0];
    while(t!=i)
    {
        len[t] = len[i];
        t=p[t][0];
    }
    return;
}

void dfs(int i)
{
    if(vis[i] != 0)
    {
        vis2[i] = 1;
        return;
    }
    vis[i] = 1;
    dfs(p[i][0]);
    if(!vis2[i]) len[i] = len[p[i][0]]+1;
    else cycleProtocol(i);
    return;
}

void loadP()
{
    for(int k = 1; k <= 31; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            p[i][k] = p[p[i][k-1]][k-1];
        }
    }
    return;
}

int main()
{
    cin >> n;
    vis.resize(n+1);
    vis2.resize(n+1, 0);
    len.resize(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> p[i][0];
        vis[i] = 0;
        len[i] = 0;
    }

    for(int i = 1; i <= n; i++)
        if(!vis[i])
            dfs(i);

    loadP();

    /*for(int i = 1; i <= n; i++)
    {
        if(!check(i)) cout << len[i] << " ";
        else cout << len[walk(i, len[i])] << " ";
    }*/

    for(int i = 1; i <= n; i++) cout << len[i] << " ";

    return 0;
}
