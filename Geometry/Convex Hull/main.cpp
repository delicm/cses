#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define point pair<ll, ll>

ll cross(point a, point b) {return a.first*b.second-a.second*b.first;}

bool isLeft(vector<point>& upper)
{
    int n = upper.size();
    if(n <= 2) return false;
    point cma = {upper[n-1].first-upper[n-3].first, upper[n-1].second-upper[n-3].second};
    point cmb = {upper[n-1].first-upper[n-2].first, upper[n-1].second-upper[n-2].second};
    return cross(cma, cmb) > 0;
}

bool isRight(vector<point>& upper)
{
    int n = upper.size();
    if(n <= 2) return false;
    point cma = {upper[n-1].first-upper[n-3].first, upper[n-1].second-upper[n-3].second};
    point cmb = {upper[n-1].first-upper[n-2].first, upper[n-1].second-upper[n-2].second};
    return cross(cma, cmb) < 0;
}

void reflect(point& p) {p = {-p.first, -p.second};}

vector<point> convex_hull(vector<point> v)
{
    //upper hull
    sort(v.begin(), v.end());
    vector<point> upper; upper.push_back(v[0]);
    for(unsigned int i = 1; i < v.size(); i++){
        upper.push_back(v[i]);
        while(isLeft(upper)) upper.erase(upper.end()-2);
    }

    //flip and do upper again
    for(unsigned int i = 0; i < v.size(); i++) reflect(v[i]);
    reverse(v.begin(), v.end());
    vector<point> lower; lower.push_back(v[0]);
    for(unsigned int i = 1; i < v.size(); i++){
        lower.push_back(v[i]);
        while(isLeft(lower)) lower.erase(lower.end()-2);
    }

    //reflip
    for(unsigned int i = 0; i < lower.size(); i++) reflect(lower[i]);

    //merge
    for(unsigned int i = 1; i < lower.size()-1; i++) upper.push_back(lower[i]);
    return upper;
}

int main()
{
    int n; cin >> n;
    vector<point> v(n, {0, 0});
    for(int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

    //for(int i = 0; i < n; i++) v[i] = {i+1, i*(2*(i%2)-1)};

    v = convex_hull(v);
    cout << v.size() << endl;
    for(auto p : v) cout << p.first << " " << p.second << endl;
    //cout << "done";
    return 0;
}
