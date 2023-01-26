#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define int long long int

vector <int> c;
vector <int> pos;

int u = 0;

void update(int a, int b)
{
    u = 0;
    if(b < a) swap(a, b);

    int x = c[a], y = c[b];
    if(pos[x+1] > a && pos[x+1] <= b) u++;
    if(pos[y-1] < b && pos[y-1] >= a) u++;
    if(pos[x-1] > a && pos[x-1] <= b) u--;
    if(pos[y+1] < b && pos[y+1] >= a) u--;

    if(x == y+1) u++;
    if(x == y-1) u--;

    c[a] = y; c[b] = x;
    pos[x] = b; pos[y] = a;
    return;
}

int32_t main()
{
    int n, m; cin >> n >> m;
    c.resize(n+1);
    pos.resize(n+1);

    c[0] = 0;
    pos[0] = 0;

    for(int i = 1; i <= n; i++)
    {
        cin >> c[i];
        pos[c[i]] = i;
    }

    set <int> s;
    int sol = 0;

    for(int i = 1; i <= n; i++)
    {
        if(!s.count(c[i]-1)) sol++;
        s.insert(c[i]);
    }

    while(m--)
    {
        int a, b;
        cin >> a >> b;
        update(a, b);
        sol+=u;
        cout << sol << endl;
    }

    return 0;
}
