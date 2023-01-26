#include <bits/stdc++.h>

using namespace std;

int n, q, L;

vector <int> ord;
vector <int> depth;
vector <int> pos;
vector <int> d;

vector <vector <int>> g;
vector <vector <int>> m;
vector <vector <int>> succ;

void dfs(int v, int p, int d)
{
    depth[v] = d;
    for(auto u : g[v])
    {
        if(u != p)
        {
            ord.push_back(v);
            dfs(u, v, d+1);
        }
    }
    ord.push_back(v);
}

void STA()
{
    int N = 2*n-1;
    m.resize(N);
    for(int i = 0; i < N; i++) m[i].resize(L+1, INT_MAX);

    for(int i = 0; i < N; i++) m[i][0] = d[i];

    for(int j = 1; j <= L; j++)
    {
        for(int i = 0; i < N; i++)
        {
            if(i+(1<<j) <= N) m[i][j] = min(m[i][j-1], m[i+(1<<(j-1))][j-1]);
            else m[i][j] = INT_MAX;
        }
    }

    pos.resize(n+1);
    for(unsigned int i = 0; i < ord.size(); i++) pos[ord[i]] = i;
}

int depthSearch(int x, int y)
{
    if(y < x) swap(x, y);
    int t = (int) log2(y-x+1);
    int tt = (1<<t);

    return min(m[x][t], m[y-tt][t]);
}

void preProcess()
{
    for(int i = 0; i <= L; i++) succ[1][i] = 0;
    for(int i = 0; i <= L; i++) succ[0][i] = 0;

    for(int i = 1; i <= L; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            succ[j][i] = succ[succ[j][i-1]][i-1];
        }
    }
}

int querie(int x, int k)
{
    int sol = x;
    for(int i = 0; i <= L; i++)
        if(k&(1<<i)) sol = succ[sol][i];

    return sol;
}

int main()
{
    cin >> n >> q;
    L = (int) log2(n);
    L++;

    depth.resize(n+1);
    g.resize(n+1);
    succ.resize(n+1);
    for(int i = 0; i <= n; i++) succ[i].resize(L+1);

    for(int i = 2; i <= n; i++)
    {
        scanf("%d", &succ[i][0]);
        g[i].push_back(succ[i][0]);
        g[succ[i][0]].push_back(i);
    }

    dfs(1, 0, 0);
    d.resize(2*n-1);
    for(int i = 0; i < 2*n-1; i++) d[i] = depth[ord[i]];

    STA();
    preProcess();

    while(q--)
    {
        int x, y;
        cin >> x >> y;

        if(x == y)
        {
            cout << x << "\n";
            continue;
        }

        if(depth[x] > depth[y]) swap(x, y);
        y = querie(y, depth[y] - depth[x]);

        cout << querie(y, depth[y] - depthSearch(pos[x], pos[y])) << "\n";
    }

    return 0;
}
