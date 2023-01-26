#include <bits/stdc++.h>

using namespace std;

vector <vector <int>> vOut;
vector <vector <int>> vIn;
vector <bool> visOut;
vector <bool> visIn;

void out_1(int i)
{
    if(visOut[i]) return;
    visOut[i] = 1;
    for(auto e : vOut[i]) out_1(e);
    return;
}

void in_1(int i)
{
    if(visIn[i]) return;
    visIn[i] = 1;
    for(auto e : vIn[i]) in_1(e);
    return;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vOut.resize(n+1);
    vIn.resize(n+1);
    visOut.resize(n+1, 0);
    visIn.resize(n+1, 0);

    while(m--)
    {
        int a, b;
        cin >> a >> b;
        vOut[a].push_back(b);
        vIn[b].push_back(a);
    }

    out_1(1);
    for(int i = 1; i <= n; i++)
    {
        if(!visOut[i])
        {
            cout << "NO" << endl << 1 << " " << i;
            return 0;
        }
    }

    in_1(1);
    for(int i = 1; i <= n; i++)
    {
        if(!visIn[i])
        {
            cout << "NO" << endl << i << " " << 1;
            return 0;
        }
    }

    cout << "YES";

    return 0;
}
