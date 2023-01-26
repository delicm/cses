#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool ok = 1;

void asign(int a, vector <int> v[], int team[])
{
    queue <int> q;
    q.push(a);
    team[a] = 0;
    int c = 0;

    while(q.size())
    {
        int s = q.front();
        q.pop();
        c = (team[s]+1)%2;
        for(int i = 0; i < v[s].size(); i++)
        {
            if(team[v[s][i]] == -1)
            {
                team[v[s][i]] = c%2;
                q.push(v[s][i]);
            }
            else if(team[v[s][i]] != c%2)
            {
                ok = 0;
                return;
            }
        }

    }
    return;

}

int main()
{
    int n, m;
    cin >> n >> m;

    vector <int> v[n+1];
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int team[n+1];

    for(int i = 0; i < n+1; i++)
    {
        team[i] = -1;
    }

    for(int i = 1; i <= n; i++)
    {
        if(team[i] == -1)
        {
            asign(i, v, team);
            if(!ok) break;
        }
    }

    if(!ok)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    for(int i = 1; i <= n; i++)
    {
        cout << team[i] + 1 << " ";
    }

    return 0;
}
