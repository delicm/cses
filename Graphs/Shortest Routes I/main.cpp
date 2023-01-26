#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    long long d[n+1];
    bool vis[n+1];
    vector <pair <long long, long long>> v[n+1];
    while(m--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    for(int i = 0; i <= n; i++) vis[i] = 0;
    for(int i = 0; i <= n; i++) d[i] = LLONG_MAX;

    priority_queue <pair <long long, long long>> q;

    d[1] = 0;
    q.push({0, 1});

    while(!q.empty())
    {
        long long s = q.top().second;
        q.pop();
        if(vis[s]) continue;
        vis[s]= 1;

        for(auto u : v[s])
        {
            long long a = u.first, b = u.second;
            if(d[s] + b < d[a]){
                d[a] = d[s]+b;
                q.push({-d[a], a});
            }
        }
    }

    for(int i = 1; i <= n; i++) cout << d[i] << " ";

    return 0;
}
