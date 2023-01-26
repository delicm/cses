#include <bits/stdc++.h>

using namespace std;

#define int long long int

int n, m, k, F;
int capacity[1005][1005];
int flow[1005][1005];
int parent[1005];
int currentFlow[1005];

vector <int> graph[1005];
vector <pair <int, int>> pairs;

void findPairs()
{
    for(int i = 1; i <= F; i++)
    {
        if(flow[1][i] == 1)
        {
            for(int j = 1; j <= F; j++)
            {
                if(flow[i][j] == 1)
                {
                    pairs.push_back({i-1, j-n-1});
                    break;
                }
            }
        }
    }
}

int bfs()
{
    memset(parent, -1, sizeof parent);
    memset(currentFlow, 0, sizeof currentFlow);
    queue<int> q;
    q.push(1);
    currentFlow[1] = 10000001;

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
            if(nextNode == F) return currentFlow[F];
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

        int node = F;
        while(node != 1)
        {
            int parentNode = parent[node];
            flow[parentNode][node] += nextFlow;
            flow[node][parentNode] -= nextFlow;
            node = parentNode;
        }
    }
    return maxFlow;
}

int32_t main()
{
    cin >> n >> m >> k; F = n+m+2;
    for(int i = 1; i <= k; i++)
    {
        int a, b;
        cin >> a >> b;
        a++; b+= n+1;
        capacity[a][b] = 1;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 2; i <= n+1; i++)
    {
        capacity[1][i] = 1;
        graph[1].push_back(i);
        graph[i].push_back(1);
    }
    for(int i = n+2; i <= n+m+1; i++)
    {
        capacity[i][F] = 1;
        graph[i].push_back(F);
        graph[F].push_back(i);
    }

    int maxFlow = edmondsKarp();
    cout << maxFlow << endl;
    findPairs();
    for(auto p : pairs) cout << p.first << " " << p.second << endl;

    return 0;
}
