#include <bits/stdc++.h>

using namespace std;

int n, m;
vector <vector <int>> out;
vector <vector <int>> in;
vector <bool> vis;

int main()
{
    cin >> n >> m;

    out.resize(n+1);
    in.resize(n+1);
    vis.resize(n+1, 0);
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        out[a].push_back(b);
        in[b].push_back(a);
    }

    for(int i = 2; i <= n-1; i++)
    {
        if(out[i].size() != in[i].size())
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    if(out[1].size() != in[1].size()+1) {cout << "IMPOSSIBLE"; return 0;}
    if(out[n].size() != in[n].size()-1) {cout << "IMPOSSIBLE"; return 0;}

    stack <int> st;
    vector <int> path;
    st.push(1);

    while(!st.empty())
    {
        int x = st.top();
        if(out[x].empty())
        {
            path.push_back(x);
            st.pop();
        }
        else
        {
            st.push(out[x].back());
            out[x].pop_back();
        }
    }

    if(path.size() != m+1) {cout << "IMPOSSIBLE"; return 0;}
    reverse(path.begin(), path.end());
    for(auto i : path) cout << i << " ";

    return 0;
}
