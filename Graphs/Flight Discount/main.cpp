#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector <pair <int, int>> v[n+1];
    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }

    priority_queue <pair <long long, pair <int, bool>>> q;
    long long dc[n+1];
    long long dnc[n+1];

    for(int i = 0; i <= n; i++)
    {
        dc[i] = 9223372036854775807;
        dnc[i] = 9223372036854775807;
    }
    dc[1] = 0; dnc[1] = 0;

    q.push(make_pair(0, make_pair(1, 0)));

    while(!q.empty())
    {
        int s = q.top().second.first;
        long long dist = q.top().first;
        bool coupon = q.top().second.second;
        q.pop();

        if(coupon)
        {
            if(dist > dc[s]) continue;
        }
        else
        {
            if(dist > dnc[s]) continue;
        }

        for(auto e : v[s])
        {
            int v = e.first, w = e.second;
            if(coupon)
            {
                if(dc[v] > dc[s]+w)
                {
                    dc[v] = dc[s]+w;
                    q.push({-dc[v], {v, 1}});
                }
            }
            else
            {
                if(dc[v] > dnc[s]+w/2)
                {
                    dc[v] = dnc[s]+w/2;
                    q.push({-dc[v], {v, 1}});
                }
                if(dnc[v] > dnc[s]+w)
                {
                    dnc[v] = dnc[s]+w;
                    q.push({-dc[v], {v, 0}});
                }
            }
        }
    }

    cout << dc[n];

    return 0;
}
