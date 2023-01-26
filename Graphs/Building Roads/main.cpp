#include <bits/stdc++.h>

using namespace std;

int n, m;
vector <int> v[100001];
bool vis[100001];
vector <int> r;

void traverse(int a)
{
    if(vis[a]) return;
    vis[a] = 1;

    for(int i = 0; i < v[a].size(); i++)
    {
        traverse(v[a][i]);
    }
    return;
}

int main()
{
    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }

    for(int i = 0; i < n; i++)
    {
        vis[i] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            traverse(i);
            r.push_back(i);
        }
    }

    cout << r.size() - 1 << endl;

    for(int i = 0; i < r.size()-1; i++)
    {
        cout << r[i]+1 << " " << r[i+1]+1 << endl;
    }

    return 0;
}
