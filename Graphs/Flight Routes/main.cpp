#include <bits/stdc++.h>

using namespace std;

#define int long long int

int32_t main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector <pair<int, int>> v[n+1];
    vector <int> dist[n+1];
    for(int i = 0; i <= n; i++) dist[i].resize(k, LLONG_MAX);
    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }

    priority_queue <
	  pair<int,int>,
	  vector<pair<int,int>>,
	  greater<pair<int,int>>
	> q;
    q.push({0, 1});
    dist[1][0] = 0;

    while(!q.empty())
    {
        int cost = q.top().first;
        int dest = q.top().second;
        q.pop();

        if(dist[dest][k-1] < cost) continue;

        for(auto e : v[dest])
        {
            int a = e.first, b = e.second;
            if(dist[a][k-1] > cost + b)
            {
                dist[a][k-1] = cost + b;
                q.push({dist[a][k-1], a});
                sort(dist[a].begin(), dist[a].end());
            }
        }
    }

    for(int i = 0; i < k; i++) cout << dist[n][i] << " ";

    return 0;
}
