#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define point vector<ll>
#define bigll 7999999994000000008

ll dist2(point a, point b){return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);}

bool xdist(point a, point b, ll d) {return d <= dist2({a[0], 0}, {b[0], 0});}

ll minimum_distance(vector<point> v)
{
    sort(v.begin(), v.end());

    //definitions
    queue<point> left; //keep track of [x-d, x] strip leftmost
    set<point> strip; //keep track of strip, reversed coords
    ll d = bigll;

    for(unsigned int i = 0; i < v.size(); i++){
        point curpoint = v[i];
        //remove points not in [x-d, x] strip
        while(!left.empty() && xdist(left.front(), curpoint, d)){
            strip.erase(strip.find({left.front()[1], left.front()[0]}));
            left.pop();
        }

        //empty strip case
        if(strip.empty()){left.push(curpoint); strip.insert({curpoint[1], curpoint[0]}); continue;}

        //find candidates
        vector<point> candidates; ll maxydist = floor(sqrt(d));
        auto lower = strip.lower_bound({curpoint[1]-maxydist, -bigll});
        auto upper = strip.upper_bound({curpoint[1]+maxydist, -bigll});
        if(lower == strip.end() || upper == strip.begin()) {left.push(curpoint); strip.insert({curpoint[1], curpoint[0]}); continue;}

        //test candidates
        for(auto candidate = lower; candidate != upper; candidate++) d = min(d, dist2(curpoint, {(*candidate)[1], (*candidate)[0]}));

        //edit data
        left.push(curpoint);
        strip.insert({curpoint[1], curpoint[0]});
    }

    return d;
}

int main()
{
    int n; cin >> n;
    vector<point> v;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        v.push_back({x, y});
    }

    cout << minimum_distance(v);

    return 0;
}
