#include <bits/stdc++.h>

using namespace std;

int n, m;
vector <int> sol;
vector <int> color;
vector <bool> ifLast;
vector <int> tree;
vector <pair <int, pair <int, int>>> queries;
map <int, int> last;


bool cmp(pair <int, pair <int, int>> a, pair <int, pair <int, int>> b)
{
    if(a.second.second == b.second.second) return a.second.first < b.second.first;
    return a.second.second < b.second.second;
}

int sum(int k)
{
    int sol = 0;
    while(k >= 1){
        sol += tree[k];
        k -= k & -k;
    }
    return sol;
}

void update(int k, int x)
{
    while(k <= n){
        tree[k] += x;
        k += k & -k;
    }
}

void solve()
{
    int q = 0;
    int colcount = 0;
    for(int i = 1; i <= n && q < n; i++){
        int col = color[i];
        if(last.count(col)){
            ifLast[last[col]] = false;
            update(last[col], -1);
        }
        else colcount++;
        last[col] = i;

        while(q < n && queries[q].second.second == i){
            int a = queries[q].second.first;
            sol[queries[q].first] = colcount-sum(a-1);
            q++;
        }
    }
}

void init()
{
    cin >> n >> m;
    color.resize(n+1, 0);
    sol.resize(m, 0);
    ifLast.resize(n+1, true);
    tree.resize(n+1, 0);

    for(int i = 1; i <= n; i++){
        cin >> color[i];
        update(i, 1);
    }

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        queries.push_back(make_pair(i, make_pair(a, b)));
    }
    sort(queries.begin(), queries.end(), cmp);
    solve();
}

int main()
{
    init();
    //for(auto x : queries) cout << x.first << " " << x.second.first << " " << x.second.second << endl;
    for(auto x : sol) cout << x << " ";
    return 0;
}
