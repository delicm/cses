#include <bits/stdc++.h>

using namespace std;

int n, m;
int x[33000][2];
int vis[33000];
queue <bool> s;

void printBinary(int t)
{
    for(int i = n-1; i >= 0; i--)
    {
        if(t&(1<<i)) cout << 1;
        else cout << 0;
    }
}

void dfs(int k, bool parent)
{
    if(vis[k]) return;
    vis[k] = 1;
    s.push(parent);
    dfs(x[k][1], 1);
    dfs(x[k][0], 0);
    return;
}

int main()
{
    cin >> n;
    m = (int) pow(2, n);

    for(int i = 0; i < m; i++)
    {
        x[i][0] = (2*i)%m;
        x[i][1] = (2*i)%m+1;
        vis[i] = 0;
    }

    dfs(0, 0);
    for(int i = 1; i <= n-1; i++) cout << 0;

    while(!s.empty())
    {
        cout << s.front();
        s.pop();
    }

    return 0;
}
