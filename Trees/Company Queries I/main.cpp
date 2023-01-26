#include <bits/stdc++.h>

using namespace std;

int n, m;
vector <vector <int>> succ;

void preProcess()
{
    for(int i = 1; i < m; i++)
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
    for(int i = 0; i < m; i++)
        if(k&(1<<i)) sol = succ[sol][i];

    return sol;
}

int main()
{
    int q;
    cin >> n >> q;
    m = (int) log2(n) + 1;
    succ.resize(n+1);
    for(int i = 0; i <= n; i++) succ[i].resize(m);

    for(int i = 0; i < m; i++) succ[1][i] = 0;
    for(int i = 0; i < m; i++) succ[0][i] = 0;

    for(int i = 2; i <= n; i++) cin >> succ[i][0];

    preProcess();

    while(q--)
    {
        int x, k;
        cin >> x >> k;
        int s = querie(x, k);
        if(s) cout << s << " ";
        else cout << -1 << " ";
    }

    return 0;
}
