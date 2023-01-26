#include <iostream>
#include <string>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m; cin >> n >> m;

    char x[n][m];
    bool vis[n][m];
    char pre[n][m];
    int a0 = 0, b0 = 0, a1 = 0, b1 = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> x[i][j];
            vis[i][j] = x[i][j] == '#';
            pre[i][j] = '#';
            if(x[i][j] == 'A')
            {
                a0 = i; b0 = j;
            }
            if(x[i][j] == 'B')
            {
                a1 = i; b1 = j;
            }
        }
    }

    queue <pair <int, int>> q;
    q.push({a0, b0});
    pre[a0][b0] = 'S';
    vis[a0][b0] = true;

    while(q.size())
    {
        int a = q.front().first, b = q.front().second;
        q.pop();

        if(a+1 < n && !vis[a+1][b])
        {
            vis[a+1][b] = true;
            pre[a+1][b] = 'D';
            q.push({a+1, b});
        }
        if(a-1 >= 0 && !vis[a-1][b])
        {
            vis[a-1][b] = true;
            pre[a-1][b] = 'U';
            q.push({a-1, b});
        }
        if(b+1 < m && !vis[a][b+1])
        {
            vis[a][b+1] = true;
            pre[a][b+1] = 'R';
            q.push({a, b+1});
        }
        if(b-1 >= 0 && !vis[a][b-1])
        {
            vis[a][b-1] = true;
            pre[a][b-1] = 'L';
            q.push({a, b-1});
        }
    }

    string s;

    if(pre[a1][b1] == '#')
    {
        cout << "NO";
        return 0;
    }
    char temp = pre[a1][b1]; int a = a1; int b = b1;
    while(temp != 'S')
    {
        if(temp == 'U') a++;
        else if(temp == 'D') a--;
        else if(temp == 'L') b++;
        else if(temp == 'R') b--;
        s.push_back(temp);
        temp = pre[a][b];
    }

    reverse(s.begin(), s.end());
    cout << "YES" << endl << s.size() << endl << s;

    return 0;
}
