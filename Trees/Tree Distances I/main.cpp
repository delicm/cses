#include <bits/stdc++.h>

using namespace std;

vector <vector <int>> g;
vector <int> sol;
int d1, d2, n;

int bfs(int source)
{
    queue <int> q;
    q.push(source);
    vector <int> d(n+1, -1);
    d[source] = 0;
    sol[source] = max(sol[source], d[source]);

    int s;
    while(!q.empty())
    {
        s = q.front(); q.pop();

        for(auto v : g[s])
        {
            if(d[v] == -1)
            {
                q.push(v);
                d[v] = d[s]+1;
                sol[v] = max(sol[v], d[v]);
            }
        }
    }

    return s;

}

int main()
{
    cin >> n;
    g.resize(n+1);
    sol.resize(n+1, -1);

    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    d1 = bfs(1);
    d2 = bfs(d1);

    bfs(d2);

    for(int i = 1; i <= n; i++)
        cout << sol[i] << " ";

    return 0;
}
