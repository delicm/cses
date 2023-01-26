#include <bits/stdc++.h>

using namespace std;

#define int long long int

int n, m;
int capacity[505][505];
int flow[505][505];
int parent[505];
bool finalVis[505];
int currentFlow[505];

vector <int> graph[505];
vector <pair<int, int>> streets;

void finalBFS()
{
    memset(finalVis, 0, sizeof finalVis);
    queue<int> q;
    q.push(1);
    finalVis[1] = 1;

    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(auto nextNode : graph[x])
        {
            if(finalVis[nextNode] == 1) continue;
            if(parent[nextNode] == -1)
            {
                streets.push_back({x, nextNode});
                continue;
            }
            q.push(nextNode);
            finalVis[nextNode] = 1;
        }
    }
}

void reachableBFS()
{
    memset(parent, -1, sizeof parent);
    queue<int> q;
    q.push(1);
    parent[1] = 1;

    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(auto nextNode : graph[x])
        {
            if(parent[nextNode] != -1) continue;
            if(capacity[x][nextNode] - flow[x][nextNode] <= 0) continue;
            q.push(nextNode);
            parent[nextNode] = 1;
        }
    }
}

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
        if(nextFlow == 0)
        {
            reachableBFS();
            finalBFS();
            return maxFlow;
        }

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
        int a, b;
        cin >> a >> b;
        capacity[a][b] = 1;
        capacity[b][a] = 1;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int maxFlow = edmondsKarp();
    cout << maxFlow << endl;
    for(auto s : streets) cout << s.first << " " << s.second << endl;

    return 0;
}
