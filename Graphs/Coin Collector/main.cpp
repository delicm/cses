#include <bits/stdc++.h>

using namespace std;

#define int long long int

vector <vector <int>> out;
vector <vector <int>> in;

vector <int> kingdoms;
vector <int> kingdomSums;
vector <int> visit;
vector <int> kingdomLinks[100005];
vector <int> finalSums;

vector <bool> kingdomVisit;

int cnt = 0;
int coin[100005];
int MAX = -1;

void dfsIn(int x)
{
    if(kingdoms[x] != -1 || visit[x] == cnt) return;
    visit[x] = cnt;
    for(auto e : in[x]) dfsIn(e);
    return;
}

void dfsOut(int x)
{
    if(visit[x] != cnt || kingdoms[x] == cnt) return;
    kingdoms[x] = cnt;
    kingdomSums[cnt] += coin[x];
    for(auto e : out[x]) dfsOut(e);
    return;
}

void kingdomDfs(int x)
{
    if(kingdomVisit[x]) return;
    kingdomVisit[x] = 1;
    for(auto e : kingdomLinks[x])
    {
        kingdomDfs(e);
        finalSums[x] = max(finalSums[x], finalSums[e]+kingdomSums[x]);
    }
    MAX = max(MAX, finalSums[x]);
}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    out.resize(n+1);
    in.resize(n+1);
    kingdoms.resize(n+1, -1);
    visit.resize(n+1, -1);

    for(int i = 1; i <= n; i++) cin >> coin[i];

    while(m--)
    {
        int a, b;
        cin >> a >> b;
        out[a].push_back(b);
        in[b].push_back(a);
    }
    kingdomSums.push_back(0);
    for(int i = 1; i <= n; i++)
    {
        if(kingdoms[i] == -1)
        {
            cnt++;
            kingdomSums.push_back(0);
            dfsIn(i);
            dfsOut(i);
        }
    }


    for(int i = 1; i <= n; i++)
    {
        for(auto j : out[i])
            if(kingdoms[i] != kingdoms[j]) kingdomLinks[kingdoms[i]].push_back(kingdoms[j]);
    }

    finalSums.resize(cnt+1);
    kingdomVisit.resize(cnt+1, 0);
    for(int i = 1; i <= cnt; i++) finalSums[i] = kingdomSums[i];

    for(int i = 1; i <= cnt; i++)
        if(!kingdomVisit[i])
            kingdomDfs(i);

    cout << MAX;

    return 0;
}
