#include <bits/stdc++.h>

using namespace std;

#define int long long int

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector <pair<pair<int, int>, int>> edges;
    int dist[n+1];
    int pre[n+1];

    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({{a, b}, c});
    }

    for(int i = 2; i <= n; i++) dist[i] = 5000000000001;
    for(int i = 1; i <= n; i++) pre[i] = i;
    dist[1] = 0;

    for(int i = 1; i <= n-1; i++)
    {
        for(auto e : edges)
        {
            if(dist[e.first.second] > dist[e.first.first]+e.second)
            {
                pre[e.first.second] = e.first.first;
                dist[e.first.second] = dist[e.first.first]+e.second;
            }
        }
    }

    int start = -1;
    //for(int i = 1; i <= n; i++) cout << dist[i] << " ";

    for(auto e : edges)
    {
        if(dist[e.first.second] > dist[e.first.first]+e.second)
        {
            start = e.first.second;
            pre[start] = e.first.first;
            dist[e.first.second] = dist[e.first.first]+e.second;
            break;
        }
    }

    if(start == -1)
    {
        cout << "NO";
        return 0;
    }

    vector <int> cyc;
    for(int i = 1; i <= n; i++)
    {
        //cout << start << " ";
        start = pre[start];
    }

    for(int a = start; ; a = pre[a])
    {
        cyc.push_back(a);
        if(a == start && cyc.size() > 1) break;
    }
    cout << "YES" << endl;
    reverse(cyc.begin(), cyc.end());
    for(int i = 0; i < cyc.size(); i++) cout << cyc[i] << " ";


    return 0;
}
