#include <bits/stdc++.h>

using namespace std;

#define int long long int

vector <vector <pair<int, int>>> v;
vector <int> dist;
vector <int> paths;
vector <int> minPath;
vector <int> maxPath;

int32_t main()
{
    int n, m;
    cin >> n >> m;

    v.resize(n+1);
    paths.resize(n+1);
    minPath.resize(n+1);
    maxPath.resize(n+1);
    dist.resize(n+1, LLONG_MAX);
    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }

    priority_queue <
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
    > q;
    q.push({0, 1});
    dist[1] = 0;
    paths[1] = 1;
    minPath[1] = 0;
    maxPath[1] = 0;

    while(!q.empty())
    {
        int vDistance = q.top().first;
        int vertex = q.top().second;
        q.pop();

        if(vDistance > dist[vertex]) continue;

        for(auto e : v[vertex])
        {
            if(dist[e.first] > vDistance+e.second)
            {
                dist[e.first] = vDistance+e.second;
                minPath[e.first] = minPath[vertex]+1;
                maxPath[e.first] = maxPath[vertex]+1;
                paths[e.first] = paths[vertex];
                q.push({dist[e.first], e.first});
            }
            else if(dist[e.first] == vDistance+e.second)
            {
                dist[e.first] = vDistance+e.second;
                minPath[e.first] = min(minPath[vertex]+1, minPath[e.first]);
                maxPath[e.first] = max(maxPath[vertex]+1, maxPath[e.first]);
                paths[e.first] += paths[vertex];
                paths[e.first] %= 1000000007;
            }
        }
    }

    cout << dist[n] << " " << paths[n] << " " << minPath[n] << " " << maxPath[n];

    return 0;
}
