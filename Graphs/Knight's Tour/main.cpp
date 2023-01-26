#include <bits/stdc++.h>

using namespace std;

vector <pair<int, int>> board[15][15];
vector <pair<int, int>> moves = {{-2, 1}, {-2, -1}, {2, 1}, {2, -1}, {1, 2}, {-1, 2}, {-1, -2}, {1, -2}};

int movement[15][15];

void load()
{
    for(int i = 0; i <= 9; i++)
    {
        for(int j = 0; j <= 9; j++)
        {
            movement[i][j] = 0;
        }
    }

    for(int i = 1; i <= 8; i++)
    {
        for(int j = 1; j <= 8; j++)
        {
            for(auto e : moves)
            {
                int nextx = e.first + i, nexty = e.second+j;
                //if(i == 2 && j == 7) movement[nextx][nexty] = 1;
                if(nextx <= 0 || nextx >= 9 || nexty >= 9 || nexty <= 0) continue;
                board[i][j].push_back({nextx, nexty});
            }
        }
    }
}

void finishProtocol()
{
    for(int i = 1; i <= 8; i++)
    {
        for(int j = 1; j <= 8; j++)
        {
            cout<<movement[i][j] << " ";
        }
        cout << endl;
    }
    exit(0);
}

int deg(int i, int j)
{
    int s = 0;
    for(auto e : moves)
            {
                int nextx = e.first + i, nexty = e.second+j;
                if(nextx <= 0 || nextx >= 9 || nexty >= 9 || nexty <= 0 || movement[nextx][nexty] == -1) continue;
                s++;
            }
    return s;
}

void alg(int step, int i, int j)
{
    if(movement[i][j] != 0) return;

    movement[i][j] = step;
    if(step == 64) finishProtocol();

    vector <pair <int, pair<int, int>>> v;

    for(auto e : board[i][j])
    {
        int d = deg(e.first, e.second);
        v.push_back({d, {e.first, e.second}});
    }
    sort(v.begin(), v.end());
    for(auto t : v)
    {
        alg(step+1, t.second.first, t.second.second);
    }

    movement[i][j] = 0;
    return;
}

int main()
{
    int x, y;
    cin >> y >> x;
    load();
    alg(1, x, y);

    return 0;
}
