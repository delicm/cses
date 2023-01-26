#include <bits/stdc++.h>

using namespace std;

#define int long long int

int n, m;
int capacity[505][505];
int flow[505][505];
int parent[505];
int currentFlow[505];

vector <int> graph[505];

int bfs()
{
    memset(parent, -1, sizeof parent);
    memset(currentFlow, 0, sizeof currentFlow);
    queue<int> q;
    q.push(1);
    currentFlow[1] = LLONG_MAX;

    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(auto nextNode : graph[x])
        {
            if(parent[nextNode] != -1) continue;
            if(capacity[x][nextNode] - flow[x][nextNode] <= 0) continue;
            q.push(nextNode);
            parent[nextNode] = x;
            currentFlow[nextNode] = min(currentFlow[x], capacity[x][nextNode] - flow[x][nextNode]);
            if(nextNode == n) return currentFlow[n];
        }
    }
    return 0;
}

int edmondsKarp()
{
    int maxFlow = 0;
    int nextFlow = 0;
    while(true)
    {
        nextFlow = bfs();
        maxFlow += nextFlow;
        if(nextFlow == 0) return maxFlow;

        int node = n;
        while(node != 1)
        {
            int parentNode = parent[node];
            flow[parentNode][node] += nextFlow;
            flow[node][parentNode] -= nextFlow;
            node = parentNode;
        }
        /*for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                cout << flow[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;*/
    }
    return maxFlow;
}

int32_t main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        capacity[a][b] += c;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int maxFlow = edmondsKarp();
    cout << maxFlow;

    return 0;
}
