#include <bits/stdc++.h>

using namespace std;

vector <vector <int>> v;
vector <int> maxd;
vector <int> pre;

int main()
{
    int n, m;
    cin >> n >> m;
    v.resize(n+1);
    maxd.resize(n+1, -1);
    pre.resize(n+1, -1);

    while(m--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    priority_queue <
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
    > q;
    q.push({1, 1});

    while(!q.empty())
    {
        int cnt = q.top().first;
        int vertex = q.top().second;
        q.pop();

        if(maxd[vertex] > cnt) continue;

        for(auto e : v[vertex])
        {
            if(maxd[e] < cnt+1)
            {
                maxd[e] = cnt+1;
                q.push({maxd[e], e});
                pre[e] = vertex;
            }
        }
    }

    if(maxd[n] == -1)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    vector <int> order;
    int t = n;
    while(t!=-1)
    {
        order.push_back(t);
        t=pre[t];
    }
    cout << order.size() << endl;
    reverse(order.begin(), order.end());
    for(auto e : order) cout << e << " ";
    return 0;
}
