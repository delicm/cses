#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>

int n;
vector <pair<int, pair<int, int> > > v;

vector <int> in;
vector <int> out;

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    if(a.second.first == b.second.first) return a.second.second >= b.second.second;
    return a.second.first <= b.second.first;
}

void compactify()
{
    int temp[2*n];
    for(int i = 0; i < n; i++)
    {
        temp[2*i] = v[i].second.first;
        temp[2*i+1] = v[i].second.second;
    }
    sort(temp, temp+2*n);

    map <int, int> m;
    int j = 1;
    for(int i = 0; i < 2*n; i++)
    {
        if(m.count(temp[i]) == 0)
        {
            m[temp[i]] = j;
            j++;
        }
    }

     for(int i = 0; i < n; i++)
    {
        v[i].second.first = m[v[i].second.first];
        v[i].second.second = m[v[i].second.second];
    }

}

void solveIn()
{
    ordered_set s;
    for(int i = 0; i < n; i++)
    {
        s.insert(make_pair(v[i].second.second, i));
        in[v[i].first] = s.size()-s.order_of_key(make_pair(v[i].second.second, 0))-1;
    }
}

void solveOut()
{
    ordered_set t;
    for(int i = n-1; i >= 0; i--)
    {
        t.insert(make_pair(v[i].second.second, n-i));
        out[v[i].first] = t.order_of_key(make_pair(v[i].second.second, n+1))-1;
    }
}

int main()
{
    cin >> n;
    v.resize(n);
    in.resize(n);
    out.resize(n);

    for(int i = 0; i < n; i++)
    {
        v[i].first = i;
        cin >> v[i].second.first >> v[i].second.second;

        in[i] = 0;
        out[i] = 0;
    }

    sort(v.begin(), v.end(), cmp);
    //compactify();
    solveIn();
    solveOut();

    for(auto x : out) cout << x << " ";
    cout << endl;
    for(auto x : in) cout << x << " ";

    return 0;
}
