#include <bits/stdc++.h>

using namespace std;

#define int long long int

int n, m;
vector<pair<int, int>> edge[200005];
vector <int> path;
bool vis[200005];

void go()
{
    stack <int> s;
    s.push(1);

    while(!s.empty()){
        int x = s.top(); bool fail = 0;
        while(!edge[x].empty())
        {
            auto [ne, no] = edge[x].back();
            edge[x].pop_back();
            if(!vis[no])
            {
                vis[no] = true;
                s.push(ne);
                fail = 1;
                break;
            }
        }
        if(!fail)
        {
            path.push_back(x);
            s.pop();
        }
    }

    if(path.size() != m+1)
    {
        cout << "IMPOSSIBLE";
        return;
    }

    for(auto i : path) cout << i << " ";

    return;
}

int32_t main()
{
    cin >> n >> m;

    for(int i = 0; i <= n+1; i++) vis[i] = 0;

    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        edge[a].push_back({b, i});
        edge[b].push_back({a, i});
    }

    for(int i = 1; i <= n; i++)
    {
        if(edge[i].size()%2 == 1)
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    go();

    return 0;
}
