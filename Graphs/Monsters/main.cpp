#include <bits/stdc++.h>

using namespace std;

int n, m, timee = -1;
vector < vector <char> > l;
vector < vector <int> > t;
vector < pair <int, int> > moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
queue <pair <int, int>> q;
pair <int, int> start;
pair <int, int> finish;
map <pair <int, int>, pair <int, int>> pair_map;

bool valid(int x, int y)
{
    if(x < 0 || x >= n || y < 0 || y >= m) return 0;
    if(l[x][y] == '#') return 0;
    return 1;
}

bool val_move(int x, int y, int timer)
{
    if(!valid(x, y)) return 0;
    if(timer >= t[x][y]) return 0;
    return 1;
}

bool escape(int x, int y, int timer)
{
    if(x == 0 || x == n-1 || y == 0 || y == m-1) return 1;
    return 0;
}

bool escapePlan()
{
    queue <pair <pair <int, int>, int>> qu;
    qu.push(make_pair(start, 0));

    while(!qu.empty())
    {
        int x = qu.front().first.first;
        int y = qu.front().first.second;
        int timer = qu.front().second + 1;
        qu.pop();
        for(auto mv : moves)
        {
            int next_x = x+mv.first;
            int next_y = y+mv.second;
            if(val_move(next_x, next_y, timer))
            {
                if(escape(next_x, next_y, timer))
                {
                    finish.first = next_x;
                    finish.second = next_y;
                    if(pair_map.count({next_x, next_y}) == 0) pair_map[{next_x, next_y}] = {x, y};
                    return true;
                }
                if(pair_map.count({next_x, next_y}) == 0) pair_map[{next_x, next_y}] = {x, y};
                l[next_x][next_y] = timer;
                qu.push(make_pair(make_pair(next_x, next_y), timer));
            }
        }
    }
    return false;

}

void process_lava()
{
    int d = -1;
    t.resize(n);
    for(int i = 0; i < n; i++) t[i].assign(m, INT_MAX);

    int vis[n][m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(l[i][j] == '#' || l[i][j] == 'M') vis[i][j] = 1;
            else vis[i][j] = 0;
        }
    }

    while(!q.empty())
    {
        int layer = q.size();
        d++;
        while(layer--)
        {
            pair <int, int> s = q.front();
            q.pop();
            t[s.first][s.second] = d;

            if(s.first > 0 && !vis[s.first-1][s.second])
            {
                q.push(make_pair(s.first-1, s.second));
                vis[s.first-1][s.second] = 1;
            }
            if(s.first < n-1 && !vis[s.first+1][s.second])
            {
                q.push(make_pair(s.first+1, s.second));
                vis[s.first+1][s.second] = 1;
            }
            if(s.second > 0 && !vis[s.first][s.second-1])
            {
                q.push(make_pair(s.first, s.second-1));
                vis[s.first][s.second-1] = 1;
            }
            if(s.second < m-1 && !vis[s.first][s.second+1])
            {
                q.push(make_pair(s.first, s.second+1));
                vis[s.first][s.second+1] = 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    l.resize(n);
    for(int i = 0; i < n; i++) l[i].resize(m);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            char c;
            cin >> c;

            if(c == 'A') start = make_pair(i, j);
            else if(c == 'M') q.push({i, j});
            l[i][j] = c;
        }
    }

    if(start.first == 0 || start.second == 0 || start.first == n-1 || start.second == m-1)
    {
        cout << "YES" << endl << 0;
        return 0;
    }

    process_lava();

    if(!escapePlan())
    {
        cout << "NO";
        return 0;
    }

    if(escape(start.first, start.second, 0))
    {
        cout << "YES" << endl << 0;
        return 0;
    }

    cout << "YES" << endl;

    vector <char> sol;
    pair <int, int> p = finish;
    pair_map[start] = {-1, -1};
    while(pair_map[p] != make_pair(-1, -1))
    {
        if(p.first - pair_map[p].first == 1)
        {
            sol.push_back('D');
        }
        if(p.first - pair_map[p].first == -1)
        {
            sol.push_back('U');
        }
        if(p.second - pair_map[p].second == 1)
        {
            sol.push_back('R');
        }
        if(p.second - pair_map[p].second == -1)
        {
            sol.push_back('L');
        }
        //cout << p.first << " " << p.second << endl;
        p = pair_map[p];
    }
    cout << sol.size() << endl;
    for(int i = sol.size()-1; i >= 0; i--)
    {
        cout << sol[i];
    }

    return 0;
}
