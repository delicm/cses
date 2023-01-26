#include <bits/stdc++.h>

using namespace std;

#define int long long int

int n, m, finalFlow;
int capacity[505][505];
int flow[505][505];
int parent[505];
int currentFlow[505];
bool ok = 1;

vector <int> graph[505];
vector <int> alt_graph[505];
vector <vector<int>> paths;

void printPath(vector <int> newPath)
{
    cout << newPath.size() << endl;
    for(auto e : newPath) cout << e << " ";
    cout << endl;
}

void dfs(int parent, int node, vector <int> newPath)
{
    if(!ok) return;
    flow[parent][node] = -1;
    newPath.push_back(node);

    if(node == n)
    {
        printPath(newPath);
        ok = 0;
        return;
    }

    for(auto nextNode : graph[node])
    {
        if(flow[node][nextNode] != 1) continue;
        dfs(node, nextNode, newPath);
    }
    return;
}

void printPaths()
{
    for(int i = 1; i <= finalFlow; i++)
    {
        ok = 1;
        vector <int> temp;
        dfs(0, 1, temp);
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
        if(nextFlow == 0) return maxFlow;

        int node = n;
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
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        capacity[a][b] += 1;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    finalFlow = edmondsKarp();
    cout << finalFlow << endl;
    printPaths();

    return 0;
}
