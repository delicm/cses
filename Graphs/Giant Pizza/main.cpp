#include <bits/stdc++.h>

using namespace std;

int n, m;
bool nopeFirst = 0;
vector<vector <int>> v;
vector<int> vis;
vector<int> visAlt;

void make_edge(char a, int b, char c, int d)
{
        if(a == '+')
        {
            if(c == '+')
            {
                v[b].push_back(d);
                v[d].push_back(b);
            }
            else
            {
                v[b].push_back(d+m);
                v[d+m].push_back(b);
            }
        }
        else
        {
            if(c == '+')
            {
                v[b+m].push_back(d);
                v[d].push_back(b+m);
            }
            else
            {
                v[b+m].push_back(d+m);
                v[d+m].push_back(b+m);
            }
        }
}

void nope()
{
    cout << "IMPOSSIBLE";
    exit(0);
}

void traverseAlt(int x, int turn)
{
    if(visAlt[x] == turn) return;
    if(visAlt[x] == -turn) nope();

    visAlt[x] = turn;
    vis[x] = turn;
    if(turn == -1) for(auto e : v[x]) traverseAlt(e, -turn);
    else if(x > m) traverseAlt(x-m, -turn);
    else traverseAlt(x+m, -turn);
    return;
}

void traverse(int x, int turn)
{
    if(vis[x] == turn || nopeFirst) return;
    if(vis[x] == -turn)
    {
        nopeFirst = 1;
        return;
    }

    vis[x] = turn;
    if(turn == -1) for(auto e : v[x]) traverse(e, -turn);
    else if(x > m) traverse(x-m, -turn);
    else traverse(x+m, -turn);
    return;
}

int main()
{
    cin >> n >> m;
    v.resize(2*m+1);
    vis.resize(2*m+1, 0);
    visAlt.resize(2*m+1, 0);

    for(int i = 1; i <= n; i++)
    {
        char a, c; int b, d;
        cin >> a >> b >> c >> d;
        make_edge(a, b, c, d);
    }

    for(int i = 1; i <= m; i++)
    {
        v[i].push_back(i+m);
        v[i+m].push_back(i);
    }

    for(int i = 1; i <= m; i++)
    {
        if(vis[i] == 0)
        {
            traverse(i, 1);
            if(nopeFirst)
            {
                nopeFirst = 0;
                traverseAlt(i, -1);
            }
        }
    }

    for(int i = 1; i <= m; i++)
    {
        if(vis[i] == 1) cout << '+' << " ";
        else cout << '-' << " ";
    }

    return 0;
}
