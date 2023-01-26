#include <bits/stdc++.h>

using namespace std;

#define int long long int

int link[100001];
int no[100001];
vector <pair<int, pair<int, int>>> edge;

int rep(int x)
{
    while(x != link[x]) x = link[x];
    return x;
}

void unite(int x, int y)
{
    x = rep(x);
    y = rep(y);

    if(no[x] < no[y]) swap(x,y);
    no[x] += no[y];
    link[y] = x;
    return;
}

bool same(int x, int y)
{
    return rep(x) == rep(y);
}

int32_t main()
{
    int n,  m;
    int ans = 0, cnt = 0;
    cin >> n >> m;

    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({c, {a, b}});
    }

    sort(edge.begin(), edge.end());
    for(int i = 1; i <= n; i++) link[i] = i;
    for(int i = 1; i <= n; i++) no[i] = 1;

    for(auto e : edge)
    {
        int a = e.second.first, b = e.second.second;
        if(same(a, b)) continue;
        unite(a, b);
        ans += e.first;
        cnt++;
    }

    if(cnt != n-1) cout << "IMPOSSIBLE";
    else cout << ans;

    return 0;
}
