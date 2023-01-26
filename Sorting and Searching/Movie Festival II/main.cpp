#include <iostream>
#include <algorithm>
#include <set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

int main()
{
    long long n, k; cin >> n >> k;
    pair <long long, long long> x[n];
    for(int i = 0; i<n; i++)
        cin >> x[i].second >> x[i].first;

    sort(x, x+n);

    multiset <int> s;
    long long cnt = 0;

    s.insert(x[0].first);
    cnt++;

    for(int i = 1; i < n; i++)
    {
        auto ind = s.upper_bound(x[i].second);
        if(ind != s.begin())
        {
            ind--;
            s.erase(ind);
            s.insert(x[i].first);
            cnt++;
        }
        else if(s.size()<k)
        {
            s.insert(x[i].first);
            cnt++;
        }

    }

    cout << cnt;

    return 0;
}
