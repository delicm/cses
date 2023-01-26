#include <bits/stdc++.h>

using namespace std;

vector <vector <int>> out;
vector <vector <int>> in;

vector <int> kingdoms;
vector <int> visit;
vector <bool> visOut;
vector <bool> visIn;

int cnt = 0;

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
    for(auto e : out[x]) dfsOut(e);
    return;
}

int main()
{
    int n, m;
    cin >> n >> m;
    out.resize(n+1);
    in.resize(n+1);
    visIn.resize(n+1, 0);
    visOut.resize(n+1, 0);
    kingdoms.resize(n+1, -1);
    visit.resize(n+1, -1);

    while(m--)
    {
        int a, b;
        cin >> a >> b;
        out[a].push_back(b);
        in[b].push_back(a);
    }

    for(int i = 1; i <= n; i++)
    {
        if(kingdoms[i] == -1)
        {
            cnt++;
            dfsIn(i);
            dfsOut(i);
        }
    }

    cout << cnt << endl;
    for(int i = 1; i <= n; i++) cout << kingdoms[i] << " ";

    return 0;
}
