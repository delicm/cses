#include <bits/stdc++.h>
#define int long long int

using namespace std;

int n, q;
vector <vector <int>> m;
vector <int> v;

void init()
{
    cin >> n >> q;
    v.resize(n+1, LLONG_MAX);
    m.resize(n+1);
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    for(int i = 0; i <= n; i++)
        m[i].resize(19, LLONG_MAX);
    for(int i = 0; i <= n; i++)
        m[i][0] = v[i];

    for(int j = 1; j <= 18; j++)
    {
        int p = pow(2, j-1);
        for(int i = 1; i <= n; i++)
        {
            if(i+p <= n) m[i][j] = min(m[i][j-1], m[i+p][j-1]);
            else m[i][j] = m[i][j-1];
        }
    }

}

int po2(int k)
{
    int s = 1;
    int ans = 0;
    while(2*s <= k)
    {
        s *= 2;
        ans++;
    }
    return ans;
}

int ans(int a, int b)
{
    int d = po2(b-a+1);
    int k = pow(2,d);
    return min(m[a][d], m[b-k+1][d]);
}

int32_t main()
{
    init();

    /*for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= 18; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }*/

    while(q--)
    {
        int a, b; cin >> a >> b;
        cout << ans(a,b) << endl;
    }

    return 0;
}
