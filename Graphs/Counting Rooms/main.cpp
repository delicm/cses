#include <iostream>

using namespace std;

int n, m;

void dfs(char x[1001][1001], bool visit[1001][1001], int a, int b)
{
    if(visit[a][b]) return;
    if(a < 0 || a >= n || b < 0 || b >= m) return;
    if(x[a][b] == '#') return;

    visit[a][b] = true;

    dfs(x, visit, a+1, b);
    dfs(x, visit, a-1, b);
    dfs(x, visit, a, b+1);
    dfs(x, visit, a, b-1);
}

int main()
{
    int total = 0;
    cin >> n >> m;

    char x[1001][1001];
    bool visit[1001][1001];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> x[i][j];
            visit[i][j] = false;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!visit[i][j] && x[i][j] == '.')
            {
                dfs(x, visit, i, j);
                total++;
            }
        }
    }

    cout << total;

    return 0;
}
