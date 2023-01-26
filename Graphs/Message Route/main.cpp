#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;

int main()
{
    cin >> n >> m;

    vector <int> v[n+1];

    for(int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    queue <int> q;
    bool vis[n+1];
    int pre[n+1];
    q.push(1);

    for(int i = 0; i <= n; i++)
    {
        vis[i] = 0;
        pre[i] = -1;
    }

    vis[1] = 1;

    while(q.size())
    {
        int s = q.front();
        q.pop();

        for(int i = 0; i < v[s].size(); i++)
        {
            if(!vis[v[s][i]])
            {
                q.push(v[s][i]);
                vis[v[s][i]] = 1;
                pre[v[s][i]] = s;
            }
        }
    }

    if(pre[n] == -1)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    int t = n;
    vector <int> r;

    while(pre[t] != -1)
    {
        r.push_back(pre[t]);
        t = pre[t];
    }

    cout << r.size()+1 <<endl;

    for(int i = r.size()-1; i>=0; i--) cout << r[i] << " ";
    cout << n;

    return 0;
}
